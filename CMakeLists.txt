cmake_minimum_required(VERSION 3.8)
project(cpp_2nd_tw_mighty_text_adventure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Area.hpp Game.cpp Game.h Player.cpp Player.h Item.cpp Item.h)
add_executable(cpp_2nd_tw_mighty_text_adventure ${SOURCE_FILES} Player.cpp Player.h)