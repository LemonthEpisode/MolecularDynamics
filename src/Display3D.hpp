#include <SDL.h>

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

class Display {

public:

    Display(const char*, int, int, int, int);
    ~Display();

    bool running() { return isRunning; }

    void clearDisplay() { SDL_FillRect(surface, NULL, 0); }
    void updateDisplay() { SDL_UpdateWindowSurface(win); }
    void quitDisplay() { isRunning = false; }

    void drawCircle(int, int, int, Uint8, Uint32);

private:
    SDL_Window *win;
    SDL_Surface *surface;

    bool isRunning;
    Uint8 *depthBuffer;

    int w, h;
};

#endif