//
// Created by alex on 2017.10.10..
//

#include "Inventory.h"
#include "iterator"

Inventory::Inventory(const int &capacity) {
    this->capacity = capacity;
}

void Inventory::pickUpItem(Item &item) {
    if (capacity > weight + item.getWeigth()) {
        items.emplace_back(item);
        weight += item.getWeigth();
        item.setPosition(-1);
    }
}

void Inventory::dropItem(Item &item, int& pos) {
    std::vector<Item>::iterator it;
    it = std::find(items.begin(), items.end(), item);
    items.erase(it);
    item.setPosition(pos);
}

std::vector<Item> Inventory::getItems() const {
    return items;
}