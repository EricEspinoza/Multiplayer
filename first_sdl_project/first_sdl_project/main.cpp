#include "SDL.h"
#include "gamemanager.h"

int main( int argc, char* args[] )
{
    GameManager gm;
    gm.init( );

    while( gm.update( ) )
    {
        gm.pause( );
    }

    gm.shutdown( );

    return 0;
}