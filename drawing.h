#ifndef DRAWING_H
#define DRAWING_H

#include "main.h"
#include "drawing.h"

const Colour WHITE = {
        .r = 255,
        .g = 255,
        .b = 255,
        .alpha = 255,
};

const Colour BLACK = {
        .r = 0,
        .g = 0,
        .b = 0,
        .alpha = 255,
    };


void draw_rollercoaster(Rollercoaster *rc, GameManager *game_manager);   
void draw_bresenhams_line_alg(Coordinate *coord1, Coordinate *coord2, GameManager *game_manager);
void draw_midpoint_circ_alg(Coordinate *center, int r, int grid[][SCREEN_WIDTH], int arc);




#endif