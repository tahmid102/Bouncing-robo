#include "iGraphics.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char message[] = "HAPPY NEW YEAR!";
int messageLength = 0;
int screenWidth = 800, screenHeight = 600;
int fallingStars[50][2];
int starSpeed = 5;

// Falling stars with color variations
void drawFallingStars() {
    for (int i = 0; i < 50; i++) {
        int red = rand() % 256;
        int green = rand() % 256;
        int blue = rand() % 256;
        iSetColor(red, green, blue);
        iFilledCircle(fallingStars[i][0], fallingStars[i][1], 3);
    }
}

// Update stars' positions
void updateFallingStars() {
    for (int i = 0; i < 50; i++) {
        fallingStars[i][1] -= starSpeed;
        if (fallingStars[i][1] < 0) {
            fallingStars[i][1] = screenHeight;
            fallingStars[i][0] = rand() % screenWidth;
        }
    }
}

// Gradually reveal the message
void drawLetters() {
    iSetColor(0, 255, 0);
    for (int i = 0; i < messageLength; i++) {
        char letter[2] = {message[i], '\0'};
        iText((screenWidth / 2) - 150 + i * 30, screenHeight / 2, letter, GLUT_BITMAP_HELVETICA_18);
    }
}

void increaseMessageLength() {
    if (messageLength < strlen(message)) {
        messageLength++;
    }
}

// iGraphics draw loop
void iDraw() {
    iClear();

    // Background gradient
    for (int i = 0; i < screenHeight; i++) {
        iSetColor(0, 0, 50 + i / 5);
        iLine(0, i, screenWidth, i);
    }

    drawFallingStars();
    drawLetters();
}

// Setup function for initializations
void iSetUp() {
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < 50; i++) {
        fallingStars[i][0] = rand() % screenWidth;
        fallingStars[i][1] = rand() % screenHeight;
    }
}

// Main function
int main() {
    iSetUp();
    // Ensure timers are set correctly
    iSetTimer(50, updateFallingStars);
    iSetTimer(500, increaseMessageLength);
    // Initialize iGraphics
    iInitialize(screenWidth, screenHeight, "Happy New Year Animation");
    return 0;
}
