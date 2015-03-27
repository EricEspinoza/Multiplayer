#include "SDL.h"
#include "SDL_Image.h"
#include <string>

using std::string;

#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

struct Vector2
{
    float x;
    float y;
};

struct Direction
{
    bool up, down, left, right;
};

struct AABB
{
    int x, y, w, h;
};

class GameObject
{
public:
    GameObject( );
    ~GameObject( );

    void Update( SDL_Surface* );
    void setImage( string );
    void shutdown( );

    void setX( int );
    void setY( int );

    void setDirUp( bool );      void setDirDown( bool );
    void setDirLeft( bool );    void setDirRight( bool );

    bool collision( GameObject* other );
    void switchVel( );

	Vector2* GetPos( );

private:
    SDL_Rect offset;
    SDL_Surface* surface;

    Vector2 pos;
    Vector2 vel;
    Vector2 acc;
    Direction dir;
};

#endif