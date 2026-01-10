#include "main.h"


void render(GameManager *game_manager, Rollercoaster *rc, int grid[][SCREEN_WIDTH]) {
    SDL_SetRenderDrawColor(game_manager->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game_manager->renderer); // fills the screen with this colour
    SDL_SetRenderDrawColor(game_manager->renderer, white.r, white.g, white.b, white.alpha);

    /* 
    
    Add things to render here
    
    */



    // draw all the pixels from the grid - for now this is just the circle
    for(int i = 0; i < SCREEN_HEIGHT; i++) {
        for(int j = 0; j < SCREEN_WIDTH; j++) {
            if(grid[i][j] == 1) {
                SDL_RenderDrawPoint(game_manager->renderer, i, j); // draw a single pixel
            }

        }
    }

    

    SDL_RenderPresent(game_manager->renderer); // update the screen 


}