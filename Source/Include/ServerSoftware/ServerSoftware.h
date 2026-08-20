#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ServerSoftware.h"
#include "TcpClient/TcpClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ServerSoftwareClass; };
QT_END_NAMESPACE

class ServerSoftware : public QMainWindow
{
    Q_OBJECT

public:
    ServerSoftware(QWidget *parent = nullptr);
    ~ServerSoftware();
public slots:
    void OnConnectBtnClicked();
    void OnSendBtnClicked();
    void OnDisconnectBtnClicked();
    void ConnectSucceeded();
    void DisconnectSucceeded();
    void Reconnect();
    void ReconnectFailed();
    void ReadyRead(const QString msg);
    void ConnectFailed();
private:
    Ui::ServerSoftwareClass *ui;
    TcpClient* m_client;
    bool isConnecting;
};

