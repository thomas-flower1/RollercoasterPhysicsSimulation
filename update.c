#include "update.h"

void update(GameManager *game_manager, Rollercoaster *rc, int *counter, Coordinate *top_left, int dimension, int grid[][SCREEN_WIDTH]){
    if (*counter == 1000) {


        // rotation_around_point(&(rc->top_right), &(rc->center));
        // rotation_around_point(&(rc->top_left), &(rc->center));

        // rotation_around_point(&(rc->bottom_right), &(rc->center));
        // rotation_around_point(&(rc->bottom_left), &(rc->center));

        follow_line_left(top_left, dimension, grid);

        *counter = 0;


    }

    (*counter)++;

   
    
    

}

void rotation_around_point(Coordinate *point, Coordinate *c) {
    double theta = 10.0 * 3.14 / 180.0; // the amount we want to move the point around the center
    point->x -= c->x;
    point->y -= c->y;

    // then we use the rotation rule
    double dx = round(point->x * cos(theta) - point->y * sin(theta));
    double dy = round(point->x * sin(theta) + point->y * cos(theta));

    point->x = dx;
    point->y = dy;

    // add the center back to the point
    point->x += c->x;
    point->y += c->y;

}

void follow_line_left(Coordinate *top_left, int dimension, int grid[][SCREEN_WIDTH]) {
    /*
    Note that this only works if the cube is already centered on the arc


    
    
    */

    Coordinate new_center = {
        .x = top_left->x,
        .y = top_left->y + floor(dimension / 2)

    };

    new_center.x --; // since we are moving to the left

    // use this coordinate to index into the grid and check if there is a pixel
    if(grid[new_center.x][new_center.y] == 1) {

        // if there is a pixel, this update the top left to be around this coord
        top_left->x = new_center.x;
        return;
    }

   
    if(grid[new_center.x][new_center.y - 1] == 1) {

        // NOTE THIS CASE HAS NOT BEEN TESTED

        top_left->x = new_center.x;
        top_left->y = new_center.y - floor(dimension / 2) - 1;

    } else if (grid[new_center.x][new_center.y + 1]) {
        top_left->x = new_center.x;
        top_left->y = new_center.y - floor(dimension / 2) + 1;
    }
    
    
}
