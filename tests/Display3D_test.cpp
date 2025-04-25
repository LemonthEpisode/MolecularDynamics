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
        // disp->clearDisplay();
        // disp->updateDisplay();
        SDL_Delay(16);        
    }

    return 0;

}