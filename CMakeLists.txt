cmake_minimum_required(VERSION 3.16)

project(RPGConsole VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(rpg-console
    src/main.cpp
    src/App.cpp
    src/core/Archer.cpp
    src/core/Dragon.cpp
    src/core/Goblin.cpp
    src/core/Mage.cpp
    src/core/Orc.cpp
    src/core/Warrior.cpp
    src/factory/ArcherFactory.cpp
    src/factory/DragonFactory.cpp
    src/factory/GoblinFactory.cpp
    src/factory/MageFactory.cpp
    src/factory/OrcFactory.cpp
    src/factory/WarriorFactory.cpp
    src/ui/ConsoleUI.cpp
)

target_include_directories(rpg-console PRIVATE
    src
)
