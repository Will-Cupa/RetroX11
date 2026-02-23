#include "client.h"

Client* createClient(Display *display, Window *window, long white, long black){
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

    client->window = *window;

    XSelectInput(display, client->window, ExposureMask | StructureNotifyMask);

    XMapWindow(display, client->window);

    client->graphicContext = XCreateGC(display, client->window, 0, NULL);

    return client;
}

void drawWindow(Client *client, Display *display, long white, long black){
    XSetForeground(display, client->graphicContext, white);

    XDrawLine(display, client->window, client->graphicContext, 10,10, 190,190);
    XDrawLine(display, client->window, client->graphicContext, 10,190, 190,10);
}