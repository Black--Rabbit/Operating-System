#include "main_header.h"

	void baggage_counter ()
	{
		int run = 1;			// flag to check the pass through this function.
//		kill (getpid(), SIGSTOP);
		
		pid_t lug_sec, wg, bd_ps;
		label_run:
		
//			fflush(stdout);
//			printf ("~~~asdf~~~");
		
			if (run == 1)
			{	
				lug_sec = fork();	
		
				if (!lug_sec)
					luggage_security ();		// initiate luggage counter
				else
				{
					usleep (100);
					wg = fork();		
					if (!wg)
						weight (lug_sec);	// initiate weight counter
					else
					{
						usleep (100);
		//				waitid (P_PID, wg, NULL, WSTOPPED); 
						bd_ps = fork();
					        if (!bd_ps)
							boarding_pass (wg);	// initiate the boarding pass.
						else
						{
							run++;			// inc run flag.
							usleep (100);
							kill (getpid(), SIGSTOP);					
					
							FILE *fp = fopen ("pointer.txt", "r");	
							passenger *temp;
							fscanf (fp, "%p", &temp);	// get the address of the current passenger who has completed baggage counter.
							fclose (fp);
							FILE *ptr = fopen ("pointer2.txt","w");
							fprintf (ptr, "%p", temp); // place this address in the pointer2 file to be accessed by the immigration.
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

