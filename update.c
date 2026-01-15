#include "update.h"

void update(GameManager *game_manager, Rollercoaster *rc, int *counter){
    if (*counter == 1000) {


        rotation_around_point(&(rc->top_right), &(rc->center));
        rotation_around_point(&(rc->top_left), &(rc->center));

        rotation_around_point(&(rc->bottom_right), &(rc->center));
        rotation_around_point(&(rc->bottom_left), &(rc->center));

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

void line_tracking() {


}

