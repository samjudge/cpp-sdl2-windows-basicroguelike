#include "BRL_Creature.hpp"

BRL_Creature::BRL_Creature(int strStat, int dexStat, int intStat, int lukStat){
	BRL_Creature(strStat, dexStat, intStat, lukStat, 0, 0, 0);
}

BRL_Creature::BRL_Creature(int strStat, int dexStat, int intStat, int lukStat, int xPos, int yPos, int zIndex) : BRL_Unit(xPos, yPos, zIndex){
	this->strStat = strStat;
	this->dexStat = dexStat;
	this->intStat = intStat;
	this->lukStat = lukStat;
}

BRL_Creature::BRL_Creature(int strStat, int dexStat, int intStat, int lukStat, int xPos, int yPos, int zIndex, SDL_Surface* bitmap) : BRL_Unit(xPos, yPos, zIndex){ //changed var list from bitmap since it gets changed
	BRL_Creature(strStat, dexStat, intStat, lukStat, xPos, yPos, zIndex); //here anyway
	setBitmap(bitmap); //the correct bitmap is set here
}

BRL_Creature::~BRL_Creature(){

}

void BRL_Creature::setStrStat(int strStat){
	this->strStat = strStat;
}

void BRL_Creature::setIntStat(int intStat){
	this->intStat = intStat;
}

void BRL_Creature::setDexStat(int dexStat){
	this->dexStat = dexStat;
}

void BRL_Creature::setLukStat(int lukStat){
	this->lukStat = lukStat;
}

int BRL_Creature::getStrStat(){
	return strStat;
}
int BRL_Creature::getIntStat(){
	return intStat;
}
int BRL_Creature::getDexStat(){
	return dexStat;
}
int BRL_Creature::getLukStat(){
	return lukStat;
}

void BRL_Creature::setCurrentHp(int currentHP){
	this->currentHP = currentHP;
}
int BRL_Creature::getCurrentHp(){
	return currentHP;
}

void BRL_Creature::setXVel(int xVel){
	this->xVel = xVel;
}

void BRL_Creature::setYVel(int yVel){
	this->yVel = yVel;
}

int BRL_Creature::getXVel(){
	return xVel;
}

int BRL_Creature::getYVel(){
	return yVel;
}

void BRL_Creature::move(){ //moves in the given vector of xvel and yvel
	this->getPos()->xPos = (this->getPos()->xPos) + xVel;
	this->getPos()->yPos = (this->getPos()->yPos) + yVel;
}
