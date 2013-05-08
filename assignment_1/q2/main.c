#include "main_header.h"

	int main (int argc, char *argv[])
	{
	
		
		passenger **arr = input (argv[1]);
		int nr_passengers;
		
		FILE *fp = fopen (argv[1], "r");
		fscanf (fp, "%d", &nr_passengers);
		fclose (fp);
		
		pid_t bag_c, immig;
//		bag_c = fork();
		int i = 0;
		
		while (i < nr_passengers)
		{
			FILE *ptr = fopen ("pointer.txt","w");	// store the address of the passenger currently present in being accessed.
			fprintf (ptr, "%p", arr[i]);
			fflush (ptr);
			fclose (ptr);
			
			if (i == 0)
			{
				bag_c = fork();
			
				if (!bag_c)
				{
					baggage_counter ();	// initiate the baggage counter process.
				}
				else
				{
					kill (getpid(), SIGSTOP);
					i++;
					ptr = fopen ("pointer.txt","w");
					fprintf (ptr, "%p", arr[i]);
					fflush (ptr);
					fclose (ptr);
					kill (bag_c, SIGCONT);					
					immig = fork();
					if (!immig)
						immigration ();		// initiate the immigration process
					else
						kill (getpid(), SIGSTOP);
				}
			}
			else
			{
//				kill (bag_c, SIGCONT);
				i++;
				usleep (100);
				kill (bag_c, SIGCONT);
				usleep (100);
				kill (immig, SIGCONT);
				kill (getpid(), SIGSTOP);
			}
					
		}
		
		
//		baggage_counter (0);
		
		return 0;
		
	}
