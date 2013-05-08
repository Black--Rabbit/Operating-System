#include "main_header.h"

	void baggage_counter ()
	{
		int run = 1;
//		kill (getpid(), SIGSTOP);
		
		pid_t lug_sec, wg, bd_ps;
		label_run:
		
//			fflush(stdout);
//			printf ("~~~asdf~~~");
		
			if (run == 1)
			{	
				lug_sec = fork();
		
				if (!lug_sec)
					luggage_security ();
				else
				{
					usleep (100);
					wg = fork();
					if (!wg)
						weight (lug_sec);
					else
					{
						usleep (100);
		//				waitid (P_PID, wg, NULL, WSTOPPED); 
						bd_ps = fork();
					        if (!bd_ps)
							boarding_pass (wg);
						else
						{
							run++;
							usleep (100);
							kill (getpid(), SIGSTOP);					
					
							FILE *fp = fopen ("pointer.txt", "r");
							passenger *temp;
							fscanf (fp, "%p", &temp);
							fclose (fp);
							FILE *ptr = fopen ("pointer2.txt","w");
							fprintf (ptr, "%p", temp);
							fflush (ptr);
							fclose (ptr);
					
		//					kill (immigration, SIGCONT);
	
	//						usleep (1000);
							kill (getppid(), SIGCONT);
							kill (getpid(), SIGSTOP);
						
							goto label_run;
						}
					}
				}
			}
			else
			{
				usleep (100);
				kill (lug_sec, SIGCONT);
				usleep (100);
				kill (wg, SIGCONT);
				usleep (100);
				kill (bd_ps, SIGCONT);
				
//				usleep (100);
				kill (getpid(), SIGSTOP);
				
				FILE *fp = fopen ("pointer.txt", "r");
				passenger *temp;
				fscanf (fp, "%p", &temp);
				fclose (fp);
				FILE *ptr = fopen ("pointer2.txt","w");
				fprintf (ptr, "%p", temp);
				fflush (ptr);
				fclose (ptr);
//				kill (immigration, SIGCONT);
				
				kill (getppid(), SIGCONT);
				kill (getpid(), SIGSTOP);
				goto label_run;
			}		
	}

