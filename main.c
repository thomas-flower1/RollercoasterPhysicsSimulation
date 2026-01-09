#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "Rollercoaster Physics Simulator"


typedef struct GameManager{
    SDL_Window *window; // a window pointer
    SDL_Renderer *renderer;
    int is_running;


} GameManager;

typedef struct Colour{
    int r;
    int g;
    int b;
    int alpha;

} Colour;




int create_window(GameManager *game_manager);
void handle_events(GameManager *game_manager);
void colour_init(Colour *colour);


int main() {
    GameManager game_manager;
    
    if (create_window(&game_manager) == 1) {
        return 1;

    }

    // now we can say that the game is running
    game_manager.is_running = 0;

    while(game_manager.is_running == 0) {

        handle_events(&game_manager);

        SDL_SetRenderDrawColor(game_manager.renderer, 255, 0, 0, 255);

        SDL_RenderClear(game_manager.renderer);

        SDL_RenderPresent(game_manager.renderer);

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

void handle_events(GameManager *game_manager) {
    SDL_Event event;
    SDL_PollEvent(&event); // get the current event
    switch (event.type)
    {
    case SDL_QUIT:
        game_manager->is_running = -1;
        break;
        
        
    
    default:
        break;
    }



}
