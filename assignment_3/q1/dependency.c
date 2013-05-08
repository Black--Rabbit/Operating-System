/* dependency.c */
/*
 * Author : Siddharth Mohan Misr
 */

/*
 * This file will find the number of arguments
 * and will be used to free up the dynamically allocated memory.
 */

#include "header.h"

	int nr_options (char *str)
	{
		if(!strcmp(str, "NULL"))
			return 0;
		int count = 0;
		char temp[20];
		strcpy(temp, str);
		char *tok;
		for(tok = strtok(temp, " "); tok; tok = strtok(NULL, " "), count++);
		return count;
	}
	
	void freeup (command *A[], command *B[], int a, int b)
	{
		int i;
		
		for(i = 0; i < a; i++)
		{
			free(A[i] -> dep);
			free(A[i] -> env);
			int x = 0;
			while(A[i] -> arg[x])
				free(A[i] -> arg[x++]);
			free(A[i]);
		}
		
		
		for(i = 0; i < b; i++)
		{
			free(B[i] -> dep);
			free(B[i] -> env);
			int x = 0;
			while(B[i] -> arg[x])
				free(B[i] -> arg[x++]);
			free(B[i]);
		}
	}

