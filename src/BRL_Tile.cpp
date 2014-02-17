#include "BRL_Tile.hpp"

BRL_Tile::BRL_Tile(int xPos, int yPos, int zIndex, SDL_Surface& bitmap) : BRL_Unit(xPos, yPos, zIndex, bitmap){
}

BRL_Tile::BRL_Tile(int xPos, int yPos, int zIndex) : BRL_Unit(xPos, yPos, zIndex){

}

BRL_Tile::BRL_Tile() : BRL_Unit(){
}

BRL_Tile::~BRL_Tile(){
}
