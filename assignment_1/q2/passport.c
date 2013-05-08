#include "main_header.h"

	void passport ()
	{
	
			FILE *fp;
		run:
			fp = fopen ("pointer2.txt", "r");
			passenger *pas;
			fscanf (fp, "%p", &pas);
			fclose (fp);
		
			int result = 0;
			
			result = (pas -> ret_flag) ? check_date ((pas -> passport_exp_date), (pas -> return_date)) : check_date ((pas -> passport_exp_date), (pas -> entry_date));
			
			if (!result)
			{
				fp = fopen ("immig_status.txt", "w");
				fprintf (fp, "%d", 0);
				fflush (fp);
				fclose (fp);
				fp = fopen ((pas -> ticket_nr), "a");
				fprintf (fp, "Immigration not successful!\t");
				fflush (fp);
				fclose (fp);
				kill (getpid(), SIGSTOP);
				goto run;
			}
			else
			{
				fp = fopen ("immig_status.txt", "w");
				fprintf (fp, "%d", 1);
				fflush (fp);
				fclose (fp);
				kill (getpid(), SIGSTOP);
				goto run;
			}
	}
	
	int check_date (char *date1, char *date2)
	{
		int yy1 = atoi (date1 + 6);
		int yy2 = atoi (date2 + 6);
		
		if (yy1 < yy2)
			return 0;
		if (yy1 > yy2)
			return 1;
			
		int mm1 = atoi (date1 + 3);
		int mm2 = atoi (date2 + 3);
		
		if (mm1 < mm2)
			return 0;
		if (mm1 > mm2)
			return 1;
		
		int dd1 = atoi (date1);
		int dd2 = atoi (date2);
		
		if (dd1 < dd2)
			return 0;
			
		return 1;
	}
