#include <iostream>
#include <string>

#include "const.h"
#include "consoleStyle.h"
#include "view_pixel_is_life.h"

void br(){
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void update_life(pixel e_game_pixels[HEIGHT][WIDTH]) {
    pixel temp[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            temp[y][x] = e_game_pixels[y][x];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = is_pixel_is_life(e_game_pixels, y, x);

            if (e_game_pixels[y][x].is_life) {
                if (neighbors < 2 || neighbors > 3)
                    temp[y][x].is_life = false;
            } else {
                if (neighbors == 3)
                    temp[y][x].is_life = true;
            }
        }
    }
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            e_game_pixels[y][x] = temp[y][x];
}


void console_graphic_out(pixel e_game_pixels[HEIGHT][WIDTH]){

    br();

    for (int y = 1; y < HEIGHT; y++) {
        std::string outline = "";
        for (int x = 1; x < WIDTH; x++) {
            int pixel_color;
            std::string pixel = "@@";

            e_game_pixels[y][x].is_life ? pixel_color = 6  : pixel_color = 0;

            outline += colorize(pixel, pixel_color, pixel_color);
        }
        std::cout << outline << std::endl;
    }
}
