#include "enemies.h"
#include "raylib.h"
#include <iostream>
#include <cmath>

/*
Reese Combat and enemy creation/movement
*/


void classEnemy::moveLeft(int distance) {
    world_position[0] -= distance;
}

void classEnemy::moveRight(int distance) {
    world_position[0] += distance;
}

void classEnemy::moveUp(int distance) {
    world_position[1] -= distance;
}

void classEnemy::moveDown(int distance) {
    world_position[1] += distance;
}

void classEnemy::render() {
    DrawRectangle(world_position[0], world_position[1], 50, 50, RED);
    DrawText(TextFormat("HP: %d", health), world_position[0], world_position[1] - 20, 12, WHITE);
}

void classEnemy::takeDamage(int damage) {
    int effectiveDamage = damage - defence;
    if (effectiveDamage > 0) {
        health -= effectiveDamage;
    }
    if (health <= 0) {
        std::cout << "Enemy defeated!" << std::endl;
    }
}


bool classEnemy::checkCollision(Vector2 playerPos, float attackRange) {
    float dx = playerPos.x - world_position[0];
    float dy = playerPos.y - world_position[1];
    float distance = sqrt(dx * dx + dy * dy);

    return distance < attackRange;
}