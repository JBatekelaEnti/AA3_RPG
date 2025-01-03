#pragma once
#include "Player.h"
#include "Enemy.h"
#include  "Chest.h"
#define MAP_SIZE 5
struct Map
{
        Player player;
        Enemy enemies[7];
        Chest chests[2];
        char map[MAP_SIZE][MAP_SIZE];
        int numEnemies;
        int numChests;
        Map();

       

        void InitializeGame();

        void RenderMap();
};


