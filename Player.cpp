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
    if (inventory->getWeight()  == 0) {
        std::cout<<"empty";
    }
    //TODO show size/remaining space
    for (std::map<Item*,int>::iterator it=getInventory()->getInventory()->begin(); it!=getInventory()->getInventory()->end(); ++it) {
        std::cout << it->first << ": " << it->second << '\n';
    }
    std::cout<<"\nYour health is: "<<getHealth()<<std::endl;
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

int Player::getHealth() { return this->health; }

void Player::modifyHealth(int modifier) {
    this->health += modifier;
}

void Player::eat(std::string& food) {
/*
    for (Item item: inventory->getItems() ) {
        if ( item.getName() == food ) {
            if ( item.isEdible() ) {

            }
        }
    }
*/
}