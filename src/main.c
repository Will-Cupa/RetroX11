#include "app/app.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    App app;

    init(&app);

    // Create window
    Window window = XCreateSimpleWindow(display, DefaultRootWindow(display), 50, 50, 200, 200, 2, white, black);

    XSelectInput(display, window, ExposureMask | StructureNotifyMask);

    XMapWindow(display, window);

    XEvent event;
    GC gc = XCreateGC(display, window, 0, NULL);

    while (1) {
        XNextEvent(display, &event);

        switch (event.type) {

            case MapNotify:
                printf("Mapped\n");
                break;

            case Expose:
                {
                    XSetForeground(display, gc, white);

                    XDrawLine(display, window, gc, 10,10, 190,190);
                    XDrawLine(display, window, gc, 10,190, 190,10);

                    XFlush(display);
                }
                break;
        }
    }

    return 0;
}
