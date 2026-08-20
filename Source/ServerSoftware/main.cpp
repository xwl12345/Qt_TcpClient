#include "ServerSoftware/ServerSoftware.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ServerSoftware window;
    window.show();
    return app.exec();
}