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
{1,1,1,1,4,-1,-1,-1,0,0,-1,-1,-1,3,1,1,1,1,1,1,
1,1,1,1,1,5,0,-1,2,0,-1,0,5,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,-1,-1,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,2,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,3,-1,0,0,-1,-1,0,0,-1,0,0,0,0,0,-2,0,
-1,0,0,0,0,0,-1,0,-1,-1,0,-1,0,0,0,0,0,0,-1,0,
0,0,-2,0,0,0,0,0,-1,-1,0,0,0,0,0,0,0,2,-2,0,
-1,0,0,5,0,0,0,0,0,-1,0,0,0,5,3,0,0,0,-1,0,
0,0,-2,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,-2,
-1,0,0,1,0,0,3,0,0,0,0,0,1,0,0,1,0,-1,2,0,
0,0,-2,1,0,0,2,-1,0,1,1,1,1,0,-1,1,1,1,1,0,
-1,0,0,1,0,0,2,0,0,1,0,0,0,0,0,1,0,0,-2,0,
0,0,-2,1,1,1,1,-1,-1,1,1,1,1,0,-1,1,1,1,1,0,
-1,0,0,0,0,-1,0,-2,-2,0,-1,0,0,0,-2,0,0,-1,0,0,
0,0,-2,-1,-1,0,-2,-1,-1,-2,0,-1,-1,0,-2,-1,0,0,-1,0,
-1,-1,-1,0,0,0,-2,-1,-2,0,0,0,-1,-1,-1,0,0,0,0,-1},

{-1,-1,-1,-1,1,0,0,0,1,-1,0,0,0,0,1,-1,-1,-1,-1,-1,
-1,1,-2,1,-2,0,0,0,0,0,0,0,0,-2,-1,1,-2,1,1,-1,
2,1,1,1,2,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,-1,4,-1,-1,-1,0,0,0,0,0,0,0,0,
0,4,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,
0,0,0,0,0,0,3,-1,-1,-1,-1,-1,2,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,-1,-1,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,1,1,-2,-2,1,1,1,1,0,0,1,1,1,1,0,
0,4,0,1,0,0,-2,0,0,1,0,0,0,0,0,1,4,-2,-2,
0,0,0,1,1,1,1,-1,-2,-2,-1,1,1,1,2,1,1,1,1,-2,
-1,-2,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-2,-2,
-2,-2,-1,-1,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,-2,
-1,-2,-1,-2,0,0,0,0,2,0,0,4,0,0,0,0,0-2,-1-2,-2,-2},

{1,1,1,1,1,0,0,0,1,1,0,0,0,0,-1,-1,1,1,1,1,
1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,3,2,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,4,0,0,0,3,0,0,0,0,4,0,0,0,0,0,0,
0,0,0,-2,-2,-2,-2,0,0,-2,-2,-2,-2,0,0,-2,-2,-2,-2,0,
0,0,0,-2,0,0,0,0,0,0,0,0,-2,0,0,-2,0,0,0,0,
0,0,0,-2,0,0,0,0,0,-2,-2,-2,-2,0,0,-2,-2,-2,-2,0,
0,0,0,-2,0,0,0,0,0,-2,0,0,0,0,0,-2,0,0,0,0,
0,0,0,-2,-2,-2,-2,-1,-1,-2,-2,-2,-2,0,0,-2,-2,-2,-2,0,
0,0,4,0,0,0,0,-1,-1,-1,-1,-1,-1,0,4,0,0,0,2,-2,
0,0,0,0,0,4,0,0,4,-1,-1,-1,0,0,0,0,0,0,0,
0,0,0,0,0,4,0,0,4,0,0,0,0,4,0,0,0,0,0,0}


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
char sobsesh[50];
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
power a,c;

//shooting functions
int panix;
int paniy=q;

int shootstate=0;



typedef struct{
int bulstate[20]={0};
int bulx[20];
int buly[20];
}bullet;

int musicstate=1;




bullet fire;

int bulletCount=0;

void autoShoot() {
    if (shootstate && bulletCount < 20) {
        // guli ber hobe ekhon yeeeeeeeeeeeeeeee
        fire.bulstate[bulletCount] = 1;
        fire.bulx[bulletCount] = p;            // bam pashe
        fire.buly[bulletCount] = q + rechi;    

        fire.bulstate[bulletCount + 1] = 1;
        fire.bulx[bulletCount + 1] = p + reclen; // dan pashe
        fire.buly[bulletCount + 1] = q + rechi;

        bulletCount += 2;  

        if (bulletCount >= 20) {
            shootstate = 0;
            bulletCount = 0;
        }
    }
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
    texty=(texty+2)%800;
}


static int music=0;

void saveScore(int score) {
    FILE *file = fopen("scores2.txt", "a"); 
    
    fprintf(file, "%d\n", score); 
    fclose(file);
    printf("Score saved successfully.\n");
}

int scores[10000];
int scoreCount=0;


void loadScores() {
    scoreCount = 0;
    FILE *file = fopen("scores2.txt", "r");
    if(file == NULL) {
        printf("No scores found.\n");
        return;
    }
    while(fscanf(file, "%d", &scores[scoreCount]) == 1) {
        scoreCount++;
        if(scoreCount >= 1000) break; // prevent overflow if file is huge
    }
    fclose(file);

    // Now sort the scores in descending order
    for(int i=0; i<scoreCount; i++) {
        for(int j=i+1; j<scoreCount; j++) {
            if(scores[j] > scores[i]) {
                int temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
}




void iDraw() {

    if(cpage==-1)
    {
        iShowBMP(0,0,"onlybricks.bmp");
        iSetColor(0,255,0);
        iShowBMP(400,300,"robofes (1)-Photoroom.bmp");
        iText(450,310,"LIFE UP");
        iShowBMP2(370,180,"shootpup.bmp",(0,0,0));
        
        iText(450,210,"SHOOTING");
        iShowBMP2(395,100,"danger.bmp",(0,0,0));
        iText(450,115,"LIFE DOWN");
        iShowBMP(400,30,"roboball.bmp");
        iText(450,50,"SPEED INCREASES");
        iSetColor(255,255,0);
        iText(1000,texty,"BLINKING BRICKS CARRY THE POWERUPS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(900,texty-60,"SHOOTING DOES NOT ALWAYS BRING HAPPINESS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1000,texty-120,"MYSTERY LIES IN DIFFETRENT COLOURS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1000,texty-180,"THE POOKIE STAYS IN THE FINAL LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);





        iSetColor(0,230,230);
        iText(200,500,"PRESS B TO BACK",GLUT_BITMAP_TIMES_ROMAN_24);


        iText(200,600,"PRESS SPACE TO START",GLUT_BITMAP_TIMES_ROMAN_24);

       

    }//about

    if(cpage==-2){
        iShowBMP(0,0,"MENURIEL (1).bmp");
      
    }

    
    if(cpage==0 && music==0 &&initial)
   {
     //PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
      Sleep(2000);
      music=1;
   }

   
    if(cpage==0){

        //iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\bggame.bmp");
    iClear(); // Clears the window
   // iSetColor(205,215,230);
    //iFilledRectangle(0,0,screenWidth,screenHeight);
  

    // Example: Draw a red rctangle
    iSetColor(r, g, b);
    
    iSetColor(255,0,233);
    //iText(200,400,"ROBO SAVE THE POOKIE",GLUT_BITMAP_HELVETICA_18);
    iShowBMP2(100,400,"robosavethepookie.bmp",(0,0,0));
    if(level==2)iShowBMP2(850,500,"pookiecat.bmp",(0,0,0));

    iShowBMP(x,y,"robofes (1)-Photoroom.bmp");//robo xd
    

    iShowBMP(p,q,"paddle.bmp");//paddle

    iShowBMP(1400,700,"exit.bmp");

    iText(385,405,"E ");



    
    //iText(1200,200,"BREAK THEM ALL",GLUT_BITMAP_HELVETICA_12);
    iShowBMP2(900,200,"pause.bmp",(0,0,0));

    int shootcount=0;


   
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
            iSetColor(51,221,255);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);

        }
        else if(show[level][j][i]==-2)
        {
            iSetColor(153,0,127);
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
            iSetColor(r+9,b-9,g+90);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);

        }
         else if(show[level][j][i]==5)
        {
            iSetColor(r-90,b+9,g+9);
            iFilledRectangle(400+(bricklen+5)*i,400+(brickhi+5)*j,bricklen,brickhi);

        }
        
      
    }}

    int count =0;

    

    if(level>2){
        iClear();
        iShowBMP(400,100,"ribon.bmp");
        saveScore(score);
        iText(900,400,"CONGRATULATIONS! POOKIE HAS BEEN RESCUED",GLUT_BITMAP_TIMES_ROMAN_24);


        
    }


    
    iSetColor(200,50,60); 
   // iFilledRectangle(10,580,100,40);
    sprintf(output," :%d",score);
    iText(120,650,output,GLUT_BITMAP_TIMES_ROMAN_24); 
    iShowBMP2(0,640,"scorebuttonJPG120x30.bmp",(0,0,0));



    for(int i=0;i<life;i++)
    {
        iSetColor(255,255,255);
        //iFilledCircle(20+30*i,600,10);
        iShowBMP(20+30*i,600,"life123.bmp");

    }
    if(a.state){
        if(a.type==1)
        //iFilledCircle(a.px,a.py,10);
        iShowBMP2(a.px,a.py,"robofes (1)-Photoroom.bmp",(0,0,0));
        if(a.type==2)
        {
            
        iShowBMP2(a.px,a.py,"shootpup.bmp",(0,0,0));

        }

         if(a.type==3)
        {
            
        iShowBMP2(a.px,a.py,"danger.bmp",(0,0,0));

        }
        if(a.type==4)
        {
            iShowBMP(a.px,a.py,"roboball.bmp");
        }
        
        
    }
     if(c.state){
        if(c.type==1)
        //iFilledCircle(a.px,a.py,10);
        iShowBMP2(c.px,c.py,"robofes (1)-Photoroom.bmp",(0,0,0));
        if(c.type==2)
        {
            
        iShowBMP2(c.px,c.py,"shootpup.bmp",(0,0,0));

        }

         if(c.type==3)
        {
            
        iShowBMP2(c.px,c.py,"danger.bmp",(0,0,0));

        }
        if(c.type==4)
        {
            iShowBMP(c.px,c.py,"roboball.bmp");
        }
        
    }
    
    }
    if(cpage==1)
    {
        iClear();
        iShowBMP(0,0,"gameover.bmp");
        sprintf(sobsesh,"YOUR SCORE IS :%d",score);
        iText(120,650,sobsesh,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    
    if(cpage == 2) {
    iClear();
    iSetColor(255,255,255);
    iText(600,700,"SCOREBOARD", GLUT_BITMAP_TIMES_ROMAN_24);
    // Display top 10 scores or all scores if fewer than 10
    int maxToShow = scoreCount < 10 ? scoreCount : 10;
    for(int i=0; i<maxToShow; i++) {
        char scoreStr[50];
        sprintf(scoreStr, "%d. %d", i+1, scores[i]);
        iText(600, 650 - i*30, scoreStr, GLUT_BITMAP_HELVETICA_18);
    }

    // Add a button to go back to menu
    iSetColor(200,50,60);
    iFilledRectangle(600,100,100,40);
    iSetColor(255,255,255);
    iText(610,115,"Back", GLUT_BITMAP_HELVETICA_18);
    }


    
}

void iMouse(int button, int state, int a, int b) {
    // handle mouse click events
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && cpage==-2) {
        if(a>=605 && a<=970 && b>=300 && b<=375)
    {
        cpage++;
        if(cpage==-1)
        {
            PlaySound(NULL, 0, 0);
        
        PlaySound(TEXT("pookiesound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
    } 
    else if(a>=586 && a<=770 && b>=158 && b<=232)
    {
        cpage=0;
         PlaySound(NULL, 0, 0);
        PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else if(a>=810 && a<=992 && b>=158 && b<=232)
    {
        exit(0);
    }
    else if(a>=810 && a<=992 && b>=40 && b<=114)
    {
        cpage=-1;
         PlaySound(NULL, 0, 0);
        
        PlaySound(TEXT("pookiesound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        
    }}

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && cpage==0){
        if(a>=1400 && b>=700 && b<=740)
        {
            exit(0); 
        }
    }
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && cpage==1)
    {
        if(a>=530 && a<=670 && b>=40 && b<=90)
        {
            
        score = 0;
        life = 3;
        level = 0;
        initial = 0; 
        restartGame();
        cpage=0;


            
        }
        else if(a>=860 && a<=970 && b>=40 && b<=90)
        {
            exit(0);
        }
    }
    if(cpage == -2) {
    // Suppose the scoreboard button is at (x: 600-700, y: 200-250)
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(a>=600 && a<=700 && b>=40 && b<=120) {
            loadScores();
            cpage = 2; // go to scoreboard page
        }
    }
    }
    if(cpage == 2) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Check if player clicked on the back button
        if(a>=600 && a<=700 && b>=100 && b<=140) {
            cpage = -2; // Return to main menu
        }
    }
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
    if( key==' ' && cpage==-1) 
    {cpage++;
    if(cpage==0)
    {
         PlaySound(NULL, 0, 0);
        PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    }
    if( key==' ' && cpage==0) {
        if(initial!=-1)
        initial=-1;
        else initial=1;
    }
    if(cpage==0 && key=='s')initial=1;
    if(cpage==-1 && key=='b')cpage=-2;
    

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
    checklevel();

    if(y<=0)
    {
        
        restartGame();
        life--;
       
    }
    if(life==0 && cpage == 0)
        {
            cpage=1;
            saveScore(score);
            initial=-1;
            PlaySound(NULL, 0, 0);
            
            
        }
    if(a.state)a.py-=5;
    if(c.state)c.py-=5;

    // powerup functionalities

    if (a.state==1 && a.py<=25 && a.px+33 >= p && a.px <= p + reclen){
        if(a.type==1){
            life++;
        }
        else if(a.type==2){
            shootstate=1;
            bulletCount=0;
        }
        
        else if(a.type==3)
        {
            life--;
        }
        else if(a.type==4)
        {
            v*=1.05;
        }
        a.state=0;
    }
    if(a.py<0)
    {
        a.state=0;
    }

    if (c.state==1 && c.py<=25 && c.px+33 >= p && c.px <= p + reclen){
        if(c.type==1){
            life++;
        }
        else if(c.type==2){
            shootstate=1;
        }
        
        else if(c.type==3)
        {
            life--;
        }
        c.state=0;
    }
    if(c.py<0)
    {
        c.state=0;
    }


    r=(r+1)%255;
    g=(g+3)%255;
    b=(b+2)%255;



   if (y + 32 >= 400 && y <= 400 + h * (brickhi + 5)) {
    int brickRow;
    int brickCol;
    for(int i=10;i<25;i++){
    brickRow = (y+i- 400) / (brickhi + 5);
    brickCol = (x+i- 400) / (bricklen + 5);
    
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
            if(!a.state){
            a.state=1;
            a.px=p1;
            a.py=y;
            a.type=2;}
            else if(!c.state){
            c.state=1;
            c.px=p1;
            c.py=y;
            c.type=2;
            }
            //iShowBMP(p1,q1,"C:\\Users\\ASUS\\OneDrive\\Desktop\\project\\lifepup.bmp");

        }

        else if( show[level][brickRow][brickCol]==2){
            show[level][brickRow][brickCol]=1; 
            int p1=x,q1=y;
            dy=-dy;

           if(!a.state){
            a.state=1;
            a.px=x;
            a.py=y;
            a.type=1;
           }
           else if(!c.state)
           {
            c.state=1;
            c.px=x;
            c.py=y;
            c.type=1;
           }
            
            
        }
         else if( show[level][brickRow][brickCol]==4){
            show[level][brickRow][brickCol]=1; 
            int p1=x,q1=y;
            dy=-dy;

            if(!a.state){
            a.state=1;
            a.px=x;
            a.py=y;
            a.type=3;
           }
           else if(!c.state)
           {
            c.state=1;
            c.px=x;
            c.py=y;
            c.type=3;
           }

         }

         else if( show[level][brickRow][brickCol]==5){
            show[level][brickRow][brickCol]=1; 
            int p1=x,q1=y;
            dy=-dy;

            if(!a.state){
            a.state=1;
            a.px=x;
            a.py=y;
            a.type=4;
           }
           else if(!c.state)
           {
            c.state=1;
            c.px=x;
            c.py=y;
            c.type=4;
           }

         }

        



    }
}

   if(cpage!=0)
   {
    music=1;
   // PlaySound(NULL, NULL, SND_ASYNC);
   }

    
    
   if(y<=0)
    {
    life--;
    if(life>0){
        Sleep(1000);
        restartGame();
    }

 
    else if(life ==0)
    {
    cpage++;
    }
   }
}
}




void ishoot()
{
     for (int i = 0; i < 20; i++) {
        if (fire.bulstate[i]) {
            fire.buly[i] += 10;

            // Deactivate bullet if it goes off-screen
            if (fire.buly[i] > screenHeight) {
                fire.bulstate[i] = 0;
            }
            
        }
    }
       for(int i=0;i<20;i++){
    if ( fire.buly[i] >= 400 && fire.buly[i] <= (400 + h * (brickhi + 5))) {
    int brickRow;
    int brickCol;
    
    brickRow = (fire.buly[i]- 400) / (brickhi + 5);
    brickCol = (fire.bulx[i]- 400) / (bricklen + 5);
    if (brickRow >= 0 && brickRow < h && brickCol >= 0 && brickCol < n ){
         
        if( show[level][brickRow][brickCol]>1) {
        
        show[level][brickRow][brickCol]=rand()%(5-1+1)+1; 
        //fire.bulstate[i]=0;// brick  destroyed
        
    
    }


    else if( show[level][brickRow][brickCol]<1) {
        
        show[level][brickRow][brickCol]=rand()%(1+2+1)+1; 
        //fire.bulstate[i]=0;// brick  destroyed
        
    
    }
    
    }}
        }
}








int main()
{
    x = screenWidth / 2; 
    y = 50;              
   dx=7;
   dy=7;
   
    p = (screenWidth - reclen) / 2; 
    if(initial==0) iSetTimer(.004,change);
    iSetTimer(10,texttimer);
   iSetTimer(300, autoShoot);  
   iSetTimer(3,ishoot);


    iSetTimer(10,changebg);
    iInitialize(screenWidth, screenHeight, "THE BOUNCING ROBO");
  
    


}
