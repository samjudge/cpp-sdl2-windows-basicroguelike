#ifndef H_HRL_MAPGEN
#define H_HRL_MAPGEN

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cmath>
#include "../constants.hpp"
#include "../BRLClasses/BRL_Tile.hpp"

#define HUGE_NUM 9999999

class HRL_MapGenerator {
public:
	static std::vector<BRL_Tile> generateMap(BRL_Map mapToDraw);
	static HRL_MapGenerator* getInstance();
protected:

private:

	HRL_MapGenerator();

	HRL_MapGenerator(HRL_MapGenerator const&);
	void operator=(HRL_MapGenerator const&);

	static int numberOfGeneratedRooms;
	static HRL_MapGenerator* instance;

	struct Room{
		int x;
		int y;
		int w;
		int h;

		bool operator==(const Room& rhs);
	};

	struct Point{
		int x;
		int y;
	};

	static bool isRoomColliding(Room firstRoom, std::vector<Room> rooms);

	static Room findClosestRoom(Room r, std::vector<Room> rooms);
};

#endif
