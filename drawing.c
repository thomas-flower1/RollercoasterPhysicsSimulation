#include "drawing.h"

void draw_rollercoaster(Rollercoaster *rc, GameManager *game_manager)
{

    // add to use bresenhams line alg

    SDL_RenderDrawPoint(game_manager->renderer, rc->top_left.x, rc->top_left.y);
    SDL_RenderDrawPoint(game_manager->renderer, rc->top_right.x, rc->top_right.y);

    // draw the top line
    draw_bresenham_line_alg(&(rc->top_left), &(rc->top_right), game_manager);
    //  draw_bresenham_line_alg(&(rc->top_right), &(rc->bottom_right), game_manager);
    // draw_bresenham_line_alg(&(rc->bottom_left), &(rc->bottom_right), game_manager);
    // draw_bresenham_line_alg(&(rc->top_left), &(rc->bottom_left), game_manager);
}

void draw_bresenham_line_alg(Coordinate *coord1, Coordinate *coord2, GameManager *game_manager) {
    // pseudo code taken from wikipedia - note does not draw a vertical linedoes

    // check if the same coords
    if (coord1->x == coord2->x) {
        // draw a vertical line
        int start_y = min(coord1->y, coord2->y);
        int end_y = max(coord1->y, coord2->y);




        for(int y = start_y; y < end_y; y++) {
            SDL_RenderDrawPoint(game_manager->renderer, coord1->x, y);


        }

    } else {

        int dx = coord2->x - coord1->x;
        int dy = coord2->y - coord1->y;
        int D = 2 * dy - dx;
        int y = coord1->y;

        for (int x = coord1->x; x < coord2->x; x++) {
            SDL_RenderDrawPoint(game_manager->renderer, x, y);
            if (D > 0)
            {
                y++;
                D = D - 2 * dx;
            }
            D = D + 2 * dy;
        }
    }
}

void draw_midpoint_circ_alg(Coordinate *center, int r, int grid[][SCREEN_WIDTH], int arc)
{
    int x = 0;
    int y = -r;

    while (x < -y)
    {
        double y_mid = y + 0.5;

        if (x * x + y_mid * y_mid > r * r)
        {
            y++;
        }

        grid[center->x - x][center->y + y] = 1;
        grid[center->x + y][center->y - x] = 1;

        if (arc)
        {
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

int max(int x, int y) {
    if(x > y) {
        return x;
    }

    return y;

}

int min(int x, int y) {
    if(x < y) {
        return x;
    }

    return y;

}