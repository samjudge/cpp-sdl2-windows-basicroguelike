#ifndef H_BRL_CREATURE
#define H_BRL_CREATURE

#include "BRL_Unit.hpp"

class BRL_Creature : public BRL_Unit {
public:
	void setStrStat(int strStat);
	void setIntStat(int intStat);
	void setDexStat(int dexStat);
	void setLukStat(int lukStat);
	int getStrStat();
	int getIntStat();
	int getDexStat();
	int getLukStat();

	void setXVel(int xVel);
	void setYVel(int yVel);
	int getXVel();
	int getYVel();

	void setCurrentHp(int currentHp);
	int getCurrentHp();

	void move();

	BRL_Creature(int strStat, int intStat, int dexStat, int lukStat); //move these into protected after BRL_Player and BRL_enemy are made (and declare virtual)
	BRL_Creature(int strStat, int intStat, int dexStat, int lukStat,int xPos, int yPos, int zIndex);
	BRL_Creature(int strStat, int intStat, int dexStat, int lukStat,int xPos, int yPos, int zIndex, SDL_Surface* bitmap);
	~BRL_Creature();

protected:

private:

	int xVel;
	int yVel; //Velocity in x and y directions for movement

	int currentHP;

	int strStat;
	int intStat;
	int	dexStat;
	int lukStat;
};

#endif
