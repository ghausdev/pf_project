//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Battleship.
//============================================================================

#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include<string>
#include <unistd.h>
#include <ctime>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
int battleshipCount = 0;

//int PX,PY,CX,CY;
const int microToSeconds = 1000000; 
const double delay = 4 * microToSeconds; 

int ARRAY2[10][10];
int gridx,gridy;
int GX,GY;
bool hold=false,ship1=false,ship2=false,ship3=false,ship4=false,ship5=false,
     ship6=false,ship7=false,ship8=false,ship9=false,ship10=false;
bool COMPT=false;
int mouseX,mouseY;
int moveX,moveY;
int ARRAY[10][10];

int ship1x=800,ship1y=450; 
int ship2x=850,ship2y=550; 
int ship3x=850,ship3y=350;
int ship4x=650,ship4y=250; 
int ship5x=650,ship5y=150; 
int ship6x=750,ship6y=250;
int ship7x=750,ship7y=150; 
int ship8x=650,ship8y=350; 
int ship9x=650,ship9y=450;
int ship10x=650,ship10y=550; 
bool KS=false;
bool place=true;
bool HIT=false,MISS;
int hit=0,miss=0;
bool xp1, xp2, xp3, xp4, xp5, xp6, xp7, xp8, xp9, xp10, xp11, xp12, xp13, xp14, xp15, xp16, xp17, xp18, xp19, xp20, xp21, xp22, xp23, xp24, xp25, xp26, xp27, xp28, xp29, xp30, xp31, xp32, xp33, xp34, xp35, xp36, xp37, xp38, xp39, xp40, xp41, xp42, xp43, xp44, xp45, xp46, xp47, xp48, xp49, xp50, xp51, xp52, xp53, xp54, xp55, xp56, xp57, xp58, xp59, xp60, xp61, xp62, xp63, xp64, xp65, xp66, xp67, xp68, xp69, xp70, xp71, xp72, xp73, xp74, xp75, xp76, xp77, xp78, xp79, xp80, xp81, xp82, xp83, xp84, xp85, xp86, xp87, xp88, xp89, xp90, xp91, xp92, xp93, xp94, xp95, xp96, xp97, xp98, xp99, xp100;

bool place1=true,place2=true,place3=true;
bool place4=true,place5=true,place6=true;
bool place7=true,place8=true,place9=true;
bool place10=true;

bool LB=false;
bool AUTO=false;

int MCX,MCY;
string Color="B";

void dx();

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
void store(int x,int y);
void RCO(int x,int y);
void CChcker(int row , int col);
int RPX()
{  srand(time(0));
   return 50+rand()%501;
 }

int ROW,COL;

int RPY()
{
   
  return 305+rand()%763;
}


bool isValidPosition(int row, int col) 
{ 
	// checking if the cell is empty 
	if (COMPT) {if (ARRAY2[row][col] == 0) 
	return true; return false;
         } else {if (ARRAY[row][col] == 0) 
	return true; return false;
         } 
	 
} 

void placeing()
{

if (place1) place1=false;
if (place2) place2=false;
if (place3) place3=false;
if (place4) place4=false;
if (place5) place5=false;
if (place6) place6=false;
if (place7) place7=false;
if (place8) place8=false;
if (place9) place9=false;
if (place10) place10=false;
}

// Function to check if the position of battleship is valid or not 
bool isValidPosition2(int row, int col, int shipLength, int dir) 
{ 
	int i; 

	// checking if the ship is going out of the board 
	if (dir == 0) { 
		if (col + shipLength > 10) 
			return false; 
	} 
	else { 
		if (row + shipLength > 10) 
			return false; 
	} 

	// check if the ship is overlapping or not 
	if (dir == 0) { 
		for (i = col; i < col + shipLength; i++) { 
			// checking if the cell is empty 
			if (COMPT) { if (ARRAY2[row][i] == 0) 
				continue; 
			else
				return false; }
			else { if (ARRAY[row][i] == 0) 
				continue; 
			else
				return false; }
		} 
	} 
	else { 
		for (i = row; i < row + shipLength; i++) { 
			// checking if the cell is empty 
			if (COMPT){if (ARRAY2[i][col] == 0) 
				continue; 
			else
				return false; }
			else {if (ARRAY[i][col] == 0) 
				continue; 
			else
				return false; }
		} 
	} 

	

	return true; 
} 

void PLAYERTURN();
// Function to place the battleship 
void placeBattleship(int row, int col, int shipLength, int dir) 
{ 
	int i; 

	// horizontally placing the battleship 
	if (dir == 0) { 
		if (COMPT){ for (i = col; i < col + shipLength; i++) { 
			ARRAY2[row][i] = 1; 
		} } else { for (i = col; i < col + shipLength; i++) { 
			ARRAY[row][i] = 1; 
		} }
	
	CChcker(row,col);
//if (AUTO==true)
	{
        

   	if (shipLength==1) {DrawSquare(GX,GY,50,colors[DARK_BLUE]);           placeing(); }
	if (shipLength==2) {DrawRoundRect(GX,GY,100,50,colors[DARK_BLUE],40); placeing(); }
	if (shipLength==3) {DrawRoundRect(GX,GY,150,50,colors[DARK_BLUE],40); placeing();}
	if (shipLength==4) {DrawRoundRect(GX,GY,200,50,colors[DARK_BLUE],40); placeing();}
        
glutSwapBuffers();
        }

	}
	 
	// vertically placing the battleship 
	else { 
		for (i = row; i < row + shipLength; i++) { 
			ARRAY[i][col] = 2; 
		} 
	} //glutSwapBuffers();
} 




void RPLACE1()
{

    for (int i=0; i<10;i++)
    {for (int k=0; k<10;k++)
    { ARRAY[i][k]=0;
    }
    }
	//declare variables
	int battleship1 = 4; 
	int battleship2 = 3; 
	int battleship3 = 3; 
	int battleship4 = 2; 
	int battleship5 = 2; 
	int battleship6 = 2; 
	int battleship7 = 1; 
	int battleship8 = 1; 
	int battleship9 = 1; 
	int battleship10 = 1;
	int dir = 0;
	int battleshipCount = 0;
	
	//loop until all battleships are placed
	while (battleshipCount < 10)
	{ 
		//generate random row and column positions
		srand(time(0));
		int RPX = rand()%10;
		int RPY = rand()%10;

		//check if position is valid
		if (isValidPosition(RPX,RPY)) 
		{ 
			//determine length of battleship based on battleshipCount
			int battleshipLength;
			if (battleshipCount == 0) battleshipLength = battleship1;
			else if (battleshipCount == 1) battleshipLength = battleship2;
			else if (battleshipCount == 2) battleshipLength = battleship3;
			else if (battleshipCount == 3) battleshipLength = battleship4;
			else if (battleshipCount == 4) battleshipLength = battleship5;
			else if (battleshipCount == 5) battleshipLength = battleship6;
			else if (battleshipCount == 6) battleshipLength = battleship7;
			else if (battleshipCount == 7) battleshipLength = battleship8;
			else if (battleshipCount == 8) battleshipLength = battleship9;
			else if (battleshipCount == 9) battleshipLength = battleship10;

			//check if position is valid for battleship length
			if (isValidPosition2(RPX,RPY,battleshipLength,dir)) 
			{ 
				//place battleship if position is valid
				placeBattleship(RPX,RPY,battleshipLength,dir); 
				battleshipCount++;
			} 
		} 
	}
}

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 400, yI = 400;

void drawObject() {

	DrawSquare(xI, yI, 20, colors[WHITE]);
	glutPostRedisplay();
}


bool flag = true;
void moveObject() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}

/*
 * Main Canvas drawing function.
 * */
 
void Battle();

void ENEMYGRID()
{

glBegin(GL_LINES);

glColor3f(0.256f,0.256f,0.256f);
  for (float i = 0; i <= 1350 ; i+=50.0f) {
        glVertex3f(i, 0.0,0.0); 
        glVertex3f(i,850,0.0); }
 
  for (float i = 0; i <= 850 ; i+=50) {
        glVertex3f(0.0,i,0.0); 
        glVertex3f(1350,i,0.0); }
    glEnd(); 
    int x=50,y=100;
   int a=x,b=y;
 
   for (int i=0;i<10;i++)
   { for(int j=0; j<10;j++)
       {  DrawSquare(a,b,50,colors[DIM_GRAY]);b+=50;}
       a+=50;
       b=y;

} }
void END()

{


	glClearColor(0.0, 0.0,0.0,1.0); 
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	if (miss==20)
	{
	DrawString(550, 565, "	COMPUTER WINS ", colors[WHITE]);
	} else DrawString(550, 565, "	YOU WINS ", colors[WHITE]);
	DrawString( 770, 665, "BALANCE: " + to_string(hit*60-miss*-20) , colors[WHITE]);
	glutSwapBuffers(); 


}

void COMGRID()
{  int x=800,y=100;
   int a=x,b=y;
 
   for (int i=0;i<10;i++)
   { for(int j=0; j<10;j++)
       {  DrawSquare(a,b,50,colors[DIM_GRAY]);b+=50;}
       a+=50;
       b=y;

} }
void Grid()
{ 

glBegin(GL_LINES);

glColor3f(0.0f,0.0f,0.0f);
  for (float i = 0; i <= 1350 ; i+=50.0f) {
        glVertex3f(i, 0.0,0.0); 
        glVertex3f(i,850,0.0); }
 
  for (float i = 0; i <= 850 ; i+=50) {
        glVertex3f(0.0,i,0.0); 
        glVertex3f(1350,i,0.0); }
    glEnd(); 
    int x=50,y=100;
   int a=x,b=y;
 
   for (int i=0;i<10;i++)
   { for(int j=0; j<10;j++)
       {  DrawSquare(a,b,50,colors[SKY_BLUE]);b+=50;}
       a+=50;
       b=y;
   }
}
void Ship();


bool pcheck(int x,int y, int battleshipLength)
{  int dir=0;
  for (int i=0; i<1; i++) {	if (isValidPosition(x,y)) 
		{ 


		
			if (isValidPosition2(x,y,battleshipLength,dir)) 
			{ placeBattleship(x,y,battleshipLength,dir); 
				return true; 
				
			} else return false;
			
		}     
		}
}


void COMP()
{   COMPT=true;

 
    
    
	//declare variables
	int battleship1 = 4; 
	int battleship2 = 3; 
	int battleship3 = 3; 
	int battleship4 = 2; 
	int battleship5 = 2; 
	int battleship6 = 2; 
	int battleship7 = 1; 
	int battleship8 = 1; 
	int battleship9 = 1; 
	int battleship10 = 1;
	int dir = 0;
	
	
	//loop until all battleships are placed
	while (battleshipCount < 10)
	{ 
		//generate random row and column positions
		srand(time(0));
		int RPX = rand()%10;
		int RPY = rand()%10;

		//check if position is valid
		if (isValidPosition(RPX,RPY)) 
		{ 
			//determine length of battleship based on battleshipCount
			int battleshipLength;
			     if (battleshipCount == 0) battleshipLength = battleship1;
			else if (battleshipCount == 1) battleshipLength = battleship2;
			else if (battleshipCount == 2) battleshipLength = battleship3;
			else if (battleshipCount == 3) battleshipLength = battleship4;
			else if (battleshipCount == 4) battleshipLength = battleship5;
			else if (battleshipCount == 5) battleshipLength = battleship6;
			else if (battleshipCount == 6) battleshipLength = battleship7;
			else if (battleshipCount == 7) battleshipLength = battleship8;
			else if (battleshipCount == 8) battleshipLength = battleship9;
			else if (battleshipCount == 9) battleshipLength = battleship10;

			//check if position is valid for battleship length
			if (isValidPosition2(RPX,RPY,battleshipLength,dir)) 
			{ 
				//place battleship if position is valid
				placeBattleship(RPX,RPY,battleshipLength,dir); 
				battleshipCount++;
			} 
		} 
	}



}

void BGCOM()
{

srand(time(0));




int XT=50+rand()%501;
int YT=305+rand()%763;


XT-=XT%50;
YT-=YT%50;

RCO(XT,YT);

if (ARRAY[ROW][COL]==1) DrawString(XT,YT, "X", colors[ORANGE]); else DrawString(XT,YT, "B", colors[ORANGE]); 

 glutSwapBuffers(); 
}



void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.

	glClearColor(0.0, 0.41,0.58,1.0); 
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Score
	 DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	 // for (int i=0;i<10;i++)
         //{ for (int k=0;k<10;k++)
         //{ARRAY[i][k]=0; } }
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	
	
	Grid();
	if (AUTO!=true) Ship();
	
      DrawString(50,710, "AUTO ", colors[WHITE]);
      if (moveX>50 && moveX<150 && moveY>740 && moveY<780 && LB==1)
	{ LB=0; AUTO=true; RPLACE1(); } 

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	//drawObject();
	DrawString(1100, 65, "START BATTLE: ", colors[WHITE]);
	if (moveX>1100 && moveX<1300 && moveY>270 && moveY<306 && LB==1)
	{ LB=0; glutDisplayFunc(Battle); }
	
	glutSwapBuffers(); // do not modify this line..

}
void MAINMENU();
void COMP1();
void LEADER_BOARD()
{
	  glClearColor(0.0,0.0,0.34,0.5); 
	  glClear (GL_COLOR_BUFFER_BIT); //Update the colors
            ofstream scoring;
            scoring.open("Hightscores.txt");
            scoring<<"NAME: "<<"\t\t\t"<<"SCORES: "<<"\n";
            DrawString(520, 600, "NAMES: ", colors[WHITE]);
            DrawString(720, 600, "SCORE: ", colors[WHITE]);
            
          DrawString(1100, 800, "BACK TO MENU", colors[WHITE]); 
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833) { DrawString( 520, 600, "BACK TO MENU", colors[BLUE]); }
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833 && LB==true) {LB=false; glutDisplayFunc(MAINMENU);  }
	  glutSwapBuffers(); // do not modify this line..

}

void StART_NEW_GAME()
{
	  glClearColor(0.0,0.0,0.0,0.5); 
	  glClear (GL_COLOR_BUFFER_BIT); //Update the colors
          
           
           DrawString(520, 600, "SELECT BATTLESHIP COLOR: ", colors[WHITE]);
      
      
   DrawSquare(300,400,50,colors[DARK_BLUE]);
   DrawSquare(400,400,50,colors[DARK_BLUE]);     
   DrawRoundRect(500,400,100,50,colors[DARK_BLUE],20);
   DrawRoundRect(650,400,100,50,colors[DARK_BLUE],20);
   
   DrawSquare(300,300,50,colors[GRAY]);
   DrawSquare(400,300,50,colors[GRAY]);     
   DrawRoundRect(500,300,100,50,colors[GRAY],20);
   DrawRoundRect(650,300,100,50,colors[GRAY],20);
   
   DrawSquare(300,200,50,colors[PURPLE]);
   DrawSquare(400,200,50,colors[PURPLE]);     
   DrawRoundRect(500,200,100,50,colors[PURPLE],20);
   DrawRoundRect(650,200,100,50,colors[PURPLE],20);
   
   DrawSquare(300,100,50,colors[BLACK]);
   DrawSquare(400,100,50,colors[BLACK]);     
   DrawRoundRect(500,100,100,50,colors[BLACK],20);
   DrawRoundRect(650,100,100,50,colors[BLACK],20);
   
   if (moveX>300 && moveX<745 && moveY>524 && moveY<556 && LB==false) { Color="B";glutDisplayFunc(GameDisplay);} 
   if (moveX>300 && moveX<745 && moveY>454 && moveY<488 && LB==false) { Color="G";glutDisplayFunc(GameDisplay);} 
   if (moveX>300 && moveX<745 && moveY>384 && moveY<415 && LB==false) { Color="P";glutDisplayFunc(GameDisplay);} 
   if (moveX>300 && moveX<745 && moveY>309 && moveY<345 && LB==false) { Color="BL";glutDisplayFunc(GameDisplay);} 
  
  
    
           
           DrawString(1100, 800, "BACK TO MENU", colors[WHITE]); 
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833) { DrawString( 520, 600, "BACK TO MENU", colors[BLUE]); }
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833 && LB==true) {LB=false;  glutDisplayFunc(MAINMENU); }
        
	 glutSwapBuffers(); // do not modify this line..

}

void BALANCE()
{
	  glClearColor(0.0,0.0,0.0,0.5); 
	  glClear (GL_COLOR_BUFFER_BIT); //Update the colors
           
           DrawString(520, 600,"YOUR BALANCE: 500", colors[WHITE]);
           
           DrawString(1100, 800, "BACK TO MENU", colors[WHITE]); 
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833) { DrawString( 520, 600, "BACK TO MENU", colors[BLUE]); }
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833 && LB==true ) {LB=false; glutDisplayFunc(MAINMENU);  }
	  glutSwapBuffers(); // do not modify this line..

}

void OPTIONS()
{
	  glClearColor(0.0,0.0,0.0,0.5); 
	  glClear (GL_COLOR_BUFFER_BIT); //Update the colors
          
          
           DrawString(1100, 800, "BACK TO MENU", colors[WHITE]); 
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833) { DrawString( 520, 600, "BACK TO MENU", colors[BLUE]); }
           if (moveX>1100 && moveX<1300 && moveY>810 && moveY<833 && LB==true) {LB=false; glutDisplayFunc(MAINMENU); }
	  glutSwapBuffers(); // do not modify this line..

}





/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {


	
	if (key == 27/* Escape key ASCII*/) {
		glutDisplayFunc(MAINMENU); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		BGCOM();
		cout << "b pressed" << endl;

	}

	glutPostRedisplay();
}
	



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveObject();
       
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {

	
{
hold=true;
mouseX=x;
mouseY=850-y;

} 
	//cout << x << " " << y << endl;
	//hold=true;
	//mouseX=x; 
	//mouseY=y;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	y = 850 - y;
	moveX=x;
	moveY=y;
 
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

void MouseClicked(int button, int state, int x, int y) {

   y=850-y;
   

	if (button == GLUT_LEFT_BUTTON )  // dealing only with left button
                      
		{ if (LB==true) LB=false; else LB=true;     cout<<endl<<x<<"\t"<<y<<endl; MCX=x; MCY=y;
		//cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} 
	 
	{ if (button == GLUT_LEFT_BUTTON && moveX>850 && moveX<1050 && moveY>560 && moveY<600 )
	 { ship1=true;}
	 
	 
		if (button == GLUT_RIGHT_BUTTON && ship1 == true) {
		RCO(ship1x -= ship1x % 50, ship1y -= ship1y % 50);
		if (pcheck(ROW, COL, 4) /*&& mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */ ) {
			ship1x -= ship1x % 50;
			ship1y -= ship1y % 50;
			store(ship1x, ship1y);
			ship1 = false;
		} else {
			ship1x = 800;
			ship1y = 450;
		        ship1 = false;
		}
	}
	
	 }
	 
	{ if (button == GLUT_LEFT_BUTTON && moveX>850 && moveX<1000 && moveY>630 && moveY<670 )
	 { ship2=true;}
			if (button == GLUT_RIGHT_BUTTON && ship2 == true) {
		RCO(ship2x -= ship2x % 50, ship2y -= ship2y % 50);
		if (pcheck(ROW, COL, 3) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */) {
			ship2x -= ship2x % 50;
			ship2y -= ship2y % 50;
			store(ship2x, ship2y);
			ship2 = false;
		} else {
			ship2x = 850;
			ship2y = 550;
			ship2 = false;
		}
	}
	}
	 
	{ if (button == GLUT_LEFT_BUTTON && moveX>850 && moveX<1000 && moveY>490 && moveY<525 )
	 { ship3=true;}
		if (button == GLUT_RIGHT_BUTTON && ship3 == true) {
		RCO(ship3x -= ship3x % 50, ship3y -= ship3y % 50);
		if (pcheck(ROW, COL, 3) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */ ) {
			ship3x -= ship3x % 50;
			ship3y -= ship3y % 50;
			store(ship3x, ship3y);
			ship3 = false;
		} else {
			ship3x = 850;
			ship3y = 350;
			ship3 = false;
		}
	}
	 	} 
	{ if (button == GLUT_LEFT_BUTTON && moveX>650 && moveX<700 && moveY>416 && moveY<452  )
	 { ship4=true;}
	 	if (button == GLUT_RIGHT_BUTTON && ship4 == true) {
		RCO(ship4x -= ship4x % 50, ship4y -= ship4y % 50);
		if (pcheck(ROW, COL, 1) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670*/ ) {
			ship4x -= ship4x % 50;
			ship4y -= ship4y % 50;
			store(ship4x, ship4y);
			ship4 = false;
		} else {
			ship4x = 650;
			ship4y = 250;
			ship4=false;
		}
	}
	 }
	
	{ if (button == GLUT_LEFT_BUTTON && moveX>650 && moveX<700 && moveY>346 && moveY<380  )
	 { ship5=true;}
	 	if (button == GLUT_RIGHT_BUTTON && ship5 == true) {
		RCO(ship5x -= ship5x % 50, ship5y -= ship5y % 50);
		if (pcheck(ROW, COL, 1) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */ ) {
			ship5x -= ship5x % 50;
			ship5y -= ship5y % 50;
			store(ship5x, ship5y);
			ship5 = false;
		} else {
			ship5x = 650;
			ship5y = 150;
			ship5=false;
		}
	}
	 }
	 
	{ if (button == GLUT_LEFT_BUTTON && moveX>750 && moveX<800 && moveY>417 && mouseY<450  )
	 { ship6=true;}
		if (button == GLUT_RIGHT_BUTTON && ship6 == true) {
		RCO(ship6x -= ship6x % 50, ship6y -= ship6y % 50);
		if (pcheck(ROW, COL, 1) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */ ) {
			ship6x -= ship6x % 50;
			ship6y -= ship6y % 50;
			store(ship6x, ship6y);
			ship6 = false;
		} else {
			ship6x = 750;
			ship6y = 250;
			ship6=false;
		}
	}
	
	 }
	{ if (button == GLUT_LEFT_BUTTON && moveX>750 && moveX<800 && moveY>344 && moveY<376 )
	 { ship7=true;}
	 	if (button == GLUT_RIGHT_BUTTON && ship7 == true) {
		RCO(ship7x -= ship7x % 50, ship7y -= ship7y % 50);
		if (pcheck(ROW, COL, 1)/* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */) {
			ship7x -= ship7x % 50;
			ship7y -= ship7y % 50;
			store(ship7x, ship7y);
			ship7 = false;
		} else {
			ship7x = 750;
			ship7y = 150;
			ship7=false;
		}
	}
	 }
	 
	 {if (button == GLUT_LEFT_BUTTON && moveX>650 && moveX<750 && moveY>486 && moveY<520 )
	 { ship8=true;}
	 	if (button == GLUT_RIGHT_BUTTON && ship8 == true) {
		RCO(ship8x -= ship8x % 50, ship8y -= ship8y % 50);
		if (pcheck(ROW, COL, 2) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */) {
			ship8x -= ship8x % 50;
			ship8y -= ship8y % 50;
			store(ship8x, ship8y);
			ship8 = false;
		} else {
			ship8x = 650;
			ship8y = 350;
			ship8=false;
		}
	}
	 }
	{ if (button == GLUT_LEFT_BUTTON && moveX>650 && moveX<750 && moveY>560 && moveY<600  )
	 { ship9=true;}
		if (button == GLUT_RIGHT_BUTTON && ship9 == true) {
		RCO(ship9x -= ship9x % 50, ship9y -= ship9y % 50);
		if (pcheck(ROW, COL, 2) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670 */ ) {
			ship9x -= ship9x % 50;
			ship9y -= ship9y % 50;
			store(ship9x, ship9y);
			ship9 = false;
		} else {
			ship9x = 650;
			ship9y = 450;
			ship9=false;
		}
	}
	 }
	 { if (button == GLUT_LEFT_BUTTON && moveX>650 && moveX<750 && moveY>632 && moveY<670 )
	 { ship10=true;}
		if (button == GLUT_RIGHT_BUTTON && ship10 == true) {
		RCO(ship10x -= ship10x % 50, ship10y -= ship10y % 50);
		if (pcheck(ROW, COL, 2) /* && mouseX>50 && mouseX<550 && mouseY>311 && mouseY<670  */) {
			ship10x -= ship10x % 50;
			ship10y -= ship10y % 50;
			store(ship10x, ship10y);
			ship10 = false;
		} else {
			ship10x = 650;
			ship10y = 550;
			ship10=false;
		}
	}
	 }
	 

	 
	
	 if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{ 	
	    //	cout<<endl<<x<<"\t"<<y<<endl;
		
			 
		//	cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
 
void shipplace()
{
      if (ship4==true )   { ship4x=mouseX; ship4y=mouseY; }  
  { if ( Color=="B") DrawSquare(ship4x,ship4y,50,colors[DARK_BLUE]);
  else if (Color=="G") DrawSquare(ship4x,ship4y,50,colors[GRAY]);
  else if (Color=="P") DrawSquare(ship4x,ship4y,50,colors[PURPLE]);
  else if (Color=="BL") DrawSquare(ship4x,ship4y,50,colors[BLACK]);
  }    
  //ship5   650 150
      //(mouseX>650 && mouseX<700 && mouseY>346 && mouseY<380 )
    
   {if ( Color=="B") DrawSquare(ship5x,ship5y,50,colors[DARK_BLUE]);
 else if (Color=="G") DrawSquare(ship5x,ship5y,50,colors[GRAY]);
  else if (Color=="P") DrawSquare(ship5x,ship5y,50,colors[PURPLE]);
  else if (Color=="BL") DrawSquare(ship5x,ship5y,50,colors[BLACK]);
   }
   //ship6 750 250
    // (mouseX>750 && mouseX<800 && mouseY>417 && mouseY<450 )
     
  { if ( Color=="B")   DrawSquare(ship6x,ship6y,50,colors[DARK_BLUE]);
  else if (Color=="G") DrawSquare(ship6x,ship6y,50,colors[GRAY]);
  else if (Color=="P") DrawSquare(ship6x,ship6y,50,colors[PURPLE]);
  else if (Color=="BL") DrawSquare(ship6x,ship6y,50,colors[BLACK]);
   } 
 
 {   if ( Color=="B") DrawSquare(ship7x,ship7y,50,colors[DARK_BLUE]);
     else if (Color=="G") DrawSquare(ship7x,ship7y,50,colors[GRAY]);
     else if (Color=="P") DrawSquare(ship7x,ship7y,50,colors[PURPLE]);
     else if (Color=="BL") DrawSquare(ship7x,ship7y,50,colors[BLACK]);
   
   }
   
   
 //ship8 650 350
   //(mouseX>650 && mouseX<750 && mouseY>632 && mouseY<670 )
   
  { if ( Color=="B")    DrawRoundRect(ship8x,ship8y,100,50,colors[DARK_BLUE],20);
  else if (Color=="G")  DrawRoundRect(ship8x,ship8y,100,50,colors[GRAY],20);
  else if (Color=="P")  DrawRoundRect(ship8x,ship8y,100,50,colors[PURPLE],20);
  else if (Color=="BL")  DrawRoundRect(ship8x,ship8y,100,50,colors[BLACK],20);
  }
  
  //ship9 650 450
  
   {if ( Color=="B")  DrawRoundRect(ship9x,ship9y,100,50,colors[DARK_BLUE],20);
  else if (Color=="G") DrawRoundRect(ship9x,ship9y,100,50,colors[GRAY],20);
  else if (Color=="P") DrawRoundRect(ship9x,ship9y,100,50,colors[PURPLE],20);
  else if (Color=="BL") DrawRoundRect(ship9x,ship9y,100,50,colors[BLACK],20);
   }
   
   //ship10 650 550
    // (mouseX>650 && mouseX<750 && mouseY>486 && mouseY<520 )
  
   { if ( Color=="B") DrawRoundRect(ship10x,ship10y,100,50,colors[DARK_BLUE],20);
  else if (Color=="G") DrawRoundRect(ship10x,ship10y,100,50,colors[GRAY],20);
  else if (Color=="P") DrawRoundRect(ship10x,ship10y,100,50,colors[PURPLE],20);
  else if (Color=="BL") DrawRoundRect(ship10x,ship10y,100,50,colors[BLACK],20);
  
   }
   
   
   
   {// if (mouseX>850 && mouseX<1050 && mouseY>560 && mouseY<600 && place1==1 ) { hold=1; ship1=true; }  
   
//if (ship1==true && place==true && place1==true )   {ship1x-=ship1x%50; ship1y-=ship1y%50; hold=false;  place=false;   ship1=false; place1=0; } 

  if ( Color=="B")     DrawRoundRect(ship1x,ship1y,200,50,colors[DARK_BLUE],20);
  else if (Color=="G") DrawRoundRect(ship1x,ship1y,200,50,colors[GRAY],20);
  else if (Color=="P") DrawRoundRect(ship1x,ship1y,200,50,colors[PURPLE],20);
  else if (Color=="BL") DrawRoundRect(ship1x,ship1y,200,50,colors[BLACK],20);
   // 850 450 
   }
   
   

   
 // SHIP LENGHT 3
   { // if (mouseX>850 && mouseX<1000 && mouseY>490 && mouseY<525 && place3==1 ) { hold=1; ship3=true; }  
 
//if (ship3==true && place==true && place3==true )   {ship3x-=ship3x%50; ship3y-=ship3y%50; hold=false;  place=false;   ship3=false; place3=0; }
     if ( Color=="B")    DrawRoundRect(ship3x,ship3y,150,50,colors[DARK_BLUE],20);
  else if (Color=="G")   DrawRoundRect(ship3x,ship3y,150,50,colors[GRAY],20);
  else if (Color=="P")   DrawRoundRect(ship3x,ship3y,150,50,colors[PURPLE],20);
  else if (Color=="BL")  DrawRoundRect(ship3x,ship3y,150,50,colors[BLACK],20);
  
  } // 850 350 
   
   
   // SHIP LENGHT 3
    { //if (mouseX>850 && mouseX<1000 && mouseY>630 && mouseY<670 && place2==1 ) { hold=1; ship2=true; }  
 
 

      if (Color=="B") DrawRoundRect(ship2x,ship2y,150,50,colors[DARK_BLUE],20); // 850 550 
 else if (Color=="G") DrawRoundRect(ship2x,ship2y,150,50,colors[GRAY],20); // 850 550 
 else if (Color=="P") DrawRoundRect(ship2x,ship2y,150,50,colors[PURPLE],20); // 850 550 
 else if (Color=="BL") DrawRoundRect(ship2x,ship2y,150,50,colors[BLACK],20); }// 850 550  
}
int main(int argc, char*argv[]) {

	int width = 1350, height = 850; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(0, 1350); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	// glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

const int M=10,N=10;

int** ARRAY1 = new int*[M];

for (int i = 0;i < M; i++) {
ARRAY1[i] = new int[N]; }



for (int i=0; i<10;i++)
    {for (int k=0; k<10;k++)
    { ARRAY[i][k]=0;
    }
    }
  for (int i=0; i<10;i++)
    {for (int k=0; k<10;k++)
    { ARRAY2[i][k]=0;
    }
    }
    COMP1();
	glutDisplayFunc(MAINMENU); // tell library which function to call for drawing Canvas.
	//glutDisplayFunc(GameDisplay);
	
	//glutDisplayFunc(Battle);
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	
	for (int i = 0; i < M; i++) {
                       delete[] ARRAY1[i]; }
delete[] ARRAY1; 
	return 1; 
}

void Ship()
{
      // Battleships:
      
      // ship4   650 250
      // (mouseX>650 && mouseX<700 && mouseY>416 && mouseY<452 ) 
      if (ship4==true )   { ship4x=mouseX; ship4y=mouseY; }  
  { if ( Color=="B") DrawSquare(ship4x,ship4y,50,colors[DARK_BLUE]);
  else if (Color=="G") DrawSquare(ship4x,ship4y,50,colors[GRAY]);
  else if (Color=="P") DrawSquare(ship4x,ship4y,50,colors[PURPLE]);
  else if (Color=="BL") DrawSquare(ship4x,ship4y,50,colors[BLACK]);
  }    
  //ship5   650 150
      //(mouseX>650 && mouseX<700 && mouseY>346 && mouseY<380 )
    if (ship5==true )   { ship5x=mouseX; ship5y=mouseY; }  
   {if ( Color=="B") DrawSquare(ship5x,ship5y,50,colors[DARK_BLUE]);
 else if (Color=="G") DrawSquare(ship5x,ship5y,50,colors[GRAY]);
  else if (Color=="P") DrawSquare(ship5x,ship5y,50,colors[PURPLE]);
  else if (Color=="BL") DrawSquare(ship5x,ship5y,50,colors[BLACK]);
   }
   //ship6 750 250
    // (mouseX>750 && mouseX<800 && mouseY>417 && mouseY<450 )
    if (ship6==true )   { ship6x=mouseX; ship6y=mouseY; }  
  { if ( Color=="B")   DrawSquare(ship6x,ship6y,50,colors[DARK_BLUE]);
  else if (Color=="G") DrawSquare(ship6x,ship6y,50,colors[GRAY]);
  else if (Color=="P") DrawSquare(ship6x,ship6y,50,colors[PURPLE]);
  else if (Color=="BL") DrawSquare(ship6x,ship6y,50,colors[BLACK]);
   } 
   //ship7  750 150
   //(mouseX>750 && mouseX<800 && mouseY>344 && mouseY<376 )
   //   
 {   if ( Color=="B") DrawSquare(ship7x,ship7y,50,colors[DARK_BLUE]);
     else if (Color=="G") DrawSquare(ship7x,ship7y,50,colors[GRAY]);
     else if (Color=="P") DrawSquare(ship7x,ship7y,50,colors[PURPLE]);
     else if (Color=="BL") DrawSquare(ship7x,ship7y,50,colors[BLACK]);
     if (ship7==true )   { ship7x=mouseX; ship7y=mouseY; }
   }
   
   
 //ship8 650 350
   //(mouseX>650 && mouseX<750 && mouseY>632 && mouseY<670 )
   if (ship8==true )   { ship8x=mouseX; ship8y=mouseY; }  
  { if ( Color=="B")    DrawRoundRect(ship8x,ship8y,100,50,colors[DARK_BLUE],20);
  else if (Color=="G")  DrawRoundRect(ship8x,ship8y,100,50,colors[GRAY],20);
  else if (Color=="P")  DrawRoundRect(ship8x,ship8y,100,50,colors[PURPLE],20);
  else if (Color=="BL")  DrawRoundRect(ship8x,ship8y,100,50,colors[BLACK],20);
  }
  
  //ship9 650 450
   //(mouseX>650 && mouseX<750 && mouseY>560 && mouseY<600 )
   if (ship9==true )   { ship9x=mouseX; ship9y=mouseY; }  
   {if ( Color=="B")  DrawRoundRect(ship9x,ship9y,100,50,colors[DARK_BLUE],20);
  else if (Color=="G") DrawRoundRect(ship9x,ship9y,100,50,colors[GRAY],20);
  else if (Color=="P") DrawRoundRect(ship9x,ship9y,100,50,colors[PURPLE],20);
  else if (Color=="BL") DrawRoundRect(ship9x,ship9y,100,50,colors[BLACK],20);
   }
   
   //ship10 650 550
    // (mouseX>650 && mouseX<750 && mouseY>486 && mouseY<520 )
  
   { if ( Color=="B") DrawRoundRect(ship10x,ship10y,100,50,colors[DARK_BLUE],20);
  else if (Color=="G") DrawRoundRect(ship10x,ship10y,100,50,colors[GRAY],20);
  else if (Color=="P") DrawRoundRect(ship10x,ship10y,100,50,colors[PURPLE],20);
  else if (Color=="BL") DrawRoundRect(ship10x,ship10y,100,50,colors[BLACK],20);
    if (ship10==true )   { ship10x=mouseX; ship10y=mouseY; } 
   }
   
   
   
   {// if (mouseX>850 && mouseX<1050 && mouseY>560 && mouseY<600 && place1==1 ) { hold=1; ship1=true; }  
   
//if (ship1==true && place==true && place1==true )   {ship1x-=ship1x%50; ship1y-=ship1y%50; hold=false;  place=false;   ship1=false; place1=0; } 

  if ( Color=="B")     DrawRoundRect(ship1x,ship1y,200,50,colors[DARK_BLUE],20);
  else if (Color=="G") DrawRoundRect(ship1x,ship1y,200,50,colors[GRAY],20);
  else if (Color=="P") DrawRoundRect(ship1x,ship1y,200,50,colors[PURPLE],20);
  else if (Color=="BL") DrawRoundRect(ship1x,ship1y,200,50,colors[BLACK],20);
   // 850 450 
   if (ship1==true )   { ship1x=mouseX; ship1y=mouseY; } }
   

   
 // SHIP LENGHT 3
   { // if (mouseX>850 && mouseX<1000 && mouseY>490 && mouseY<525 && place3==1 ) { hold=1; ship3=true; }  
 
//if (ship3==true && place==true && place3==true )   {ship3x-=ship3x%50; ship3y-=ship3y%50; hold=false;  place=false;   ship3=false; place3=0; }
     if ( Color=="B")    DrawRoundRect(ship3x,ship3y,150,50,colors[DARK_BLUE],20);
  else if (Color=="G")   DrawRoundRect(ship3x,ship3y,150,50,colors[GRAY],20);
  else if (Color=="P")   DrawRoundRect(ship3x,ship3y,150,50,colors[PURPLE],20);
  else if (Color=="BL")  DrawRoundRect(ship3x,ship3y,150,50,colors[BLACK],20);
  if (ship3==true )  { ship3x=mouseX; ship3y=mouseY; }  
  } // 850 350 
   
   
   // SHIP LENGHT 3
    { //if (mouseX>850 && mouseX<1000 && mouseY>630 && mouseY<670 && place2==1 ) { hold=1; ship2=true; }  
 if (ship2==true)    { ship2x=mouseX; ship2y=mouseY; }  
 

      if (Color=="B") DrawRoundRect(ship2x,ship2y,150,50,colors[DARK_BLUE],20); // 850 550 
 else if (Color=="G") DrawRoundRect(ship2x,ship2y,150,50,colors[GRAY],20); // 850 550 
 else if (Color=="P") DrawRoundRect(ship2x,ship2y,150,50,colors[PURPLE],20); // 850 550 
 else if (Color=="BL") DrawRoundRect(ship2x,ship2y,150,50,colors[BLACK],20); }// 850 550  
 
 
  
}


void Battle()
{        glClearColor(0.105f,0.105f,0.105f,1.0); // (132, 136, 132)
	 glClear (GL_COLOR_BUFFER_BIT);

         
         
         
         
         DrawString( 500, 765, "BLACK HARBOUR", colors[WHITE]);

         
         DrawRoundRect(150,650,200,50,colors[SILVER],20);
         DrawRoundRect(450,650,200,50,colors[SILVER],20);
         DrawRoundRect(750,650,250,50,colors[SILVER],20);
         if (HIT) {DrawString( 170, 665, "SCORE: "+to_string(60), colors[BLACK]);}
         DrawString( 170, 665, "SCORE: ", colors[BLACK]);
         DrawString( 470, 665, "TIMER: ", colors[BLACK]);
 
 
 
         DrawString( 770, 665, "BALANCE: ", colors[BLACK]);
         
         
         COMGRID();
         ENEMYGRID();
         COMP1();
         shipplace();
         PLAYERTURN();
        // if (hit==20){glutDisplayFunc(END);} 
       
 
       
       // Game ends
       // ...
       
    
  
        dx();
    
       
    //   DrawString(820,565, "X", colors[ORANGE]);
    
  

         glutSwapBuffers(); 
}

void MAINMENU()
{
	  glClearColor(0,0,0,1.0); 
	  glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	  
          DrawString( 500, 800, "WELCOME TO SEA BATTLE", colors[WHITE]);
          DrawString( 520, 600, "LEADER BOARD", colors[WHITE]);
          DrawString( 500, 500, "StART NEW GAME", colors[WHITE]);
          DrawString( 535, 400, "BALANCE", colors[WHITE]);
          DrawString( 535, 300, "OPTIONS", colors[WHITE]);
          DrawString(535, 200, "EXIT ", colors[WHITE]);
          
          if (moveX>525 && moveX<705 && moveY>672 && moveY<686) { DrawString( 520, 600, "LEADER BOARD", colors[BLUE]); }
          if (moveX>500 && moveX<700 && moveY>595 && moveY<611) {DrawString( 500, 500, "StART NEW GAME", colors[BLUE]);}
          if (moveX>539 && moveX<648 && moveY>528 && moveY<543) {DrawString( 535, 400, "BALANCE", colors[BLUE]); }
          if (moveX>542 && moveX<641 && moveY>453 && moveY<470) { DrawString( 535, 300, "OPTIONS", colors[BLUE]);}
          
          if (moveX>525 && moveX<705 && moveY>672 && moveY<686 && LB==true) {LB=false; glutDisplayFunc(LEADER_BOARD);} 
          if (moveX>500 && moveX<700 && moveY>595 && moveY<611 && LB==true) {LB=false; glutDisplayFunc(StART_NEW_GAME);}
          if (moveX>539 && moveX<648 && moveY>528 && moveY<543 && LB==true) {LB=false; glutDisplayFunc(BALANCE);}
          if (moveX>542 && moveX<641 && moveY>453 && moveY<470 && LB==true) {LB=false; glutDisplayFunc(OPTIONS);}
          if (moveX>538 && moveX<600 && moveY>382 && moveY<400 && LB==true) {exit(0);}
          
     	  glutSwapBuffers(); // do not modify this line..

}

void store(int x,int y)
{

if (x==50 && y==550)  {ARRAY[0][0]=1;}
if (x==100 && y==550) {ARRAY[0][1]=1;}
if (x==150 && y==550) {ARRAY[0][2]=1;}
if (x==200 && y==550) {ARRAY[0][3]=1;}
if (x==250 && y==550) {ARRAY[0][4]=1;}
if (x==300 && y==550) {ARRAY[0][5]=1;}
if (x==350 && y==550) {ARRAY[0][6]=1;}
if (x==400 && y==550) {ARRAY[0][7]=1;}
if (x==450 && y==550) {ARRAY[0][8]=1;}
if (x==500 && y==550) {ARRAY[0][9]=1;}
if (x==50 && y==500)  {ARRAY[1][0]=1;}
if (x==100 && y==500) {ARRAY[1][1]=1;}
if (x==150 && y==500) {ARRAY[1][2]=1;}
if (x==200 && y==500) {ARRAY[1][3]=1;}
if (x==250 && y==500) {ARRAY[1][4]=1;}
if (x==300 && y==500) {ARRAY[1][5]=1;}
if (x==350 && y==500) {ARRAY[1][6]=1;}
if (x==400 && y==500) {ARRAY[1][7]=1;}
if (x==450 && y==500) {ARRAY[1][8]=1;}
if (x==500 && y==500) {ARRAY[1][9]=1;}
if (x==50 && y==450) {ARRAY[2][0]=1;}
if (x==100 && y==450) {ARRAY[2][1]=1;}
if (x==150 && y==450) {ARRAY[2][2]=1;}
if (x==200 && y==450) {ARRAY[2][3]=1;}
if (x==250 && y==450) {ARRAY[2][4]=1;}
if (x==300 && y==450) {ARRAY[2][5]=1;}
if (x==350 && y==450) {ARRAY[2][6]=1;}
if (x==400 && y==450) {ARRAY[2][7]=1;}
if (x==450 && y==450) {ARRAY[2][8]=1;}
if (x==500 && y==450) {ARRAY[2][9]=1;}
if (x==50 && y==400)  {ARRAY[3][0]=1;}
if (x==100 && y==400) {ARRAY[3][1]=1;}
if (x==150 && y==400) {ARRAY[3][2]=1;}
if (x==200 && y==400) {ARRAY[3][3]=1;}
if (x==250 && y==400) {ARRAY[3][4]=1;}
if (x==300 && y==400) {ARRAY[3][5]=1;}
if (x==350 && y==400) {ARRAY[3][6]=1;}
if (x==400 && y==400) {ARRAY[3][7]=1;}
if (x==450 && y==400) {ARRAY[3][8]=1;}
if (x==500 && y==400) {ARRAY[3][9]=1;}
if (x==50 && y==350)  {ARRAY[4][0]=1;}
if (x==100 && y==350) {ARRAY[4][1]=1;}
if (x==150 && y==350) {ARRAY[4][2]=1;}
if (x==200 && y==350) {ARRAY[4][3]=1;}
if (x==250 && y==350) {ARRAY[4][4]=1;}
if (x==300 && y==350) {ARRAY[4][5]=1;}
if (x==350 && y==350) {ARRAY[4][6]=1;}
if (x==400 && y==350) {ARRAY[4][7]=1;}
if (x==450 && y==350) {ARRAY[4][8]=1;}
if (x==500 && y==350) {ARRAY[4][9]=1;}
if (x==50 && y==300)  {ARRAY[5][0]=1;}
if (x==100 && y==300) {ARRAY[5][1]=1;}
if (x==150 && y==300) {ARRAY[5][2]=1;}
if (x==200 && y==300) {ARRAY[5][3]=1;}
if (x==250 && y==300) {ARRAY[5][4]=1;}
if (x==300 && y==300) {ARRAY[5][5]=1;}
if (x==350 && y==300) {ARRAY[5][6]=1;}
if (x==400 && y==300) {ARRAY[5][7]=1;}
if (x==450 && y==300) {ARRAY[5][8]=1;}
if (x==500 && y==300) {ARRAY[5][9]=1;}
if (x==50 && y==250)  {ARRAY[6][0]=1;}
if (x==100 && y==250) {ARRAY[6][1]=1;}
if (x==150 && y==250) {ARRAY[6][2]=1;}
if (x==200 && y==250) {ARRAY[6][3]=1;}
if (x==250 && y==250) {ARRAY[6][4]=1;}
if (x==300 && y==250) {ARRAY[6][5]=1;}
if (x==350 && y==250) {ARRAY[6][6]=1;}
if (x==400 && y==250) {ARRAY[6][7]=1;}
if (x==450 && y==250) {ARRAY[6][8]=1;}
if (x==500 && y==250) {ARRAY[6][9]=1;}
if (x==50 && y==200)  {ARRAY[7][0]=1;}
if (x==100 && y==200) {ARRAY[7][1]=1;}
if (x==150 && y==200) {ARRAY[7][2]=1;}
if (x==200 && y==200) {ARRAY[7][3]=1;}
if (x==250 && y==200) {ARRAY[7][4]=1;}
if (x==300 && y==200) {ARRAY[7][5]=1;}
if (x==350 && y==200) {ARRAY[7][6]=1;}
if (x==400 && y==200) {ARRAY[7][7]=1;}
if (x==450 && y==200) {ARRAY[7][8]=1;}
if (x==500 && y==200) {ARRAY[7][9]=1;}
if (x==50 && y==150)  {ARRAY[8][0]=1;}
if (x==100 && y==150) {ARRAY[8][1]=1;}
if (x==150 && y==150) {ARRAY[8][2]=1;}
if (x==200 && y==150) {ARRAY[8][3]=1;}
if (x==250 && y==150) {ARRAY[8][4]=1;}
if (x==300 && y==150) {ARRAY[8][5]=1;}
if (x==350 && y==150) {ARRAY[8][6]=1;}
if (x==400 && y==150) {ARRAY[8][7]=1;}
if (x==450 && y==150) {ARRAY[8][8]=1;}
if (x==500 && y==150) {ARRAY[8][9]=1;}
if (x==50 && y==100)  {ARRAY[9][0]=1;}
if (x==100 && y==100) {ARRAY[9][1]=1;}
if (x==150 && y==100) {ARRAY[9][2]=1;}
if (x==200 && y==100) {ARRAY[9][3]=1;}
if (x==250 && y==100) {ARRAY[9][4]=1;}
if (x==300 && y==100) {ARRAY[9][5]=1;}
if (x==350 && y==100) {ARRAY[9][6]=1;}
if (x==400 && y==100) {ARRAY[9][7]=1;}
if (x==450 && y==100) {ARRAY[9][8]=1;}
if (x==500 && y==100) {ARRAY[9][9]=1;}
}

void CChcker(int row , int col)
{ if (row==0 && col==0) {GX=50; GY=550;}


if (row==0 && col==1) {GX=100; GY=550;}

if (row==0 && col==2) {GX=150; GY=550;}

if (row==0 && col==3) {GX=200; GY=550;}

if (row==0 && col==4) {GX=250; GY=550;}

if (row==0 && col==5) {GX=300; GY=550;}

if (row==0 && col==6) {GX=350; GY=550;}

if (row==0 && col==7) {GX=400; GY=550;}

if (row==0 && col==8) {GX=450; GY=550;}

if (row==0 && col==9) {GX=500; GY=550;}

if (row==1 && col==0) {GX=50; GY=500;}

if (row==1 && col==1) {GX=100; GY=500;}

if (row==1 && col==2) {GX=150; GY=500;}

if (row==1 && col==3) {GX=200; GY=500;}

if (row==1 && col==4) {GX=250; GY=500;}

if (row==1 && col==5) {GX=300; GY=500;}

if (row==1 && col==6) {GX=350; GY=500;}

if (row==1 && col==7) {GX=400; GY=500;}

if (row==1 && col==8) {GX=450; GY=500;}

if (row==1 && col==9) {GX=500; GY=500;}

if (row==2 && col==0) {GX=50; GY=450;}

if (row==2 && col==1) {GX=100; GY=450;}

if (row==2 && col==2) {GX=150; GY=450;}

if (row==2 && col==3) {GX=200; GY=450;}

if (row==2 && col==4) {GX=250; GY=450;}

if (row==2 && col==5) {GX=300; GY=450;}

if (row==2 && col==6) {GX=350; GY=450;}

if (row==2 && col==7) {GX=400; GY=450;}

if (row==2 && col==8) {GX=450; GY=450;}

if (row==2 && col==9) {GX=500; GY=450;}

if (row==3 && col==0) {GX=50; GY=400;}

if (row==3 && col==1) {GX=100; GY=400;}

if (row==3 && col==2) {GX=150; GY=400;}

if (row==3 && col==3) {GX=200; GY=400;}

if (row==3 && col==4) {GX=250; GY=400;}

if (row==3 && col==5) {GX=300; GY=400;}

if (row==3 && col==6) {GX=350; GY=400;}

if (row==3 && col==7) {GX=400; GY=400;}

if (row==3 && col==8) {GX=450; GY=400;}

if (row==3 && col==9) {GX=500; GY=400;}

if (row==4 && col==0) {GX=50; GY=350;}

if (row==4 && col==1) {GX=100; GY=350;}

if (row==4 && col==2) {GX=150; GY=350;}

if (row==4 && col==3) {GX=200; GY=350;}

if (row==4 && col==4) {GX=250; GY=350;}

if (row==4 && col==5) {GX=300; GY=350;}

if (row==4 && col==6) {GX=350; GY=350;}

if (row==4 && col==7) {GX=400; GY=350;}

if (row==4 && col==8) {GX=450; GY=350;}

if (row==4 && col==9) {GX=500; GY=350;}

if (row==5 && col==0) {GX=50; GY=300;}

if (row==5 && col==1) {GX=100; GY=300;}

if (row==5 && col==2) {GX=150; GY=300;}

if (row==5 && col==3) {GX=200; GY=300;}

if (row==5 && col==4) {GX=250; GY=300;}

if (row==5 && col==5) {GX=300; GY=300;}

if (row==5 && col==6) {GX=350; GY=300;}

if (row==5 && col==7) {GX=400; GY=300;}

if (row==5 && col==8) {GX=450; GY=300;}

if (row==5 && col==9) {GX=500; GY=300;}

if (row==6 && col==0) {GX=50; GY=250;}

if (row==6 && col==1) {GX=100; GY=250;}

if (row==6 && col==2) {GX=150; GY=250;}

if (row==6 && col==3) {GX=200; GY=250;}

if (row==6 && col==4) {GX=250; GY=250;}

if (row==6 && col==5) {GX=300; GY=250;}

if (row==6 && col==6) {GX=350; GY=250;}

if (row==6 && col==7) {GX=400; GY=250;}

if (row==6 && col==8) {GX=450; GY=250;}

if (row==6 && col==9) {GX=500; GY=250;}

if (row==7 && col==0) {GX=50; GY=200;}

if (row==7 && col==1) {GX=100; GY=200;}

if (row==7 && col==2) {GX=150; GY=200;}

if (row==7 && col==3) {GX=200; GY=200;}

if (row==7 && col==4) {GX=250; GY=200;}

if (row==7 && col==5) {GX=300; GY=200;}

if (row==7 && col==6) {GX=350; GY=200;}

if (row==7 && col==7) {GX=400; GY=200;}

if (row==7 && col==8) {GX=450; GY=200;}

if (row==7 && col==9) {GX=500; GY=200;}

if (row==8 && col==0) {GX=50; GY=150;}

if (row==8 && col==1) {GX=100; GY=150;}

if (row==8 && col==2) {GX=150; GY=150;}

if (row==8 && col==3) {GX=200; GY=150;}

if (row==8 && col==4) {GX=250; GY=150;}

if (row==8 && col==5) {GX=300; GY=150;}

if (row==8 && col==6) {GX=350; GY=150;}

if (row==8 && col==7) {GX=400; GY=150;}

if (row==8 && col==8) {GX=450; GY=150;}

if (row==8 && col==9) {GX=500; GY=150;}

if (row==9 && col==0) {GX=50; GY=100;}

if (row==9 && col==1) {GX=100; GY=100;}

if (row==9 && col==2) {GX=150; GY=100;}

if (row==9 && col==3) {GX=200; GY=100;}

if (row==9 && col==4) {GX=250; GY=100;}

if (row==9 && col==5) {GX=300; GY=100;}

if (row==9 && col==6) {GX=350; GY=100;}

if (row==9 && col==7) {GX=400; GY=100;}

if (row==9 && col==8) {GX=450; GY=100;}


if (row==9 && col==9) {GX=500; GY=100;}
}


void RCO(int x,int y)

{
cout<<"\n RCO: "<<x<<"\t"<<y;

if (x==50 && y==550) { ROW=0; COL=0;}

if (x==100 && y==550) {ROW=0; COL=1;}

if (x==150 && y==550) {ROW=0; COL=2;}

if (x==200 && y==550) {ROW=0; COL=3;}

if (x==250 && y==550) {ROW=0; COL=4;}

if (x==300 && y==550) {ROW=0; COL=5;}

if (x==350 && y==550) {ROW=0; COL=6;}

if (x==400 && y==550) {ROW=0; COL=7;}

if (x==450 && y==550) {ROW=0; COL=8;}

if (x==500 && y==550) {ROW=0; COL=9;}

if (x==50 && y==500) {ROW=1; COL=0;}

if (x==100 && y==500) {ROW=1; COL=1;}

if (x==150 && y==500) {ROW=1; COL=2;}

if (x==200 && y==500) {ROW=1; COL=3;}

if (x==250 && y==500) {ROW=1; COL=4;}

if (x==300 && y==500) {ROW=1; COL=5;}

if (x==350 && y==500) {ROW=1; COL=6;}

if (x==400 && y==500) {ROW=1; COL=7;}

if (x==450 && y==500) {ROW=1; COL=8;}

if (x==500 && y==500) {ROW=1; COL=9;}

if (x==50 && y==450) {ROW=2; COL=0;}

if (x==100 && y==450) {ROW=2; COL=1;}

if (x==150 && y==450) {ROW=2; COL=2;}

if (x==200 && y==450) {ROW=2; COL=3;}

if (x==250 && y==450) {ROW=2; COL=4;}

if (x==300 && y==450) {ROW=2; COL=5;}

if (x==350 && y==450) {ROW=2; COL=6;}

if (x==400 && y==450) {ROW=2; COL=7;}

if (x==450 && y==450) {ROW=2; COL=8;}

if (x==500 && y==450) {ROW=2; COL=9;}

if (x==50 && y==400) {ROW=3; COL=0;}

if (x==100 && y==400) {ROW=3; COL=1;}

if (x==150 && y==400) {ROW=3; COL=2;}

if (x==200 && y==400) {ROW=3; COL=3;}

if (x==250 && y==400) {ROW=3; COL=4;}

if (x==300 && y==400) {ROW=3; COL=5;}

if (x==350 && y==400) {ROW=3; COL=6;}

if (x==400 && y==400) {ROW=3; COL=7;}

if (x==450 && y==400) {ROW=3; COL=8;}

if (x==500 && y==400) {ROW=3; COL=9;}

if (x==50 && y==350) {ROW=4; COL=0;}

if (x==100 && y==350) {ROW=4; COL=1;}

if (x==150 && y==350) {ROW=4; COL=2;}

if (x==200 && y==350) {ROW=4; COL=3;}

if (x==250 && y==350) {ROW=4; COL=4;}

if (x==300 && y==350) {ROW=4; COL=5;}

if (x==350 && y==350) {ROW=4; COL=6;}

if (x==400 && y==350) {ROW=4; COL=7;}

if (x==450 && y==350) {ROW=4; COL=8;}

if (x==500 && y==350) {ROW=4; COL=9;}

if (x==50 && y==300) {ROW=5; COL=0;}

if (x==100 && y==300) {ROW=5; COL=1;}

if (x==150 && y==300) {ROW=5; COL=2;}

if (x==200 && y==300) {ROW=5; COL=3;}

if (x==250 && y==300) {ROW=5; COL=4;}

if (x==300 && y==300) {ROW=5; COL=5;}

if (x==350 && y==300) {ROW=5; COL=6;}

if (x==400 && y==300) {ROW=5; COL=7;}

if (x==450 && y==300) {ROW=5; COL=8;}

if (x==500 && y==300) {ROW=5; COL=9;}

if (x==50 && y==250) {ROW=6; COL=0;}

if (x==100 && y==250) {ROW=6; COL=1;}

if (x==150 && y==250) {ROW=6; COL=2;}

if (x==200 && y==250) {ROW=6; COL=3;}

if (x==250 && y==250) {ROW=6; COL=4;}

if (x==300 && y==250) {ROW=6; COL=5;}

if (x==350 && y==250) {ROW=6; COL=6;}

if (x==400 && y==250) {ROW=6; COL=7;}

if (x==450 && y==250) {ROW=6; COL=8;}

if (x==500 && y==250) {ROW=6; COL=9;}

if (x==50 && y==200) {ROW=7; COL=0;}

if (x==100 && y==200) {ROW=7; COL=1;}

if (x==150 && y==200) {ROW=7; COL=2;}

if (x==200 && y==200) {ROW=7; COL=3;}

if (x==250 && y==200) {ROW=7; COL=4;}

if (x==300 && y==200) {ROW=7; COL=5;}

if (x==350 && y==200) {ROW=7; COL=6;}

if (x==400 && y==200) {ROW=7; COL=7;}

if (x==450 && y==200) {ROW=7; COL=8;}

if (x==500 && y==200) {ROW=7; COL=9;}

if (x==50 && y==150) {ROW=8; COL=0;}

if (x==100 && y==150) {ROW=8; COL=1;}

if (x==150 && y==150) {ROW=8; COL=2;}

if (x==200 && y==150) {ROW=8; COL=3;}

if (x==250 && y==150) {ROW=8; COL=4;}

if (x==300 && y==150) {ROW=8; COL=5;}

if (x==350 && y==150) {ROW=8; COL=6;}

if (x==400 && y==150) {ROW=8; COL=7;}

if (x==450 && y==150) {ROW=8; COL=8;}

if (x==500 && y==150) {ROW=8; COL=9;}

if (x==50 && y==100) {ROW=9; COL=0;}

if (x==100 && y==100) {ROW=9; COL=1;}

if (x==150 && y==100) {ROW=9; COL=2;}

if (x==200 && y==100) {ROW=9; COL=3;}

if (x==250 && y==100) {ROW=9; COL=4;}

if (x==300 && y==100) {ROW=9; COL=5;}

if (x==350 && y==100) {ROW=9; COL=6;}

if (x==400 && y==100) {ROW=9; COL=7;}

if (x==450 && y==100) {ROW=9; COL=8;}

if (x==500 && y==100) {ROW=9; COL=9;}



}

void dx()
{
if (xp1==true) if (ARRAY2[0][0]==1) { DrawString(820,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,565, "B", colors[BLACK]); miss++;MISS=false;}


if (xp2==true) if (ARRAY2[0][1]==1) { DrawString(870,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp3==true) if (ARRAY2[0][2]==1) { DrawString(920,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp4==true) if (ARRAY2[0][3]==1) { DrawString(970,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp5==true) if (ARRAY2[0][4]==1) { DrawString(1020,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp6==true) if (ARRAY2[0][5]==1) { DrawString(1070,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp7==true) if (ARRAY2[0][6]==1) { DrawString(1120,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp8==true) if (ARRAY2[0][7]==1) { DrawString(1170,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp9==true) if (ARRAY2[0][8]==1) { DrawString(1220,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp10==true) if (ARRAY2[0][9]==1) { DrawString(1270,565, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,565, "B", colors[BLACK]); miss++;MISS=false; }

if (xp11==true) if (ARRAY2[1][0]==1) { DrawString(820,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp12==true) if (ARRAY2[1][1]==1) { DrawString(870,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp13==true) if (ARRAY2[1][2]==1) { DrawString(920,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp14==true) if (ARRAY2[1][3]==1) { DrawString(970,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp15==true) if (ARRAY2[1][4]==1) { DrawString(1020,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp16==true) if (ARRAY2[1][5]==1) { DrawString(1070,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp17==true) if (ARRAY2[1][6]==1) { DrawString(1120,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp18==true) if (ARRAY2[1][7]==1) { DrawString(1170,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp19==true) if (ARRAY2[1][8]==1) { DrawString(1220,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp20==true) if (ARRAY2[1][9]==1) { DrawString(1270,515, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,515, "B", colors[BLACK]); miss++;MISS=false; }

if (xp21==true) if (ARRAY2[2][0]==1) { DrawString(820,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,465, "B", colors[BLACK]); miss++;MISS=false; }

if (xp22==true) if (ARRAY2[2][1]==1) { DrawString(870,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,465, "B", colors[BLACK]); miss++;MISS=false; }

if (xp23==true) if (ARRAY2[2][2]==1) { DrawString(920,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,465, "B", colors[BLACK]); miss++;MISS=false; }

if (xp24==true) if (ARRAY2[2][3]==1) { DrawString(970,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,465, "B", colors[BLACK]); miss++;MISS=false; }

if (xp25==true) if (ARRAY2[2][4]==1) { DrawString(1020,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,465, "B", colors[BLACK]); miss++;MISS=false; }

if (xp26==true) if (ARRAY2[2][5]==1) { DrawString(1070,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,465, "B", colors[BLACK]); miss++;MISS=false;   }
	if (xp27==true) if (ARRAY2[2][6]==1) { DrawString(1120,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,465, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp28==true) if (ARRAY2[2][7]==1) { DrawString(1170,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,465, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp29==true) if (ARRAY2[2][8]==1) { DrawString(1220,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,465, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp30==true) if (ARRAY2[2][9]==1) { DrawString(1270,465, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,465, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp31==true) if (ARRAY2[3][0]==1) { DrawString(820,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp32==true) if (ARRAY2[3][1]==1) { DrawString(870,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp33==true) if (ARRAY2[3][2]==1) { DrawString(920,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp34==true) if (ARRAY2[3][3]==1) { DrawString(970,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp35==true) if (ARRAY2[3][4]==1) { DrawString(1020,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,415, "B", colors[BLACK]); miss++;MISS=false;   }
	
	if (xp36==true) if (ARRAY2[3][5]==1) { DrawString(1070,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp37==true) if (ARRAY2[3][6]==1) { DrawString(1120,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp38==true) if (ARRAY2[3][7]==1) { DrawString(1170,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp39==true) if (ARRAY2[3][8]==1) { DrawString(1220,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp40==true) if (ARRAY2[3][9]==1) { DrawString(1270,415, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,415, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp41==true) if (ARRAY2[4][0]==1) { DrawString(820,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp42==true) if (ARRAY2[4][1]==1) { DrawString(870,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp43==true) if (ARRAY2[4][2]==1) { DrawString(920,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp44==true) if (ARRAY2[4][3]==1) { DrawString(970,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp45==true) if (ARRAY2[4][4]==1) { DrawString(1020,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp46==true) if (ARRAY2[4][5]==1) { DrawString(1070,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp47==true) if (ARRAY2[4][6]==1) { DrawString(1120,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp48==true) if (ARRAY2[4][7]==1) { DrawString(1170,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp49==true) if (ARRAY2[4][8]==1) { DrawString(1220,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,365, "B", colors[BLACK]); miss++;MISS=false;   }

	if (xp50==true) if (ARRAY2[4][9]==1) { DrawString(1270,365, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,365, "B", colors[BLACK]); miss++;MISS=false;   }
	
	if (xp51==true) if (ARRAY2[5][0]==1) { DrawString(820,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp52==true) if (ARRAY2[5][1]==1) { DrawString(870,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp53==true) if (ARRAY2[5][2]==1) { DrawString(920,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp54==true) if (ARRAY2[5][3]==1) { DrawString(970,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp55==true) if (ARRAY2[5][4]==1) { DrawString(1020,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp56==true) if (ARRAY2[5][5]==1) { DrawString(1070,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp57==true) if (ARRAY2[5][6]==1) { DrawString(1120,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp58==true) if (ARRAY2[5][7]==1) { DrawString(1170,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp59==true) if (ARRAY2[5][8]==1) { DrawString(1220,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp60==true) if (ARRAY2[5][9]==1) { DrawString(1270,315, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,315, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp61==true) if (ARRAY2[6][0]==1) { DrawString(820,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,265, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp62==true) if (ARRAY2[6][1]==1) { DrawString(870,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,265, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp63==true) if (ARRAY2[6][2]==1) { DrawString(920,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,265, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp64==true) if (ARRAY2[6][3]==1) { DrawString(970,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,265, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp65==true) if (ARRAY2[6][4]==1) { DrawString(1020,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,265, "B", colors[BLACK]); miss++;MISS=false;  }

if (xp66==true) if (ARRAY2[6][5]==1) { DrawString(1070,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,265, "B", colors[BLACK]); miss++;MISS=false;  }
if (xp67==true) if (ARRAY2[6][6]==1) { DrawString(1120,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,265, "B", colors[BLACK]); } 
if (xp68==true) if (ARRAY2[6][7]==1) { DrawString(1170,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,265, "B", colors[BLACK]); } 
if (xp69==true) if (ARRAY2[6][8]==1) { DrawString(1220,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,265, "B", colors[BLACK]); } 
if (xp70==true) if (ARRAY2[6][9]==1) { DrawString(1270,265, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,265, "B", colors[BLACK]); } 

if (xp71==true) if (ARRAY2[7][0]==1) { DrawString(820,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,215, "B", colors[BLACK]); } 
if (xp72==true) if (ARRAY2[7][1]==1) { DrawString(870,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,215, "B", colors[BLACK]); } 
if (xp73==true) if (ARRAY2[7][2]==1) { DrawString(920,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,215, "B", colors[BLACK]); } 
if (xp74==true) if (ARRAY2[7][3]==1) { DrawString(970,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,215, "B", colors[BLACK]); }
if (xp75==true) if (ARRAY2[7][4]==1) { DrawString(1020,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,215, "B", colors[BLACK]); }  
if (xp76==true) if (ARRAY2[7][5]==1) { DrawString(1070,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,215, "B", colors[BLACK]); } 
if (xp77==true) if (ARRAY2[7][6]==1) { DrawString(1120,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,215, "B", colors[BLACK]); } 
if (xp78==true) if (ARRAY2[7][7]==1) { DrawString(1170,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,215, "B", colors[BLACK]); } 
if (xp79==true) if (ARRAY2[7][8]==1) { DrawString(1220,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,215, "B", colors[BLACK]); } 
if (xp80==true) if (ARRAY2[7][9]==1) { DrawString(1270,215, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,215, "B", colors[BLACK]); } 

if (xp81==true) if (ARRAY2[8][0]==1) { DrawString(820,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,165, "B", colors[BLACK]); } 
if (xp82==true) if (ARRAY2[8][1]==1) { DrawString(870,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,165, "B", colors[BLACK]); } 
if (xp83==true) if (ARRAY2[8][2]==1) { DrawString(920,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,165, "B", colors[BLACK]); } 
if (xp84==true) if (ARRAY2[8][3]==1) { DrawString(970,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,165, "B", colors[BLACK]); } 
if (xp85==true) if (ARRAY2[8][4]==1) { DrawString(1020,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,165, "B", colors[BLACK]); } 
if (xp86==true) if (ARRAY2[8][5]==1) { DrawString(1070,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,165, "B", colors[BLACK]); } 
if (xp87==true) if (ARRAY2[8][6]==1) { DrawString(1120,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,165, "B", colors[BLACK]); } 
if (xp88==true) if (ARRAY2[8][7]==1) { DrawString(1170,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,165, "B", colors[BLACK]); } 
if (xp89==true) if (ARRAY2[8][8]==1) { DrawString(1220,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,165, "B", colors[BLACK]); } 
if (xp90==true) if (ARRAY2[8][9]==1) { DrawString(1270,165, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1270,165, "B", colors[BLACK]); } 

if (xp91==true) if (ARRAY2[9][0]==1) { DrawString(820,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(820,115, "B", colors[BLACK]); } 
if (xp92==true) if (ARRAY2[9][1]==1) { DrawString(870,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(870,115, "B", colors[BLACK]); } 
if (xp93==true) if (ARRAY2[9][2]==1) { DrawString(920,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(920,115, "B", colors[BLACK]); } 
if (xp94==true) if (ARRAY2[9][3]==1) { DrawString(970,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(970,115, "B", colors[BLACK]); } 
if (xp95==true) if (ARRAY2[9][4]==1) { DrawString(1020,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1020,115, "B", colors[BLACK]); } 
if (xp96==true) if (ARRAY2[9][5]==1) { DrawString(1070,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1070,115, "B", colors[BLACK]); } 
if (xp97==true) if (ARRAY2[9][6]==1) { DrawString(1120,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1120,115, "B", colors[BLACK]); } 
if (xp98==true) if (ARRAY2[9][7]==1) { DrawString(1170,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1170,115, "B", colors[BLACK]); } 
if (xp99==true) if (ARRAY2[9][8]==1) { DrawString(1220,115, "X", colors[BLACK]); hit++; HIT=true; } else { DrawString(1220,115, "B", colors[BLACK]); } 
if (xp100==true) if (ARRAY2[9][9]==1) { DrawString(1270,115, "X", colors[BLACK]); hit++; HIT=true; } else DrawString(1270,115, "B", colors[BLACK]);
}

void COMP1()
{

ARRAY2[0][0]=1;
ARRAY2[0][1]=1;
ARRAY2[0][2]=1;

ARRAY2[9][0]=1;
ARRAY2[9][1]=1;
ARRAY2[9][2]=1;

ARRAY2[5][0]=1;
ARRAY2[5][1]=1;

ARRAY2[5][3]=1;
ARRAY2[5][4]=1;

ARRAY2[5][6]=1;
ARRAY2[5][7]=1;

ARRAY2[6][9]=1;
ARRAY2[7][9]=1;
ARRAY2[8][9]=1;
ARRAY2[9][9]=1;

ARRAY2[9][4]=1;
ARRAY2[3][9]=1;
ARRAY2[9][6]=1;
ARRAY2[1][9]=1;


}

void PLAYERTURN()
{


   if (moveX>800 && moveX<850 && moveY>635 && moveY<670 && LB==true) { LB=false; xp1=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>635 && moveY<670 && LB==true) { LB=false; xp2=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>635 && moveY<670 && LB==true) { LB=false; xp3=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>635 && moveY<670 && LB==true) { LB=false; xp4=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>635 && moveY<670 && LB==true) { LB=false; xp5=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>635 && moveY<670 && LB==true) { LB=false; xp6=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>635 && moveY<670 && LB==true) { LB=false; xp7=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>635 && moveY<670 && LB==true) { LB=false; xp8=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>635 && moveY<670 && LB==true) { LB=false; xp9=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>635 && moveY<670 && LB==true) { LB=false; xp10=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>601 && moveY<635 && LB==true) { LB=false; xp11=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>601 && moveY<635 && LB==true) { LB=false; xp12=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>601 && moveY<635 && LB==true) { LB=false; xp13=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>601 && moveY<635 && LB==true) { LB=false; xp14=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>601 && moveY<635 && LB==true) { LB=false; xp15=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>601 && moveY<635 && LB==true) { LB=false; xp16=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>601 && moveY<635 && LB==true) { LB=false; xp17=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>601 && moveY<635 && LB==true) { LB=false; xp18=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>601 && moveY<635 && LB==true) { LB=false; xp19=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>601 && moveY<635 && LB==true) { LB=false; xp20=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>567 && moveY<601 && LB==true) { LB=false; xp21=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>567 && moveY<601 && LB==true) { LB=false; xp22=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>567 && moveY<601 && LB==true) { LB=false; xp23=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>567 && moveY<601 && LB==true) { LB=false; xp24=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>567 && moveY<601 && LB==true) { LB=false; xp25=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>567 && moveY<601 && LB==true) { LB=false; xp26=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>567 && moveY<601 && LB==true) { LB=false; xp27=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>567 && moveY<601 && LB==true) { LB=false; xp28=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>567 && moveY<601 && LB==true) { LB=false; xp29=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>567 && moveY<601 && LB==true) { LB=false; xp30=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>533 && moveY<567 && LB==true) { LB=false; xp31=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>533 && moveY<567 && LB==true) { LB=false; xp32=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>533 && moveY<567 && LB==true) { LB=false; xp33=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>533 && moveY<567 && LB==true) { LB=false; xp34=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>533 && moveY<567 && LB==true) { LB=false; xp35=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>533 && moveY<567 && LB==true) { LB=false; xp36=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>533 && moveY<567 && LB==true) { LB=false; xp37=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>533 && moveY<567 && LB==true) { LB=false; xp38=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>533 && moveY<567 && LB==true) { LB=false; xp39=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>533 && moveY<567 && LB==true) { LB=false; xp40=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>499 && moveY<533 && LB==true) { LB=false; xp41=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>499 && moveY<533 && LB==true) { LB=false; xp42=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>499 && moveY<533 && LB==true) { LB=false; xp43=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>499 && moveY<533 && LB==true) { LB=false; xp44=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>499 && moveY<533 && LB==true) { LB=false; xp45=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>499 && moveY<533 && LB==true) { LB=false; xp46=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>499 && moveY<533 && LB==true) { LB=false; xp47=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>499 && moveY<533 && LB==true) { LB=false; xp48=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>499 && moveY<533 && LB==true) { LB=false; xp49=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>499 && moveY<533 && LB==true) { LB=false; xp50=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>465 && moveY<499 && LB==true) { LB=false; xp51=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>465 && moveY<499 && LB==true) { LB=false; xp52=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>465 && moveY<499 && LB==true) { LB=false; xp53=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>465 && moveY<499 && LB==true) { LB=false; xp54=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>465 && moveY<499 && LB==true) { LB=false; xp55=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>465 && moveY<499 && LB==true) { LB=false; xp56=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>465 && moveY<499 && LB==true) { LB=false; xp57=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>465 && moveY<499 && LB==true) { LB=false; xp58=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>465 && moveY<499 && LB==true) { LB=false; xp59=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>465 && moveY<499 && LB==true) { LB=false; xp60=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>431 && moveY<465 && LB==true) { LB=false; xp61=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>431 && moveY<465 && LB==true) { LB=false; xp62=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>431 && moveY<465 && LB==true) { LB=false; xp63=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>431 && moveY<465 && LB==true) { LB=false; xp64=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>431 && moveY<465 && LB==true) { LB=false; xp65=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>431 && moveY<465 && LB==true) { LB=false; xp66=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>431 && moveY<465 && LB==true) { LB=false; xp67=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>431 && moveY<465 && LB==true) { LB=false; xp68=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>431 && moveY<465 && LB==true) { LB=false; xp69=true; dx(); }
    if (moveX>1250 && moveX<1300 && moveY>431 && moveY<465 && LB==true) { LB=false; xp70=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>397 && moveY<431 && LB==true) { LB=false; xp71=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>397 && moveY<431 && LB==true) { LB=false; xp72=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>397 && moveY<431 && LB==true) { LB=false; xp73=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>397 && moveY<431 && LB==true) { LB=false; xp74=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>397 && moveY<431 && LB==true) { LB=false; xp75=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>397 && moveY<431 && LB==true) { LB=false; xp76=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>397 && moveY<431 && LB==true) { LB=false; xp77=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>397 && moveY<431 && LB==true) { LB=false; xp78=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>397 && moveY<431 && LB==true) { LB=false; xp79=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>397 && moveY<431 && LB==true) { LB=false; xp80=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>363 && moveY<397 && LB==true) { LB=false; xp81=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>363 && moveY<397 && LB==true) { LB=false; xp82=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>363 && moveY<397 && LB==true) { LB=false; xp83=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>363 && moveY<397 && LB==true) { LB=false; xp84=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>363 && moveY<397 && LB==true) { LB=false; xp85=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>363 && moveY<397 && LB==true) { LB=false; xp86=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>363 && moveY<397 && LB==true) { LB=false; xp87=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>363 && moveY<397 && LB==true) { LB=false; xp88=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>363 && moveY<397 && LB==true) { LB=false; xp89=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>363 && moveY<397 && LB==true) { LB=false; xp90=true; dx(); }
  if (moveX>800 && moveX<850 && moveY>329 && moveY<363 && LB==true) { LB=false; xp91=true; dx(); }
  if (moveX>850 && moveX<900 && moveY>329 && moveY<363 && LB==true) { LB=false; xp92=true; dx(); }
  if (moveX>900 && moveX<950 && moveY>329 && moveY<363 && LB==true) { LB=false; xp93=true; dx(); }
  if (moveX>950 && moveX<1000 && moveY>329 && moveY<363 && LB==true) { LB=false; xp94=true; dx(); }
  if (moveX>1000 && moveX<1050 && moveY>329 && moveY<363 && LB==true) { LB=false; xp95=true; dx(); }
  if (moveX>1050 && moveX<1100 && moveY>329 && moveY<363 && LB==true) { LB=false; xp96=true; dx(); }
  if (moveX>1100 && moveX<1150 && moveY>329 && moveY<363 && LB==true) { LB=false; xp97=true; dx(); }
  if (moveX>1150 && moveX<1200 && moveY>329 && moveY<363 && LB==true) { LB=false; xp98=true; dx(); }
  if (moveX>1200 && moveX<1250 && moveY>329 && moveY<363 && LB==true) { LB=false; xp99=true; dx(); }
  if (moveX>1250 && moveX<1300 && moveY>329 && moveY<363 && LB==true) { LB=false; xp100=true; dx(); }
  
}
#endif /* Battleship_CPP_ */
