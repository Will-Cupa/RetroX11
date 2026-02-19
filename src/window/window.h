#ifndef WINDOW_H
#define WINDOW_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

typedef struct {
    Window window;
    int x, y;
    int width, height;
} Client;

#endif /* WINDOW_H */