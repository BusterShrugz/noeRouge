#ifndef H_OBJECT
#define H_OBJECT
#include <cstdio>
#include <vector>
#include "raylib.h"
#include "player.h"   // Include player 

/*
// TODO list:
//
// 00 - maybe rename this to something that makes more sense?
//
*/

class gameObject {
private:
    int id;

public:
    
    gameObject() {}
    gameObject(int id) {
        this->id = id;
    }
    virtual~gameObject() {
        // No memory is currently allocated, do nothing
        ;;
    }

    // Getters
    int getId();
    // Setters
    void setId(int id);

    virtual void onTick();
    virtual void onRender();
};

class objectHandler {
private:
    int numberOfObjects;
    int nextId;
    std::vector<class gameObject *> allObjects;

public:
    objectHandler() : numberOfObjects(0), nextId(0) {}
    ~objectHandler();

    void tickAll();
    void renderAll();
    class gameObject *getObject(int id);
    class gameObject *createObject();

    //create player
    player *createPlayer(Vector2 position, Vector2 size, int speed);
};

#endif
