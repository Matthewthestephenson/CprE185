// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
//Updated for Esplora 2013 TeamRursch185


// Headers
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define COLMS 100
#define ROWS 80
#define MAXPOINTS 10000
// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define YOUR_PATH '.'
#define WALL '*'
#define EMPTY_SPACE ' '
#define LENGTHOFAVG 20
#define FREQUENCY2 25
#define FREQUENCY 750
#define TOLERANCE .5
#define TRUE 1
#define FALSE 0
// Number of samples taken to form an average for the accelerometer data
// Feel free to tweak this.  You may actually want to use the moving averages
// code you created last week 
#define NUM_SAMPLES 10  
double avg(double buffer[], int num_items);
int read_acc(int* time, double* a_x, double* a_y, double* a_z,  int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);
void updatebuffer(double buffer[], int length, double new_item);
double roll(double x_mag);
// 2D character array which the maze is mapped into
char MAZE[COLMS][ROWS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < y_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the pitch function written in previous labs.  

double calc_roll(double x_mag);

// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[])
{
double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];

int counter = 0, b_down, b_up, b_left, b_right;

double a_x, a_y, a_z, min_x, min_y, min_z, max_x, max_y, max_z, avg_x, avg_y, avg_z;

int difficulty = 0, dropTime = 1 ,dropTime2;

int axisX = 50, axisY = 0, t = 0,lose;

	srand((int)time(0));
	    
	initscr();
	refresh();

	if (argc>1) {//Difficulty
		sscanf(argv[1], "%d", &difficulty );
	}
	else {
	}
	
	generate_maze(difficulty);
	
	draw_maze ();

	draw_character(axisX,axisY,AVATAR);//Avatar placed & waiting
	

	do
	{
	read_acc (&t, &a_x, &a_y, &a_z, &b_up, &b_down, &b_left, &b_right);

	counter++;

	updatebuffer( x,  LENGTHOFAVG,  a_x);
	updatebuffer( y,  LENGTHOFAVG,  a_y);
	updatebuffer( z,  LENGTHOFAVG,  a_z);
	

	if (counter >= LENGTHOFAVG){
	
	
	avg_x = avg( x, LENGTHOFAVG);
	avg_y = avg( y, LENGTHOFAVG);
	avg_z = avg( z, LENGTHOFAVG);
	}
	
		
	if(t > dropTime + FREQUENCY2){//begin move?
	
		dropTime = t ;
		
		
		if (roll(a_x) > TOLERANCE && MAZE[axisX-1][axisY] != WALL && axisX > 0 ){// can i move left?
			
			axisX--;// update x
			
			draw_character(axisX,axisY,AVATAR);// place new avatar
			
			draw_character(axisX+1,axisY,YOUR_PATH);// erase previous avatar
	
		}
		else if (roll(a_x) < (-1.0*TOLERANCE) && MAZE[axisX+1][axisY] != WALL && axisX < 99){// can i move right?
			
			axisX++;// update x
		
			draw_character(axisX,axisY,AVATAR);// place new avatar
			
			draw_character(axisX-1,axisY,YOUR_PATH);// erase previous avatar
	
		}
		
	}
	
	if(t > dropTime2 + FREQUENCY){// begin fall?
	
			dropTime2 = t ;	
			
		if( MAZE[axisX][axisY+1] != WALL){// can i fall?
		
			axisY++;// update y
			
			draw_character(axisX,axisY,AVATAR);// place new avatar
			
			draw_character(axisX,axisY-1,YOUR_PATH);// erase previous avatar
			
		}
	
	
	if (MAZE[axisX-1][axisY] == WALL && MAZE[axisX+1][axisY] == WALL && MAZE[axisX][axisY+1] == WALL){ //did i win?
		lose = 1;
		}
	else{ 
		lose = 0;
		}
	
}




	}while (axisY < 80 && lose != 1);


	// Print the win message
	endwin();
	if (lose = 0){
	printf("YOU WIN!\n");//announce & exit
	
}
	else{
	printf("YOU LOSE!\n");//announce & exit
	}
	
	}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}
void generate_maze(int difficulty) {
srand((int)time(0));
int percentDif = (rand() % 100);
int x = 0;
int y = 0;

for (x = 0; x < COLMS; x++){

	for(y = 0; y < ROWS; y++){
	int percentDif = (rand() % 100);
		if( percentDif < difficulty){
			MAZE[x][y] = WALL;

		}
		else{
			MAZE[x][y] = EMPTY_SPACE;
		}
		
		
	}

}

}
void draw_maze(void) {
int x=0;
int y=0;
char use;
	for (x = 0; x < COLMS; x++){

		for(y = 0; y < ROWS; y++){
		use = MAZE[x][y];
		draw_character( x,  y,  MAZE[x][y]);
		
		}

	}

}
int read_acc(int* time, double* a_x, double* a_y, double* a_z,  int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT)
{
	int result;
	
	int s, b ;
	
	scanf ("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d",time,  a_x, a_y, a_z, Button_DOWN, Button_UP,  Button_LEFT, Button_RIGHT, &b, &s);
	
	if (*Button_LEFT == 1)
	{
		result = 1;
	}
	else {
		result = 0;
	}
	return result;
}
double avg(double buffer[], int num_items){
int x;
double z;

for( x = 0, z = 0.0; x < num_items; x++){
z += buffer[x];

}
return (z/num_items);
}
void updatebuffer(double buffer[], int length, double new_item){
int i;
for( i = 0; i < length-1; i++){
	
buffer [i] = buffer [i+1];

}
buffer [length-1] = new_item;
}


double roll(double x_mag){

	if(x_mag > 1.0){
	
	x_mag = 1.0;
	
	}
	if(x_mag < -1.0){
	
	x_mag = -1.0;
	
	}
	return asin(x_mag);
	}
	
