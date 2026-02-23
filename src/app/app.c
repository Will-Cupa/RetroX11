#include "app.h"


void init(App *app) {
    app->display = XOpenDisplay(NULL);

    if( !app->display){
        printf("Could not create display."); 
        exit(1); 
    }

    app->screenId = DefaultScreen(app->display);

    // Get black and white color (see this as two tones color space, independently of the real colors)
    app->white = WhitePixel(app->display, app->screenId);
    app->black = BlackPixel(app->display, app->screenId);

    XSelectInput(app->display, DefaultRootWindow(app->display), SubstructureRedirectMask | SubstructureNotifyMask);
    XSync(app->display, False); //Flush errors
}


void run(App *app) {
    XEvent event;
    while (1) {
        printf("loop\n");

        XNextEvent(app->display, &event);
        printf("events\n");
        handle_event(app, &event);
    }
}


void handle_event(App *app, XEvent *event) {
    switch (event->type) {
        case Expose:
            Client *client = app->client_chain;

            while(client){
                client = client->next;
                drawWindow(client, app->display, app->white, app->black);
            }

            XFlush(app->display);
            break;

        case MapRequest:
            printf("requested\n");
            fflush(stdout);
            handle_map_request(app, &event->xmaprequest);
            // for WM later
            break;
        
        case ConfigureRequest:
            printf("configure request\n");
            configureRequest(app->display, &event->xconfigurerequest);
            break;

        case DestroyNotify:
            break;
    }
}


void configureRequest(Display *display, XConfigureRequestEvent *ev){
    XWindowChanges changes;

    changes.x = ev->x;
    changes.y = ev->y;
    changes.width = ev->width;
    changes.height = ev->height;
    changes.border_width = ev->border_width;
    changes.sibling = ev->above;
    changes.stack_mode = ev->detail;

    XConfigureWindow(display, ev->window, ev->value_mask, &changes);
}


void handle_map_request(App *app, XMapRequestEvent *e) {

    // Add window to your internal client list
    Client *client = createClient(app->display, &e->window, app->white, app->black);

    // Insert client at the start of the chain
    if(!app->client_chain){
        app->client_chain = client;
    } else {
        client->next =  app->client_chain;
        app->client_chain->next = client;
    }

    // // You decide size/position
    // XMoveResizeWindow(app->display, e->window, 100, 100, 800, 600);
}

