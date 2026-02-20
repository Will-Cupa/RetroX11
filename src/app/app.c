#include "app.h"


void init(App *app) {
    app->display = XOpenDisplay( NULL );

    if( !app->display){
        printf("Could not create display."); 
        exit(1); 
    }

    app->screenId = DefaultScreen(app->display);

    // Get black and white color (see this as two tones color space, independently of the real colors)
    app->white = WhitePixel(app->display, app->screenId);
    app->black = BlackPixel(app->display, app->screenId);
}


void run(App *app) {
    XEvent event;
    while (1) {
        XNextEvent(app->display, &event);
        handle_event(app, &event);
    }
}


void handle_event(App *app, XEvent *event) {
    switch (event->type) {
        case Expose:
            XFlush(app->display);
            break;

        case MapRequest:
            // for WM later
            break;

        case DestroyNotify:
            break;
    }
}