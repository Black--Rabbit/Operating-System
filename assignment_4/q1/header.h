#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <asm/unistd.h>
#include <string.h>
	
	typedef struct
	{
		int row;
		int col;
		int pos;
	}args;
	
	extern int **matrix;
	extern int *sequence;
	extern int N;
	extern int M;
	
	extern int nr_path;
	
	extern char *path[3];
	
//	extern int pos;
	
	extern void take_input(char*);
	extern void free_up();
//	extern void show_input();
	
	extern void *find_path(void*);
//	extern void *mov(void*);
//	extern int check(args*);
	
