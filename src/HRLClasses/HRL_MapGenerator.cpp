#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cmath>


#include "HRL_MapGenerator.hpp"


#define HUGE_NUM 9999999

	std::vector<BRL_Tile> HRL_MapGenerator::generateMap(int width, int height){

		srand(time(NULL)); //set random number seed

		BRL_Tile map[width][height];

		for (int y = 0; y < height; y++){
			for (int x = 0 ; x < width; x++){
				map[x][y] = BRL_Tile(IMPASSIBLE_TILE_M_VALUE, x , y , 0); //create new tiles
				//map[x][y].setMoveValue(IMPASSIBLE_TILE_M_VALUE);
			}
		}

		int numberOfRooms = (rand()%10)+10;
		int minRoomSize = 5;
		int maxRoomSize = 15;

		std::vector<Room> rooms(0);

		for(int n = 0; n < numberOfRooms; n++){
			Room* room = new Room();
			//debug note: rand() returns int
			room->x = rand()%(width - maxRoomSize - 1)+1 ;
			room->y = rand()%(height - maxRoomSize - 1)+1 ;
			room->w = rand()%maxRoomSize + minRoomSize;
			room->h = rand()%maxRoomSize + minRoomSize;
			//debug
			//printf("generating room : %d\n", n);
			//endbug
			if(isRoomColliding(*room, rooms)){
				//debug
				//printf("Colliding Rooms, retrying..\n");
				//endbug
				n--; //try again
				continue;
			}
			room->w--;
			room->h--; //shrink room slighty for walls
			//debug
			//printf("xPos: %d, yPos: %d, w: %d, h: %d\n", room->x,room->y,room->w,room->h);
			//printf("%d\n",numberOfGeneratedRooms);
			//endbug
			rooms.push_back(*room); //add the room to the vector
			numberOfGeneratedRooms = rooms.size();
		}

		for(int n = 0; n < numberOfRooms; n++){ //corridoor




			Room roomA = rooms.at(n);
			Room roomB = findClosestRoom(roomA, rooms);


			Point pointA;
			pointA.x=rand()%(roomA.w)+roomA.x;
			pointA.y=rand()%(roomA.h)+roomA.y;
			Point pointB;
			pointB.x=rand()%(roomB.w)+roomB.x;
			pointB.y=rand()%(roomB.h)+roomB.y;

			//debug
			//printf("generating corridoor for room: %d\nxPos: %d, yPos: %d, w: %d, h: %d\n", n, roomA.x,roomA.y,roomA.w,roomA.h);
			//printf("generating corridoor to room: \nxPos: %d, yPos: %d, w: %d, h: %d\n", roomB.x,roomB.y,roomB.w,roomB.h);
			//continue; //it's trying to %0, which is DBZ arithmatic run time error
			//endbug


			while((pointB.x != pointA.x)||(pointB.y != pointA.y)){
				if(pointB.x != pointA.x){
					if (pointB.x > pointA.x) pointB.x--;
					else pointB.x++;
				} else if (pointB.y != pointA.y){
					if(pointB.y > pointA.y) pointB.y--;
					else pointB.y++;
				}

				//line below is error
				//debug
				//printf("PBX: %d, PBY: %d\n", pointB.x, pointB.y);
				//endbug
				map[pointB.x][pointB.y].setMoveValue(EMPTY_TILE_M_VALUE); //1 is moveable
			}
		}

		for(int n = 0; n < numberOfRooms; n++){ //fill in the rooms
			Room room = rooms.at(n);
			for(int x = room.x; x < room.x + room.w; x++){
				for(int y = room.y; y < room.y + room.h; y++){
					map[x][y].setMoveValue(EMPTY_TILE_M_VALUE);
				}
			}
		}

		BRL_Tile mapSingleDimension[width*height];

		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				mapSingleDimension[(y*width)+x] = map[x][y];
			}
		}

		std::vector<BRL_Tile> mapVect(mapSingleDimension, mapSingleDimension + (sizeof mapSingleDimension / sizeof mapSingleDimension[0]));

		return mapVect;

	}


	int HRL_MapGenerator::numberOfGeneratedRooms = 0;
	HRL_MapGenerator* HRL_MapGenerator::instance;

	HRL_MapGenerator* HRL_MapGenerator::getInstance(){
		if (instance == NULL){
			instance = new HRL_MapGenerator();
		}
		return instance;
	}

	HRL_MapGenerator::HRL_MapGenerator(){
	}

	bool HRL_MapGenerator::Room::operator==(const Room& rhs){
		if (this->x == rhs.x && this->y == rhs.y && this->w == rhs.w && this->h == rhs.h) return true;
		return false;
	}

	bool HRL_MapGenerator::isRoomColliding(Room firstRoom, std::vector<Room> rooms){
		for(int n = 0; n < numberOfGeneratedRooms; n++){
			Room secondRoom = rooms.at(n);
			if(firstRoom == secondRoom) continue;
			if(!((firstRoom.x + firstRoom.w < secondRoom.x) || (firstRoom.x > secondRoom.x + secondRoom.w) ||
				 (firstRoom.y+firstRoom.h < secondRoom.y)||(firstRoom.y > secondRoom.y + secondRoom.h))) return true;
		}
		return false;
	}
	//void squashRooms(); //i might leave this out, although would be interesting anyway
	HRL_MapGenerator::Room HRL_MapGenerator::findClosestRoom(Room r, std::vector<Room> rooms){
		Point mid;
		mid.x = r.x+(r.w/2);
		mid.y = r.y+(r.h/2);
		Room* closest;
		int closestDistance = HUGE_NUM;
		for(int n = 0; n < rooms.size(); n++){
			Room roomToCheck = rooms.at(n);
			if(r == roomToCheck) continue;
			Point midRoomToCheck;
			midRoomToCheck.x = roomToCheck.x + (roomToCheck.w/2);
			midRoomToCheck.y = roomToCheck.y + (roomToCheck.h/2);
			int distance = std::abs(mid.x - midRoomToCheck.x) + std::abs(mid.y - midRoomToCheck.y);
			if(distance < closestDistance){
				closestDistance = distance;
				closest = &roomToCheck;
			}
		}
		return *closest;
	}
