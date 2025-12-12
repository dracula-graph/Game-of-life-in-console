
#include <iostream>
#include <thread>
#include <chrono>

#include "game_massives.h"
#include "console_graphic.h"



int main(void){
    std::cout << "Hello in game life" << std::endl;

    pixel game_pixels[HEIGHT][WIDTH] = {};
    bool is_game_loop = true;
    int ms = 150;

    set_massive(game_pixels);

    while (is_game_loop) {
        console_graphic_out(game_pixels);
        update_life(game_pixels);
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    return 0;
}
