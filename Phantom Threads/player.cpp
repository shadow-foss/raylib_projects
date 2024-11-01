#include <raylib.h>
#include "player.h"

//CONSTRUCTOR
player::player(float x, float y) :position({ x,y }), speed(200.f), gravity(9.81f), jumpHeight(50.f), direction(0), isJumping(false) {}

//LOAD SPRITE SHEET
void player::loadSprite() {
	texture = LoadTexture("data/ghost.png");
}
//UPDATE POSITION - PLAYER MOVEMENT CODE
void player::updatePos(float deltaTime) {
	
	//MOVE RIGHT
	if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
		position.x += speed * deltaTime;
		direction = 1;
	}

	//MOVE LEFT
	if (IsKeyDown(KEY_LEFT)||IsKeyDown(KEY_A)){
		position.x -= speed * deltaTime;
		direction = -1;
	}
	else {
		direction = 0;

	}
	if ( (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) && !isJumping && isOnFloor()) {
		isJumping = true;
	}
	if (isJumping) {
		position.y += jumpHeight * deltaTime;
	}
}
void player::updateAnim() {
	//sprite anim for left side movement
	              

	if (direction == -1) {

	}
	if (direction = 1) {

	}
	if (direction = 0) {

	}
}
void player::drawplayer(){}






