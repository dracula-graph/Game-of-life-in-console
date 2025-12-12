#include <cstdlib>
#include <ctime>

#include "game_massives.h"

void set_massive(pixel p_game_pixels[HEIGHT][WIDTH]){
    std::srand(std::time(nullptr));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            p_game_pixels[y][x].x = x;
            p_game_pixels[y][x].y = y;

            p_game_pixels[y][x].is_life = (std::rand() % 3 == 0);
        }
    }
}
