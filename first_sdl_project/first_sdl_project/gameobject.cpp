#include "gameobject.h"

GameObject::GameObject( )
{  
    surface = NULL;

    offset.x = 0;   offset.y = 0;
    pos.x = 0;      pos.y = 0;
    vel.x = 0;      vel.y = 0;
    acc.x = 0;      acc.y = 0;

    dir.up = false;
    dir.down = false;
    dir.left = false;
    dir.right = false;
}

GameObject::~GameObject( )
{
 
}

void GameObject::shutdown( )
{
    SDL_FreeSurface( surface );
}

void GameObject::Update( SDL_Surface* screen )
{
    offset.x = pos.x;
    offset.y = pos.y;   

    // arrow input
    if( dir.up == true )
        pos.y -= 3;

    if( dir.down == true )
        pos.y += 3;

    if( dir.left == true )
        pos.x -= 3;

    if( dir.right == true )
        pos.x += 3;

    SDL_BlitSurface( surface, NULL, screen, &offset );

}

void GameObject::setImage( string filename )
{
    surface = IMG_Load( filename.c_str( ) );

    if( surface != NULL )
    {
        SDL_Surface* optimizedImage = SDL_DisplayFormat( surface );
        SDL_FreeSurface( surface );
        surface = optimizedImage;
    }
}
 
void GameObject::setX( int val )
{
    pos.x = val;
}

void GameObject::setY( int val )
{
    pos.y = val;
}

void GameObject::setDirUp( bool d )
{
    dir.up = d;
}

void GameObject::setDirDown( bool d )
{
    dir.down = d;
}

void GameObject::setDirLeft( bool d )
{
    dir.left = d;
}

void GameObject::setDirRight( bool d )
{
    dir.right = d;
}

bool GameObject::collision( GameObject* other )
{
	if( ( this->pos.x <= other->pos.x && other->pos.x <= this->pos.x + this->surface->w ) && 
		( this->pos.y <= other->pos.y && other->pos.y <= this->pos.y + this->surface->h ) ) {
        return true;
    }

	if( ( this->pos.x <= other->pos.x && other->pos.x <= this->pos.x + this->surface->w ) && 
		( this->pos.y <= other->pos.y + other->surface->h && other->pos.y + other->surface->h <= this->pos.y + this->surface->h ) ) {
        return true;
    }

	if( ( this->pos.x <= other->pos.x + other->surface->w && other->pos.x + other->surface->w <= this->pos.x + this->surface->w ) && 
		( this->pos.y <= other->pos.y && other->pos.y <= this->pos.y + this->surface->h ) ) {
        return true;
    }

	if( ( this->pos.x <= other->pos.x + other->surface->w && other->pos.x + other->surface->w <= this->pos.x + this->surface->w ) && 
		( this->pos.y <= other->pos.y + other->surface->h && other->pos.y + other->surface->h <= this->pos.y + this->surface->h ) ) {
        return true;
    }

    return false;
}

void GameObject::switchVel( )
{
}

Vector2* GameObject::GetPos( ) {
	return &pos;
}