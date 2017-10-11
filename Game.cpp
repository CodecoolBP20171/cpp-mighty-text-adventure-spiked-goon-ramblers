#include <iostream>
#include <fstream>
#include "Game.h"
#include "Player.h"

Player player;

void Game::init()
{
    setSize(3, 3);
    loadAreas();
    createMaze();
    setStartAndEndRoomIndex(6, 2);
    createItem();
    player.setPosition(startRoomIndex);
}

void Game::createMaze() {

    string roomType;
    ifstream levelFile ("maze.txt");
    if (levelFile.is_open())
    {
        while ( getline(levelFile, roomType) )
        {
            maze.push_back(&areas[std::stoi(roomType)]);//std::cout<<std::stoi(roomType);
        }
        levelFile.close();
    }
    else cout << "Unable to open file";

/*
    maze.push_back(&areas[3]);
    maze.push_back(&areas[2]);
    maze.push_back(&areas[1]);
    maze.push_back(&areas[5]);
    maze.push_back(&areas[2]);
    maze.push_back(&areas[1]);
    maze.push_back(&areas[4]);
    maze.push_back(&areas[0]);
    maze.push_back(&areas[0]);
*/
}

void Game::setSize(int x, int y) {
    this->xSize = x;
    this->ySize = y;
}

void Game::setStartAndEndRoomIndex(int s, int e) {
    this->startRoomIndex = s;
    this->endRoomIndex = e;
}

void Game::loadAreas()
{
    areas.emplace_back(Area::closed, Area::closed, Area::closed, Area::closed);
    areas.emplace_back(Area::closed, Area::closed, Area::closed, Area::open);
    areas.emplace_back(Area::closed, Area::open, Area::closed, Area::open);
    areas.emplace_back(Area::closed, Area::open, Area::open, Area::closed);
    areas.emplace_back(Area::open, Area::closed, Area::closed, Area::closed);
    areas.emplace_back(Area::open, Area::open, Area::open, Area::closed);
    //areas not used for basic game
    areas.emplace_back(Area::open, Area::open, Area::open, Area::open);
    areas.emplace_back(Area::closed, Area::open, Area::closed, Area::closed);
    areas.emplace_back(Area::closed, Area::closed, Area::open, Area::closed);
    areas.emplace_back(Area::open, Area::open, Area::closed, Area::open);
    areas.emplace_back(Area::open, Area::closed, Area::open, Area::open);
    areas.emplace_back(Area::closed, Area::open, Area::open, Area::open);
    areas.emplace_back(Area::open, Area::open, Area::closed, Area::closed);
    areas.emplace_back(Area::open, Area::closed, Area::open, Area::closed);
    areas.emplace_back(Area::open, Area::closed, Area::closed, Area::open);
    areas.emplace_back(Area::closed, Area::closed, Area::open, Area::open);
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
    if (dir == Area::north && maze[player.getPosition()]->toNorth) {
        player.setPosition(player.getPosition()-xSize);
        return;
    }
    if (dir == Area::east && maze[player.getPosition()]->toEast) {
        player.setPosition(player.getPosition()+1);
        return;
    }
    if (dir == Area::south && maze[player.getPosition()]->toSouth) {
        player.setPosition(player.getPosition()+xSize);
        return;
    }
    if (dir == Area::west && maze[player.getPosition()]->toWest) {
        player.setPosition(player.getPosition()-1);
        return;
    }
    return;
}

//TODO enum for directions
void Game::moveTo(const std::string& dir) {
    std::cout<<"GO"<<std::endl;
    if (dir == "n" || dir == "north") {
        moveDirection(Area::north);
    } else if (dir == "e" || dir == "east") {
        moveDirection(Area::east);
    } else if (dir == "s" || dir == "south") {
        moveDirection(Area::south);
    } else if (dir == "w" || dir == "west") {
        moveDirection(Area::west);
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
            printRoomRow(y*xSize);
    }

    std::cout<<"Information about visited rooms:\n";
    std::cout<<"@ -> you are here\n";
    for (auto &room: player.getRoomsVisited() ) {
        /*if ( area.isVisited() ) {
            std::cout<<area.getName()[0]<<": "<<area.getDescription()<<std::endl;*/
        std::cout<<room<<std::endl;
        }
    std::cout<<std::endl;
}

void Game::printRoomRow(int mazeRowFirstElementIndex) {
    //if all rooms in rows are empty, don't draw anything
    //Area* room = &area;
    int count = 0;
    for (int x = mazeRowFirstElementIndex; x < mazeRowFirstElementIndex+xSize; x++) {
        if ( !player.isRoomVisited(x) ) {
            ++count;
        }
    }
    if (count == xSize) {
        return;
    }
    //first row of draw
    for (int x = mazeRowFirstElementIndex; x < mazeRowFirstElementIndex+xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !player.isRoomVisited(x) ) {
            std::cout<<"     ";
        } else if ( maze[x]->toNorth ) {
            std::cout<<"+   +";
        } else {
            std::cout<<"+---+";
        }
    }
    std::cout<<std::endl;

    //second row of draw
    for (int x = mazeRowFirstElementIndex; x < mazeRowFirstElementIndex+xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !player.isRoomVisited(x) ) {
            std::cout<<"     ";
        } else if ( maze[x]->toWest ) {
            std::cout<<"    ";
            if ( maze[x]->toEast ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        } else {
            std::cout<<"|   ";
            if ( maze[x]->toEast ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        }
    }
    std::cout<<std::endl;

    //third row of draw
    for (int x = mazeRowFirstElementIndex; x < mazeRowFirstElementIndex+xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !player.isRoomVisited(x) ) {
            std::cout<<"     ";
        } else if ( maze[x]->toWest ) {
            std::cout<<"  "<<x<<" ";
            if ( maze[x]->toEast ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        } else {
            std::cout<<"| "<<x<<" ";
            if ( maze[x]->toEast ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        }
    }
    std::cout<<std::endl;


    //fourth row of draw
    for (int x = mazeRowFirstElementIndex; x < mazeRowFirstElementIndex+xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !player.isRoomVisited(x) ) {
            std::cout<<"     ";
        } else if ( maze[x]->toWest ) {
            std::cout<<"   ";
            if ( x == player.getPosition() ) {
                std::cout<<"@";
            } else {
                std::cout<<" ";
            }
            if ( maze[x]->toEast ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        } else {
            std::cout<<"|  ";
            if ( x == player.getPosition() ) {
                std::cout<<"@";
            } else {
                std::cout<<" ";
            }
            if ( maze[x]->toEast ) {
                std::cout<<" ";
            } else {
                std::cout<<"|";
            }
        }
    }
    std::cout<<std::endl;

    //fifth row of draw
    for (int x = mazeRowFirstElementIndex; x < mazeRowFirstElementIndex+xSize; x++) {
        //std::cout<<(room+x)->getName()<<" "<<(room+x)->isVisited()<<" | ";
        if ( !player.isRoomVisited(x) ) {
            std::cout<<"     ";
        } else if ( maze[x]->toSouth ) {
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
            restWords = removeWhitespace(restWords);
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
        moveTo(restWords);
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
        showMap();
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
    //areas[player.getPosition()].setVisited();
    player.setRoomVisited(player.getPosition());
    showMap();

    std::cout<<"Congratulations, you have reached the End room and won the game!"<<std::endl;
}

bool Game::step() {
    do {
        int pos = player.getPosition();
        std::cout<<"You are now in room nr "<<pos<<std::endl;//", "<<areas[pos].getDescription()<< std::endl;
        player.setRoomVisited(pos);//areas[pos].setVisited();
        printItemsInRoom(getItems(pos));
        //const int* dirs = areas[pos].getValidDirs();
        std::cout<<"You can go to ";
        if (maze[pos]->toNorth) std::cout << " north";
        if (maze[pos]->toEast) std::cout << " east";
        if (maze[pos]->toSouth) std::cout << " south";
        if (maze[pos]->toWest) std::cout << " west";
        std::cout<<std::endl;
        /*string dir;
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
        */
        handleUserInput();
    } while (player.getPosition() != endRoomIndex);
    return true;
}

