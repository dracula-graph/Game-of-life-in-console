#include "view_pixel_is_life.h"

int is_pixel_is_life(pixel game_pixels[HEIGHT][WIDTH], int y, int x) {
    int count = 0;

    const int dirs[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},         { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    for (auto &d : dirs) {
        int ny = y + d[0];
        int nx = x + d[1];

        if (ny < 0 || ny >= HEIGHT) continue;
        if (nx < 0 || nx >= WIDTH) continue;

        if (game_pixels[ny][nx].is_life)
            count++;
    }

    return count;
}
