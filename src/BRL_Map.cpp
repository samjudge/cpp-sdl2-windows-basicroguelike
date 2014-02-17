#include<list>
#include "BRL_Map.hpp"

BRL_Map::BRL_Map(){
	mapTilesList = new std::list<BRL_Tile>();
}

BRL_Map::BRL_Map(std::list<BRL_Tile> mapTilesList){
	BRL_Map();
	setMapTilesList(mapTilesList);
}

std::list<BRL_Tile>* BRL_Map::getMapTilesList(){
	return mapTilesList;
}

void BRL_Map::setMapTilesList(std::list<BRL_Tile> mapTilesList){
	this->mapTilesList->clear();
	std::list<BRL_Tile>::const_iterator mapTilesConstIterator;
	for(mapTilesConstIterator = mapTilesList.begin(); mapTilesConstIterator != mapTilesList.end(); ++mapTilesConstIterator){
		this->mapTilesList->push_back(*mapTilesConstIterator);
	}
}
