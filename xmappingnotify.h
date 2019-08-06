#ifndef XMAPPINGNOTIFY_H
#define XMAPPINGNOTIFY_H

#include <QThread>
#include <X11/XKBlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

class XMappingNotify : public QThread
{
    Q_OBJECT

public:
    XMappingNotify() {
        display = XOpenDisplay(nullptr);
        XKeysymToKeycode(display, XK_F1);
    }
    ~XMappingNotify() {
        XCloseDisplay(display);
    }
    QString Layout() {
        XkbDescRec* _kbdDescPtr = XkbAllocKeyboard();
        XkbGetNames(display, XkbSymbolsNameMask, _kbdDescPtr);
        Atom symName = _kbdDescPtr->names->symbols;
        QString layoutString = XGetAtomName(display, symName);
        if (layoutString.contains("+")) {
            layoutString = layoutString.split("+")[1];
        }
        return layoutString;
    }

protected:
    void run() {
        while (1) {
            XNextEvent(display, &event);
            if (event.type == MappingNotify) {
                XMappingEvent *e = (XMappingEvent *)&event;
                if (e->request == MappingKeyboard) {
                    emit hasChanged(Layout());
                }
                XRefreshKeyboardMapping(e);
            }
        }
    }


signals:
    void hasChanged(QString);

public slots:

private:
    XEvent event;
    Display* display;
};

#endif // XMAPPINGNOTIFY_H
