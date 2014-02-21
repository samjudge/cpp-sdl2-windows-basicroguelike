/*
 * BRL_Player.hpp
 *
 *  Created on: 20 Feb 2014
 *      Author: Sam
 */
#ifndef H_BRL_PLAYER
#define H_BRL_PLAYER

#include "BRL_Creature.hpp"

class BRL_Player : public BRL_Creature {
public:
	BRL_Player(int strStat, int intStat, int dexStat, int lukStat,int xPos, int yPos, int zIndex);
	BRL_Player();
protected:

private:

};

#endif
