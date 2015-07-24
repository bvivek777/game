#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

void gun(int a)
{
setcolor(YELLOW);
rectangle(50,10+a,110,30+a);
rectangle(110,17+a,180,23+a);
rectangle(40,19+a,15,21+a);
rectangle(10,15+a,15,30+a);
rectangle(55,30+a,65,45+a);
rectangle(85,30+a,95,50+a);
rectangle(50,15+a,40,25+a);
}
////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void clear(int a)
{
setcolor(BLACK);
rectangle(50,10+a,110,30+a);
rectangle(110,17+a,180,23+a);
rectangle(40,19+a,15,21+a);
rectangle(10,15+a,15,30+a);
rectangle(55,30+a,65,45+a);
rectangle(85,30+a,95,50+a);
rectangle(50,15+a,40,25+a);
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void movegun()
{
	int ch=0,colour,move=0,x,score=0,y,misses=0,w=200;
	int dely=100;
	while(misses<5)           //checks for five misses of the gun
	{
       colour=1+rand()%14;         // random color for the ball
	x=getmaxx()-50;            // positions the ball at the end of the screen
	w=180;
	while(ch!=13)       //checks for the press of enter button
	{
	gun(move);          //draws the gun at the begining
	while(!kbhit())     // for the continous moment of the circle
	{
	 setcolor(colour);
	 circle(x,y,30);
	 circle(x,y,29);
	 delay(dely);
	 setcolor(BLACK);
	 circle(x,y,30);
	 circle(x,y,29);
	 y+=20;
	 if(y>=getmaxy()-30)      //brings the ball closer to the gun
	 {
	 y=30;
	 x-=30;
	 if(x<200)                // if the ball is one line closer to the gun then prints game over and prints the score
	 {
	 gotoxy(30,15);
	printf("GAME OVER");
	gotoxy(30,17);
	printf("SCORE:%d",score*10);
	getch();
		 exit(0);    // exits the game
		 }
	 }
	}
	if(ch==80)             //if the down button is pressed
	{
	clear(move);         //clears the previous position of gun
	move+=10;
	if(move>400)         // checks if the gun is outside the range of the screen
	{                    //if so then draws it at the starting of the screen
	move=0;
	}
	gun(move);
	}
	if(ch==72)           // similar process for the up arrow
	{
	clear(move);
	move-=10;
	if(move<0)
	{
	move=400;
	}


	gun(move);

	}
	ch=getch();            //input from the user
	}
	ch=0;
	setcolor(colour);       //draws the circle to show position
	circle(x,y,30);
	circle(x,y,29);
	while(w<x-10)
	{                                 // bullet firing loop
	setcolor(WHITE);
	line(w,move+20,w+10,move+20);
	sound(200);
	delay(1);
	setcolor(BLACK);
	line(w,move+20,w+10,move+20);
	w+=2;
		}
		nosound();
		setcolor(BLACK);               //clears the circle drawn
		circle(x,y,30);
		circle(x,y,29);
	if((move>=y-60)&&(move<=y))
	{                             //checks whether bullet has hit the ball
	score++;
	sound(100);
	delay(100);                 // if so the score is incremented
	y=30;
	if(score>=10)
	{                        //increases speed for every 10 hits
	dely=80;
	}
	if(score>=20)
	{
	dely=50;
	}
	if(score>=30)
	{
	dely=30;
	}
	if(score>=40)
	{
	dely=15;
	}
	nosound();
	 }
	 else
	 {
	 misses++;
	 printf("miss number %d",misses); //if the ball is not hit then value of misses is incremented
	  sound(600);
	 delay(500);
	 nosound();
	 }

	 cleardevice();
	}
	gotoxy(30,15);        // after the while loop ends ie after 5 misses
	printf("GAME OVER");  // it prints score and the game ends
	gotoxy(30,17);
	printf("SCORE:%d",score*10);
	getch();
	exit(0);

}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
void credits()
{
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
//setbkcolor(WHITE);
setcolor(YELLOW);
outtextxy(20,20,"Done By-");
settextstyle(7,0,6);
outtextxy(150,150,"Vivek Bengre LN");
outtextxy(150,250,"Suryaprasad R");
getch();

}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
void intro()
{
cleardevice();
settextstyle(3,HORIZ_DIR,1);
setcolor(YELLOW);
outtextxy(20,20,"This is a game Program in which the player has to shoot the");
outtextxy(20,40,"ball.");
outtextxy(20,90,"The gun should be fired exactly when the ball is in line");
outtextxy(20,110,"with the gun to count as a point.");
outtextxy(20,160,"If the bullet does'nt strike the ball its treated as a miss,");
outtextxy(20,180,"the player is allowed a total of five misses before the game ends.");
outtextxy(20,230,"Also the ball keeps coming closer to the gun if gun is not fired.");
outtextxy(20,280,"If the ball reaches the gun then the game is over.");
outtextxy(20,330,"The ball keeps Speeding up every 10 points the player scores ");

getch();
cleardevice();
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void main()
{
int gd=DETECT,gm,x=100,ch;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(1)
{
cleardevice();
settextstyle(10,HORIZ_DIR,5);
setcolor(RED);
outtextxy(10,0,"TARGET PRACTICE");
settextstyle(1,HORIZ_DIR,6);
setcolor(YELLOW);
outtextxy(220,100,"CREDITS");
outtextxy(220,170,"RULES");
outtextxy(220,240,"PLAY GAME");
outtextxy(220,310,"EXIT");
//getch();
while(ch!=13)
{
setcolor(YELLOW);
outtextxy(140,x,"->");
ch=getch();
if(ch==72)
{
setcolor(BLACK);
outtextxy(140,x,"->");
if(x>100)
x-=70;
}
if(ch==80)
{
setcolor(BLACK);
outtextxy(140,x,"->");
if(x<310)
x+=70;
}
}
ch=0;
switch(x)
{
case 100:
credits();
break;
case 170:
intro();
break;
case 240:
cleardevice();
movegun();
break;
case 310:
cleardevice();
exit(0);
default:
break;
}
}

//intro();
//movegun();
}