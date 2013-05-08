#include "main_header.h"

	void weight (pid_t lug_sec)
	{
		
		FILE *file_ptr;
		run:
			file_ptr = fopen("pointer.txt","r");
			passenger *pas;
			fscanf (file_ptr, "%p", &pas);
			fclose (file_ptr);
			
			int count = (pas -> nr_of_bags) - 1;
			double extra_cost = 0;
			if (count > 2)
				extra_cost += (count - 2) * 40;
			int i = 0;
			for (; i < count; i++)
			{
				double diff = 0;
				if ((diff = ((pas -> weight_of_bags[i]) - 20)) > 0)
					extra_cost += (diff * 2);
			}
			kill (getpid(), SIGSTOP);
			if (extra_cost)
			{
				printf ("Extra Lugage cost is : %lf\n", extra_cost);
				fflush (stdout);
			}
			FILE *fp = fopen ((pas -> ticket_nr), "a");
			fprintf (fp, "Extra Lugage cost is : %lf\t", extra_cost);
			fflush (fp);
			fclose (fp);
			
			usleep (1000);
			kill (lug_sec, SIGCONT);
			kill (getpid(), SIGSTOP);
		goto run;		
	}
