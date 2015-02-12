#include <stdio.h>


#define MAXPOINTS 10000
int read_acc(double* a_x, double* a_y, double* a_z,  int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}


	
	/* PUT YOUR CODE HERE */
	int counter = 0, b_down, b_up, b_left, b_right;
	double a_x, a_y, a_z, min_x, min_y, min_z, max_x, max_y, max_z, avg_x, avg_y, avg_z;
	
	do
	{
	read_acc (&a_x, &a_y, &a_z, &b_up, &b_down, &b_left, &b_right);
	counter++;
	

	
	updatebuffer( x,  lengthofavg,  a_x);
	updatebuffer( y,  lengthofavg,  a_y);
	updatebuffer( z,  lengthofavg,  a_z);
	
	if(counter == 1){
	//min_x = max_x = a_x;
	//min_y = max_y = a_y;
	//min_z = max_z = a_z;
	printf("%lf, %lf, %lf \n", a_x, a_y, a_z);
	}
	else if (counter >= lengthofavg){
	maxmin( x, lengthofavg, &max_x, &min_x);
	maxmin( y, lengthofavg, &max_y, &min_y);
	maxmin( z, lengthofavg, &max_z, &min_z);
	
	avg_x = avg( x, lengthofavg);
	avg_y = avg( y, lengthofavg);
	avg_z = avg( z, lengthofavg);
	printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf \n", a_x, a_y, a_z, avg_x, avg_y, avg_z, max_x, min_x, max_y, min_y, max_z, min_z);
	}
	else{
	
	printf("%lf, %lf, %lf \n", a_x, a_y, a_z);
	}
	
	}while (b_left != 1);

}
int read_acc(double* a_x, double* a_y, double* a_z,  int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT)
{
	int result;
	
	int s, b, time = 0;
	
	scanf ("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d",&time,  a_x, a_y, a_z, Button_DOWN, Button_UP,  Button_LEFT, Button_RIGHT, &b, &s);
	
	if (*Button_LEFT == 1)
	{
		result = 1;
	}
	else {
		result = 0;
	}
	return result;
}
void updatebuffer(double buffer[], int length, double new_item){
int i;
for( i = 0; i < length-1; i++){
	
buffer [i] = buffer [i+1];

}
buffer [length-1] = new_item;
}

void maxmin(double array[], int num_items, double* max, double* min){
int i ;
*max = *min = array[0];
for( i = 1; i < num_items; i++){
if (array[i] > *max){

*max = array[i];
}
 
if (array[i] < *min){
*min = array[i];

}
}
}

double avg(double buffer[], int num_items){
int x;
double z;

for( x = 0, z = 0.0; x < num_items; x++){
z += buffer[x];

}
return (z/num_items);
}