#include "headers.h"
	
	void findPath (int **arr, int n, int i, int j)
	{
	
		if (arr[i][j] == 1)
			exit (1);
		int status_1 = 0;
		int status_2 = 0;
		
		pid_t right, down;

		if ((j + 1) < n)
		{
			right = fork();		
			if (!right)
			{
				j++;
				if (arr[i][j] != 2)
					findPath (arr, n, i, j);
				else 
			        {
				     	printf ("(%d, %d) ", i, j);
				     	exit(2);
			        }
			}
		}
		if ((i + 1) < n)
		{
			down = fork();
			if (!down)
			{	
				i++;	
				if (arr[i][j] != 2)
					findPath (arr, n, i, j);
				else
				{ 
				     	printf ("(%d, %d) ", i, j);
				     	exit(2);
				}
			}
		}
		wait (&status_1);
		wait (&status_2);
		
		if ((status_1/256) == 2 || (status_2/256) == 2)
		{
			printf ("(%d, %d) ", i, j);
			if (i == 0 && j == 0)
				printf ("MJ successfully rescued.\n");
			exit (2);			// send exit status 2 so that while retracing the path one only takes the right 0's.
		}
		else
		{
			if (i == 0 && j == 0)
				printf ("Spiderman cannot rescue MJ.\n");
			exit (1);
		}
	}	
