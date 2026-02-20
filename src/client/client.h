#ifndef CLIENT_H
#define CLIENT_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

typedef struct Client {
    Window window;
    GC graphicContext;
    int x, y;
    int width, height;
    struct Client *next;
} Client;

Client createClient(Display *display, Window *window, long white, long black);

void drawWindow(Client *client, Display *display, long white, long black);

#endif /* CLIENT_H */