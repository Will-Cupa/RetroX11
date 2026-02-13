#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    Display *display = XOpenDisplay( NULL );
    if( !display ){
        printf("Could not create display."); 
        return 1; 
    }

    int screenId = DefaultScreen(display);

    // Get black and white color (see this as two tones color space, independently of the real colors)
    unsigned long white = WhitePixel(display,screenId);
    unsigned long black = BlackPixel(display,screenId);

    // Create window
    Window window = XCreateSimpleWindow(display, DefaultRootWindow(display), 50, 50, 200, 200, 0, black, white);

    // Add window
    XMapWindow(display, window);

    // Create empty mask
    long eventMask = StructureNotifyMask;

    // Select input to check (in that case, if the window was succesfully added to the display)
    XSelectInput(display, window, eventMask);

    XEvent event;
    do{
        XNextEvent(display, &event);   // Wait for event, /!\ calls XFlush
    }while(event.type != MapNotify); // Check each event until we hit MapNotify (the one we're looking for)

    // Create graphic context (for drawing)
    GC graphicContext = XCreateGC(display, window, 0, NULL);   

    XSetForeground(display, graphicContext, black);

    XDrawLine(display, window, graphicContext, 10,10, 190,190); //from-to
    XDrawLine(display, window, graphicContext, 10,190, 190,10); //from-to

    while(1);

    return 0;
}
