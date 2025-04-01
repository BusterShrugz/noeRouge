#pragma once
#include <cstdlib>
#include "raylib.h"
#include <iostream>

class classEnemy {
private:
    int world_position[2];
    int local_position[2];
    // Inventory is a float array of item ids
    // The decimal value can be used for item durrabilty (if applicible)
    float *inventoryPtr;
    int health;
    int defence;
    char graphic;
    // etc...

public:
    // Constructor
    classEnemy(int x, int y, int hp, int def, char gfx)
        : health(hp), defence(def), graphic(gfx)
    {
        world_position[0] = x;
        world_position[1] = y;
        local_position[0] = x;
        local_position[1] = y;
        inventoryPtr = nullptr;  // No inventory for now
    }

    ~classEnemy() {
        if (inventoryPtr) {
            delete[] inventoryPtr;
        }
    }

    //Movement methods
    void moveLeft(int distance);
    void moveRight(int distance);
    void moveUp(int distance);
    void moveDown(int distance);

    //interaction methods
    void render();
    void takeDamage(int damage);

    // Collision detection
    bool checkCollision(Vector2 playerPos, float attackRange);

    // Getter for position
    Vector2 getPosition() const {
        return { static_cast<float>(world_position[0]), static_cast<float>(world_position[1]) };
    }
    int getHealth() const { return health; }
};
