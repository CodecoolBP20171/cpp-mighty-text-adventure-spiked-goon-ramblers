#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP

using namespace std;

class Area
{
public:
    enum directions {
        north,
        east,
        south,
        west
    };

    enum door {
        closed,
        open
    };


    Area(const string& description, const door& n, const door& e, const door& s, const door& w)
            : description(description)
            , toNorth(n)
            , toEast(e)
            , toSouth(s)
            , toWest(w)
    {}

    const bool toNorth, toEast, toSouth, toWest;

    string getDescription() { return this->description;}

private:
    const string description;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP

