#ifndef H_HRL_MAP2DDRAWSDL
#define H_HRL_MAP2DDRAWSDL

#include "..\BRLClasses\BRL_Map.hpp"

class HRL_Map2DDrawSDL{
public:
	HRL_Map2DDrawSDL(BRL_Map* map, SDL_Window* window);

	~HRL_Map2DDrawSDL();

	void draw2DMapSDL(); //in funture projects, have the Map class, and an extension SDLDrawableMap extend a virtual Drawable type with a draw method. I can then put the graphics logic in that extension class

protected:

private:

	SDL_Renderer *renderer;
	SDL_Window* window;
	BRL_Map* map;
};

#endif
