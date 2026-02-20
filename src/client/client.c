#include "client.h"

Client createClient(Display *display, Window *window, long white, long black){
    Client *client;

    client->window = XCreateSimpleWindow(display, DefaultRootWindow(display), client->x, client->y, client->width, client->height, 2, white, black);

    XSelectInput(display, client->window, ExposureMask | StructureNotifyMask);

    XMapWindow(display, client->window);

    client->graphicContext = XCreateGC(display, client->window, 0, NULL);

    return *client;
}

void drawWindow(Client *client, Display *display, long white, long black){
    XSetForeground(display, client->graphicContext, white);

    XDrawLine(display, client->window, client->graphicContext, 10,10, 190,190);
    XDrawLine(display, client->window, client->graphicContext, 10,190, 190,10);
}