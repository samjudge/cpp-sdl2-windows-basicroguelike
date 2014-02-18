#include "..\constants.hpp"
#include "BRL_Tile.hpp"

BRL_Tile::BRL_Tile(int moveValue, int xPos, int yPos, int zIndex, SDL_Surface& bitmap) : BRL_Unit(xPos, yPos, zIndex, bitmap){
	this->moveValue = moveValue; //like wtf BRL_Tile(moveValue) causes shadow param error
}

BRL_Tile::BRL_Tile(int moveValue, int xPos, int yPos, int zIndex) : BRL_Unit(xPos, yPos, zIndex){
	this->moveValue = moveValue;
}

BRL_Tile::BRL_Tile(int moveValue) : BRL_Unit(){
	this->moveValue = moveValue;
}

BRL_Tile::BRL_Tile() : BRL_Unit(){
	BRL_Tile(IMPASSIBLE_TILE_M_VALUE);
}

BRL_Tile::~BRL_Tile(){
}

int BRL_Tile::getMoveValue() const{
	return moveValue;
}

void BRL_Tile::setMoveValue(int moveValue){
	this->moveValue = moveValue;
}

bool BRL_Tile::isImpassable(){
	if (moveValue == IMPASSIBLE_TILE_M_VALUE) return true;
	return false;
}
