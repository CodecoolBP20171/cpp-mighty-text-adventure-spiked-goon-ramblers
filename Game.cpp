#include <iostream>
#include "Game.h"
#include "Player.h"

Player player;

void Game::init()
{
    loadAreas();
    player.setPosition(0);
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

void Game::printHelp() {
    std::cout<<"Help: you can use case insensitive 'h' or 'help' for this message, or"<<std::endl;
    std::cout<<"'g' or 'go' n/north/e/east/s/south/w/west to go to the given direction"<<std::endl;
    std::cout<<"or..."<<std::endl;
}

//TODO remove code duplicates
void Game::moveTo(const std::string& dir) {
    std::cout<<"GO"<<std::endl;
    if (dir == "n" || dir == "north") {
        if (areas[player.getPosition()].getValidDirs()[0] != -1) {
            player.setPosition(areas[player.getPosition()].getValidDirs()[0]);
            run();
        } else {
            std::cout << "Not valid direction" << std::endl;
            run();
        }
    }
    if (dir == "e" || dir == "east") {
        if (areas[player.getPosition()].getValidDirs()[1] != -1) {
            player.setPosition(areas[player.getPosition()].getValidDirs()[1]);
            run();
        } else {
            std::cout << "Not valid direction" << std::endl;
            run();
        }
    }
    if (dir == "s" || dir == "south") {
        if (areas[player.getPosition()].getValidDirs()[2] != -1) {
            player.setPosition(areas[player.getPosition()].getValidDirs()[2]);
            run();
        } else {
            std::cout << "Not valid direction" << std::endl;
            run();
        }
    }
    if (dir == "w" || dir == "west") {
        if (areas[player.getPosition()].getValidDirs()[3] != -1) {
            player.setPosition(areas[player.getPosition()].getValidDirs()[3]);
            run();
        } else {
            std::cout << "Not valid direction" << std::endl;
            run();
        }
    }
}

void Game::handleUserInput() {
    string input;
    bool validInput;
    bool isValidFirstWord = false;
    std::string firstWord;
    std::string restWords;
    do {
        firstWord = "";
        restWords = "";
        std::string lowerInput = "";
        validInput = true;
        std::cout<<"What are you going to do next? ";
        getline(std::cin, input);
        for (char c: input) {
            if ( (c < 'A' && c != ' ') || c > 'z' || (c > 'Z' && c < 'a') ) {
                std::cout<<"Sorry, there mist be a typo somewhere :-("<<std::endl;
                validInput = false;
                break;
            } else if (c == ' ' && lowerInput == "") {
                continue;
            } else if ( c >= 'A' && c <= 'Z') {
                lowerInput += c + 'z' - 'Z';
                std::cout<<"lower char "<<lowerInput<<std::endl;
            } else {
                lowerInput += c;
            }
        }
        if ( !validInput) {
            continue;
        }
        std::cout<<"Your input is "<<lowerInput<<std::endl;
        int spacePos = lowerInput.find(' ');
        if (spacePos == -1) {
            firstWord = lowerInput;
        } else {
            firstWord = lowerInput.substr(0, spacePos);
            restWords = lowerInput.substr(spacePos+1, lowerInput.size());
            //TODO rmeove spaces from the begon amd end of restWords
        }
        std::cout<<"firstWord "<<firstWord<<std::endl;
        if (restWords != "") {
            std::cout<<"restWords "<<restWords<<std::endl;
        }
        std::vector<std::string> validFirstWords = {"h", "help",
                                                    "g", "go",
                                                    "u", "use",
                                                    "e", "eat",
                                                    "f", "fight"};

        for (std::string word : validFirstWords) {
            if (firstWord == word) {
                std::cout << "Valid first word" << std::endl;
                isValidFirstWord = true;
                break;
            }
        }
        if ( !isValidFirstWord) {
            std::cout<<"Sorry, I can not understand :-("<<std::endl;
        }
    } while ( !isValidFirstWord );

    if (firstWord == "h" || firstWord == "help") {
        printHelp();
        Game::handleUserInput();
    } else if (firstWord == "g" || firstWord == "go") {
        Game::moveTo(restWords);
        Game::handleUserInput();
    }

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
        printHelp();
        //TODO refactor infinit while true loop
        while(true) {
            handleUserInput();
        }
        break;
    }
}

//TODO refactor step
bool Game::step()
{
    return false;
}

