#include <vector>
#include "gameobject.h"
#include "Network.h"

#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

class GameManager
{
public:
    GameManager( );
    ~GameManager( );

    void init( );
    bool update( );
    void pause( );
    void shutdown( );

    bool keyUpdate( );

	static GameManager* instance;
	std::vector<GameObject> objs;

private:    
    SDL_Surface *screen;
	Network *network;

	int controlledPlayer;
};

#endif