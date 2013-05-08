#include "header.h"
	
	int M, N;
	int *sequence, **matrix;	
	int nr_path;
	char *path[3];
		
	int main(int argc, char *argv[])
	{
		take_input(argv[1]);
		
		
		if(sequence[0] != matrix[0][0])	// 1st element being checked.
		{
			printf("Path not found!!\n");
			return 0;
		}
		
		int i = 0;
		for(; i < 3; i++)
		{
			path[i] = (char*)malloc(sizeof(char)*200);
			strcpy(path[i], " ");
		}

		args param;
		param.row = param.col = param.pos = 0;		// 1st param being formed.
				
		find_path(&param);				// find_path function called.
		printf("\nNumber of paths is %d\n", nr_path);
		
		
		for(i = 0 ; i < 3; i++)
			if(!(strlen(path[i]) > 6 && strlen(path[i]) < 10))
				printf("%s\n", path[i]);
		
		free_up();
			
		return 0;
	}
	
	void free_up()
	{
		
		free(sequence);
		
		int i = 0;		
		for(; i < N; i++)
			free(matrix[i]);
		free(matrix);
		free(path[0]);
		free(path[1]);
		free(path[2]);
	}
