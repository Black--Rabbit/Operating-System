/* main.c */
/*
 * Author : Siddharth Mohan Misr
 */

/*
 * header file required for the program.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

	typedef struct command
	{
		char *dep;
		char *env;
		char **arg;
	}command;

	extern int nr_options(char*);
	void execute(command *A[], command *B[], int, int);
	extern void freeup(command *A[], command *B[], int, int);

