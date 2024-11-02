#include <raylib.h>
#include "player.h"

//CONSTRUCTOR
player::player(float x, float y) :position({ x,y }), speed(100.f), direction(0), jumpHeight(60.f), jumpSpeed(150.f), isJumping(false), gravity(50.f), frame(0), animRuntime(0.f), animUpdatetime((float)1.f / 8.f), offset({320.f,0.f}), targetpos({position.x,0}) { sprite = {0,0,32.f,32.f}; }


//LOAD SPRITE SHEET
void player::loadSprite() {
	spritesheet = LoadTexture("data/ghost.png");
}

//FUNCTION TO SET FLOOR POSITION
void player::setFloorPos(float Pos) {
	floorPos = Pos;
}

//TO CHECK IF PLAYER IS COLLIDING WITH FLOOR
bool player::isOnFloor() {
	if ((position.y ) >= floorPos) {
		return true;
	}
	else {
		return false;
	}
	
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
	if ( (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)) && !isJumping && isOnFloor()) {
		initialjumpPos = position.y;
		isJumping = true;
	}
	if (isJumping) {
		
		position.y -= jumpSpeed* deltaTime;
		if (position.y <= (initialjumpPos - jumpHeight)) {
			isJumping = false;
		}
		
	}
	//GRAVITY MECHANISM
	if (!isOnFloor()&& !isJumping) {
		position.y += gravity * deltaTime;
	}
}
//FUNCTION TO UPDATE ANIMATIONS

void player::updateAnim(float deltaTime) {
	//SETS ANIM TO BE PLAYED AS PER STATE OF PLAYER, values of sprite.y idle = 0,movemment = 32,hover/jump =64
	
	//MOVE LEFT ANIM
	if (direction == -1) {
		sprite.y = 32;     
		(sprite.width > 0) ? sprite.width *= -1 : sprite.width *= 1;  //FLIPS THE SPRITE 
	}
	//MOVE RIGHT ANIM
	else if (direction == 1) {
		sprite.y = 32;
		(sprite.width < 0) ? sprite.width *= -1 : sprite.width *= 1;  //FLIPS THE SPRITE
	}
	//IDLE ANIM
	else if (direction == 0) {
		sprite.y = 64; 
	}
	//ANIM PLAYER
	animRuntime += deltaTime;
	if (animRuntime >= animUpdatetime) {
		animRuntime = 0.f;
		sprite.x = (float)frame * 32.f;
		frame ++;
		if (frame > 5) {
			frame = 0;
		}

	}
}

void player::drawplayer(){
	DrawTextureRec(spritesheet, sprite, position,WHITE);
}
Vector2 player::getPosition() const {
	return position;
}

//SETTING CAMERA
void player::setCamera() {
	playercam.offset = offset;
	playercam.target = targetpos;
	playercam.rotation = 0.f;
	playercam.zoom = 1.f;

}
//UPDATES THE CAMERA POSITION TO PLAYER POSITION
void player::updateCamerapos() {
	targetpos = { position.x,0 };
	if (targetpos.x < 320) {
		targetpos = {320,0};
	}
	playercam.target = targetpos;
}
//RETURNS THE PLAYER CAM TO BE DRAWN IN MAIN
Camera2D player::getCamera() const {
	return playercam;
}
