#include <raylib.h>
#include "player.h"

//CONSTRUCTOR
player::player(float x, float y) :position({ x,y }), speed(150.f), gravity(9.81f), jumpHeight(50.f), direction(0), isJumping(false), frame(0) { sprite = { 0,0,32.f,32.f }; }

//LOAD SPRITE SHEET
void player::loadSprite() {
	texture = LoadTexture("data/ghost.png");
}

//TO CHECK IF PLAYER IS COLLIDING WITH FLOOR
bool player::isOnFloor() {
	return true;
}

//UPDATE POSITION - PLAYER MOVEMENT CODE
void player::updatePos(float deltaTime) {
	
	//MOVE RIGHT
	if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && !(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) {
		position.x += speed * deltaTime;
		direction = +1;
	}

	//MOVE LEFT
	else if ((IsKeyDown(KEY_LEFT)||IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))){
		position.x -= speed * deltaTime;
		direction = -1;
	}
	//IF NOTHING IS PRESSED IT SETS STATE TO IDLE IE direction = 0
	else {
		direction = 0;

	}
	//JUMPING MECHANISM WIP
	if ( (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) && !isJumping && isOnFloor()) {
		isJumping = true;
	}
	if (isJumping) {
		position.y -= jumpHeight * deltaTime;
		isJumping = false;
	}
}
//FUNCTION TO UPDATE ANIMATIONS

void player::updateAnim() {
	//SETS ANIM TO BE PLAYED AS PER STATE OF PLAYER, values of sprite.y idle = 0,movemment = 32,hover/jump =64
	if (direction == -1) {
		sprite.y = 32;
	}
	else if (direction == 1) {
		sprite.y = 32;
	}
	else if (direction == 0) {
		sprite.y = 0;
	}
}
void player::drawplayer(){
	DrawTextureRec(texture, sprite, position,WHITE);
}
Vector2 player::getPosition() const {
	return position;
}





