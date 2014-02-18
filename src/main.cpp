/* Basic Roguelike by Sam Judge
Project contains classes needed to create a basic graphical roguelike
last edited 18/02/2014
*/

#include "SDL2/SDL.h"
#include <stdio.h>
#include "BRLClasses/BRL_Map.hpp"
#include "HRLClasses/HRL_MapGenerator.hpp"


const char a = 219;
const char b = 0;

void printBRLMapAsChars(){
	int mapWidth = 64;
	int mapHeight = 64;
	BRL_Map gameMap(mapWidth, mapHeight);
	gameMap.setMapTilesList(HRL_MapGenerator::getInstance()->generateMap(gameMap.getMaxWidth(), gameMap.getMaxHeight()));
	printf("\n");
	for (int y = 0 ; y < mapHeight; y++){
		for (int x = 0 ; x < mapWidth; x++){
			char valueToPrint = gameMap.getMapTilesList()->at((gameMap.getMaxWidth()*y)+x).getMoveValue();
			(valueToPrint == 0)?valueToPrint=a:valueToPrint=b;
			printf("%c", (char*)valueToPrint );
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]){
   //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    printBRLMapAsChars();

    //Quit SDL
    SDL_Quit();

	return 0;
}


