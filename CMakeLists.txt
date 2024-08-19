# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(BlackJack CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add executable target
add_executable(BlackJack
    src/main.cpp
    src/Cards.cpp
    src/Game.cpp
)

#set(CMAKE_BUILD_TYPE Release)
