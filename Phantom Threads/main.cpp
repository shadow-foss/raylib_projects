#include <raylib.h>
#include "player.h"
int main() {
	bool running = true;
	const int screenHeight = 720;
	const int Screenwidth = 1280;
	InitWindow(Screenwidth/2, screenHeight/2, "Phantom Threads");
	player ghost(0, 300);
	ghost.loadSprite();
	while (running) {
		ghost.updatePos(GetFrameTime());
		ghost.updateAnim();
		BeginDrawing();
		ClearBackground(GRAY);
		ghost.drawplayer();


		EndDrawing();


	}
}