#ifndef DRAWING_H
#define DRAWING_H

#include "game.h"


void draw_rollercoaster(Rollercoaster *rc, GameManager *game_manager);   
void draw_bresenhams_line_alg(Coordinate *coord1, Coordinate *coord2, GameManager *game_manager);
void draw_midpoint_circ_alg(Coordinate *center, int r, int grid[][SCREEN_WIDTH], int arc);




#endif