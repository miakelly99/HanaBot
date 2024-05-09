cmake_minimum_required(VERSION 3.26)

set(CMAKE_BUILD_TYPE Debug)

project(HanabBots
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

file(GLOB SOURCES
    src/agents/*.cpp
    src/game/*.cpp
    include/*.h
    include/agents/*.h
    include/game/*.h
    include/game/actions/*.h
)

add_executable(TestPlayFirstAgent src/execs/test_play_first_agents.cpp ${SOURCES})