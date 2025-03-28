#include "iGraphics.h"
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define screenWidth 1500
#define screenHeight 750
#define n 20
#define h 16
#define levels 3
 


int level =0;

int show[levels][h][n]={
{1,1,1,1,1,-1,-1,-1,0,0,-1,-1,-1,3,1,1,1,1,1,1,
1,1,1,1,1,0,0,-1,0,0,-1,0,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,-1,-1,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

{1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,
1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

{1,1,1,1,1,0,0,0,1,1,0,0,0,0,-1,-1,1,1,1,1,
1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}


};   

int x=550,y=2;
int p=0,q=0;
int r=0,g=0,b=0;

int angle=0;
float v=10;
int life =3;
int dx=7,dy=7;


int score=0;
char output[50];
int reclen = 220;
int rechi=20;
int cpage=-2;
int bricklen=45;
int brickhi=15;
char somoy[50];

int times=0;
 
int initial=0; 

/*void startMusic() {
    PlaySound("C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\sound.wav", NULL,  SND_FILENAME | SND_ASYNC | SND_LOOP);
}*/
void iDraw() {

    if(cpage==-1)
    {
        iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\roboback.bmp");
        iSetColor(255,255,255);
        iText(800,600,"PRESS SPACE TO BREAK CSE",GLUT_BITMAP_TIMES_ROMAN_24);

       

    }//home

    if(cpage==-2){
        iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\MENURIEL.bmp");
    }
    if(cpage==0){

        //iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\bggame.bmp");
    iClear(); // Clears the window
  

    // Example: Draw a red rectangle
    iSetColor(r, g, b);
    /*iLine(x+15,y+0,x+45,y+0);
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
    iLine(x+25,y+22.5,x+35,y+22.5);*/
    
    iSetColor(255,0,233);
    iText(200,400,"OH ROBO  ME",GLUT_BITMAP_HELVETICA_18);
    
    /*iFilledRectangle(x+20,y+10,20,5);
    iFilledCircle(x+20,y+30,2.5);
    iFilledCircle(x+40,y+30,2.5);
    iCircle(x+20,y+30,5);
    iCircle(x+40,y+30,5);
    iSetColor(255,255,0);*/

    iShowBMP(x,y,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\robofes (1)-Photoroom.bmp");//robo xd
    

    iShowBMP(p,q,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\paddle.bmp");//paddle



    //iFilledRectangle(p,q,reclen,rechi);
    // Center the paddle
    iText(1200,200,"BREAK THEM ALL",GLUT_BITMAP_HELVETICA_12);


   for(int j=0;j<h;j++){
    for(int i=0;i<n;i++)
    {
        if(show[level][j][i]==0)
        {
        iSetColor(21,54,130);
        iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);
        }
        else if(show[level][j][i]==-1)
        {
            iSetColor(255,0,0);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);

        }
      
    }}

    int count =0;

     for(int j=0;j<h;j++){
    for(int i=0;i<n;i++)
    {
       if(show[level][j][i]!=0)
       {
        count++;
        break;
       }
      
    }}
    if(count==0) level++;
   /* for(int i=0;1;i++)
    {
        Sleep(1000);
        sprintf(somoy,"%d seconds remaining",5000-times);
        iText(10,300,somoy,GLUT_BITMAP_TIMES_ROMAN_10);
    }
    */
    //startMusic();
    
    iSetColor(200,50,60); 
    iFilledRectangle(10,580,100,40);
    sprintf(output,"SCORE :%d",score);
    iText(10,650,output,GLUT_BITMAP_TIMES_ROMAN_24); 
    for(int i=0;i<life;i++)
    {
        iSetColor(255,255,255);
        iFilledCircle(20+30*i,600,10);
    }
    
    
    }
    if(cpage==1)
    {
        iClear();
        iText(400,400,"SORRY BRO >>>CSE IS NOT FOR YOU NOOB",GLUT_BITMAP_TIMES_ROMAN_24); 
    }
    

    
}

void iMouse(int button, int state, int a, int b) {
    // handle mouse click events
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && cpage==-2 && a>=605 && a<=970 && b>=300 && b<=375)
    {
        cpage++;
    } 
}

void iMouseMove(int x, int y) {
    // handle mouse movement
    int mx=x;
    int my=y;
    if(mx>screenWidth-reclen)p=screenWidth-reclen;
    else p=x;
}



void iKeyboard(unsigned char key) {
    // handle keyboard input
    if(key=='a' && p>0) p-=30;
    else if(key=='d'  && (p+reclen)<screenWidth)p+=30;
    else if(key=='r')r=(r+10)%255;
    else if(key=='g')g=(g+10)%255;
    else if(key=='b')b=(b+10)%255;
    if( key==' ' && cpage<0) cpage++;
    if(cpage==0 && key=='p')initial=1;
    if(key=='l') level++;
    iDraw();
}
void iSpecialKeyboard(unsigned char key) {
    // handle special keyboard input (arrow keys, function keys, etc.)
    if(key==GLUT_KEY_RIGHT && (p+reclen)<screenWidth)p+=30;
   
    else if(key==GLUT_KEY_LEFT && p>0)p-=30;
    
}


void restartGame() {
    
    x = screenWidth / 2; 
    y = 50;              
   dx=7;
   dy=7;
    // Reset paddle position
    p = (screenWidth - reclen) / 2; // Center the paddle
}

void change()
{
   if(initial>0){x+=dx;
   y+=dy;}
    
    if(x+35>=screenWidth || x<=0) dx=dx*(-1);
    if(y+35>=screenHeight ) dy=dy*(-1);
   if (y<=25 && x+33 >= p && x <= p + reclen) {
        dy = -dy;
        dx=-dx;
        angle=((reclen-(x+33-p))+125)%120+30;
        dx=(int)v*cos(angle*3.14/180);
        dy=(int)v*sin(angle*3.14/180);
        y = q + 26;  // Position above paddle
        score++;
        v*=1.005;
        printf("\a");
         
    }
   


   if (y + 32 >= 400 && y <= 400 + h * (brickhi + 5)) {
    int brickRow = (y+16 - 400) / (brickhi + 5);
    int brickCol = (x+16- 400) / (bricklen + 5);
    if (brickRow >= 0 && brickRow < h && brickCol >= 0 && brickCol < n && show[level][brickRow][brickCol]<=0) {
        show[level][brickRow][brickCol] ++; // brick  destroyed
        dy = -dy; // Change the ball's direction
     
        score++;
      //  y += dy > 0 ? 5 : -5;
    } 
    if(p<0) p=1;
    r=(r+10)%255;
    g=(g+6)%255;
    b=(b+20)%255;


    }
   
   if(y<=0)
    {
    life=life-1;
    if(life>0){
        Sleep(100);
        restartGame();
    }


    if(life ==0)
    {
    cpage++;
    }
   }
}



int main()
{
    x = screenWidth / 2; 
    y = 50;              
   dx=7;
   dy=7;
    // Reset paddle position
    p = (screenWidth - reclen) / 2; 
    if(initial==0) iSetTimer(.01,change);
    iInitialize(screenWidth, screenHeight, "Noob trying");
    
    
    /*for(int j=0;j<h;j++){
    for(int i=0;i<n;i++)
    {
        show[level][j][i]=0;
    }
    }
    */
    

    
    
}
