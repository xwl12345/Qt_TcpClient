#include "ServerSoftware/ServerSoftware.h"
#include <QHostAddress>
#include <QMessageBox>
ServerSoftware::ServerSoftware(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerSoftwareClass())
    , isConnecting(false)
{
    ui->setupUi(this);
    m_client = new TcpClient(this);
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_disconnect->setEnabled(false);
    connect(ui->pushButton_connect, &QPushButton::clicked, this, &ServerSoftware::OnConnectBtnClicked);
    connect(ui->pushButton_send, &QPushButton::clicked, this, &ServerSoftware::OnSendBtnClicked);
    connect(ui->pushButton_disconnect, &QPushButton::clicked, this, &ServerSoftware::OnDisconnectBtnClicked);
    connect(m_client, &TcpClient::MessageRecved, this, &ServerSoftware::ReadyRead);
    connect(m_client, &TcpClient::connectedSucceeded, this, &ServerSoftware::ConnectSucceeded);
    connect(m_client, &TcpClient::disconnectSucceeded, this, &ServerSoftware::DisconnectSucceeded);
    connect(m_client, &TcpClient::reconnect, this, &ServerSoftware::Reconnect);
    connect(m_client, &TcpClient::reconnect_Timeout, this, &ServerSoftware::ReconnectFailed);
    connect(m_client, &TcpClient::connectFailed, this, &ServerSoftware::ConnectFailed);
}

ServerSoftware::~ServerSoftware()
{
    delete ui;
}

void ServerSoftware::OnConnectBtnClicked()
{
    if (isConnecting == true)
    {
        ui->textBrowser_logInformation->append("正在连接中，请勿重复点击");
        return;
    }
    QHostAddress addr;
    QString address = ui->lineEdit_ip->text();
    bool ok;
    quint16 port = (ui->lineEdit_port->text()).toUShort(&ok, 10);
    if (!addr.setAddress(address))
    {
        QMessageBox::critical(this, "错误", "请输入正确的ip地址");
        return;
    }
    if ((ok == false) || (port == 0))
    {
        QMessageBox::critical(this, "错误", "请输入正确的port");
        return;
    }
    isConnecting = true;
    ui->textBrowser_logInformation->append("正在连接中...");
    m_client->connectToServer(address, port);

}


void ServerSoftware::OnSendBtnClicked()
{
    QString message = ui->lineEdit_send->text();
	bool is_empty = message.isEmpty();
    if (is_empty)
    {
        QMessageBox::warning(this, "警告", "请输入信息");
        return;
    }
    m_client->sendMessage(message);
}

void ServerSoftware::OnDisconnectBtnClicked()
{
    m_client->disconnectFromServer();
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_disconnect->setEnabled(false);
}

void ServerSoftware::ConnectSucceeded()
{
    qDebug() << "ServerSoftware:connectSucceeded";
    ui->pushButton_connect->setEnabled(false);
    ui->pushButton_send->setEnabled(true);
    ui->pushButton_disconnect->setEnabled(true);
    isConnecting = false;
    ui->textBrowser_logInformation->append("连接成功");
   

}

void ServerSoftware::DisconnectSucceeded()
{
    qDebug() << "DisconnectSucceeded";
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_disconnect->setEnabled(false);
    ui->textBrowser_logInformation->append("连接正常断开");

}

void ServerSoftware::Reconnect()
{
    ui->textBrowser_logInformation->append("正在重连中.....");

}

void ServerSoftware::ReconnectFailed()
{
    ui->textBrowser_logInformation->append("重连失败");
    ui->textBrowser_logInformation->append("连接已断开");
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_disconnect->setEnabled(false);
}

void ServerSoftware::ReadyRead(const QString msg)
{
    ui->textBrowser_logInformation->append("收到信息:");
    ui->textBrowser_logInformation->append(msg);
}

void ServerSoftware::ConnectFailed()
{
    ui->textBrowser_logInformation->append("连接失败");
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_disconnect->setEnabled(false);
    isConnecting = false;
}

