#ifndef H_BRL_POSITION
#define H_BRL_POSITION

struct BRL_Position {
public:
	int xPos;
	int yPos;
	int zIndex; //used for drawing priority

	BRL_Position();
	BRL_Position(int xPos, int yPos, int zIndex);
};

#endif
