#include "drawing.h"

void draw_rollercoaster(Rollercoaster *rc, GameManager *game_manager) {

    // not this only draws the rollercoaster if it is exactly parallel and flat - no rotation - need an if condition if rotated based on the matching x and y coords

    // fix for the new implementation 
    for(int i = rc->top_left.y; i < rc->bottom_left.y; i++) {
        for(int j = rc->top_left.x; j < rc->top_right.x; j++) {
            SDL_RenderDrawPoint(game_manager->renderer, j, i); // draw a single pixel


        }
    }

    // add to use bresenhams line alg

   
}


void draw_bresenhams_line_alg(Coordinate *coord1, Coordinate *coord2, GameManager *game_manager) {
    // pseudo code taken from wikipedia
    int dx = coord2->x - coord1->x;
    int dy = coord2->y - coord1->y;
    int D = 2 * dy - dx;
    int y = coord1->y;

    for(int x = coord1->x; x < coord2->x; x++) {
        SDL_RenderDrawPoint(game_manager->renderer, x, y);
        if (D > 0) {
            y++;
            D = D - 2 * dx;

        }
        D = D + 2 * dy;
    }

}

void draw_midpoint_circ_alg(Coordinate *center, int r, int grid[][SCREEN_WIDTH], int arc){
    int x = 0;
    int y = -r;

    while(x < -y) {
        double y_mid = y + 0.5;

        if(x * x + y_mid * y_mid > r * r) {
            y++;

        }

        grid[center->x - x][center->y + y] = 1;
        grid[center->x + y][center->y - x] = 1;

        if (arc){
            grid[center->x + x][center->y + y] = 1;
            grid[center->x + x][center->y - y] = 1;
            grid[center->x - x][center->y - y] = 1;
            grid[center->x + y][center->y + x] = 1;
            grid[center->x - y][center->y + x] = 1;
            grid[center->x - y][center->y - x] = 1;

        }
       
        x++;

    }

}