#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <atomic>
#include "ProtocolParser.h"
class  TcpClient:public QObject
{
    Q_OBJECT
public:
    TcpClient();
    void ClientConnect(const QString& address,const quint16 port);//发送Tcp连接
    void ClientDisconnect();//请求中断
    void InitClient();
public slots:
    void OnConnected(const QString& data);//发送数据
signals:
    void requestSucceeded(int data);
    void requestFailed();
    void finish();
    void requestTotalFailed();
private:
    QTcpSocket* m_client;
    std::atomic<bool> m_running;
    std::atomic<bool> m_using;
};
