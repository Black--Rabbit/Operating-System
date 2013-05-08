/* search.c */
/*
 * Author : Siddharth Mohan Misra
 */

/*
 * This is the file where search function is implemented using dup()
 */

#include "header.h"

	void search(char *cwd, char *file)
	{
	
		if(chdir(cwd) == -1)	// if permission are not set to open the directory
		{
			if(!fork())
			{
				char *arg[] = {"chmod", "777", cwd, 0};
				execv("/bin/chmod", arg);
				exit(0);
			}
			wait(NULL);
		}
		
		pid_t proc_ls, proc_grep;
		
		proc_ls = fork();
		if(!proc_ls)
		{
			close(fileno(stdout));
			FILE *fptr = fopen("ls_out.txt","w");
			dup(fileno(fptr));
			execl("/bin/ls", "ls", "-p", 0);	
		}
		else
		{
			wait(NULL);
			proc_grep = fork();
			if(!proc_grep)
			{
				close(fileno(stdin));
				FILE *fptr = fopen("ls_out.txt", "r");
				dup(fileno(fptr));
				close(fileno(stdout));
				FILE *fp = fopen("grep_out.txt", "w");
				dup(fileno(fp));
				execl("/bin/grep", "grep", "-c", "-x", file, 0);	// read output of ls and find the file
			}
			else
			{		
				wait(NULL);
				FILE *fp = fopen("grep_out.txt", "r");
				int flag_grep = 0;
				fscanf(fp, "%d", &flag_grep);	// read the output of grep
				fclose(fp);
				if(flag_grep)
				{
					fp = fopen("/home/user/student/question2/flag.txt", "r+");
					int flag_main;
					fscanf(fp, "%d", &flag_main);
					if(flag_main)
					{
						fclose(fp);
						delete("ls_out.txt");
						delete("grep_out.txt");
						exit(0);
					}
					else
					{
						rewind(fp);
						fprintf(fp, "%d", 1);
						fclose(fp);
						fp = fopen("/home/user/student/question2/path.txt", "w");
						fprintf(fp, "%s%s", cwd, file);
						fclose(fp);
						delete("ls_out.txt");
						delete("grep_out.txt");
						exit(0);
					}	
				}
				else
				{
					fp = fopen("/home/user/student/question2/flag.txt", "r+");
					int flag_main;
					fscanf(fp, "%d", &flag_main);
					fclose(fp);
					if(flag_main)
					{
						delete("ls_out.txt");
						delete("grep_out.txt");					
						exit(0);
					}
					else
					{
						pid_t proc_grep_dir, proc_grep_count;
						
						proc_grep_dir = fork();
						
						if(!proc_grep_dir)
						{
							close(fileno(stdin));
							dup(fileno(fopen("ls_out.txt", "r")));
							close(fileno(stdout));
							dup(fileno(fopen("grep_out.txt", "w")));
							execl("/bin/grep", "grep", "/", 0);	//list all the directories
							exit(0);							
						}
						else
						{
							wait(NULL);
							delete("ls_out.txt");
							
							proc_grep_count = fork();
							
							if(!proc_grep_count)
							{
								close(fileno(stdin));
								dup(fileno(fopen("grep_out.txt", "r")));
								close(fileno(stdout));
								dup(fileno(fopen("grep_count.txt","w")));
								execl("/bin/grep", "grep", "-c","/", 0);	// count the number of directories
							}
							else
							{
								wait(NULL);
								int nr_dir = 0;
								fp = fopen("grep_count.txt", "r");
								fscanf(fp, "%d", &nr_dir);
								fclose(fp);
								delete("grep_count.txt");
								
								int i = 0;
								FILE *fpr = fopen("grep_out.txt", "r");								
								for(; i < nr_dir; i++)
								{									
									char dir_name[100];
									fscanf(fpr, "%s", dir_name);	// take in the directory name
									char tmp[500];
									strcpy(tmp, cwd);
									strcat(tmp, dir_name);
									
									if(!fork())
										search(tmp, file);
								}
								while((wait(NULL) != -1));
								fclose(fpr);
								
 								delete("grep_out.txt");
								exit(0);
							}
						}
					}
				}
			}
		}
		
		
	}
