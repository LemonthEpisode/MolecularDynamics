#include <iostream>
#include "Display3D.hpp"


int main (int argc, char* argv[]) {
    
    Display *disp = new Display("Display Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

    while (disp->running()) {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                disp->quitDisplay();
            }
        }

        disp->clearDisplay();

        // depth test - same output regardless of order
        disp->drawCircle((Point) {400, 300, 10}, 20, 0xFF00FF00);
        disp->drawCircle((Point) {410, 310, 11}, 15, 0xFF00FF00);

        // lines
        // disp->drawLine(10, 10, 30, 50, 0xFFFFFFFF);
        
        disp->updateDisplay();
        SDL_Delay(100);        
    }

    return 0;

}