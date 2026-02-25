#include "client.h"

Client* createClient(Display *display, Window *contentWindow, long white, long black){
    Client *client = malloc(sizeof(Client)); 

    Client temp = {
        NULL,
        NULL,
        0, 0,
        200, 100,
        NULL
    };

    *client = temp;

    printf("display ptr: %p\n", display);

    client->window = XCreateSimpleWindow(display, DefaultRootWindow(display), client->x, client->y, client->width, client->height, 2, white, black);

    XReparentWindow(display, *contentWindow, client->window, client->x, client->y);

    XSelectInput(display, client->window, ExposureMask | StructureNotifyMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

    XMapWindow(display, client->window);
    XMapWindow(display, *contentWindow);

    client->graphicContext = XCreateGC(display, client->window, 0, NULL);

    return client;
}

void drawWindow(Client *client, Display *display, long white, long black){  
    Window **childWindowList;
    unsigned int nbChildren;

    XSetForeground(display, client->graphicContext, white);

    XDrawLine(display, client->window, client->graphicContext, 10,10, 190,190);
    XDrawLine(display, client->window, client->graphicContext, 10,190, 190,10);

//     XQueryTree(display, client->window, NULL, NULL, childWindowList, nbChildren);

//     for(int i=0; i < nbChildren; i++){
//         childWindowList[i]->drawWindow();
//     }
}