#include <QtCore/QCoreApplication>
#include "Server.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    Server srv(&a);
    return a.exec();
}