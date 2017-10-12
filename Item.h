//
// Created by alex on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H

#include <iostream>

class Item {

public:
    Item(const std::string& name, const int& weight, const bool& edible, const int& healthModifier);

    std::string getName() const;

    //int getPosition() const;

    //void setPosition(int pos);

    int getWeight() const;

    bool isEdible();

    int getHealthModifier();

private:
    const std::string name;
    //int position;
    const int weight;
    const bool edible;
    const int healthModifier;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
