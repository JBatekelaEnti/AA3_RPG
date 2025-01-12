#include "Map.h"

Map::Map() : numEnemies(5), numChests(2)
{
    InitializeGame();
}

void Map::InitializeGame()
{
    // Clear map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = ' '; // Empty space instead of '.'
        }
    }

    // Place player
    map[player.position.y][player.position.x] = 'P';

    // Spawn enemies (5 enemies as shown in image)
    for (int i = 0; i < numEnemies; i++) {
        int x, y;
        do {
            x = rand() % MAP_SIZE;
            y = rand() % MAP_SIZE;
        } while (map[y][x] != ' ');
        enemies[i] = Enemy(x, y);
        map[y][x] = 'E';
    }

    // Spawn chests
    for (int i = 0; i < numChests; i++) {
        int x, y;
        do {
            x = rand() % MAP_SIZE;
            y = rand() % MAP_SIZE;
        } while (map[y][x] != ' ');
        chests[i] = Chest(x, y);
        map[y][x] = 'C';
    }
}


void Map::RenderMap()
{
    printf("------ DUNGEON ------\n\n");
    printf("E -> Enemy    P -> Player    C -> Chest\n\n");

    // Print status using your Player class members
    printf("Health: %d / %d\n", player.health, player.maxHealth);
    printf("Potions: %d / %d\n", (int)player.potionBag.size(), 3);
    printf("Moves: %d / %d\n\n", player.agility, player.maxStamina);

    // Render each row of the map
    for (int i = 0; i < MAP_SIZE; i++) {
        // Top border of cells
        for (int j = 0; j < MAP_SIZE; j++) {
            printf(" ---");
        }
        printf("\n");

        // Middle part: first empty row inside the cell
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("|   ");
        }
        printf("|\n");

        // Middle part: second row with potential content
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("| ");
            if (map[i][j] == ' ') {
                printf(" ");
            }
            else {
                printf("%c", map[i][j]);
            }
            printf(" ");
        }
        printf("|\n");

        // Middle part: third empty row inside the cell
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("|   ");
        }
        printf("|\n");
    }

    // Bottom border of the last row
    for (int j = 0; j < MAP_SIZE; j++) {
        printf(" ---");
    }
    printf("\n");

    printf("\nW A S D -> Move\n");
    printf("P -> Potion\n");
    printf("\nEnter your action: ");
}

