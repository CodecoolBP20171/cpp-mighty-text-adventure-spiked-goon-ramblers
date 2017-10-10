#include <iostream>
#include "Game.h"
#include "Player.h"

Player player;

void Game::init()
{
    loadAreas();
    createItem();
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
    std::cout<<"'g' or 'go' n/north/e/east/s/south/w/west to go to the given direction or"<<std::endl;
    std::cout<<"'u' or 'use' or"<<std::endl;
    std::cout<<"'e' or 'eat' or"<<std::endl;
    std::cout<<"'f' or 'fight' or"<<std::endl;
    std::cout<<"'p' or 'pickup' or"<<std::endl;
    std::cout<<"'d' or 'drop' or"<<std::endl;
    std::cout<<"'x' or 'exit' or"<<std::endl;
    std::cout<<"..."<<std::endl;
}

void Game::moveDirection(int dir) {
    if (areas[player.getPosition()].getValidDirs()[dir] != -1) {
        player.setPosition(areas[player.getPosition()].getValidDirs()[dir]);
        run();
    } else {
        std::cout << "Not valid direction" << std::endl;
    }
    return;
}

//TODO enum for directions
void Game::moveTo(const std::string& dir) {
    std::cout<<"GO"<<std::endl;
    if (dir == "n" || dir == "north") {
        Game::moveDirection(0);
    } else if (dir == "e" || dir == "east") {
        Game::moveDirection(1);
    } else if (dir == "s" || dir == "south") {
        Game::moveDirection(2);
    } else if (dir == "w" || dir == "west") {
        Game::moveDirection(3);
    }
    run();
}

std::string Game::removeWhitespace(std::string str) {
    std::string result = "";
    //remove leading spaces
    int c = 0;
    while (str[c] == ' ') {
        ++c;
    }
    str = str.substr(c, str.size());
    //remove inner double spaces
    while (str.find("  ") != -1) {
        int pos = str.find("  ");
        result = str.substr(0, pos);
        result += str.substr(pos+1, str.size());
        str = result;
    }
    //remove trailing spaces
    c = str.size()-1;
    while (str[c] == ' ') {
        --c;
    }
    result = str.substr(0, c+1);

    return result;
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
            restWords = Game::removeWhitespace(restWords);
        }
        std::cout<<"firstWord "<<firstWord<<std::endl;
        if (restWords != "") {
            std::cout<<"restWords "<<restWords<<std::endl;
        }
        //TODO inventory
        std::vector<std::string> validFirstWords = {"h", "help",
                                                    "g", "go",
                                                    "u", "use",
                                                    "e", "eat",
                                                    "f", "fight",
                                                    "x", "exit",
                                                    "p", "pickup",
                                                    "d", "drop"};

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

void Game::createItem() {
    items.emplace_back("Key", 3, 2);
}

std::vector<Item> Game::getItems(int& pos) const {
    std::vector<Item> itemsInRoom;
    for (Item item : items) {
        if (item.getPosition() == pos) {
            itemsInRoom.emplace_back(item);
        }
    }
    return itemsInRoom;
}

void Game::printItemsInRoom(std::vector<Item> items) {
    cout << "Items: ";
    if (items.empty()) {
        cout << "no item in this room\n";
        return;
    }
    for (Item item : items) {
        cout << item.getName() << endl;
    }
}

void Game::run()
{
    while(!step()) {
        int pos = player.getPosition();
        std::cout<<"You are now in room nr "<<areas[pos].getName()<<", "<<areas[pos].getDescription()<< std::endl;
        printItemsInRoom(getItems(pos));
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

