#pragma once

#include <QtWidgets/QMainWindow>
#include "ServerSoftware/ui_ServerSoftware.h"
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

private:
    Ui::ServerSoftwareClass *ui;
    
};

