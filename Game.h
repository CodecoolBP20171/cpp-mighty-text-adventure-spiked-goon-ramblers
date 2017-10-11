#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H

#include <vector>
#include "Area.hpp"
#include "Item.h"
#include "Inventory.h"

using namespace std;

class Game {
public:
    void init();
    void run();
    void createItem();
    std::vector<Item> getItems(int& pos) const;
    void printItemsInRoom(std::vector<Item> items);
    void setSize(int, int);

private:
    vector<Area> areas; // areas has only non-changeable information
    int xSize;
    int ySize;

    void loadAreas();
    bool step();
    void handleUserInput();
    void moveTo(const std::string& dir);
    void printHelp();
    std::vector<Item> items;
    void moveDirection(int dir);
    std::string removeWhitespace(std::string str);
    void showMap();
    void printRoomRow(Area&);
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
