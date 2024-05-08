cmake_minimum_required(VERSION 3.26)

project(HanabBots
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


include_directories(include/)

add_library(DeckLib src/game/deck.cpp)