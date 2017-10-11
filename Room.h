/*
//
// Created by en on 2017.10.11..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H

#include <iostream>

class Room {
private:
    enum directions {
        north,
        east,
        south,
        west
    };

    enum door {
        closed,
        open
    };

    directions doors[4];

public:
    Room(door, door, door, door) {}
    bool toNorth, toEast, toSouth, toWest;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
*/
