#ifndef APP_H
#define APP_H

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

void draw(App *app);

void handle_event(App *app, XEvent *event);

void handle_map_request(App *app, XMapRequestEvent *e);

void configureRequest(Display *display, XConfigureRequestEvent *ev);

#endif /* APP_H */