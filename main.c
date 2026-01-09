#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
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


typedef struct Rollercoaster {
    int x;
    int y;
    int width;
    int height;
    int visible;


} Rollercoaster;


int create_window(GameManager *game_manager);
void handle_events(GameManager *game_manager, Rollercoaster *rc);
void render(GameManager *game_manager, Rollercoaster *rc, int grid[][SCREEN_WIDTH]);
void update(GameManager *game_manager, Rollercoaster *rc);
void draw_circle(int cx, int cy, int r, int grid[][SCREEN_WIDTH], int arc);
void draw_rollercoaster(Rollercoaster *rc, GameManager *game_manager);



int main() {
    GameManager game_manager;
    int grid[SCREEN_HEIGHT][SCREEN_WIDTH] = {0}; // initialize an array of 0s for each pixel on the screen;

    // draw a circle
    draw_circle(200, 200, 100, grid, 0); // 0 means draw an arc

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

    // initialize the rollercoaster
    Rollercoaster rc = {
        .x = 100,
        .y = 100,
        .width = 20,
        .height = 10,
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

void handle_events(GameManager *game_manager, Rollercoaster *rc) {
    SDL_Event event;
    SDL_PollEvent(&event); // get the current event

    int pressed = 0;

    switch (event.type)
    {
    case SDL_QUIT:
        game_manager->is_running = -1;
        break;
    
    case SDL_MOUSEBUTTONDOWN:
        pressed = 1;
        break;
    
    default:
        break;
    }


    if (pressed) {
        // make the rollercoaster visible
        rc->visible = 1;
        
    }




}

void render(GameManager *game_manager, Rollercoaster *rc, int grid[][SCREEN_WIDTH]) {
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

    // draw all the pixels from the grid - for now this is just the circle
    for(int i = 0; i < SCREEN_HEIGHT; i++) {
        for(int j = 0; j < SCREEN_WIDTH; j++) {
            if(grid[i][j] == 1) {
                SDL_RenderDrawPoint(game_manager->renderer, i, j); // draw a single pixel
            }


        }
    }

    // draw the rollercoaster
    draw_rollercoaster(rc, game_manager);


    

    SDL_RenderPresent(game_manager->renderer); // update the screen 
}

void update(GameManager *game_manager, Rollercoaster *rc){
    if(rc->visible) {
        rc->x -= 1;
    }
    

}


void draw_circle(int cx, int cy, int r, int grid[][SCREEN_WIDTH], int arc){
    /*
    
    function that assigns 1s to the circls staring at the center. We are using the midpoint circle algorithm
    
    */


    int x = 0;
    int y = -r;

    while(x < -y) {
        double y_mid = y + 0.5;

        if(x * x + y_mid * y_mid > r * r) {
            y++;

        }

        grid[cx - x][cy + y] = 1;
        grid[cx + y][cy - x] = 1;

        if (arc){
            grid[cx + x][cy + y] = 1;
            grid[cx + x][cy - y] = 1;
            grid[cx - x][cy - y] = 1;
            grid[cx + y][cy + x] = 1;
            grid[cx - y][cy + x] = 1;
            grid[cx - y][cy - x] = 1;

        }

        // grid[cx + x][cy + y] = 1;
        // grid[cx - x][cy + y] = 1;
        // grid[cx + x][cy - y] = 1;
        // grid[cx - x][cy - y] = 1;
        // grid[cx + y][cy + x] = 1;
        // grid[cx - y][cy + x] = 1;
        // grid[cx + y][cy - x] = 1;
        // grid[cx - y][cy - x] = 1;
        
        x++;

    }
   
    // also need to modify so that it can draw an arc when requested




}

void draw_rollercoaster(Rollercoaster *rc, GameManager *game_manager) {
    for(int i = rc->y; i < rc->y + rc->height; i++) {
        for(int j = rc->x; j < rc->x + rc->width; j++) {
            SDL_RenderDrawPoint(game_manager->renderer, j, i); // draw a single pixel


        }
    }


}