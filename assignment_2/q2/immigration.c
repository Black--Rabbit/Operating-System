#include "main_header.h"

	void immigration ()
	{	
	
		int flag = 0;
	
		int pass = 1;
		int status;
		FILE *ptr;
		pid_t vis, pasp;
		run:
//		fflush(stdout);
			if (pass == 1)
			{
				if (!flag)
					pasp = fork();
				if (!pasp)
					passport ();
				else
				{
					usleep (1000);
					ptr = fopen ("immig_status.txt", "r");
					fscanf (ptr, "%d", &status);
					fclose (ptr);
					if (status)
					{
						vis = fork();
						if (!vis)
							visa ();
						else
						{
							usleep (1000);
							pass++;
							ptr = fopen ("immig_status.txt", "r");
							fscanf (ptr, "%d", &status);
							fclose (ptr);
							
							ptr = fopen ("pointer2.txt", "r");
							passenger *temp;
							fscanf (ptr, "%p", &temp);
							fclose (ptr);
							
							ptr = fopen ("pointer3.txt", "w");
							fprintf (ptr, "%p", temp);
							fflush (ptr);
							fprintf (ptr, "%d", status);
							fflush (ptr);
							fclose (ptr);
							
							kill (getppid(), SIGCONT);
							kill (getpid(), SIGSTOP);
							goto run;								
						}
					}
					else
					{
						flag = 1;
//						usleep (100);
						ptr = fopen ("immig_status.txt", "r");
						fscanf (ptr, "%d", &status);
						fclose (ptr);
						
						ptr = fopen ("pointer2.txt", "r");
						passenger *temp;
						fscanf (ptr, "%p", &temp);
						fclose (ptr);
						
						ptr = fopen ("pointer3.txt", "w");
						fprintf (ptr, "%p", temp);
						fflush (ptr);
						fprintf (ptr, "%d", status);
						fflush (ptr);
						fclose (ptr);
						
						kill (getppid(), SIGCONT);
						kill (getpid(), SIGSTOP);
						goto run;
					}
					
				}
			}
			else
			{
				usleep (100);
				kill (pasp, SIGCONT);
				usleep (100);
				ptr = fopen ("immig_status.txt", "r");
				fscanf (ptr, "%d", &status);
				fclose (ptr);
				if (status)
				{
					kill (vis, SIGCONT);
					usleep (100);
				}
				
				ptr = fopen ("immig_status.txt", "r");
				fscanf (ptr, "%d", &status);
				fclose (ptr);
				
				ptr = fopen ("pointer2.txt", "r");
				passenger *temp;
				fscanf (ptr, "%p", &temp);
				fclose (ptr);
				
				ptr = fopen ("pointer3.txt", "w");
				fprintf (ptr, "%p", temp);
				fflush (ptr);
				fprintf (ptr, "%d", status);
				fflush (ptr);
				fclose (ptr);
				
				kill (getppid(), SIGCONT);
				kill (getpid(), SIGSTOP);
				goto run;
			}
	}
