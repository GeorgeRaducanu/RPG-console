cmake_minimum_required(VERSION 3.16)

project(RPGConsole VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(rpg-console
    src/main.cpp
    src/App.cpp
    src/ui/ConsoleUI.cpp
)

target_include_directories(rpg-console PRIVATE
    src
)
