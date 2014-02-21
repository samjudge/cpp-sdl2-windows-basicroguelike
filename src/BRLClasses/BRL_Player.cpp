/*
 * BRL_Player.cpp
 *
 *  Created on: 20 Feb 2014
 *      Author: Sam
 */

#include "BRL_Player.hpp"

BRL_Player::BRL_Player(int strStat, int intStat, int dexStat, int lukStat,int xPos, int yPos, int zIndex): BRL_Creature(strStat, intStat, dexStat, lukStat, xPos, yPos, zIndex){

}

BRL_Player::BRL_Player(): BRL_Creature(0,0,0,0){

}
