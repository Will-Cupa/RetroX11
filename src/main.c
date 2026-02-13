#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    Display *dpy = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(dpy);

    XSelectInput(dpy, root, SubstructureRedirectMask | SubstructureNotifyMask);

    while (1) {
        XEvent ev;
        XNextEvent(dpy, &ev);

        if (ev.type == MapRequest) {
            XMapWindow(dpy, ev.xmaprequest.window);
        }
    }

    return 0;
}
