#ifndef CLIENT_H
#define CLIENT_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../app/app.h"

typedef struct {
    Window window;
    GC graphicContext;
    int x, y;
    int width, height;
} Client;

void createWindow(Client *client, App *app);

void drawWindow(Client *client, App *app);

#endif /* CLIENT_H */