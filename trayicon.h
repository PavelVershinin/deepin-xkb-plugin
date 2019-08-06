#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>
#include <QPainter>

class TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    TrayIcon(QString text) {
        write(text);
    }

public slots:
    void write(QString text) {
        QPixmap pixmap(128, 128);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setPen(Qt::white);
        painter.setFont({"Monotype", 90});
        painter.drawText(0, 100, text);
        painter.end();
        QIcon icon(pixmap);
        setIcon(icon);
        show();
    }
};

#endif // TRAYICON_H
