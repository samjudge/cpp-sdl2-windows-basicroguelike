/* Basic Roguelike by Sam Judge
Project contains classes needed to create a basic graphical roguelike
last edited 18/02/2014
*/

#include "SDL2/SDL.h"
#include <stdio.h>
#include "BRLClasses/BRL_Map.hpp"
#include "HRLClasses/HRL_MapGenerator.hpp"
#include "HRLClasses/HRL_Map2DDrawSDL.hpp"
#include "HRLClasses/HRL_EventHandler.hpp"
#include "constants.hpp"

const int MAP_WIDTH = 32;
const int MAP_HEIGHT = 32;
const int SCREEN_WIDTH = 27 * MAP_WIDTH;
const int SCREEN_HEIGHT = 27 * MAP_HEIGHT;


void printBRLMapAsChars(BRL_Map gameMap){
	printf("\n");
	for (int y = 0 ; y < MAP_HEIGHT; y++){
		for (int x = 0 ; x < MAP_WIDTH; x++){
			char valueToPrint = gameMap.getMapTilesList()->at((gameMap.getMaxWidth()*y)+x).getMoveValue();
			(valueToPrint == 0)?valueToPrint=219:valueToPrint=0;
			printf("%c", (char*)valueToPrint );
		}
		printf("\n");
	}
}

void initGameMap(BRL_Map& gameMap){
	gameMap.setMapTilesList(HRL_MapGenerator::getInstance()->generateMap(gameMap));
}

int main(int argc, char *argv[]){
   //Start SDL
    if (SDL_Init( SDL_INIT_EVERYTHING ) == -1){
    	return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Hi World", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL); //replace 0,0 with screen height/width if I must
    BRL_Map* gameMap = new BRL_Map(MAP_WIDTH,MAP_HEIGHT);
    HRL_EventHandler* eventHandler =  HRL_EventHandler::getInstance();


    HRL_Map2DDrawSDL* gameMapDrawable = new HRL_Map2DDrawSDL(gameMap, window);

    if (window == NULL){
    	printf("something went wrong making the window");
    }

    initGameMap(*gameMap); //create random map

    while(eventHandler->handleEventLoop(gameMap)){
        gameMapDrawable->draw2DMapSDL(); //draw the map while we do not quit
        printf("game loop");
    }

    //printBRLMapAsChars();

    //Quit SDL
    SDL_Quit();

	return 0;
}


