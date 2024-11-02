#pragma once
#include <raylib.h>

class player {
private:
    //loading sprites
    Texture2D spritesheet;
    Vector2 position;
    Rectangle sprite;
    //physics variables
    float speed;
    short direction; // left = -1, idle = 0, right = 1 
    float jumpHeight;
    float initialjumpPos;
    float jumpSpeed;
    bool isJumping;
    float gravity;
    float floorPos;
    //animation player variables
    short frame;
    float animRuntime;
    float animUpdatetime;

    //camera variables
    Camera2D playercam;
    Vector2 offset;
    Vector2 targetpos;
public:
    player(float x, float y);
    void loadSprite();
    void setFloorPos(float Pos);
    bool isOnFloor();
    void updatePos(float deltaTime);
    void updateAnim(float deltaTime);
    void drawplayer();
    Vector2 getPosition() const;
    void setCamera();
    void updateCamerapos();
    Camera2D getCamera() const;

};

