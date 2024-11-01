#pragma once
#include <raylib.h>

class player {
private:
    Texture2D texture;
    Vector2 position;
    float speed;
    float gravity;
    float jumpHeight;
    short direction; // left = -1, idle = 0, right = 1 
    Rectangle sprite;
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

