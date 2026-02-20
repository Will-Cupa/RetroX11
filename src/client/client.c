#include "client.h"

void createWindow(Client *client, App *app){

    client->window = XCreateSimpleWindow(app->display, DefaultRootWindow(app->display), client->x, client->y, client->width, client->height, 2, app->white, app->black);
    
    XSelectInput(app->display, client->window, ExposureMask | StructureNotifyMask);

    XMapWindow(app->display, client->window);

    client->graphicContext = XCreateGC(app->display, client->window, 0, NULL);
}

void drawWindow(Client *client, App *app){
    XSetForeground(app->display, client->graphicContext, app->white);

    XDrawLine(app->display, client->window, client->graphicContext, 10,10, 190,190);
    XDrawLine(app->display, client->window, client->graphicContext, 10,190, 190,10);
}