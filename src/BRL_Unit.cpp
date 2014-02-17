#include "BRL_Unit.hpp"

BRL_Unit::BRL_Unit(int xPos, int yPos, int zIndex, SDL_Surface& bitmap){
	pos = new BRL_Position();
	this->pos->xPos = xPos;
	this->pos->yPos = yPos;
	this->pos->zIndex = zIndex;
	this->bitmap = &bitmap;
}

BRL_Unit::BRL_Unit(int xPos, int yPos, int zIndex){
	BRL_Unit(xPos, yPos, zIndex, *(new SDL_Surface()));
}

BRL_Unit::BRL_Unit(){
	BRL_Unit(0, 0, 0);
}

BRL_Unit::~BRL_Unit(){

}
