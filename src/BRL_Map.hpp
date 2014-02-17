#include "BRL_Tile.hpp"

#include <list>

class BRL_Map {
public:
	BRL_Map();

	BRL_Map(std::list<BRL_Tile> mapTilesList);

	std::list<BRL_Tile>* getMapTilesList();

	void setMapTilesList(std::list<BRL_Tile> mapTilesList);

protected:

private:
	std::list<BRL_Tile>* mapTilesList;

};


