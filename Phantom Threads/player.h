#pragma once
#include <raylib.h>

class player {
private:
    Texture2D texture;
    Vector2 position;
    Rectangle sprite;
    int frame;
    float speed;
    float gravity;
    float jumpHeight;
    int direction; // left = -1, idle = 0, right = 1 
    bool isJumping;

public:
    bool isOnFloor();
    void loadSprite();
    player(float x, float y);
    void updatePos(float deltaTime);
    void updateAnim();
    void drawplayer();
    Vector2 getPosition() const;


};

