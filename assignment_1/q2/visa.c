#include "main_header.h"
#include <string.h>

	void visa ()
	{
		
		FILE *fp;
		run:
			fp = fopen ("pointer2.txt", "r");
			passenger *pas;
			fscanf (fp, "%p", &pas);
			fclose (fp);
			int check = 0;
			int check1 = 1;
	
		if (!strcmp ((pas -> nationality), (pas -> destination)))
			check = check_date ((pas -> visa_exp_date), (pas -> entry_date));
		else
			if ((pas -> ret_flag))
				check = check_date ((pas -> visa_exp_date), (pas -> return_date)) & check_date ((pas -> visa_exp_date), (pas -> entry_date));
			else
				check = check_date ((pas -> visa_exp_date), (pas -> entry_date));	
		
		fp = fopen ((pas -> ticket_nr), "a");
		FILE *ptr = fopen ("immig_status.txt", "w");
		
		if (check)
		{
			fprintf (fp, "Immigration Successful!\t");
			fflush (fp);
			fprintf (ptr, "%d", 1);
			fflush (ptr);
		}
		else
		{
			fprintf (fp, "Immigration not successful!\t");
			fflush (fp);
			fprintf (ptr, "%d", 0);
			fflush (ptr);
		}
		fclose (fp);
		fclose (ptr);
		
		kill (getppid(), SIGCONT);
		kill (getpid(), SIGSTOP);
		goto run;				
	}
