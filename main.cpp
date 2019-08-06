#include <QApplication>
#include "trayicon.h"
#include "xmappingnotify.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    XMappingNotify *notify = new XMappingNotify();
    TrayIcon *icon = new TrayIcon(notify->Layout());

    QApplication::connect(notify, SIGNAL(hasChanged(QString)), icon, SLOT(write(QString)));
    notify->start();

    return a.exec();
}
