#include "main.h"


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
        .visible = 0
    };
    



    while(game_manager.is_running == 0) {
        handle_events(&game_manager, &rc);
        render(&game_manager, &rc, grid);
        update(&game_manager, &rc);


    }


   

    return 0;
}

int create_window(GameManager *game_manager) {
    /*
    Function that initializes SDL and creates a window and renderer. Assigns these pointers to the game manager
    
    */


    // initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return 1;


    }
    fprintf(stderr, "SDL ran successfully\n");

    // now lets create a window
    game_manager->window = SDL_CreateWindow("Rollercoaster Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(game_manager->window == NULL) {
        fprintf(stderr, "SDL window error %s\n", SDL_GetError());
        return 1;

    }

    // now lets create the renderer
    game_manager->renderer = SDL_CreateRenderer(game_manager->window, -1, 0);
    if(game_manager->renderer == NULL) {
        fprintf(stderr, "SDL render error: %s\n", SDL_GetError());
        return 1;
    }




    return 0;


}









