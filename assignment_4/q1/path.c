#include "header.h"


	void *find_path(void *param)
	{
		
		args *index = (args*)param;
		int row = index->row;
		int col = index->col;
		int pos = index->pos;
		
		if(matrix[row][col] != sequence[pos])	//check if sequence and matrix entry match
			pthread_exit((void*)0);		
		else
			if(row == (N - 1) && col == (N - 1))	//check if this is the last element in the matrix
			{
				nr_path++;
				char str_row[5];
				sprintf(str_row, "%d", row);
				char str_col[5];
				sprintf(str_col, "%d", col);
				int j = 0;
				for(; j < 3; j++)
				{
					strcpy(path[j], "(");
					strcat(path[j], str_row);
					strcat(path[j],", ");
					strcat(path[j], str_col);
					strcat(path[j], ") ");
				}				
				pthread_exit((void*)1);
			}
			
		args parameter[3];	//parameter for right, down and diagnol threads.
		pthread_t tid[3];
		int status[3];		//collect status
		int flag[3] = {0};	//flag value indicates if a thread exists.
		int found = 0;		//number of threads created.
		
		if((col + 1) < N)
		{
			flag[0] = 1;
			found++;
			parameter[0].row = row;
			parameter[0].col = col + 1;
			parameter[0].pos = pos + 1;
		}
		if((row + 1) < N)
		{
			flag[1] = 1;
			found++;
			parameter[1].row = row + 1;
			parameter[1].col = col;
			parameter[1].pos = pos + 1;
		}
		
		if(found == 2)
		{
			flag[2] = 1;
			found++;
			parameter[2].row = row + 1;
			parameter[2].col = col + 1;
			parameter[2].pos = pos + 1;
		}
		
		int i = 0;
		
		for(; i < 3; i++)
		{
			if(flag[i])
				pthread_create(&tid[i], NULL, find_path, &parameter[i]);	//create thread and recur.
		}
		
		for(i = 0; i < 3; i++)
		{
			if(flag[i])
				pthread_join(tid[i], (void*)&status[i]);	//wait for different created threads.
		}
		
		if(found == 0)
		{
			if(row != 0 && col !=0)
				pthread_exit((void*)0);
		}
		
		if(status[0] || status[1] || status[2])
		{
			char str_row[5];
			sprintf(str_row, "%d", row);
			char str_col[5];
			sprintf(str_col, "%d", col);
			int j = 0;
			for(; j < 3; j++)
				if(status[j])
				{
					strcat(path[j], "(");
					strcat(path[j], str_row);
					strcat(path[j],", ");
					strcat(path[j], str_col);
					strcat(path[j], ") ");				
				}
			if(row != 0 && col !=0)
				pthread_exit((void*)1);			
		}
	}
