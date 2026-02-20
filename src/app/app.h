#ifndef APP_H
#define APP_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Display *display;
    Window root;
    int screenId;
    unsigned long white, black;
} App;

void run(App *app);

void init(App *app);

void handle_event(App *app, XEvent *event);

#endif /* APP_H */