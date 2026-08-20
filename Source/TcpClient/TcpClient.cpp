#pragma once
#include "TcpClient/TcpClient.h"
#include <QDebug>
TcpClient::TcpClient(QObject* parent):QObject(parent)
									 ,m_client(nullptr)
									 ,m_close(true)
{	
	m_Reconnect_timer = new QTimer(this);
	m_client = new QTcpSocket(this);
	connect(m_client, &QTcpSocket::connected, this, &TcpClient::OnConnected);
	connect(m_client, &QTcpSocket::disconnected, this, &TcpClient::OnDisConnected);
	connect(m_Reconnect_timer, &QTimer::timeout, this, &TcpClient::startReconnect);
	connect(m_client, &QTcpSocket::readyRead, this, &TcpClient::OnReadyRead);
	connect(m_client, &QTcpSocket::errorOccurred, this, &TcpClient::OnError);

}

void TcpClient::connectToServer(const QString& address, const quint16 port)
{
	if (m_client->state() != QAbstractSocket::UnconnectedState)
	{
		m_close.store(false);
		m_client->abort();
	}
	m_address = address;
	m_port = port;
	m_client->connectToHost(address, port);
}

void TcpClient::OnConnected()
{
	m_close.store(true);
	qDebug() << "OnConnected";
	emit connectedSucceeded();//发送连接成功信号，在后续ui触发事件时更新信息

}

void TcpClient::OnReadyRead()
{
	QByteArray data = m_client->readAll();
	m_parser.appendData(data);
	while (m_parser.hasCompleteMessage())
	{
		const QString msg = m_parser.takeNextMessage();
		emit MessageRecved(msg);
	}
}

void TcpClient::startReconnect()
{
	if (time > 1600)
	{
		emit reconnect_Timeout();
		time = 100;
	}
	time *= 2;
	OnReConnect();
	m_Reconnect_timer->start(time);
	emit reconnect();
}

void TcpClient::OnError(QAbstractSocket::SocketError socketError)
{
	emit connectFailed();
}


void TcpClient::sendMessage(const QString& data)
{
	const QByteArray message = m_parser.encode(data);
	m_client->write(message);
}

void TcpClient::OnReConnect()
{
	m_client->connectToHost(m_address, m_port);
}

void TcpClient::disconnectFromServer()
{
	m_close.store(false);
	m_client->abort();
}

void TcpClient::OnDisConnected()
{
	if(m_close.load())
	{
		startReconnect();//每次断连都进来启动重连定时器
	}
}




