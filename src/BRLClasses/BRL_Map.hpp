#ifndef H_BRL_MAP
#define H_BRL_MAP

#include <vector>
#include "BRL_Tile.hpp"
#include "BRL_Creature.hpp"
#include "BRL_Player.hpp"

class BRL_Map {
public:
	BRL_Map(int maxWidth, int maxHeight);
	BRL_Map(std::vector<BRL_Tile> mapTilesList, int maxWidth, int maxHeight);
	~BRL_Map();

	std::vector<BRL_Tile>* getMapTilesList();
	void setMapTilesList(std::vector<BRL_Tile> mapTilesList);
	int getMaxWidth();
	int getMaxHeight();

	BRL_Player* getPlayer();
	void setPlayer(BRL_Player* player);

protected:

private:
	std::vector<BRL_Tile>* mapTilesList;

	BRL_Player* player;

	int maxWidth; //in tiles
	int maxHeight; //^^
};

#endif
