# pragma once

#include <iostream>

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

class InputManager {
public:
    InputManager();
    ~InputManager();

    static void readDirection(const SDL_Event& event) {
        if(event.type == SDL_KEYDOWN) {
            if(event.key.keysym.sym == SDLK_UP) {
                std::cout << "UP" << std::endl;
            }

            else if(event.key.keysym.sym == SDLK_DOWN) {
                std::cout << "DOWN" << std::endl;
            }

            else if(event.key.keysym.sym == SDLK_LEFT) {
                std::cout << "LEFT" << std::endl;
            }

            else if(event.key.keysym.sym == SDLK_RIGHT) {
                std::cout << "RIGHT" << std::endl;
            }
        }
    };

private:
    SDL_Keycode game_keys [4] = {SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT};
};
