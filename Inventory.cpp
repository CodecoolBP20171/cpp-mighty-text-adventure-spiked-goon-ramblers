//
// Created by alex on 2017.10.10..
//

#include "Inventory.h"
#include "iterator"

Inventory::Inventory(int capacity) : capacity(capacity) {}

bool Inventory::isItemInInventory(Item& item) {
    auto search = inventory.find(&item);
    if(search != inventory.end()) {
        return true;
    }
    return false;
}

int Inventory::numberOfItemsIn(Item& item) {
    return inventory[&item];
}

void Inventory::add(Item& item) {
    if ( weight + item.getWeight() <= capacity ) {
        if ( isItemInInventory(item) ) {
            inventory[&item] += 1;
        } else {
            inventory[&item] = 1;
        }
        weight += item.getWeight();
    } else {
        std::cout<<"Sorry, out of capacity, you can not pick up item\n";
    }
}

void Inventory::remove(Item& item) {
    if ( !isItemInInventory(item) ) {
        std::cout<<"No item to remove from inventory"<<std::endl;
    } else {
        weight -= item.getWeight();
        if (numberOfItemsIn(item) > 1) {
            inventory[&item] -= 1;
        } else {
            inventory.erase(&item);
        }
    }
}

int Inventory::getCapacity() {
    return capacity;
}

int Inventory::getWeight(){
    return weight;
}

std::map<Item*, int>* Inventory::getInventory() {
    return &inventory;
}

/*Inventory::Inventory(int capacity) {
    this->capacity = capacity;
}*/

/*void Inventory::pickUpItem(Item &item) {
    if (capacity >= weight + item.getWeigth()) {
        item.setPosition(-1);
        inventoryItems.emplace_back(item);
        weight += item.getWeigth();
    }
}*/

/*
void Inventory::dropItem(Item &item, int& pos) {
    std::vector<Item>::iterator it;
    it = std::find(items.begin(), items.end(), item);
    items.erase(it);
    item.setPosition(pos);
}
*/

/*
std::vector<Item> Inventory::getItems() const {
    return inventoryItems;
*/
