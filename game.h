#ifndef GAME_H
#define GAME_H

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


typedef struct Coordinate {
    int x;
    int y;

} Coordinate;


typedef struct Rollercoaster {
    Coordinate top_right;
    Coordinate top_left;
    Coordinate bottom_right;
    Coordinate bottom_left;
    int visible;


} Rollercoaster;

int create_window(GameManager *game_manager);
    

#endif