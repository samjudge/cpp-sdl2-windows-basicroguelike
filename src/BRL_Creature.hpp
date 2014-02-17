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

protected:
	Creature() : BRL_Unit(){
	}
	Creature(int xPos, int yPos, int zIndex) : BRL_Unit(xPos, yPos, zIndex){
	}
	Creature(int xPos, int yPos, int zIndex, SDL_Surface* bitmap) : BRL_Unit(xPos, yPos, zIndex, *bitmap){
	}
	~Creature(){
	}
private:
	int strStat;
	int intStat;
	int	dexStat;
	int lukStat;
};
