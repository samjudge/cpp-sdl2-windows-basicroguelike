#ifndef H_BRL_UNIT
#define H_BRL_UNIT

#include "BRL_Position.hpp"

#include <SDL2/sdl.h>

class BRL_Unit {
public:
	SDL_Surface* getBitmap();
	BRL_Position* getPos();
	void setBitmap(SDL_Surface *bitmap);
	void setPos(BRL_Position *pos);
protected:
	BRL_Unit();
	BRL_Unit(int xPos, int yPos, int zIndex);
	BRL_Unit(int xPos, int yPos, int zIndex, SDL_Surface& bitmap);
	~BRL_Unit();
private:
	BRL_Position* pos;
	SDL_Surface* bitmap; //the image used
};

#endif
