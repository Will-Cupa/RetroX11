#include "client.h"

Client* createClient(Display *display, Window *contentWindow, long white, long black){
    Client *client = malloc(sizeof(Client)); 

    Client temp = {
        NULL,
        NULL,
        NULL,
        0, 0,
        200, 100,
        NULL
    };

    XWindowAttributes attr;
    XGetWindowAttributes(display, *contentWindow, &attr); 
    
    *client = temp;

    client->width = attr.width+BORDER_WIDTH*2;
    client->height = attr.height+BORDER_WIDTH*2;

    printf("display ptr: %p\n", display);

    client->frame = XCreateSimpleWindow(display, DefaultRootWindow(display), attr.x, attr.y, client->width, client->height, FRAME_BORDER_WIDTH, white, black);
    client->content = *contentWindow;

    XReparentWindow(display, client->content, client->frame, BORDER_WIDTH, BORDER_WIDTH);

    XSelectInput(display, client->frame, ExposureMask | StructureNotifyMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

    XMapWindow(display, client->frame);
    XMapWindow(display, client->content);

    client->graphicContext = XCreateGC(display, client->frame, 0, NULL);

    return client;
}

void moveResizeWindow(Display *display, Client *client, int x, int y, int w, int h){
    client->width = w;
    client->height = h;

    XMoveResizeWindow(display, client->frame, x, y, w, h);
    XMoveResizeWindow(display, client->content, BORDER_WIDTH, BORDER_WIDTH, w-BORDER_WIDTH*2, h-BORDER_WIDTH*2);
}

void drawWindow(Client *client, Display *display, long white, long black){  
    Window **childWindowList;
    unsigned int nbChildren;

    XSetForeground(display, client->graphicContext, white);

    XDrawLine(display, client->frame, client->graphicContext, 5, 5, client->width - 5, client->height - 5);
    XDrawLine(display, client->frame, client->graphicContext, 5, client->height -5, client->width - 5, 5);
}