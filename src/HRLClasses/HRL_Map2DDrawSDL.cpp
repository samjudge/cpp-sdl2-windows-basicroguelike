#include "HRL_Map2DDrawSDL.hpp"
#include <sdl2/sdl.h>

#define TILE_SIZE 16;


HRL_Map2DDrawSDL::HRL_Map2DDrawSDL(SDL_Window *window, int maxWidth, int maxHeight) : BRL_Map(maxWidth, maxHeight){
	this->window = window;
	this->windowHeight = this->getMaxHeight() * TILE_SIZE;
	this->windowWidth = this->getMaxWidth() * TILE_SIZE;
}

HRL_Map2DDrawSDL::HRL_Map2DDrawSDL(SDL_Window *window, std::vector<BRL_Tile> mapTilesList, int maxWidth, int maxHeight) : BRL_Map(mapTilesList, maxWidth, maxHeight){
	this->window = window;
	this->windowHeight = 16 * this->getMaxHeight();
	this->windowWidth = 16 * this->getMaxWidth();
}

HRL_Map2DDrawSDL::~HRL_Map2DDrawSDL(){

}

void HRL_Map2DDrawSDL::draw2DMapSDL(){
	//load resources - note this will be handled by a factory class that loads from xml in the future
	SDL_Surface* wallSurface = SDL_LoadBMP("./res/images/blackwalltile.bmp");
	SDL_Surface* floorSurface = SDL_LoadBMP("./res/images/mudfloortile.bmp");
	//endload

	if (wallSurface == NULL || floorSurface == NULL){
		printf("Something went wrong loading surfaces\n");
		return;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,0);
	SDL_SetRenderDrawColor(renderer,0,0,0,255); //RGBA
    //SDL_RenderClear(renderer);

    printf("screen clear\n");

	for (int y = 0 ; y < this->getMaxHeight(); y++){
		for (int x = 0 ; x < this->getMaxWidth(); x++){

			BRL_Tile tileToDraw = getMapTilesList()->at((getMaxWidth()*y)+x); //I should probably change the name of moveValue to something else, as it's use is different than named

			//at this point, the resource manager would look up what resources the BRL_Tile to draw needs and assign them to the BRL_Tile, without the below switch/case/if block. Also this would be done during the creation of the Tile (In HRL_MapGenerator)

			switch(tileToDraw.getMoveValue()){
			case 0:
				tileToDraw.setBitmap(wallSurface);
				break;
			case 1:
				tileToDraw.setBitmap(floorSurface);
				break;
			}

			SDL_Rect* pos;
			pos->x = x * TILE_SIZE;
			pos->y = y * TILE_SIZE;
			pos->w = TILE_SIZE;
			pos->h = TILE_SIZE;

			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tileToDraw.getBitmap());

			if(texture == NULL){
				printf("Something went wrong creating the texture\n");
				return;
			}

			SDL_RenderCopy(renderer, texture, NULL, pos);



		}
	}

	SDL_RenderPresent(renderer);


}
