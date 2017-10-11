#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#include <string>

using namespace std;

class Area
{
public:
    Area(const string& name, const string& description, const int (&validDirs)[4])
        : name(name)
        , description(description)
        , validDirs(validDirs)
    {}

    std::string getName() { return name;}

    std::string getDescription() { return description;}

    const int* getValidDirs() const { return validDirs;}

    bool isVisited() { return visited;}

    void setVisited() { this->visited = true;}

private:
    const string name;
    const string description;
    const int (&validDirs)[4];
    bool visited = false;
    //std::vector<int> setValidDirs();
    void setName();
    void setDescription();

};
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP

