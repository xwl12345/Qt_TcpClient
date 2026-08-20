#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <atomic>
#include <QTimer>
#include "ProtocolParser/ProtocolParser.h"
#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TCPCLIENT_LIB)
#  define TCPCLIENT_EXPORT Q_DECL_EXPORT
# else
#  define TCPCLIENT_EXPORT Q_DECL_IMPORT
# endif
#else
# define TCPCLIENT_EXPORT
#endif
class TCPCLIENT_EXPORT TcpClient:public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject* parent=nullptr);
    void connectToServer(const QString& address,const quint16 port);//发送Tcp连接
    void disconnectFromServer();//请求中断
    void sendMessage(const QString& data);//发送信息
    void OnReConnect();//重连
public slots:
    void OnConnected();
    void OnDisConnected();
    void OnReadyRead();
    void startReconnect();
    void OnError(QAbstractSocket::SocketError socketError);
signals:
    void connectedSucceeded();//连接成功
    void disconnectSucceeded();//断连成功信号
    void MessageRecved(const QString& data);//接收数据信号
    void reconnect_Timeout();//重连超时
    void reconnect();//重连信号
    void connectFailed();//连接失败信号
private:
    QTcpSocket* m_client;
    ProtocolParser m_parser;
    QString m_address;
    quint16 m_port;
    std::atomic<bool> m_close;//主动停止标志位
    QTimer* m_Reconnect_timer;
    int time;
};
