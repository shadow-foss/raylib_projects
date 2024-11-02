#include <raylib.h>
#include "player.h"
int main() {
	float deltaTime;
	bool running = true;

	const int screenHeight = 360;
	const int Screenwidth = 640;

	InitWindow(Screenwidth, screenHeight, "Phantom Threads");
	SetTargetFPS(60);
	player ghost(0.f, 270.f);
	ghost.loadSprite();
	ghost.setFloorPos(270.f);
	while (running) {

		deltaTime = GetFrameTime();
		ghost.updatePos(deltaTime);
		ghost.updateAnim(deltaTime);

		BeginDrawing();
		ClearBackground(GRAY);
		ghost.drawplayer();


		EndDrawing();


	}
}