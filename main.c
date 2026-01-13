#include "render.h"
#include "update.h"
#include "events.h"
#include "game.h"

int main() {
    GameManager game_manager;
    int grid[SCREEN_HEIGHT][SCREEN_WIDTH] = {0}; // initialize an array of 0s for each pixel on the screen;

    if (create_window(&game_manager) == 1) {
        return 1;

    }

    // now we can say that the game is running
    game_manager.is_running = 0;

    
    // initialize the rollercoaster
    Rollercoaster rc = {
        .top_left = {10, 10},
        .top_right = {20, 10},
        .bottom_left = {10, 20},
        .bottom_right = {20, 20},
        .visible = 1
    };
    



    while(game_manager.is_running == 0) {
        handle_events(&game_manager, &rc);
        render(&game_manager, &rc, grid);
        update(&game_manager, &rc);


    }


   

    return 0;
}

