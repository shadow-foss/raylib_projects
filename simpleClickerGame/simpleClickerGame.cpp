#include <iostream>
#include <raylib.h>
#include <string>
#include <raymath.h>

typedef enum GameScreen { MAINMENU , GAME , WIN } GameScreen; // CREATING AN ALIAS FOR THE ENUM

int main() {
    bool running = true; //  control variable for the main loop

    // Score variables
    int score{ 0 };
    std::string scoreLabel{ "Score:0" }; // Label to display score

    int colour_code = 0; // Index for circle color

    // Parameters for the circle
    Vector2 circlePos{ 400,400 };
    float circleRadius{ 60 };

    // Array of colors for the circle
    Color circleColors[15] = { PINK, RED , MAROON, ORANGE, GOLD, YELLOW, GREEN, LIME,
                               DARKGREEN, DARKBLUE, BLUE, SKYBLUE, PURPLE, VIOLET, DARKPURPLE };

    // Background color and window size
    Color GAMEBG{ LIGHTGRAY };
    const int screenHeight{ 800 };
    const int screenWidth{ 800 };

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "SIMPLE CLICKER GAME - RAYLIB");
    // Lock the frames per second to 75
    SetTargetFPS(75);

    // Enable anti-aliasing
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    GameScreen currentScreen = MAINMENU; // Set initial screen to MAINMENU

    // Main game loop
    while (running) {
        // Check for window close button
        if (WindowShouldClose() && IsKeyUp(KEY_ESCAPE)) {
            running = false; // Stop the loop
            CloseWindow(); // Close the window
        }
        BeginDrawing(); // Start drawing the frame
        
        switch (currentScreen) {
        case MAINMENU: {
            ClearBackground(SKYBLUE);                  // creates a bg with sky blue
            DrawText("MAIN MENU", 200, 100, 60, RED);  // Display main menu title
            DrawRectangle(295, 290, 150, 60, VIOLET);  // start button
            DrawText("Start", 310, 300, 45, RAYWHITE); // start game text
            DrawRectangle(295, 430, 150, 60, VIOLET);  // exit button
            DrawText("EXIT", 315, 440, 45, RAYWHITE);

            // Check for mouse click to start the game
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
                && (((295 < GetMouseX() && GetMouseX() < 495))
                    && (290 < GetMouseY() && GetMouseY() < 350))) {
                currentScreen = GAME; // Transition to GAME screen on click
            }

            // Check for exit button click
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
                && (((295 < GetMouseX() && GetMouseX() < 495))
                    && (430 < GetMouseY() && GetMouseY() < 490))) {
                running = false;  // Set running to false to exit
                CloseWindow();    // Close the window
            }

            break; // Exit MAINMENU case
        }

        case GAME: {
            //Gets mouse position 
            Vector2 mousePosition = GetMousePosition();
            Vector2 toMouseVector = Vector2Subtract(mousePosition, circlePos);
            float dotVector = toMouseVector.x * toMouseVector.x + toMouseVector.y * toMouseVector.y;


            ClearBackground(GAMEBG);                                                       // creates a bg with color from GAMEBG variable
            DrawCircle(circlePos.x, circlePos.y, circleRadius, circleColors[colour_code]); // Draws a circle
            DrawFPS(700, 20);                                                              // Draws or displays FPS on screen
            DrawText(scoreLabel.c_str(), 600, 120, 36, YELLOW);                            // Displays score
            DrawText("SIMPLE CLICKER GAME", 130, 50, 46, RED);                             // Displays a simple title for game


            // Check if mouse left button is pressed and if the mouse is inside the circle 
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (dotVector <= circleRadius * circleRadius))
            {

                score += 1;                                      // Increases score
                scoreLabel = ("Score:" + std::to_string(score)); // Sets a score label

                if (score < 20) {
                    circleRadius += 5; // Increase the circle size
                    colour_code += 1;  // Change circle color

                    if (colour_code > 14) {
                        colour_code = 0; // Loop back to the first color
                    }
                }
            }
            // Check if the player has won
            if (score >= 20) {
                currentScreen = WIN; // Transition to WIN screen
            }
            break;                   // Exit GAME case
        }

        case WIN: {
            ClearBackground(PURPLE);                    // creates a bg with sky blue
            DrawText("YOU WON", 230, 100, 60, RED);     // Display win message
            DrawRectangle(265, 290, 205, 60, BLUE);     // replay button
            DrawText("REPLAY", 280, 300, 45, RAYWHITE); // replay text
            DrawRectangle(295, 430, 150, 60, BLUE);     // exit button
            DrawText("EXIT", 315, 440, 45, RAYWHITE);   // exit text

            // Check for mouse click to replay the game
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
                && (((265 < GetMouseX() && GetMouseX() < 470))
                    && (290 < GetMouseY() && GetMouseY() < 350))) {

                //reseting the game variables to 0 or respective values since its restarting
                score = 0;
                scoreLabel = "Score:0";
                colour_code = 0;
                circleRadius = 60;

                currentScreen = GAME;   // Transition to GAME screen on click
            }

            // Check for exit button click
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
                && (((295 < GetMouseX() && GetMouseX() < 495))
                    && (430 < GetMouseY() && GetMouseY() < 490))) {
                running = false;   // Set running to false to exit
                CloseWindow();     // Close the window
            }
            break; // Exit WIN case
        }
        }
        EndDrawing(); // End drawing the frame
    }
    CloseWindow(); // Close the window and cleanup resources
    return 0; // Exit the program
}
