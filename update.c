#include "update.h"

void update(GameManager *game_manager, Rollercoaster *rc){
    if(rc->visible) {
       // move the rollercoaster
       rc->bottom_left.x ++;
       rc->bottom_right.x ++;
       rc->top_left.x ++;
       rc->top_right.x ++;
      
    }
    

}

