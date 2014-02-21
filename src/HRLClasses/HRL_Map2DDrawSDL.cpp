#include "HRL_Map2DDrawSDL.hpp"
#include "../constants.hpp"
#include <sdl2/sdl.h>
#include <stdio.h>

#define TILE_SIZE 27; //27



HRL_Map2DDrawSDL::HRL_Map2DDrawSDL(BRL_Map* map, SDL_Window *window){
	this->window = window;
	this->map = map;
	this->renderer = SDL_CreateRenderer(window, -1,0); //SUPER SLOW, move out of this loop, into the constructor or something
}

HRL_Map2DDrawSDL::~HRL_Map2DDrawSDL(){
	SDL_DestroyRenderer(renderer); //<-This solved my issue for double loading texture. Apparently it's one window one renderer. Also yeah, major slowdown, move to deconstructor
}

void HRL_Map2DDrawSDL::draw2DMapSDL(){
	//TESTING ONLY
	srand(time(NULL));
	//ENDTESTING
	SDL_SetRenderDrawColor(renderer,0,0,0,255); //RGBA
    SDL_RenderClear(renderer);

	//load resources - note this will be handled by a factory class that loads from xml in the future
	SDL_Surface* wallSurface = SDL_LoadBMP("./res/images/blackwalltile.bmp");
	SDL_Surface* floorSurface = SDL_LoadBMP("./res/images/mudfloortile.bmp");
	SDL_Surface* spriteSheet = SDL_LoadBMP("./res/images/sprites1.bmp");
	Uint32 spriteSheetColorKey = SDL_MapRGB(spriteSheet->format, 0xFF,0xFF,0xFF);
	SDL_SetColorKey(spriteSheet, 1, spriteSheetColorKey);
	SDL_Texture* spriteSheetTexture = SDL_CreateTextureFromSurface(renderer, spriteSheet);
	SDL_Rect* dst = new SDL_Rect();
	SDL_Rect* src = new SDL_Rect();
	//endload

	if (wallSurface == NULL || floorSurface == NULL || spriteSheet == NULL){
		printf("Something went wrong loading surfaces\n");
		return;
	}



    printf("screen clear\n");

	//draw the tiles
	for (int y = 0 ; y < map->getMaxHeight(); y++){
		for (int x = 0 ; x < map->getMaxWidth(); x++){

			BRL_Tile tileToDraw = map->getMapTilesList()->at((map->getMaxWidth()*y)+x);

			//at this point, the resource manager would look up what resources the BRL_Tile to draw needs and assign them to the BRL_Tile, without the below switch/case/if block. Also this would be done during the creation of the Tile (In HRL_MapGenerator)
			//I should probably change the name of moveValue to something else, as it's use is different than named - or something else maybe

			switch(tileToDraw.getMoveValue()){
			case IMPASSIBLE_TILE_M_VALUE:
				tileToDraw.setBitmap(wallSurface);
				break;
			case EMPTY_TILE_M_VALUE:
				tileToDraw.setBitmap(floorSurface);
			}

			//SDL_Rect* dst = new SDL_Rect();
			dst->x = x * TILE_SIZE;
			dst->y = y * TILE_SIZE;
			dst->w = TILE_SIZE;
			dst->h = TILE_SIZE;

			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tileToDraw.getBitmap());

			if(texture == NULL){
				printf("Something went wrong creating the texture\n");
				if (wallSurface == NULL || floorSurface == NULL || spriteSheet == NULL){
					printf("The Surfaces Are Null\n");
				}
				if (dst == NULL){
					printf("the dst SDL_rect is Null");
				}
				return;
			}

			SDL_RenderCopy(renderer, texture, NULL, dst);

			SDL_DestroyTexture(texture); //??

			//TESTING ONLY
			/****************************
			if (tileToDraw.getMoveValue() == 1){
				SDL_Rect* src = new SDL_Rect();

				int r = rand()%1000;
				if (r > 995){ // a player image
					src->x = 0 * 27;
					src->y = 1 * 27;
					src->w = 27;
					src->h = 27;
					SDL_RenderCopy(renderer, spriteSheetTexture, src, dst);

				} else if (r > 985){ // a dodo
					src->x = 1 * 27;
					src->y = 0 * 27;
					src->w = 27;
					src->h = 27;
					SDL_RenderCopy(renderer, spriteSheetTexture, src, dst);
				}
			}
			*****************************/
			//END TESTING ONLY


		}
	}


    //draw the player
	dst->x = map->getPlayer()->getPos()->xPos * TILE_SIZE;
	dst->y = map->getPlayer()->getPos()->yPos * TILE_SIZE;
	dst->w = TILE_SIZE;
	dst->h = TILE_SIZE;
	//debug
	printf("player x: %d\n",map->getPlayer()->getPos()->xPos);
	printf("player y: %d\n",map->getPlayer()->getPos()->yPos);
	//enddebug
	//this should be inside the BRL_Creature
	src->x = 2 * 27;
	src->y = 1 * 27;
	src->w = 27;
	src->h = 27;
	//end what should be
	SDL_RenderCopy(renderer, spriteSheetTexture, src, dst); //render the player
	//end player draw

	SDL_RenderPresent(renderer);

	//free surface here for now

	SDL_FreeSurface(wallSurface);
	SDL_FreeSurface(floorSurface);
}
