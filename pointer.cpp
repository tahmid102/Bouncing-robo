#include "iGraphics.h"
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <mmsystem.h>
#define screenWidth 1500
#define screenHeight 750
#define n 20
#define h 16
#define levels 3


 

int level =0;

int show[levels][h][n]={
{1,1,1,1,1,-1,-1,-1,0,0,-1,-1,3,3,1,1,1,1,1,1,
1,1,1,1,1,0,0,-1,2,0,-1,0,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,-1,-1,0,1,1,1,1,1,1,1,1,1,
1,1,-1,1,-1,1,1,1,2,0,1,1,1,1,1,-1,1,-1,1,1,
0,0,0,0,3,-1,0,0,-1,-1,0,0,-1,0,0,0,0,0,-2,0,
-1,0,0,0,0,0,-1,0,-1,-1,0,-1,0,0,0,0,0,0,-1,0,
0,0,-2,0,0,0,0,0,-1,-1,0,0,0,0,0,0,0,2,-2,0,
-1,0,0,0,0,0,0,0,0,-1,0,0,0,0,3,0,0,0,-1,0,
0,0,-2,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,-2,
-1,0,0,1,0,0,3,0,0,0,0,0,1,0,0,1,0,-1,2,0,
0,0,-2,1,0,0,2,-1,0,1,1,1,1,0,-1,1,1,1,1,0,
-1,0,0,1,0,0,2,0,0,1,0,0,0,0,0,1,0,0,-2,0,
0,0,-2,1,1,1,1,-1,-1,1,1,1,1,0,-1,1,1,1,1,0,
-1,0,0,0,0,-1,0,-2,-2,0,-1,0,0,0,-2,0,0,-1,0,0,
0,0,-2,-1,-1,0,-2,-1,-1,-2,0,-1,-1,0,-2,-1,0,0,-1,0,
-1,-1,-1,0,0,0,-2,-1,-2,0,0,0,-1,-1,-1,0,0,0,0,-1},

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


int bgx,bgy;

int showbg[20][10]=
{
    0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1
};


void changebg()
{
    bgx+=5;
}

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

typedef struct
{
int state=0;
int px;
int py;
int type;
}power; //powerups
power a;

//shooting functions
int panix;
int paniy=q;

int shootstate=0;



typedef struct{
int *bulstate;
int *bulx;
int *buly;
int capacity;
}bullet;
bullet fire;


void initBullets(int capacity) {
    fire.capacity = capacity;
    fire.bulstate = (int *)malloc(capacity * sizeof(int));
    fire.bulx = (int *)malloc(capacity * sizeof(int));
    fire.buly = (int *)malloc(capacity * sizeof(int));

    for (int i = 0; i < capacity; i++) {
        fire.bulstate[i] = 0;
        fire.bulx[i] = 0;
        fire.buly[i] = 0;
    }
}

void freeBullets() {
    if (fire.bulstate) free(fire.bulstate);
    if (fire.bulx) free(fire.bulx);
    if (fire.buly) free(fire.buly);
}




int bulletCount=0;

void autoShoot() {
    if (shootstate && bulletCount < 20) {
        // Fire bullets from both ends of the paddle
        fire.bulstate[bulletCount] = 1;
        fire.bulx[bulletCount] = p;            // Left end of the paddle
        fire.buly[bulletCount] = q + rechi;    // Just above the paddle

        fire.bulstate[bulletCount + 1] = 1;
        fire.bulx[bulletCount + 1] = p + reclen; // Right end of the paddle
        fire.buly[bulletCount + 1] = q + rechi;

        bulletCount += 2;  // Increase by 2 since we're firing two bullets

        // Stop shooting after 20 bullets
        if (bulletCount >= 20) {
            shootstate = 0;
            bulletCount = 0;
        }
    }
}





void shoot(bullet *a, int b) 
{
   if (a->bulstate[b]){
        a->buly[b]+= 10; 
   }

        if (a->buly[b] > screenHeight)
        { 
            a->bulstate[b] = 0; 
        }
    
}


void updateShootState()
{
    for (int i = 0; i < 10; i++)
    {
        if (fire.buly[i] != 1) // Bullet is still active
            return;
    }
    // All bullets are off-screen, reset shootstate
    shootstate = 0;
}


void restartGame() {
    
    x = screenWidth / 2; 
    y = 50;              
   dx=7;
   dy=7;
    // Reset paddle position
    p = (screenWidth - reclen) / 2; // Center the paddle
}

//level 

void checklevel()
{
    int count =0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(show[level][i][j]!=1)
            {
                count++;
            }
        }
    }
    if(count ==0)
    {
        level++;
        if(level<levels)
        {
            restartGame();
            initial=0;
        }
    }
}
int texty=600;
void texttimer(){
    texty-=-10;
}


void paddleanimation()
{
    iLine(p,q+rechi,p+reclen/2,q+rechi);
}

void iDraw() {

    if(cpage==-1)
    {
        iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\roboback.bmp");
        iSetColor(255,255,255);
        iText(texty,600,"PRESS SPACE TO BREAK CSE",GLUT_BITMAP_TIMES_ROMAN_24);

       

    }//home

    if(cpage==-2){
        iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\MENURIEL.bmp");
        

    }
    if(cpage==0){

        //iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\bggame.bmp");
    iClear(); // Clears the window
   // iSetColor(205,215,230);
    //iFilledRectangle(0,0,screenWidth,screenHeight);
  

    // Example: Draw a red rctangle
    iSetColor(r, g, b);
    
    iSetColor(255,0,233);
    iText(200,370,"ROBO SAVE THE POOKIE",GLUT_BITMAP_HELVETICA_18);
    iShowBMP2(170,400,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\pookiecat.bmp",(0,0,0));

    iShowBMP(x,y,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\robofes (1)-Photoroom.bmp");//robo xd
    

    iShowBMP(p,q,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\paddle.bmp");//paddle



    //iFilledRectangle(p,q,reclen,rechi);
    // Center the paddle
    iText(1200,200,"BREAK THEM ALL",GLUT_BITMAP_HELVETICA_12);

    int shootcount=0;


    /*if(shootstate)
    { 
            panix=p;
            
            for(int i=0;i<10;i++)
            {
                if(fire.bulstate[i])
                fire.bulx[i]=p;
                fire.buly[i]=q-200*i;
                shoot(&fire,i);
            iFilledRectangle(fire.bulx[i],fire.buly[i],5,20);
            iFilledRectangle(fire.bulx[i]+reclen,fire.buly[i],5,20);
            
               
            
            shootcount++;
            fire.bulstate[i]=0;
            }
            
    }*/
   for (int i = 0; i < 20; i++) {
    if (fire.bulstate[i]) {
        iFilledRectangle(fire.bulx[i], fire.buly[i], 5, 20);
    }
}

    
    


    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(showbg[i][j]==0)
            {
                iSetColor(255,255,255);
                bgx=(i+1)*75;
                bgy=(j+1)*75;
                iFilledCircle(bgx,bgy,1);
            }
            else if(showbg[i][j]==1)
            {
                iSetColor(70,70,255);
                iFilledCircle(bgx,bgy,1);
                
            }
        }
    }


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
        else if(show[level][j][i]==-2)
        {
            iSetColor(20,80,10);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi); 

        }

         else if(show[level][j][i]==2)
        {
            iSetColor(b,g,r);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);

        }
        
        
        else if(show[level][j][i]==3)
        {
            iSetColor(r,g,b);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);

        }
        else if(show[level][j][i]==4)
        {
            iSetColor(r,b,g);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);

        }
        
      
    }}

    int count =0;

    


    
    iSetColor(200,50,60); 
    iFilledRectangle(10,580,100,40);
    sprintf(output," :%d",score);
    iText(120,650,output,GLUT_BITMAP_TIMES_ROMAN_24); 
    iShowBMP(0,640,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\scorebuttonJPG120x30.bmp");



    for(int i=0;i<life;i++)
    {
        iSetColor(255,255,255);
        iFilledCircle(20+30*i,600,10);
    }
    if(a.state){
        if(a.type==1)
        //iFilledCircle(a.px,a.py,10);
        iShowBMP2(a.px,a.py,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\robofes (1)-Photoroom.bmp",(0,0,0));
        if(a.type==2)
        {
            
        iShowBMP2(a.px,a.py,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\shootpup.bmp",(0,0,0));

        }

         if(a.type==3)
        {
            
        iShowBMP2(a.px,a.py,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\danger.bmp",(0,0,0));

        }
        
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
    int mx=x+5;
    int my=y;
    if(mx>screenWidth-reclen)p=screenWidth-reclen;
    else if(mx<=0)p=0;
    else p=mx;
      
}



void iKeyboard(unsigned char key) {
    // handle keyboard input
    if(key=='a' && p>0) p-=30;
    else if(key=='d'  && (p+reclen)<screenWidth)p+=30;
    else if(key=='r')r=(r+10)%255;
    else if(key=='g')g=(g+10)%255;
    else if(key=='b')b=(b+10)%255;
    if( key==' ' && cpage<0) cpage++;
    if(cpage==0 && key=='s')initial=1;
    

    if(key=='l') level++;
    iDraw();
}
void iSpecialKeyboard(unsigned char key) {
    // handle special keyboard input (arrow keys, function keys, etc.)
    if(key==GLUT_KEY_RIGHT && (p+reclen)<screenWidth)p+=30;
   
    else if(key==GLUT_KEY_LEFT && p>0)p-=30;
    
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
        //float relativeImpact = ((x + 33) - (p + reclen / 2)) / (float)(reclen / 2);
        angle=((reclen-(x+33-p))+125)%120+30;
        dx=(int)v*cos(angle*3.14/180);
        dy=(int)v*sin(angle*3.14/180);
        y = q + 26;  // Position above paddle
        //score++;
        v*=1.005;
        printf("\a");
         
    }
    if(a.state)a.py-=5;

    // powerup functionalities

    if (a.state==1 && a.py<=25 && a.px+33 >= p && a.px <= p + reclen){
        if(a.type==1){
            life++;
        }
        else if(a.type==2){
            shootstate=1;
            bulletCount=0;
            initBullets(20);
        }
        
        else if(a.type==3)
        {
            life--;
        }
        a.state=0;
    }
    if(a.py<0)
    {
        a.state=0;
    }
    r=(r+1)%255;
    g=(g+3)%255;
    b=(b+2)%255;



   if (y + 32 >= 400 && y <= 400 + h * (brickhi + 5)) {

    
    int brickRow = (y+16- 400) / (brickhi + 5);
    int brickCol = (x+16- 400) / (bricklen + 5);
    if (brickRow >= 0 && brickRow < h && brickCol >= 0 && brickCol < n ){
        
        if( show[level][brickRow][brickCol]<=0) {
        dy = -dy;
        show[level][brickRow][brickCol] ++; // brick  destroyed
         // Change the ball's direction
     
        score++;}

        else if( show[level][brickRow][brickCol]==3){
            show[level][brickRow][brickCol]=1; 
            int p1=x,q1=y;
            dy=-dy;
            a.state=1;
            a.px=p1;
            a.py=y;
            a.type=2;
            //iShowBMP(p1,q1,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\lifepup.bmp");

        }


        else if( show[level][brickRow][brickCol]==2){
            show[level][brickRow][brickCol]=1; 
            int p1=x,q1=y;
            dy=-dy;

           
            a.state=1;
            a.px=x;
            a.py=y;
            a.type=1;
            
            
        }
         else if( show[level][brickRow][brickCol]==4){
            show[level][brickRow][brickCol]=1; 
            int p1=x,q1=y;
            dy=-dy;

           
            a.state=1;
            a.px=x;
            a.py=y;
            a.type=3;
            
            
        }



        for (int i = 0; i < fire.capacity; i++) {
        if (fire.bulstate[i]) {
            fire.buly[i] += 10;

            // Deactivate bullet if it goes off-screen
            if (fire.buly[i] > screenHeight) {
                fire.bulstate[i] = 0;
            }
        }
    }
     if (bulletCount >= fire.capacity) {
        shootstate = 0;
        freeBullets();  // Free the allocated memory
    }
      //  y += dy > 0 ? 5 : -5;
    
    }}





    //shoot
    for(int i=0;i<10;i++){
    if (paniy-200*i + 32 >= 400 && (paniy-200*i) <= 400 + h * (brickhi + 5)) {

    
    int brickRow = ((paniy-i)- 400) / (brickhi + 5);
    int brickCol = (panix- 400) / (bricklen + 5);
    if (brickRow >= 0 && brickRow < h && brickCol >= 0 && brickCol < n ){
        
       
        show[level][brickRow][brickCol]=1; // brick  destroyed
 
    }
    }
    }







    checklevel();
   
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

void wrapper() {
    bullet a;
    int b;
    shoot(&a, b);
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
    iSetTimer(10,texttimer);
   if(initial==0) if(shootstate)iSetTimer(.01,wrapper );
   iSetTimer(500, autoShoot);  // Fire bullets every 500 milliseconds

    iSetTimer(10,changebg);
    iInitialize(screenWidth, screenHeight, "THE BOUNCING ROBO");
    
    
    /*for(int j=0;j<h;j++){
    for(int i=0;i<n;i++)
    {
        show[level][j][i]=0;
    }
    }
    */
   if(cpage==-2)
   {
    PlaySound(TEXT("C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
   }
   
    FILE *f= fopen("highscores.txt","w");
    fprintf(f,"score ");
    fclose(f);


}
