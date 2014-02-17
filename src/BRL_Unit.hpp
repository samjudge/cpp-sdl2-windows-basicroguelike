#include <SDL2/SDL.h>
#include "BRL_Position.cpp"

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
