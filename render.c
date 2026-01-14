#include "game.h"
#include "render.h"
#include "drawing.h"


void render(GameManager *game_manager, Rollercoaster *rc, int grid[][SCREEN_WIDTH]) {
    SDL_SetRenderDrawColor(game_manager->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game_manager->renderer); // fills the screen with this colour

    Colour WHITE = {
        .r = 255,
        .g = 255,
        .b = 255,
        .alpha = 255,
};  


    SDL_SetRenderDrawColor(game_manager->renderer, WHITE.r, WHITE.g, WHITE.b, WHITE.alpha);

    /* 
    
    Add things to render here
    
    */

    draw_rollercoaster(rc, game_manager);
  




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