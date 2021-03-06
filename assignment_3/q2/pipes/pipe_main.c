/* pipe_main.c */
/*
 * Author : Siddharth Mohan Misra
 */

/*
 * This is the main driver program which will take the input and call the search function.
 */

#include "header.h"

	int main(int argc, char *argv[])
	{
		if(argc != 4)
		{
			printf("Invalid Arguments\n");
			return -1;
		}
		
		char *file = argv[1];
		char *id = argv[2];
		char *marks = argv[3];
		
		FILE *fp = fopen("flag.txt", "w");
		fprintf(fp, "%d", 0);
		fclose(fp);
		if(!fork())
			search("/home/user/evaluator/", file);	// setting the current directory
		wait(NULL);
		delete("flag.txt");
		
		char loc[100];
		fp = fopen("path.txt", "r");
		fscanf(fp, "%s", loc);
		fclose(fp);
		delete("path.txt");
		
		/* Precautionary change of permission of the file to be modified */
		
		if(!fork())
		{
			execl("/bin/chmod", "chmod", "777", loc, 0);
			exit(0);
		}
		wait(NULL);
		
		fp = fopen(loc, "r");
		FILE *wfp = fopen("new_marks.txt", "w");
		char c;
		while((c = fgetc(fp))!= EOF)
		{
			fseek(fp, -1,1);
			char temp[100];
			fscanf(fp, "%[^\n]s", temp);
			fgetc(fp);
			if(!strncmp(id, temp, 12))	// finding the id	
			{
				int i = 13;
				int x = 0;
				int len = strlen(marks);
				while(x < len)
					temp[i++] = marks[x++];

				temp[i] = 0;		
			}
			fprintf(wfp, "%s\n", temp);
		}
		
		fclose(wfp);
		fclose(fp);
		move_file("new_marks.txt", loc);	//changing the old marks file
		
		return 0;		
	}
