//
// Created by alex on 2017.10.10..
//

#include "Item.h"

Item::Item(const std::string& name, const int &weight, const bool& edible, const int& healthModifier)
        : name(name)
        , weight(weight)
        , edible(edible)
        , healthModifier(healthModifier)
{}

std::string Item::getName() const {
    return this->name;
}

/*int Item::getPosition() const {
    return this->position;
}

void Item::setPosition(int pos) {
    this->position = pos;
}*/

int Item::getWeight() const {
    return this->weight;
}

bool Item::isEdible() { return this->edible; }

int Item::getHealthModifier() { return this->healthModifier; }