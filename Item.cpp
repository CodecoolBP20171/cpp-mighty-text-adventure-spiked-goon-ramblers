//
// Created by alex on 2017.10.10..
//

#include "Item.h"

Item::Item(const std::string& name, const int& position, const int &weight) {
    this->name = name;
    this->position = position;
    this->weight = weight;
}

std::string Item::getName() const {
    return this->name;
}

int Item::getPosition() const {
    return this->position;
}

void Item::setPosition(int pos) {
    this->position = pos;
}

int Item::getWeigth() const {
    return this->weight;
}