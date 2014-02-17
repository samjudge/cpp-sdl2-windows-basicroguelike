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

protected:
	BRL_Creature(int strStat, int intStat, int dexStat, int lukStat);
	BRL_Creature(int strStat, int intStat, int dexStat, int lukStat,int xPos, int yPos, int zIndex);
	BRL_Creature(int strStat, int intStat, int dexStat, int lukStat,int xPos, int yPos, int zIndex, SDL_Surface* bitmap);
	~BRL_Creature();
private:

	int xVel;
	int yVel; //Velocity in x and y directions for movement

	int currentHP;

	int strStat;
	int intStat;
	int	dexStat;
	int lukStat;
};
