//
// Created by en on 2017.10.09..
//

#include "Player.h"

Player::Player() {

};

int Player::getPosition() const { return position; }

void Player::setPosition(int pos) { position = pos; }

Inventory* Player::getInventory() { return inventory; }

void Player::showInventory() {
    std::cout<<"Inventory: ";
    if (inventory->getItems().size() == 0) {
        std::cout<<"empty";
    }
    //TODO show size/remaining space
    for (Item item: inventory->getItems() ) {
        std::cout<<item.getName()<<" ";
    }
    std::cout<<std::endl;
}

void Player::setRoomVisited(int roomIndex) {
    if (!isRoomVisited(roomIndex)) roomsVisited.push_back(roomIndex);
}

std::vector<int> Player::getRoomsVisited() {
    return roomsVisited;
}

bool Player::isRoomVisited(int roomIndex) {
    for (auto &index: getRoomsVisited() ) {
        if (index == roomIndex) return true;
    }
    return false;
}
