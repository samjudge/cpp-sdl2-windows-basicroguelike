#ifndef H_HRL_EVENTHANDLER
#define H_HRL_EVENTHANDLER

#include <SDL2/SDL_events.h>
#include "..\BRLClasses\BRL_Creature.hpp"
#include "..\BRLClasses\BRL_Map.hpp"

class HRL_EventHandler {
public:

	static bool handleEventLoop(BRL_Map* map);
	static HRL_EventHandler* getInstance();

protected:

private:

	HRL_EventHandler();

	HRL_EventHandler(HRL_EventHandler const&);
	void operator=(HRL_EventHandler const&);

	static HRL_EventHandler* instance;

	static void handlePlayerEvent(BRL_Creature* player);
	static bool isQuitEvent();

	static SDL_Event* eventHandler;

};

#endif
