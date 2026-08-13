#include "ServerSoftware.h"

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

