// noeRouge - Terminal rouge-like ascii dungeon crawler game

// Includes
#include <iostream>
#include <vector>
#include <cstdlib>
#include "raylib.h"

// Local includes
#include "object.h"
#include "globals.h"
#include "player.h"       // Add player header
#include "enemies.h"        // Add enemy header

// Map generation
#include "mapGen.h"
/*
// TODO list (class voted it to be here)
// This list is worse than a todo at each thing because you have to just figure
// out where to work on each item listed here
//
// Doing it this way is objectivly worse in every way and has only
// disadvantages. I will comply but I beg that everyone agrees to 
// do it the other way instead
//
// 00 - Create a "game" class that holds deltatime, the map, the handlers, and
//      the game loop isRunning flag. This object will be global
// 01 - Game loop with time code
*/

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 450;
constexpr int FPS = 60;
constexpr int PLAYER_SPEED = 300;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "noeRouge alpha v0.1");
    SetTargetFPS(FPS);

        // Create the objectHandler
    objectHandler objectHandler;
    
    // Player instance
    player* player1 = objectHandler.createPlayer(
        { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f },
        { 30, 30 },
        PLAYER_SPEED
    );

       // Create enemies
    std::vector<classEnemy*> enemies = {
        new classEnemy(400, 300, 100, 5, 'E'),
        new classEnemy(600, 400, 120, 10, 'E'),
        new classEnemy(500, 350, 80, 3, 'E')
    }; 
    
    // Print version info
    std::cout << "noeRouge alpha v0.1\n";

        // driver code - just for testing before real driver code
    while (!WindowShouldClose())
    {
        // Update
        player1->updateDirection();
        player1->meleeAttack(enemies);

        //render
        BeginDrawing();
        ClearBackground(BLACK);

        // Render player and enemies
        player1->onRender();

        for (classEnemy*& enemy : enemies) {
            enemy->render();
        }

        // for testing purposes only
        for (Rectangle rect : globals::GetCollisionRectangles())
        {
           DrawRectangle( 5,8,24,25, DARKBLUE );
            
        }

        EndDrawing();
    }

    // Cleanup
    delete player1;
    for (auto& enemy : enemies) {
        delete enemy;
    }

    CloseWindow();
    return 0;
}
