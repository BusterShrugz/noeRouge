#pragma once
#include <cstdio>
#pragma once
#include "raylib.h"
#include "character.h"
#include "object.h"
#include "enemies.h"   // Include enemy for collision check
#include <vector>


class player : public Character {
private:
    float attackRange;  // Melee range
    int attackDamage;      // Damage dealt outbound
    

public:
    player(int id): Character(id) { }
    player(int id, Vector2 _position, Vector2 _size, int _speed) 
        : Character(id, _position, _size, _speed) { }
    
    void onRender() override;

    void updateDirection() override;

    void meleeAttack(std::vector<classEnemy*>& enemies);

    // Define the player crate function in the object handler
    static player* createPlayer(objectHandler& handler, Vector2 position, Vector2 size, int speed);
};



