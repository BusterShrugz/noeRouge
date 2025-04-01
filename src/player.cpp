#include "player.h"
#include "object.h"
#include "enemies.h"

using namespace std;

player* player::createPlayer(objectHandler& handler, Vector2 position, Vector2 size, int speed) {
    player* newPlayer = new player(handler.nextId++, position, size, speed);
    handler.allObjects.push_back(newPlayer);
    handler.numberOfObjects++;
    return newPlayer;
}

void player::updateDirection()
{
    if (IsKeyDown(KEY_A))
    {
        direction.x = -1;
    }
    else if (IsKeyDown(KEY_D))
    {
        direction.x = 1;
    }
    if (IsKeyDown(KEY_S))
    {
        direction.y = 1;
    }
    else if (IsKeyDown(KEY_W))
    {
        direction.y = -1;
    }
}

void player::onRender()
{
    Rectangle rectangle = bounds();
    DrawRectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height, GREEN);
}

void player::meleeAttack(std::vector<classEnemy*>& enemies) {
    if (IsKeyPressed(KEY_SPACE)) {  // Attack with SPACE
        for (classEnemy* enemy : enemies) {
            if (enemy->checkCollision(position, attackRange)) {
                enemy->takeDamage(attackDamage);
                std::cout << "Hit enemy! Health: " << enemy->getHealth() << std::endl;

                // Display hit effect
                DrawText("HIT!", enemy->getPosition().x, enemy->getPosition().y - 30, 20, RED);
            }
        }
    }
}
