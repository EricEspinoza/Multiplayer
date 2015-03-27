#include "gamemanager.h"

GameManager*	GameManager::instance = NULL;

GameManager::GameManager( )
{
    SDL_Init( SDL_INIT_EVERYTHING );
	instance = this;
}

GameManager::~GameManager( )
{
    SDL_Quit( );
}

void GameManager::init( )
{
	network = new Network();
	network->ConnectionType();

	if( network->isServer )
		controlledPlayer = 1;
	else
		controlledPlayer = 2;

    // this is where you load the stuff for your lvl
     screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

     objs.resize( 3 );
     objs[0].setImage( "images/grass.jpg" );
     objs[0].setX( 0 );
     objs[0].setY( 0 );
     objs[1].setImage( "images/hello.bmp" );
     objs[1].setX( 0 );
     objs[1].setY( 0 );
     objs[2].setImage( "images/bleh.gif" );
     objs[2].setX( 300 );
     objs[2].setY( 100 );

	 network->Init();
}

bool GameManager::update( )
{
    // key listener
    if( !keyUpdate( ) )
        return false;


    SDL_FillRect( screen, NULL, 0 );

	objs[1].Update(screen);
	objs[2].Update(screen);

    SDL_Flip( screen );

    return true;
}

void GameManager::pause( )
{
    SDL_Delay( 20 );
}

void GameManager::shutdown( )
{
    for( int i = 0; i < objs.size(); i++ )
    {
        objs[i].shutdown( );
    }
}

bool GameManager::keyUpdate( )
{
    SDL_Event key_event;
    while( SDL_PollEvent( &key_event ) )
    {
        switch( key_event.type )
        {
        case SDL_QUIT:
            return false;
            break;

        case SDL_KEYDOWN:
            if( key_event.key.keysym.sym == SDLK_ESCAPE )
                return false;

            if( key_event.key.keysym.sym == SDLK_UP )
                objs[controlledPlayer].setDirUp( true );
            if( key_event.key.keysym.sym == SDLK_DOWN )
                objs[controlledPlayer].setDirDown( true );
            if( key_event.key.keysym.sym == SDLK_LEFT )
                objs[controlledPlayer].setDirLeft( true );
            if( key_event.key.keysym.sym == SDLK_RIGHT )
                objs[controlledPlayer].setDirRight( true );
            break;
    
        case SDL_KEYUP:
            if( key_event.key.keysym.sym == SDLK_UP  )
                objs[controlledPlayer].setDirUp( false );
            if( key_event.key.keysym.sym == SDLK_DOWN )
                objs[controlledPlayer].setDirDown( false );
            if( key_event.key.keysym.sym == SDLK_LEFT )
                objs[controlledPlayer].setDirLeft( false );
            if( key_event.key.keysym.sym == SDLK_RIGHT )
                objs[controlledPlayer].setDirRight( false );
            break;

        case SDL_MOUSEMOTION:
            //objs[0].setX( key_event.motion.x );
            //objs[0].setY( key_event.motion.y );
            break;

        case SDL_MOUSEBUTTONDOWN:
            break;

        case SDL_MOUSEBUTTONUP:
            break;
        }
    }
    return true;
}