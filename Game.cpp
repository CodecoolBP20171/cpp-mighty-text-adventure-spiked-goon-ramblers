#include <iostream>
#include "Game.h"
#include "Player.h"

Player player;

void Game::init()
{
    setSize(3, 3);
    loadAreas();
    createItem();
    player.setPosition(6);
}

void Game::setSize(int x, int y) {
    this->xSize = x;
    this->ySize = y;
}

void Game::loadAreas()
{
    static int dirs4[4] = {-1, 1, 3, -1};
    areas.emplace_back("4", "Fourth room", dirs4);

    static int dirs5[4] = {-1, 2, -1, 0};
    areas.emplace_back("5", "Fifth room", dirs5);

    static int dirs6[4] = {-1, -1, -1, 1};
    areas.emplace_back("End", "End room", dirs6);

    static int dirs1[4] = {0, 4, 6, -1};
    areas.emplace_back("1", "First room", dirs1);

    static int dirs2[4] = {-1, 5, -1, 3};
    areas.emplace_back("2", "Second room", dirs2);

    static int dirs3[4] = {-1, -1, -1, 4};
    areas.emplace_back("3", "Third room", dirs3);

    static int dirs0[4] = {3, -1, -1, -1};
    areas.emplace_back("Start", "Start room", dirs0);

    static int dirsUnavailable[4] = {-1, -1, -1, -1};
    areas.emplace_back("Locked", "Locked room", dirsUnavailable);
    areas.emplace_back("Locked", "Locked room", dirsUnavailable);
}

void Game::printHelp() {
    std::cout<<"Help: you can use case insensitive 'h' or 'help' for this message, or"<<std::endl;
    std::cout<<"'g' or 'go' n/north/e/east/s/south/w/west to go to the given direction or"<<std::endl;
    std::cout<<"'u' or 'use' or"<<std::endl;
    std::cout<<"'e' or 'eat' or"<<std::endl;
    std::cout<<"'f' or 'fight' or"<<std::endl;
    std::cout<<"'p' or 'pickup' or"<<std::endl;
    std::cout<<"'d' or 'drop' or"<<std::endl;
    std::cout<<"'i' or 'inventory' or"<<std::endl;
    std::cout<<"'m' or 'map' or"<<std::endl;
    std::cout<<"'x' or 'exit' or"<<std::endl;
    std::cout<<"..."<<std::endl;
}

void Game::moveDirection(int dir) {
    if (areas[player.getPosition()].getValidDirs()[dir] != -1) {
        player.setPosition(areas[player.getPosition()].getValidDirs()[dir]);
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
    return;
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

void Game::showMap() {
    std::cout<<"Map\n";
    /*for (auto &area : areas) {
        std::cout<<area.getName()<<" "<<area.isVisited()<<std::endl;
    }*/
    for (int y = 0; y < ySize; y++) {
            printRoomRow(areas[y*xSize]);
    }
    //TODO print info on rooms below map
}

void Game::printRoomRow(Area& area) {
    Area* room = &area;
    //first row of draw
    for (int x = 0; x < xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !(room+x)->isVisited() ) {
            std::cout<<"     ";
        } else if ( (room+x)->getValidDirs()[0] != -1 ) {
            std::cout<<"+   +";
        } else {
            std::cout<<"+---+";
        }
    }
    std::cout<<std::endl;

    //second row of draw
    for (int x = 0; x < xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !(room+x)->isVisited() ) {
            std::cout<<"     ";
        } else if ( (room+x)->getValidDirs()[3] != -1 ) {
            std::cout<<"    ";
            if ( (room+x)->getValidDirs()[1] != -1 ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        } else {
            std::cout<<"|   ";
            if ( (room+x)->getValidDirs()[1] != -1 ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        }
    }
    std::cout<<std::endl;

    //third row of draw
    for (int x = 0; x < xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !(room+x)->isVisited() ) {
            std::cout<<"     ";
        } else if ( (room+x)->getValidDirs()[3] != -1 ) {
            std::cout<<"  "<<(room+x)->getName()[0]<<" ";
            if ( (room+x)->getValidDirs()[1] != -1 ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        } else {
            std::cout<<"| "<<(room+x)->getName()[0]<<" ";
            if ( (room+x)->getValidDirs()[1] != -1 ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        }
    }
    std::cout<<std::endl;


    //fourth row of draw
    for (int x = 0; x < xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !(room+x)->isVisited() ) {
            std::cout<<"     ";
        } else if ( (room+x)->getValidDirs()[3] != -1 ) {
            std::cout<<"    ";
            if ( (room+x)->getValidDirs()[1] != -1 ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        } else {
            std::cout<<"|   ";
            if ( (room+x)->getValidDirs()[1] != -1 ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        }
    }
    std::cout<<std::endl;

    //fifth row of draw
    for (int x = 0; x < xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !(room+x)->isVisited() ) {
            std::cout<<"     ";
        } else if ( (room+x)->getValidDirs()[2] != -1 ) {
            std::cout<<"+   +";
        } else {
            std::cout<<"+---+";
        }
    }
    std::cout<<std::endl;
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
        /*std::cout<<"firstWord "<<firstWord<<std::endl;
        if (restWords != "") {
            std::cout<<"restWords "<<restWords<<std::endl;
        }*/
        std::vector<std::string> validFirstWords = {"h", "help",
                                                    "g", "go",
                                                    "u", "use",
                                                    "e", "eat",
                                                    "f", "fight",
                                                    "x", "exit",
                                                    "p", "pickup",
                                                    "d", "drop",
                                                    "i", "inventory",
                                                    "m", "map"};
        for (std::string word : validFirstWords) {
            if (firstWord == word) {
                //std::cout << "Valid first word" << std::endl;
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
        return;
    } else if (firstWord == "g" || firstWord == "go") {
        Game::moveTo(restWords);
        return;
    } else if (firstWord == "p" || firstWord == "pickup") {
        //TODO make separate function for pickup
        for (auto &item : items){
            if (item.getName() == restWords) {
                if (item.getPosition() == player.getPosition()) {
                    player.getInventory()->pickUpItem(item);
                    std::cout<<item.getName()<<" picked up."<<std::endl;
                    player.showInventory();
                    break;
                }
                std::cout<<"No "<<item.getName()<<" in this room."<<std::endl;
                break;
            }
            std::cout<<"No "<<restWords<<" in the room."<<std::endl;
        }
    } else if (firstWord == "i" || firstWord == "inventory") {
        player.showInventory();
    } else if (firstWord == "m" || firstWord == "map") {
        Game::showMap();
    }
}

void Game::createItem() {
    items.emplace_back("key", 3, 2);
}

std::vector<Item> Game::getItems(int& pos) const {
    std::vector<Item> itemsInRoom;
    for (auto &item : items) {
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
    printHelp();
    do {

    } while ( !step() );
    //print 'final' map before congratulations
    areas[player.getPosition()].setVisited();
    showMap();

    std::cout<<"Congratulations, you have reached the End room and won the game!"<<std::endl;
}

bool Game::step() {
    do {
        int pos = player.getPosition();
        std::cout<<"You are now in room nr "<<areas[pos].getName()<<", "<<areas[pos].getDescription()<< std::endl;
        areas[pos].setVisited();
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
        Game::handleUserInput();
    } while (player.getPosition() != 2);
    return true;
}

