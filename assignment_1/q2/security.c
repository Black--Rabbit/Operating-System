#include "main_header.h"

	void security_counter ()
	{
		int pass = 1;
		int p = 0;
		pid_t male, female;
		FILE *fp;
		run:
			fp = fopen ("pointer3.txt", "r");
			passenger *pas;
			fscanf (fp, "%p", &pas);
			int status;
			fscanf (fp, "%d", &status);
			fclose (fp);
			
			if (status)
			{
				printf ("WARNING : Immigration was not successfull !!\n");
				fflush (stdout);
				kill (getppid(), SIGCONT);
				kill (getpid(), SIGSTOP);
				goto run;				
			}
			else
			{
				if (pass == 1)
				{
					if ((pas -> gender) == 'M')
					{
						male = fork();
						if (!male)
							security ();
						else
						{
							p++;
							if (p == 2)
								pass++;
							usleep (100);
							fp = fopen ("pointer4.txt", "w");
							fprintf (fp, "%p", pas);
							fflush (fp);
							fclose ();
							
							kill (getppid(), SIGCONT);
							kill (getpid(), SIGSTOP);							
							
						}
					}
					else
					{
						female = fork();
						if (!female)
							security();
						else
						{
							p++;
							if (p == 2)
								pass++;
							usleep (100);
							fp = fopen ("pointer4.txt", "w");
							fprintf (fp, "%p", pas);
							fflush (fp);
							fclose (fp);
							
							kill (getppid(), SIGCONT);
							kill (getpid(), SIGSTOP);
							goto run;
						}
					}
				}
				else
				{
					usleep (100);
					if ((pas -> gender) == 'M')
						kill (male, SIGCONT);
					else
						kill (female, SIGCONT);
						
						usleep (100);
						
						kill (getppid(), SIGCONT);
						kill (getpid(), SIGSTOP);
						goto run;						
				}
			}
	}
