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
    // first get the center of the cube


    Coordinate new_center = {
        .x = top_left->x,
        .y = top_left->y + floor(dimension / 2)

    };
    
    // change the y so that it is one pixel outside of the left side of the cube

    new_center.x --; // since we are moving to the left


    // make sure it's all working
    printf("Top Left: %d, %d\n", top_left->x, top_left->y);
    printf("Center: %d, %d\n", new_center.x, new_center.y);

    // use this coordinate to index into the grid and check if there is a pixel
    if(grid[new_center.x][new_center.y] == 1) {

        // if there is a pixel, this update the top left to be around this coord
        top_left->x = new_center.x;
        printf("1\n");

        return;
    }

    if(grid[new_center.x][new_center.y - 1] == 1) {

        top_left->x = new_center.x;
        top_left->y = new_center.y - dimension - 1;
        printf("2\n");

    } else if (grid[new_center.x][new_center.y + 1]) {
        top_left->x = new_center.x;
        top_left->y = new_center.y - dimension + 1;
        printf("3\n");
    }
    
    
}
