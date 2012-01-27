#include <iostream>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "defines.h"
#include "macros.h"
#include "treegenerator.h"
#include "utils.h"

#include "mymath.h"

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
        while ( SDL_PollEvent( &event ) )
        {
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
                case SDLK_SPACE:
                    cTreeGenerator::getInstance()->colonize();
                    break;
            }
        }
        
        SDL_Delay( getTimeLeft() ); // delay the rendering loop
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
