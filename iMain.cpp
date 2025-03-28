#include <GL/glut.h>
#include "iGraphics.h"

#define screenWidth 1500
#define screenHeight 750







int x=0,y=0;
int p=0;
int q=0;
int r=0,g=0,b=0;


// Function to draw something on the screen
void iDraw() {
    iClear(); // Clears the window

    // Example: Draw a red rectangle
    iSetColor(255, 255, 0); 
    iLine(x+15,y+0,x+45,y+0);
    iLine(x+15,y,x+5,y+10);
    iLine(x+45,y,x+55,y+10); 
    iLine(x+5,y+10,x+10,y+35);
    iLine(x+55,y+10,x+50,y+35);
    iLine(x+10,y+35,x+15,y+45);
    iLine(x+50,y+35,x+45,y+45);
    iLine(x+15,y+45,x+45,y+45);
    iSetColor(255, 0, 0);
    iLine(x+30,y+30,x+25,y+22.5);
    iLine(x+30,y+30,x+35,y+22.5);
    iLine(x+25,y+22.5,x+35,y+22.5);
    iSetColor(r, g, b);
    iText(0,0,"I LOVE TISHMA",GLUT_BITMAP_HELVETICA_10);
    iFilledRectangle(x+20,y+10,20,5);
    iFilledCircle(x+20,y+30,2.5);
    iFilledCircle(x+40,y+30,2.5);
    iCircle(x+20,y+30,5);
    iCircle(x+40,y+30,5);
    
    iSetColor(255,255,0);
    iFilledRectangle(p,q,100,20);





    
    
    
}
/*void iMouse(int button, int state, int a, int b) {
    // handle mouse click events
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) x=a;y=b;
}*/
void iMouseMove(int x, int y) {
    // handle mouse movement
}
void iKeyboard(unsigned char key) {
    // handle keyboard input
    if(key=='w') q+=10;
    else if(key=='d')p+=10;
    else if(key=='a')p-=10;
    else if(key=='s')q-=10;
    else if(key=='r')r=(r+10)%255;
    else if(key=='g')g=(g+10)%255;
    else if(key=='b')b=(b+10)%255;
    iDraw();
}
void iSpecialKeyboard(unsigned char key) {
    // handle special keyboard input (arrow keys, function keys, etc.)
    if(key==GLUT_KEY_RIGHT)p+=10;
    else if(key==GLUT_KEY_UP)q+=10;
    else if(key==GLUT_KEY_DOWN)q-=10;
    else if(key==GLUT_KEY_LEFT)p-=10;
}
 int dx=5,dy=5;
void change()
{
   
    x+=dx; y+=dy;
    if(x+55>=screenWidth || x<=0) dx=dx*(-1);
    if(y+45>=screenHeight || y<=0) dy=dy*(-1);
    r=(r+10)%255;
    g=(g+6)%255;
    b=(b+20)%255;

}
int main() {
    iSetTimer(.1,change);
    iInitialize(screenWidth, screenHeight, "Noob trying");
    return 0;
}
