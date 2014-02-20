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
			handlePlayerEvent(map->getPlayer());
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

	void HRL_EventHandler::handlePlayerEvent(BRL_Creature* player){
		if(eventHandler->type == SDL_KEYDOWN){
			switch(eventHandler->key.keysym.sym){
			case SDLK_UP:
				player->getPos()->yPos -= 1;
				break;
			case SDLK_RIGHT:
				player->getPos()->xPos += 1;
				break;
			case SDLK_DOWN:
				player->getPos()->yPos += 1;
				printf("\n******\nThe player's y velcity is : %d\n******\nThe Down key was pressed, the player's new position is: %d\n******\n",player->getYVel(), player->getPos()->yPos);
				break;
			case SDLK_LEFT:
				player->getPos()->xPos -= 1;
				break;
			}
			printf("keypress detected\n");
		}


	}





