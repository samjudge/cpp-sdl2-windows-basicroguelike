/*
 * HRL_EventHandler.cpp
 *
 *  Created on: 20 Feb 2014
 *      Author: Sam
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include "HRL_EventHandler.hpp"
#include "..\BRLClasses\BRL_Map.hpp"

	HRL_EventHandler::HRL_EventHandler(){
	}

	HRL_EventHandler* HRL_EventHandler::instance;
	SDL_Event* HRL_EventHandler::eventHandler;

	HRL_EventHandler* HRL_EventHandler::getInstance(){
		if (instance == NULL){
			instance = new HRL_EventHandler();
		}
		if (eventHandler == NULL){
			eventHandler = new SDL_Event();
		}
		return instance;
	}

	bool HRL_EventHandler::handleEventLoop(BRL_Map* map){
		if(SDL_PollEvent(eventHandler)){
			handlePlayerEvent(map->getPlayer(), map);
			if(isQuitEvent()){
				return false;
			}
		}
		printf("event process loop\n");
		return true;
	}

	bool HRL_EventHandler::isQuitEvent(){
		if(eventHandler->type == SDL_KEYDOWN){
			switch(eventHandler->key.keysym.sym){
			case SDLK_ESCAPE:
				return true;
			}
		}
		return false;
	}

	void HRL_EventHandler::handlePlayerEvent(BRL_Player* player, BRL_Map* map){
		if(eventHandler->type == SDL_KEYDOWN){
			switch(eventHandler->key.keysym.sym){
			case SDLK_UP:
				player->setYVel(-1);
				break;
			case SDLK_RIGHT:
				player->setXVel(1);
				break;
			case SDLK_DOWN:
				player->setYVel(1);
				break;
			case SDLK_LEFT:
				player->setXVel(-1);
				break;
			}
			printf("\nmoving now\n");
			BRL_Tile targetTile = map->getMapTilesList()->at(((player->getPos()->yPos+player->getYVel())*map->getMaxWidth())+(player->getPos()->xPos+player->getXVel()));
			printf("\ntile got\n");
			player->move(&targetTile);
			printf("\ndone moving\n");
		}


	}





