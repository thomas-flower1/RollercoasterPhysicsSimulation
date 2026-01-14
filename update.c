#include "update.h"

void update(GameManager *game_manager, Rollercoaster *rc, int *counter){
    if (*counter == 1000) {

        // need to fix this 
        Coordinate center;

        // get the center of the box
        center.x = round((rc->top_right.x + rc->top_left.x) / 2 );
        center.y = round((rc->bottom_left.y + rc->top_left.y) / 2);

        // NEED TO FIX THE CENTER POINT

      

        rotation_around_point(&(rc->top_right), &center);
        rotation_around_point(&(rc->top_left), &center);

        rotation_around_point(&(rc->bottom_right), &center);
        rotation_around_point(&(rc->bottom_left), &center);







        *counter = 0;

        

    }

    (*counter)++;
    
    

}

void rotation_around_point(Coordinate *point, Coordinate *c) {
    double theta = 90.0 * 3.14 / 180.0; // the amount we want to move the point around the center
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

