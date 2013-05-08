#include "headers.h"

	int main (int argc, char *argv[])
	{
		int **arr;
		int n;
		
		FILE *fp = fopen (argv[1], "r");
		fscanf (fp,"%d", &n);
		
		int i = 0;
		int j = 0;
		
		arr = (int**)malloc(sizeof(int*)*n);
		
		for (; i < n; i++)
		{
			arr[i] = (int*)malloc(sizeof(int)*n);
			for (j = 0; j < n; j++)
				fscanf (fp, "%d", &arr[i][j]);
		}
		
		fclose (fp);
		
		findPath (arr, n, 0, 0);
		
		return 0;
				
	}
