#include <GL/glut.h>
#include "iGraphics.h"

#define screenWidth 1500
#define screenHeight 800




void iMouseMove(int x, int y) {
    // handle mouse movement
}


int x=0,y=0;
int r=0,g=0,b=0;
char bc[1][10]={"bc\\1.bmp"};

// Function to draw something on the screen
void iDraw() {
    iClear(); // Clears the window

    // Example: Draw a red rectangle
    iSetColor(255, 255, 0); 
    iLine(x+150,y+0,x+450,y+0);
    iLine(x+150,y,x+50,y+100);
    iLine(x+450,y,x+550,y+100); 
    iLine(x+50,y+100,x+100,y+350);
    iLine(x+550,y+100,x+500,y+350);
    iLine(x+100,y+350,x+150,y+450);
    iLine(x+500,y+350,x+450,y+450);
    iLine(x+150,y+450,x+450,y+450);
    iSetColor(255, 0, 0);
    iLine(x+300,y+300,x+250,y+225);
    iLine(x+300,y+300,x+350,y+225);
    iLine(x+250,y+225,x+350,y+225);
    iSetColor(r, g, b);
    iText(0,0,"I LOVE TISHMA",GLUT_BITMAP_HELVETICA_10);
    iFilledRectangle(x+200,y+100,200,50);
    iFilledCircle(x+200,y+300,25);
    iFilledCircle(x+400,y+300,25);
    iCircle(x+200,y+300,50);
    iCircle(x+400,y+300,50);
    iShowBMP(0,0,bc[0]);





    
    
    
}
void iMouse(int button, int state, int a, int b) {
    // handle mouse click events
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) x=a;y=b;
}
void iKeyboard(unsigned char key) {
    // handle keyboard input
    if(key=='w') y+=10;
    else if(key=='d')x+=10;
    else if(key=='a')x-=10;
    else if(key=='s')y-=10;
    else if(key=='r')r=(r+10)%255;
    else if(key=='g')g=(g+10)%255;
    else if(key=='b')b=(b+10)%255;
    iDraw();
}
void iSpecialKeyboard(unsigned char key) {
    // handle special keyboard input (arrow keys, function keys, etc.)
    if(key==GLUT_KEY_RIGHT)x+=10;
    else if(key==GLUT_KEY_UP)y+=10;
    else if(key==GLUT_KEY_DOWN)y-=10;
    else if(key==GLUT_KEY_LEFT)x-=10;
}
 int dx=5,dy=5;
void change()
{
   
    x+=dx; y+=dy;
    if(x+600>=screenWidth || x<=0) dx=dx*(-1);
    if(y+400>=screenHeight || y<=0) dy=dy*(-1);
    r=(r+10)%255;
    g=(g+6)%255;
    b=(b+20)%255;

}
int main() {
    iSetTimer(.1,change);
    iInitialize(screenWidth, screenHeight, "Noob trying");
    return 0;
}
