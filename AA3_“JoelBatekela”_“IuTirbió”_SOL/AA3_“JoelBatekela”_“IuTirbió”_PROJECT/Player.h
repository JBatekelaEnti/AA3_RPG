#pragma once
#include <ctime>
#include "MapPosition.h"
#include "Potion.h"
#include "vector"
#include "cstdlib"
#include "cstdio"


struct Player {
    int gold;
    int health;
    int maxHealth;
    int stamina;
    int maxStamina;
    int agility;
    MapPosition position;
    std::vector<Potion> potionBag;

    Player();

    void UsePotion() {
        if (potionBag.empty()) {
            printf("No potions left\n");
            return;
        }
        Potion& potion = potionBag.back();
        int healing = (int)(0.4 * maxHealth);
        health = (health + healing > maxHealth) ? maxHealth : health + healing;
        potionBag.pop_back();
        printf("Used a potion. Current health: %d\n", health);
    }

    void Move(char direction) {
        if (agility <= 0) {
            printf("No moves left!\n");
            return;
        }
        switch (direction) {
        case 'W': if (position.y > 0) position.y--; break;
        case 'A': if (position.x > 0) position.x--; break;
        case 'S': if (position.y < 4) position.y++; break;
        case 'D': if (position.x < 4) position.x++; break;
        default: printf("Invalid move\n"); return;
        }
        agility--;
        printf("Moved to position (%d, %d)\n", position.x, position.y);
    }
};