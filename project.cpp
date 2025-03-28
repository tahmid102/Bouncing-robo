
#include "iGraphics.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define screenWidth 1500
#define screenHeight 750
#define n 20
#define h 5

// Global variables
int show[h][n];
int x = 100, y = 20;
int p = 0, q = 0;
int r = 0, g = 0, b = 0;
int score = 0;
int reclen = 250;
int rechi = 20;
int cpage = 0;
int bricklen = 100;
int brickhi = 15;
int dx = 7, dy = 7;

// Function prototypes
void change();
void iDraw();

// Function definitions
void change() {
    x += dx;
    y += dy;

    if (x + 55 >= screenWidth || x <= 0) dx = -dx;
    if (y + 45 >= screenHeight) dy = -dy;

    if (y <= 25 && x + 55 >= p && x <= p + reclen) {
        dy = -dy;
        y = q + 26;
        score++;
    }

    if (y <= q + rechi && y > q && x + 55 >= p && x <= p + reclen) {
        float impact = (x + 27.5 - p) / reclen;
        dx = (impact - 0.5) * 10;
        dy = -dy;
        if (fabs(dx) < 2) dx = dx < 0 ? -2 : 2;
        score++;
    }
}

void iDraw() {
    iClear();
    iSetColor(255, 255, 0);
    iFilledRectangle(p, q, reclen, rechi);

    for (int j = 0; j < h; j++) {
        for (int i = 0; i < n; i++) {
            if (!show[j][i]) {
                iSetColor(255, 0, 0);
                iFilledRectangle(400 + (bricklen + 5) * i, 400 + (brickhi + 5) * j, bricklen, brickhi);
            }
        }
    }
}

int main() {
    iSetTimer(10, change);
    iInitialize(screenWidth, screenHeight, "Noob trying");

    for (int j = 0; j < h; j++) {
        for (int i = 0; i < n; i++) {
            show[j][i] = 0;
        }
    }

    return 0; // End of main
} // Ensure this is the final closing brace
