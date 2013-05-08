#include "header.h"

	void take_input(char *file_name)
	{
		FILE *fp = fopen(file_name, "r");
		
		fscanf(fp, "%d", &M);
		sequence = (int*)malloc(sizeof(int) * M);
		
		int i = 0;
		
		for(; i < M; i++)
			fscanf(fp, "%d", &sequence[i]);
			
		fscanf(fp, "%d", &N);
	
		matrix = (int**)malloc(sizeof(int*) * N);
		
		for(i = 0; i < N; i++)
		{
			int j = 0;
			matrix[i] = (int*)malloc(sizeof(int) * N);
			for(; j < N; j++)
				fscanf(fp, "%d", &matrix[i][j]);
		}
		
		fclose(fp);
	}
	
	void show_input()
	{
		int i = 0;
		int j = 0;
		
		for(; i < M; i++)
			printf("%d\t", sequence[i]);
		
		printf("\n");
		
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
				printf("%d\t", matrix[i][j]);
			printf("\n");
		}
	}
