#include "Display3D.hpp"
#include <iostream>

Display::~Display() {}

Display::Display(const char* title, int x, int y, int w, int h) {

    // initialize SDL components    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error" << SDL_GetError() << std::endl;
        return;
    }

    win = SDL_CreateWindow(title, x, y, w, h, 0);
    if (!win) {
        std::cerr << "SDL_CreateWindow Error" << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    surface = SDL_GetWindowSurface(win);
    if (surface == NULL) { return; }
    
    // initialize z-buffer
    depthBuffer = (Uint8*)calloc(w*h, sizeof(Uint8));
    if (depthBuffer == NULL) { return; }
    for (int i=0; i < w*h; i++) {
        depthBuffer[i] = 255;
    }

    isRunning = true;
}

void Display::drawCircle(int x, int y, int r, Uint8 depth, Uint32 color) {

    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            
            if (i*i + j*j > r*r) { continue; }
            
            // skip pixel if out of screen
            if (x+i < 0 || x+i > w) { continue; }
            if (y+j < 0 || y+j > h) { continue; }

            // skip if occluded
            if (depthBuffer[x+i + (y+j)*w] < depth) { continue; }
            depthBuffer[x+i + (y+j)*w] = depth;

            SDL_Rect p = {x+i, y+j, 1, 1};
            SDL_FillRect(surface, &p, color);
        }
    }

}