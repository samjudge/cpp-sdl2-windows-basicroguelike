#ifndef H_HRL_MAP2DDRAWSDL
#define H_HRL_MAP2DDRAWSDL

#include "..\BRLClasses\BRL_Map.hpp"

class HRL_Map2DDrawSDL :  public BRL_Map{
public:
	HRL_Map2DDrawSDL(SDL_Window* window, int maxWidth, int maxHeight);
	HRL_Map2DDrawSDL(SDL_Window* window, std::vector<BRL_Tile> mapTilesList, int maxWidth, int maxHeight);

	~HRL_Map2DDrawSDL();

	void draw2DMapSDL();

protected:

private:

	SDL_Window* window;
	int windowWidth;
	int windowHeight;

};

#endif
