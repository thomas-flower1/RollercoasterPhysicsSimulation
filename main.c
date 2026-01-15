#include "render.h"
#include "update.h"
#include "events.h"
#include "game.h"

int counter = 0;

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
        .top_left = {200, 200},
        .top_right = {400, 200},
        .bottom_left = {200, 300},
        .bottom_right = {400, 300},
        .center = {300, 250}, // will make a function to calculate this at some point
        .visible = 1
    };
    
    // tmp square to test the line following alg
    Coordinate top_left = {
        .x = 295, 
        .y = 195
    };

    const int dimension = 11;


    while(game_manager.is_running == 0) {
        handle_events(&game_manager, &rc);
        update(&game_manager, &rc, &counter, &top_left, dimension, grid);
        render(&game_manager, &rc, grid, &top_left, dimension);
       

       


    }


   

    return 0;
}

