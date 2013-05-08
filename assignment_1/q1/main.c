#include "headers.h"

	int main (int argc, char *argv[])
	{
		int **arr;
		int n;
		
		FILE *fp = fopen (argv[1], "r");
		fscanf (fp,"%d", &n);
		
		int i = 0;
		int j = 0;
		
		arr = (int**)malloc(sizeof(int*)*n);	// dynamically allocating rows.
		
		for (; i < n; i++)
		{
			arr[i] = (int*)malloc(sizeof(int)*n);	// dynamically allocating columns.
			for (j = 0; j < n; j++)
				fscanf (fp, "%d", &arr[i][j]);
		}
		
		fclose (fp);
		
		findPath (arr, n, 0, 0);	// call the findPath function to calculate the path.
		
		return 0;
				
	}
