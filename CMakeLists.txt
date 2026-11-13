cmake_minimum_required(VERSION 3.16)

project(RPGConsole VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(rpg-console
    src/main.cpp
    src/App.cpp
    src/combat/AttackCommand.cpp
    src/combat/AttackReceiver.cpp
    src/combat/UseItemCommand.cpp
    src/combat/UseItemReceiver.cpp
    src/combat/MagicAttackStrategy.cpp
    src/combat/MeleeAttackStrategy.cpp
    src/combat/RangedAttackStrategy.cpp
    src/core/Archer.cpp
    src/core/Dragon.cpp
    src/core/Goblin.cpp
    src/core/Mage.cpp
    src/core/Orc.cpp
    src/core/Elixir.cpp
    src/core/Inventory.cpp
    src/core/Potion.cpp
    src/core/Sword.cpp
    src/core/Warrior.cpp
    src/factory/character/ArcherFactory.cpp
    src/factory/character/MageFactory.cpp
    src/factory/character/WarriorFactory.cpp
    src/factory/enemy/DragonFactory.cpp
    src/factory/enemy/GoblinFactory.cpp
    src/factory/enemy/OrcFactory.cpp
    src/factory/item/ElixirFactory.cpp
    src/factory/item/PotionFactory.cpp
    src/factory/item/SwordFactory.cpp
    src/ui/ConsoleUI.cpp
)

target_include_directories(rpg-console PRIVATE
    src
)
