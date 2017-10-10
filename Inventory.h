//
// Created by alex on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H

#include "Item.h"
#include <vector>
#include <algorithm>
#include <iostream>

class Inventory {

public:
    Inventory(int);

    std::vector<Item> getItems() const;

    void pickUpItem(Item &item);

    void dropItem(Item &item, int& pos);

private:
    int capacity;
    int weight;
    std::vector<Item> inventoryItems;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
