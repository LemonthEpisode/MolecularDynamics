#include <iostream>
#include "Display3D.hpp"
#include "Vec3D.hpp"
#include <math.h>

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

    this->w = w;
    this->h = h;
    isRunning = true;
}

// draw a circle given it's position and radius
void Display::drawCircle(Point p, int r, Uint32 color) {

    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            
            if (i*i + j*j > r*r) { continue; }
            
            // skip pixel if out of screen
            if (p.x+i < 0 || p.x+i > w) { continue; }
            if (p.y+j < 0 || p.y+j > h) { continue; }

            // skip if occluded
            if (depthBuffer[p.x+i + (p.y+j)*w] < p.depth) { continue; }
            depthBuffer[p.x+i + (p.y+j)*w] = p.depth;

            SDL_Rect pxl = {p.x+i, p.y+j, 1, 1};
            SDL_FillRect(surface, &pxl, color);

        }
    }

}

// draw a line between two points
// TODO: add depth
void Display::drawLine(Point s, Point e, Uint32 color) {

    int x_sign = s.x < e.x? +1 : -1;
    int y_sign = s.y < e.y? +1 : -1;

    int nx = s.x > e.x? s.x-e.x : e.x-s.x;
    int ny = s.y > e.y? s.y-e.y : e.y-s.y;

    SDL_Rect p;

    for (int i=0, j=0; i < nx || j < ny;) {
        int d = (2*i+1) * ny - (2*j+1) * nx;
        if (d == 0) {
            // go diagonal
            p = {s.x+=x_sign, s.y+=y_sign, 1, 1};
            i++; j++;
        } else if (d < 0) {
            // horizontal
            p = {s.x+=x_sign, s.y, 1, 1};
            i++;
        } else {
            // vertical
            p = {s.x, s.y+=y_sign, 1, 1};
            j++;
        }
        SDL_FillRect(surface, &p, color);
    }
}

// Project a 3D point into screen given some parameters
Point Display::project(Vec3D coord, double camera, double focal, double rotY) {
    
    // rotation and transformation
    Vec3D screen = {
        coord.z * sin(rotY) + coord.x * cos(rotY),
        coord.y,
        coord.z * cos(rotY) - coord.x * sin(rotY) + camera,
    };

    // pinhole adjust
    if (coord.z != 0) {
        screen.x *= focal / screen.z;
        screen.y *= focal / screen.z;
    }

    // interpolate
    screen.x = (screen.x + 1) * h / 2 + (w-h) / 2;
    screen.y = (screen.y + 1) * w / 2;

    // screen.z = 

    return (Point) {0,0,0};
}

void Display::drawSphere(Vec3D coord, int r, Uint32 color) {

    Point screen = project(coord, 2, 3, 0);
    Point radiusProj = project((Vec3D) {0, r, coord.z}, 2, 3, 0);
    
    drawCircle(screen, radiusProj.y, color);

}

void Display::drawLine3D(Vec3D start, Vec3D end, Uint32 color) {

    Point startProj = project(start, 2, 3, 0);
    Point endProj = project(end, 2, 3, 0);
    
    drawLine(startProj, endProj, color);

}