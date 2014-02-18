#include "BRL_Map.hpp"



BRL_Map::BRL_Map(int maxWidth, int maxHeight){
	mapTilesList = new std::vector<BRL_Tile>(0);
	this->maxHeight = maxHeight;
	this->maxWidth = maxWidth;
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
	//debug
	//printf("\nvalue : %d\n", this->mapTilesList->size());
	//printf("\nexpected: %d\n", 0);
	//int i = 0;
	//endbug
	for(mapTilesConstIterator = mapTilesList.begin(); mapTilesConstIterator != mapTilesList.end(); ++mapTilesConstIterator){
		//debug
		//if (i%maxWidth == 0) printf("\n");
		//printf("%c",mapTilesConstIterator->getMoveValue());
		//i++;
		//endbug

		this->mapTilesList->push_back(*mapTilesConstIterator);
	}
	//debug
	//printf("\nvalue : %d\n", this->mapTilesList->size());
	//printf("\nexpected: %d\n", this->getMaxHeight()*this->getMaxWidth());
	//endbug
}

int BRL_Map::getMaxHeight(){
	return maxHeight;
}

int BRL_Map::getMaxWidth(){
	return maxWidth;
}
