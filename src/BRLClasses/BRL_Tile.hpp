#ifndef H_BRL_TILE
#define H_BRL_TILE

#include "BRL_Unit.hpp"

class BRL_Tile : public BRL_Unit {
public:
	BRL_Tile();
	BRL_Tile(int moveValue);
	BRL_Tile(int moveValue, int xPos, int yPos, int zIndex);
	BRL_Tile(int moveValue, int xPos, int yPos, int zIndex, SDL_Surface& bitmap);
	~BRL_Tile();

	int getMoveValue() const;
	void setMoveValue(int moveValue);
	bool isImpassable();

private:
	int moveValue;
};

#endif
