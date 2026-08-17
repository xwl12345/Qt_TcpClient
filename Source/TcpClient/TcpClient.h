#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <atomic>
#include <QTimer>
#include "ProtocolParser.h"
class  TcpClient:public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject* parent=nullptr);
    void connectToServer(const QString& address,const quint16 port);//发送Tcp连接
    void disconnectFromServer();//请求中断
    void sendMessage(const QString& data);
    void OnReConnect();
public slots:
    void OnConnected();
    void OnDisConnected();
    void OnReadyRead();
    void startReconnect();
signals:
    void connectedSucceeded();
    void disconnectSucceeded();
    void MessageRecved(const QString& data);
    void reconnect_Timeout();//重连超时
private:
    QTcpSocket* m_client;
    ProtocolParser m_parser;
    QString m_address;
    quint16 m_port;
    std::atomic<bool> m_close;//主动停止标志位
    QTimer* m_Reconnect_timer;
    int time;
};
