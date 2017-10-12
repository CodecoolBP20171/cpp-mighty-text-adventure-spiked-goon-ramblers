#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H

#include <vector>
#include "Area.hpp"
#include "Item.h"
#include "Inventory.h"

using namespace std;

class Game {
public:
    Game() {};
    void init();
    void run();
    void createItem();
    std::vector<Item> getItems(int& pos) const;
    void printItemsInRoom(int);
    void setSize(int, int);
    void setStartAndEndRoomIndex(int, int);
    void createMaze();
    void loadItems();
    void createRoomInventories();

private:
    vector<Area> areas; // areas has only non-changeable information
    int xSize;
    int ySize;
    int startRoomIndex;
    int endRoomIndex;
    std::vector<Area*> maze;
    std::vector<Item> items;
    std::vector<Inventory*> roomInventories;
    //Inventory roomInventories[];

    void loadAreas();
    bool step();
    void handleUserInput();
    void moveTo(const std::string& dir);
    void printHelp();
    void moveDirection(int dir);
    std::string removeWhitespace(std::string str);
    void showMap();
    void printRoomRow(int);
    bool isItemInItems(std::string);
    Item& getItem(std::string);
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
