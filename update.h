#ifndef UPDATE_H
#define UPDATE_H

#include "game.h"

void update(GameManager *game_manager, Rollercoaster *rc, int *counter, Coordinate *top_left, int dimension, int grid[][SCREEN_WIDTH]);
void rotation_around_point(Coordinate *point, Coordinate *c);
void follow_line_left(Coordinate *top_left, int dimension, int grid[][SCREEN_WIDTH]);



#endif