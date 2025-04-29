#include <SDL.h>
#include "Vec3D.hpp"

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

typedef struct {
    int x, y;
    Uint8 depth;
} Point;

class Display {

public:

    Display(const char*, int, int, int, int);
    ~Display();

    bool running() { return isRunning; }

    void clearDisplay() { SDL_FillRect(surface, NULL, 0); }
    void updateDisplay() { SDL_UpdateWindowSurface(win); }
    void quitDisplay() { isRunning = false; }

    // 2D rendering
    void drawCircle(Point, int, Uint32);
    void drawLine(Point, Point, Uint32);

    // Projection
    Point project(Vec3D, double, double, double);

    // 3D Rendering
    void drawSphere(Vec3D, int, Uint32);
    void drawLine3D(Vec3D, Vec3D, Uint32);

private:
    SDL_Window *win;
    SDL_Surface *surface;

    bool isRunning;
    Uint8 *depthBuffer;

    int w, h;
};

#endif