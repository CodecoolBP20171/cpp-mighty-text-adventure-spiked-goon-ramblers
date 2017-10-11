//
// Created by en on 2017.10.09..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H


#include "Inventory.h"

class Player {
public:
    Player();
    int getPosition() const;
    void setPosition(int);
    Inventory* getInventory();
    void showInventory();
    void setRoomVisited(int);
    std::vector<int> getRoomsVisited();
    bool isRoomVisited(int);

private:
    int position;
    Inventory* inventory = new Inventory(20);
    std::vector<int> roomsVisited;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
