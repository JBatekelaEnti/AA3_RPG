#pragma once
#include "MapPosition.h"
struct Chest {
    int gold;
    bool containsPotion;
    bool isLooted;
    MapPosition position;

    Chest()
    {
        position.x = rand() % 5;
        position.y = rand() % 5;
        isLooted = false;
        gold = rand() % 151 + 50; // Random 50-200
        containsPotion = (rand() % 4 == 0); // 25% chance
    }

    Chest(int x, int y): position(x,y)
    {
       
        isLooted = false;
        gold = rand() % 151 + 50; // Random 50-200
        containsPotion = (rand() % 4 == 0); // 25% chance
    }
};