#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 660;

bool init();
bool loadMedia();
void close();

SDL_Window *gWindow = NULL;
SDL_Surface *gSurface = NULL;
SDL_Surface *helloWorld = NULL;

int main()
{
    if(!init())
    {
        printf("Fail\n");
    }
    else
    {
        if(!loadMedia())
        {
            printf("Fail\n");
        }
        else
        {
            SDL_BlitSurface( helloWorld, NULL, gSurface, NULL );
            SDL_UpdateWindowSurface(gWindow);
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    close();
    return 0;
}

bool init()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf("Something has gone wrong, the issue might be %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if(gWindow == NULL)
        {
            printf("ERROR: %s", SDL_GetError());
            success = false;
        }
        else
        {
             gSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;
    helloWorld = SDL_LoadBMP( "image.bmp" );
    if(helloWorld == NULL)
    {
        printf("ERROR: %s", SDL_GetError());
        success = false;
    }

    return success;
}


void close()
{
    SDL_FreeSurface( helloWorld );
    helloWorld = NULL;

    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    SDL_Quit();
}