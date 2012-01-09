#include <iostream>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "defines.h"
#include "treegenerator.h"

void init()
{
    SDL_Init( SDL_INIT_VIDEO );
    if ( SDL_SetVideoMode( SCREEN_W, SCREEN_H, 32, SDL_OPENGL ) == NULL )
    {
        std::cerr << "Can't init SDL window." << std::endl;
        exit( EXIT_FAILURE );
    }
    SDL_WM_SetCaption( SCREEN_TITLE, NULL );

    srand( time(NULL) ); // initialize rand seed
    cTreeGenerator::getInstance()->init();
}

void display()
{
    bool loop = true;
    SDL_Event   event;
    while ( loop == true )
    {
        glClear( GL_COLOR_BUFFER_BIT );

        // rendering
        cTreeGenerator::getInstance()->renderOneFrame();

        // flushing screen
        glFlush();
        SDL_GL_SwapBuffers();

        // catching events
        SDL_WaitEvent( &event );

        switch( event.type ) // screen events
        {
            case SDL_QUIT:
                loop = false;
                break;
        }

        switch( event.key.keysym.sym ) // keyboard events
        {
            case SDLK_ESCAPE:
                loop = false;
                break;
        }
    }
    
    cTreeGenerator::killInstance();
    SDL_Quit();
}

int main(int ac, char **av)
{
    init();
    display();
    return EXIT_SUCCESS;
}
