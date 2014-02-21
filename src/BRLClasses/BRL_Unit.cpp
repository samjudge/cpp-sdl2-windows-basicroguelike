#include "BRL_Unit.hpp"

BRL_Unit::BRL_Unit(int xPos, int yPos, int zIndex, SDL_Surface& bitmap){
	pos = new BRL_Position();
	this->pos->xPos = xPos;
	this->pos->yPos = yPos;
	this->pos->zIndex = zIndex;
	this->bitmap = &bitmap;
}

BRL_Unit::BRL_Unit(int xPos, int yPos, int zIndex){
	pos = new BRL_Position();
	this->pos->xPos = xPos;
	this->pos->yPos = yPos;
	this->pos->zIndex = zIndex;
}

BRL_Unit::BRL_Unit(){
	pos = new BRL_Position();
	this->pos->xPos = 0;
	this->pos->yPos = 0;
	this->pos->zIndex = 0;
}

BRL_Unit::~BRL_Unit(){
}

SDL_Surface* BRL_Unit::getBitmap(){
	return bitmap;
}

BRL_Position* BRL_Unit::getPos(){
	return pos;
}

void BRL_Unit::setBitmap(SDL_Surface *bitmap){
	this->bitmap = bitmap;
}

void BRL_Unit::setPos(BRL_Position *pos){
	this->pos = pos;
}
