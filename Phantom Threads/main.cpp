#include <raylib.h>
#include "player.h"
int main() {
	//DECLARING GAME VARIABLES
	float deltaTime;
	bool running = true;

	//DECALRING SCREEN SIZE
	const int screenHeight = 360;
	const int Screenwidth = 640;
	//INITIALIZING WINDOW AND LOCKS FPS
	InitWindow(Screenwidth, screenHeight, "Phantom Threads");
	SetTargetFPS(60);
	Texture2D Bg = LoadTexture("data/bg.png");
	//CREATES A PLAYER GHOST
	player ghost(0.f, 236.f);
	ghost.loadSprite();
	ghost.setFloorPos(236.f);

	//CREATING A CAMERA
	ghost.setCamera();

	while (running) {
		deltaTime = GetFrameTime();
		ghost.updatePos(deltaTime);
		ghost.updateAnim(deltaTime);
		ghost.updateCamerapos();

		BeginDrawing();
		ClearBackground(GRAY);
		BeginMode2D(ghost.getCamera());
		DrawTexture(Bg, 0, 0, WHITE);
		ghost.drawplayer();
		DrawRectangle(0, 300, 1500, 55, BLACK);
		EndMode2D();
		EndDrawing();


	}
}