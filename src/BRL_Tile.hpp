#include "BRL_Unit.hpp"

class BRL_Tile : public BRL_Unit {
public:
	BRL_Tile();
	BRL_Tile(int xPos, int yPos, int zIndex);
	BRL_Tile(int xPos, int yPos, int zIndex, SDL_Surface& bitmap);
	~BRL_Tile();
};

