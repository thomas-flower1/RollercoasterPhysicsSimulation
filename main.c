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
void render(GameManager *game_manager);
void update(GameManager *game_manager);


int main() {
    GameManager game_manager;
    int grid[SCREEN_WIDTH][SCREEN_HEIGHT] = {0}; // initialize an array of 0s for each pixel on the screen;




    if (create_window(&game_manager) == 1) {
        return 1;

    }

    // now we can say that the game is running
    game_manager.is_running = 0;


    Colour black = {
        .r = 0,
        .g = 0,
        .b = 0,
        .alpha = 255,

    };
    



    while(game_manager.is_running == 0) {
        handle_events(&game_manager);
        render(&game_manager);


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

    int pressed = 1;

    switch (event.type)
    {
    case SDL_QUIT:
        game_manager->is_running = -1;
        break;
    
    case SDL_MOUSEBUTTONDOWN:
        pressed = 0;
        break;
    
    default:
        break;
    }

    // if the button is pressed, print the coord until we release the mouse button

    // make this a separate thread ?
    while(pressed == 0) {

        // exit condition
        SDL_PollEvent(&event);
        if(event.type == SDL_MOUSEBUTTONUP) {
            pressed = 1;
        }

        int x, y;
        SDL_GetMouseState(&x, &y);
        printf("Mouse button clicked at pos: %d, %d\n", x, y);

        
    }

  


}

void render(GameManager *game_manager) {
    SDL_SetRenderDrawColor(game_manager->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game_manager->renderer); // fills the screen with this colour

    /* 

    add things to render here
    
    */

    Colour white = {
        .r = 255,
        .g = 255,
        .b = 255,
        .alpha = 255,
    };

    SDL_SetRenderDrawColor(game_manager->renderer, white.r, white.g, white.b, white.alpha);
    SDL_RenderDrawPoint(game_manager->renderer, 100, 100); // draw a single pixel

    SDL_RenderPresent(game_manager->renderer); // update the screen 
}

void update(GameManager *game_manager){

}

