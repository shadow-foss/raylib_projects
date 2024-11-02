#pragma once
#include <raylib.h>

class player {
private:
    Texture2D spritesheet;
    Vector2 position;
    Rectangle sprite;
    float speed;
    short direction; // left = -1, idle = 0, right = 1 
    float jumpHeight;
    float initialjumpPos;
    float jumpSpeed;
    bool isJumping;
    float gravity;
    float floorPos;
    short frame;
    float animRuntime;
    float animUpdatetime;

public:
    void setFloorPos(float Pos);
    bool isOnFloor();
    void loadSprite();
    player(float x, float y);
    void updatePos(float deltaTime);
    void updateAnim(float deltaTime);
    void drawplayer();
    Vector2 getPosition() const;


};

