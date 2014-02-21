#include "BRL_Map.hpp"
#include "BRL_Player.hpp"


BRL_Map::BRL_Map(int maxWidth, int maxHeight){
	mapTilesList = new std::vector<BRL_Tile>(0);
	this->maxHeight = maxHeight;
	this->maxWidth = maxWidth;

	//debug
	//this->player = new BRL_Player(); //move to BRL_Context when multiple levels
	//enddebug
}

BRL_Map::BRL_Map(std::vector<BRL_Tile> mapTilesList, int maxWidth, int maxHeight){
	BRL_Map(maxWidth, maxHeight);
	setMapTilesList(mapTilesList);
}

BRL_Map::~BRL_Map(){

}

std::vector<BRL_Tile>* BRL_Map::getMapTilesList(){
	return mapTilesList;
}

void BRL_Map::setMapTilesList(std::vector<BRL_Tile> mapTilesList){
	this->mapTilesList->clear();
	std::vector<BRL_Tile>::const_iterator mapTilesConstIterator;
	for(mapTilesConstIterator = mapTilesList.begin(); mapTilesConstIterator != mapTilesList.end(); ++mapTilesConstIterator){
		this->mapTilesList->push_back(*mapTilesConstIterator);
	}
}

int BRL_Map::getMaxHeight(){
	return maxHeight;
}

int BRL_Map::getMaxWidth(){
	return maxWidth;
}

void BRL_Map::setPlayer(BRL_Player* player){
	this->player = player;
}


BRL_Player* BRL_Map::getPlayer(){
	return player;
}
