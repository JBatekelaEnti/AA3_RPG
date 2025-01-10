#pragma once
#include "MapPosition.h"
struct Enemy {
    int health;
    int maxHealth;
    int stamina;
    int maxStamina;
    bool isDead;
    MapPosition position;

    Enemy(int x, int y);
    Enemy();
};