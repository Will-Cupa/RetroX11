#ifndef CLIENT_H
#define CLIENT_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <stdio.h>
#include <stdlib.h>

#include "../design.h"

typedef struct Client {
    Window frame;
    Window content;
    GC graphicContext;
    int x, y;
    int width, height;
    struct Client *next;
} Client;

Client* createClient(Display *display, Window *window, long white, long black);

void moveResizeWindow(Display *display, Client *client, int x, int y, int w, int h);

void drawWindow(Client *client, Display *display, long white, long black);

#endif /* CLIENT_H */