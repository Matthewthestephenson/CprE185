// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) ;

void mvprintw(int row, int col, char arg1);

int read_acc(int* time, double* a_x, double* a_y, double* a_z,  int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	int  z;
	int q,j= 0;
	char c;
	wordCount = readWords(wordlist, argv[1]);
	FILE* infile = NULL;
	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%s,", wordlist[i]);

			}
		printf("\n");
		}

// most of your code goes here. Don't forget to include the ncurses library 
	infile = fopen("wordslist.txt", "r");
	for ( z = 0; z < 6; z++){
	
		for ( q = 0; q < 6; q++){
		
		scanf("%c",&(*(infile+j)));
		
		infile;
		
		mvprintw( q,  z,  c);
		j++;
		}
	q = 0;
	}
    return 0;
	}
	

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }


// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
	
	int read_acc(int* time, double* a_x, double* a_y, double* a_z,  int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT){
	int result;
	
	int s, b ;
	
	scanf ("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d",time,  a_x, a_y, a_z, Button_DOWN, Button_UP,  Button_LEFT, Button_RIGHT, &b, &s);
	}
	void mvprintw(int row, int col,  char arg1){
	
		mvaddch(row,col,arg1);    
		refresh();
	
	
	}
/*void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
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

}*/