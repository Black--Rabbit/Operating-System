/* main.c */
/*
 * Author : Siddharth Mohan Misr
 */

/*
 * This file will take input and execute 
 * the main function to execute all the commands
 */

#include "header.h"
	int main (int argc, char *argv[])
	{
	
		if(argc < 2)
		{
			printf("Please give the file nam!!!\n");
			return -1;
		}
	
		FILE *fptr = fopen (argv[1], "r");
		int n;
		
		fscanf (fptr, "%d", &n);
		
		command *A[n], *B[n];
				
		char temp[100];
				
		int count_A = 0;
		int count_B = 0;
		int i;
		
		for (i = 0; i < n; i++)
		{
			char com[10], dep[10], path[60], opt[20];
			fscanf (fptr, "%s %s %s %[^\n]", com, dep, path, opt);
			fgetc (fptr);
		
			opt[strlen(opt) - 1] = 0;
		
			command *var = (command*)malloc(sizeof(command));
			var -> dep = (char*)malloc(sizeof(char) * 10);

			var -> dep = (char*)malloc(sizeof(char) * 10);
			var -> env = (char*)malloc(sizeof(char) * 60);
			strcpy (var -> dep, dep);
		
			int nr = nr_options(opt);
			var -> arg = (char**)malloc(sizeof(char*) * (nr+2));
			var -> arg[0] = (char*)malloc(sizeof(char) * 10);
			strcpy(var -> arg[0], com);
	
			int x = 1;
			char tmp_opt[20];
			strcpy(tmp_opt, opt);
			char *tok;
			for(tok = strtok(tmp_opt, " "); tok; tok = strtok(NULL, " "), x++)
			{
				int len = strlen(tok);
				if(tok[len - 1] == '\r')
					tok[len - 1] = 0;
				var -> arg[x] = (char*)malloc(sizeof(char) * len);
				strcpy(var -> arg[x], tok);
			}
		
			var -> arg[nr + 1] = NULL;
	
		
		
			if (!strcmp (path, "-"))
			{
				strcpy(path, "/bin/");
				strcat(path, com);
				strcat(path,":/sbin/");
				strcat(path, com);
				strcat(path, ":/etc/");
				strcat(path, com);
				strcat(path,":/home/usr/");
				strcat(path, com);
				strcpy(var -> env, path);
			}
			else
			{
				strcpy(var -> env, path);
				strcat(var -> env, "/");
				strcat(var -> env, com);
			}
			int flag = 0;
			
			if (!strcmp (dep, "-"))
			{
				if (count_A <= count_B)
					A[count_A++] = var;
				else
					B[count_B++] = var;
			}
			else
			{
				int j;
				for (j = 0; j < count_A; j++)
				{
					char temp[60];
					if (!strcmp(A[j] -> arg[0], dep))
					{
						A[count_A++] = var;
						flag = 1;
						break;
					}
				}
				if (!flag)
					for (j = 0; j < count_B; j++)
					{
						if (!strcmp(B[j] -> arg[0], dep))
						{
							B[count_B++] = var;
							flag = 1;
							break;
						}
					}
				if(flag != 1)
				{
					command *tmp_var = (command*)malloc(sizeof(command));
					tmp_var -> env = (char*)malloc(sizeof(char) * 40);
					strcpy(path, "/bin/");
					strcat(path, dep);
					strcat(path,":/sbin/");
					strcat(path, dep);
					strcat(path, ":/etc/");
					strcat(path, dep);
					strcat(path,":/home/");
					strcat(path, dep);
					strcpy(tmp_var -> env, path);
					tmp_var -> arg = (char**)malloc(sizeof(char*) * (2));
					tmp_var -> arg[0] = (char*)malloc(sizeof(char) * 10);
					strcpy(tmp_var -> arg[0], dep);
					tmp_var -> arg[1] = NULL;			
			
					if(count_A <= count_B)
					{
						A[count_A++] = tmp_var;
						A[count_A++] = var;
					}
					else
					{
						B[count_B++] = tmp_var;
						B[count_B++] = var;
					}
				}
			}
		}
	

		fclose (fptr);
/*		printf("Array A\n");
		for (i = 0; i < count_A; i++)
		{
//			printf("%s\n", A[i] -> arg[0]);
			printf ("%s\t%s\t%s\t", A[i] -> arg[0], A[i] -> dep, A[i] -> env);
			int j = 1;
			for(; A[i] -> arg[j]; j++)
				printf("%s ", A[i] -> arg[j]);
			printf("\n");
		}
		printf("Array B\n");
		for (i = 0; i < count_B; i++)
		{
//			printf("%s\n", A[i] -> arg[0]);
			printf ("%s\t%s\t%s\t", B[i] -> arg[0], B[i] -> dep, B[i] -> env);
			int j = 1;
			for(; B[i] -> arg[j]; j++)
				printf("%s ", B[i] -> arg[j]);
			printf("\n");
		}
*/		
//		printf("%d\t%d\n", count_A, count_B);
		execute (A, B, count_A, count_B);
		freeup(A, B, count_A, count_B);
					
	return 0;
}

	void execute (command *A[], command *B[], int count_a, int count_b)
	{
	
		pid_t proc_a, proc_b;
		int i ,j;
		i = j = -1;
		proc_a = fork();
		if(!proc_a)
		{
			while(++i < count_a)
			{
				if(!fork())
				{
					execv(A[i] -> env,A[i] -> arg);
					char temp[60];
					char *token;
					strcpy(temp, A[i] -> env);
					for(token = strtok(temp, ":"); token; token = strtok(NULL, ":"))
					{
						int len = strlen(token);
						if(token[len - 1] == '\r')
							token[len - 1] = 0;
						execv(token, A[i] -> arg);
					}
							exit(0);
				}
				wait(NULL);		
			}
		}
		else
		{
			proc_b = fork();
			if(!proc_b)
			{
				while(++j < count_b)
				{
					if(!fork())
					{
						execv(B[j] -> env, B[j] -> arg);
						char temp[60];
						char *token;
						strcpy(temp, B[j] -> env);
						for(token = strtok(temp, ":"); token; token = strtok(NULL, ":"))
						{
							int len = strlen(token);
							if(token[len - 1] == '\r')
								token[len - 1] = 0;
							execv(token, B[j] -> arg);
						}
					}
					wait(NULL);
				}
			}
		}
		wait(NULL);
		wait(NULL);			
	}
