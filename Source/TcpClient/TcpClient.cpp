#pragma once
#include "TcpClient.h"

TcpClient::TcpClient():m_running(false)
					  ,m_client(nullptr)
{
}

void TcpClient::ClientConnect(const QString& adress,const quint16 port)
{
	int failed=0;
	
	while(!m_running.load())
	{
		if (failed == 10)
		{
			m_running.store(true);
			emit requestTotalFailed();
		}
		if (!(m_client == nullptr))
		{
			m_client->abort();
			delete m_client;
			m_client = nullptr;
		}

		//新建一个TcpSocket
		m_client = new QTcpSocket(this);
		//给socket对应的端口号让他连接
		m_client->connectToHost(adress, port);
		//连接超时发信号
		if (!m_client->waitForConnected(1000))
		{
			emit requestFailed();
			failed += 1;
			continue;
		}
	}

}

void TcpClient::OnConnected(const QString& data)
{

}


