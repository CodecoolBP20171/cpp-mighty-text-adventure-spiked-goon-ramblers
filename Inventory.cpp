//
// Created by alex on 2017.10.10..
//

#include "Inventory.h"
#include "iterator"

Inventory::Inventory(int capacity) {
    this->capacity = capacity;
}

void Inventory::pickUpItem(Item &item) {
    if (capacity > weight + item.getWeigth()) {
        item.setPosition(-1);
        inventoryItems.emplace_back(item);
        weight += item.getWeigth();
    }
}

/*
void Inventory::dropItem(Item &item, int& pos) {
    std::vector<Item>::iterator it;
    it = std::find(items.begin(), items.end(), item);
    items.erase(it);
    item.setPosition(pos);
}
*/

std::vector<Item> Inventory::getItems() const {
    return inventoryItems;
}