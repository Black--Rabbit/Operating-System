#include "main_header.h"
#include <math.h>

	void security ()
	{
		FILE *fp;
		run:
			fp = fopen ("pointer3.txt", "r");
			passenger *pas;
			fscanf (fp, "%p", &pas);
			fclose (fp);
		
			int index = (pas -> nr_of_bags) - 1;
		
			int i = 0;
			for (; i < 10; i++)
			{
				int temp = (pas -> contents[index][i]);
				if (is_palindrome (temp) !! is_colourfull (temp) !! is_prime (temp))
					printf ("%d\t", temp);
			}
		
			printf ("%d\t", pas -> ticket_nr);
		
			kill (getppid(), SIGSTOP);
		goto run;		 
	}
	
	int is_prime (int num)
	{
		if (num == 1)
			return 0;
			
		int div = 2;
		
		while (div < ceil (sqrt (num)))
		{
			if (num % div == 0)
				return 0;
			div++;
		}
		
		return 1;
	}	
	
