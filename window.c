#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdbool.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;

int main(int argc, char **argv)
{
    SDL_Window * window = NULL;
    SDL_Surface * screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        printf("Did not work\n");
    }
    else
    {
        window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL)
        {
            printf("Did not work\n");
        }
        else
        {
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect ( screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x11, 0xFF));
            SDL_UpdateWindowSurface( window );
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}