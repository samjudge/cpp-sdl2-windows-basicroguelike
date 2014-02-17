class BRL_Position {
public:
	int xPos;
	int yPos;
	int zIndex; //used for drawing priority

	BRL_Position() {
		xPos = 0;
		yPos = 0;
		zIndex = 0;
	}

	BRL_Position(int xPos, int yPos, int zIndex){
		this->xPos = xPos;
		this->yPos = yPos;
		this->zIndex = zIndex;
	}
};
