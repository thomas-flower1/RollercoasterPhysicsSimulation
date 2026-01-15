#include "events.h"

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