#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#include <string>

using namespace std;

class Area
{
public:
/*
Room::Room(std::string name, std::string description, std::vector<int> validDirs) {
    this->name = name;
    this->description = description;
    this->validDirs = validDirs;
};
 */
    Area(const string& name, const string& description, const int (&validDirs)[4])
        : name(name)
        , description(description)
        , validDirs(validDirs)
    {}

    std::string getName() { return name;};

    std::string getDescription() { return description;};

    const int* getValidDirs() const { return validDirs;};

private:
    const string name;
    const string description;
    const int (&validDirs)[4];

    //std::vector<int> setValidDirs();
    void setName();
    void setDescription();

};
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP

