#include "ServerSoftware/ServerSoftware.h"
#include <QString>
#include <QHostAddress>
#include <QMessageBox>
ServerSoftware::ServerSoftware(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerSoftwareClass())
{
    ui->setupUi(this);
    

}

ServerSoftware::~ServerSoftware()
{
    delete ui;
}

