//
// Created by alex on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H

#include "Item.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

class Inventory {

public:
    Inventory(int);

    bool isItemInInventory(Item&);

    int numberOfItemsIn(Item&);

    Item* findItemInInventory(std::string);

    void add(Item&);

    void remove(Item&);

    int getCapacity();

    int getWeight();

    std::map<Item*, int>* getInventory();

private:
    std::map<Item*, int> inventory;
    int capacity;
    int weight = 0;

/*public:
    Inventory(int);

    std::vector<Item> getItems() const;

    void pickUpItem(Item &item);

    void dropItem(Item &item, int& pos);

private:
    int capacity;
    int weight;
    std::vector<Item> inventoryItems;*/
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
