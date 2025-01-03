#include "Player.h"

Player::Player() : gold(0), position(2, 2), agility(3) 
{
        srand(time(0));
        health = maxHealth = rand() % 21 + 90;
        stamina = maxStamina = rand() % 21 + 90;
}

