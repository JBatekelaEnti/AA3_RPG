#include "Enemy.h"

Enemy::Enemy(int x, int y) : position(x, y), isDead(false) 
{
        health = maxHealth = rand() % 31 + 60; 
        stamina = maxStamina = rand() % 31 + 60; 
}

Enemy::Enemy()
{
    position.x = rand() % 5;
    position.y = rand() % 5;
    isDead = false;
    health = maxHealth = rand() % 31 + 60;
    stamina = maxStamina = rand() % 31 + 60;
}

