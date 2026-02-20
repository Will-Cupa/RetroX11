#ifndef APP_H
#define APP_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include "../client/client.h"

typedef struct App {
    Display *display;
    Window root;
    int screenId, clientCount;
    unsigned long white, black;
    Client *client_chain;
} App;

void run(App *app);

void init(App *app);

void handle_event(App *app, XEvent *event);

void handle_map_request(App *app, XMapRequestEvent *e);

void configureRequest(Display *display, XConfigureRequestEvent *ev);

#endif /* APP_H */