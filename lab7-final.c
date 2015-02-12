// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589
#define TRUE 0
#define FALSE 1
//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;			// magnitude values of x, y, and z accelerations
	int b_Up, b_Down, b_Left, b_Right;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
	int t, q = 0, f;
	//insert any beginning needed code here
		//for( q = -25; q < 30; q+=5){
		//graph_line( q );
		//}
	do
	{

		read_acc(&x , &y, &z, &t, &b_Up, &b_Down, &b_Left, &b_Right);	// check for button input

		
		if ( f-b_Down != 0 && b_Down == 1){
		q = q + b_Down;
		}
		pitch_rad = pitch(y);
		roll_rad = roll(x); 
			// calculate roll and pitch

		// switch between roll and pitch(up vs. down button)

		if (q % 2 == 1){	// Scale your output value
			scaled_value = scaleRadsForScreen( roll_rad);
		}
		else { 
		scaled_value = scaleRadsForScreen( pitch_rad);
		}
		graph_line(scaled_value);	 // Output your graph line

	f = b_Down;
		fflush(stdout);
	} while(b_Left != 1); // Modify to stop when left button is pressed
	

	return 0;
}
//Functions
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT){

int  j, s;

scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", time, a_x, a_y, a_z, Button_UP, Button_DOWN, Button_LEFT, Button_RIGHT, &j, &s); //add joystick and slider if outputs only zeros

	if (*Button_LEFT == 0){

		return 1;
		
		}
		
	else{
		return 0;
		
		}

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
double pitch(double y_mag){
	if(y_mag > 1.0){
	
	y_mag = 1.0;
	
	}
	
	if(y_mag < -1.0){
	
	y_mag = -1.0;
	
	}
	return asin(y_mag);
}
int scaleRadsForScreen(double rad){
	return (int) (rad * (39 * 2)/PI);
}
void print_chars(int num, char use){
int x;
for(x = 0; x < num; x++ ){

printf("%c", use);

}
}
void graph_line(int number){
int x = 0;
if (number < 0){
x = number + 40;
print_chars( x,  ' ');
print_chars( -number, 'l');
}
else if ( number > 0) {
x = 40 - number;
print_chars( 40,  ' ');
print_chars( number, 'r');


}
else{
print_chars( 40,  ' ');
print_chars ( 1, '0');
}
print_chars(1, '\n');
}