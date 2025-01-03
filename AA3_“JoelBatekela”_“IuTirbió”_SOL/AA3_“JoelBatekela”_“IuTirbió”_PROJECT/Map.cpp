#include "Map.h"

Map::Map() : numEnemies(7), numChests(2) 
{
    InitializeGame();
}

void Map::InitializeGame()
{
    // Clear map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '.'; // Empty space
        }
    }

    // Place player
    map[player.position.y][player.position.x] = 'P';

    // Spawn enemies
    for (int i = 0; i < numEnemies; i++) {
        int x, y;
        do {
            x = rand() % MAP_SIZE;
            y = rand() % MAP_SIZE;
        } while (map[y][x] != '.');
        enemies[i] = Enemy(x, y);
        map[y][x] = 'E';
    }

    // Spawn chests
    for (int i = 0; i < numChests; i++) {
        int x, y;
        do {
            x = rand() % MAP_SIZE;
            y = rand() % MAP_SIZE;
        } while (map[y][x] != '.');
        chests[i] = Chest(x, y);
        map[y][x] = 'C';
    }
}

void Map::RenderMap()
{
    printf("---------------------DUNGEON---------------------\n");
    printf("E -> Enemy\t    P -> Player\t    C -> Chest\n");

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == '.') {
                printf("[ ] "); 
            }
            else {
                printf("[%c] ", map[i][j]);  
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("W A S D -> Move\n");
    printf("P -> Potion\n");
}

