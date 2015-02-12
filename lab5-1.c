/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */
double mag(double ax, double ay, double az);
int close_to (double tolerance, double point, double value);
int clearAll (int *a, int *b, int *c, int *d, int *e, int *f);
int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az; 	
	double tolerance = 0.25, point = 1.0, value;
	int a,b,c,d,e,f;
	
	while (TRUE && b2 != 1 && ( mag ( ax, ay, az)-1<(tolerance*3))) {
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	
		
		

 //CODE SECTION 0
		//printf("Echoing output: %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", t, ax, ay, az, b1, b2, b3, b4, b5, s);

/* 	CODE SECTION 1 
		printf("At %d ms, the acceleration's magnitude was: %f", t, mag(ax, ay, az));  */
		
	
		
	if(close_to(tolerance, point, ax)==1 && a != 1){
	printf("RIGHT\n\n");
	clearAll ( &a,  &b, &c, &d, &e, &f);
	a = 1;
	fflush(stdout);
	}	
	if(close_to(tolerance, point, ay)==1 && b != 1){
	printf("FRONT\n\n");
	fflush(stdout);
	clearAll ( &a,  &b, &c, &d, &e, &f);
	b = 1;
	}	
	if(close_to(tolerance, point, az)==1 && c != 1){
	printf("TOP\n\n");
	fflush(stdout);
	clearAll ( &a,  &b, &c, &d, &e, &f);
	c = 1;
	}
	if(close_to(tolerance, point, ax)==2 && d != 1){
	printf("LEFT\n\n");
	fflush(stdout);
	clearAll ( &a,  &b, &c, &d, &e, &f);
	d = 1;
	}	
	if(close_to(tolerance, point, ay)==2 && e != 1){
	printf("BACK\n\n");
	fflush(stdout);
	clearAll ( &a,  &b, &c, &d, &e, &f);
	e = 1;
	}		
	if(close_to(tolerance, point, az)==2 && f != 1){
	printf("BOTTOM\n\n");
	fflush(stdout);
	clearAll ( &a,  &b, &c, &d, &e, &f);
	f = 1;
	}		
	


    return 0;
}
}

/* Put your lab 4 functions here, as well as your new function close_to */
double mag(double ax, double ay, double az){
double y = sqrt(ax*ax + ay*ay + az*az);
return y;
}
int close_to (double tolerance, double point, double value){
	if (value>0){
		if (sqrt((value-point)*(value-point))<(tolerance)){
		return 1;
		}
		else{
		return 0;
		}
	}
	else{
	
	if(sqrt((value+point)*(value+point))<(tolerance)) //? it used to not have sqrt
	return 2;
	}
	}
	int clearAll (int *a, int *b, int *c, int *d, int *e, int *f){
	*a = *b = *c = *d = *e = *f = 0;
	
	
	}
	
	