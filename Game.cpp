#include <iostream>
#include "Game.h"
#include "Player.h"

Player player;

void Game::init()
{
    loadAreas();
    player.setPosition(4);
}

void Game::loadAreas()
{
    static int dirs0[4] = {1, -1, -1, -1};
    areas.emplace_back("Start", "Start room", dirs0);

    static int dirs1[4] = {4, 2, 0, -1};
    areas.emplace_back("1", "First room", dirs1);

    static int dirs2[4] = {-1, 3, -1, 1};
    areas.emplace_back("2", "Second room", dirs2);

    static int dirs3[4] = {-1, -1, -1, 2};
    areas.emplace_back("3", "Third room", dirs3);

    static int dirs4[4] = {-1, 5, 1, -1};
    areas.emplace_back("4", "Fourth room", dirs4);

    static int dirs5[4] = {-1, 6, -1, 4};
    areas.emplace_back("5", "Fifth room", dirs5);

    static int dirs6[4] = {-1, -1, -1, 5};
    areas.emplace_back("End", "End room", dirs6);
}

void Game::run()
{
    while(!step()) {
        int pos = player.getPosition();
        std::cout<<"You are now in room nr "<<areas[pos].getName()<<", "<<areas[pos].getDescription()<< std::endl;
        const int* dirs = areas[pos].getValidDirs();
        std::cout<<"You can go to ";
        string dir;
        for (int i = 0; i < 4; i++) {
            //std::cout<<dirs[i]<<std::endl;
            if ( dirs[i] != -1) {
                if (i == 0) dir += "north ";
                else if (i == 1) dir += "east ";
                else if (i == 2) dir += "south ";
                else if (i == 3) dir += "west ";
            }
        }
        std::cout<<dir<<std::endl;
        break;
    }
}

bool Game::step()
{
    return false;
}
