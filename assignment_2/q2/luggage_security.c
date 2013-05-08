#include "main_header.h"


	void luggage_security ()
	{
		int baggage_id = 0;
//		kill (getpid(), SIGSTOP);
		
		FILE *file_ptr;
			
		run:
			file_ptr = fopen("pointer.txt","r");
			passenger *pas;
			fscanf (file_ptr, "%p", &pas);
			fclose (file_ptr);
		
			baggage_id++;
			int i,j;
		
			int count = (pas -> nr_of_bags) - 1;
			int **eliminate = (int**)malloc(sizeof(int*) * count);
			for (i = 0; i < count; i++)
			{
				eliminate[i] = (int*)malloc(sizeof(int) * 10);
				for (j = 0; j < 10; j++)
				{
					eliminate[i][j] = 0;
					if (is_palindrome(pas -> contents[i][j]) || is_colourfull(pas -> contents[i][j]))
						eliminate[i][j] = 1;
				}
			}
		
			kill (getpid(), SIGSTOP);
			printf ("Following Luggage not allowed :\n");
			fflush (stdout);
			for (i = 0; i < count; i++)
			{
				int j = 0;
				for (; j < 10; j++)
					if (eliminate[i][j])
					{
						printf ("%d\t",(pas -> contents [i][j]));
						fflush (stdout);
						(pas -> contents[i][j]) = -1;
					}
			}
		
			FILE *fp = fopen ((pas -> ticket_nr),"a");
			fprintf (fp, "Baggage ID : %d\t", baggage_id);
			fflush (fp);
			fclose (fp);
			
			usleep (1000);
			kill (getppid(), SIGCONT);
			kill (getpid(), SIGSTOP);
		goto run;		
	}
	
	
	int is_palindrome (int num)
	{
		int temp = num;
		int rev = 0;
		while (num)
		{
			rev *= 10;
			rev += (num % 10);
			num /= 10;			
		}
		
		if (temp == rev)
			return 1;
		
		return 0;	
	}
	
	int is_colourfull (int num)
	{
		int nr_dig = 0;
		int temp = num;
		
		while (temp)
		{
			temp /= 10;
			nr_dig ++;
		}
		
		int arr_digits[nr_dig];
		temp = num;
		int i = nr_dig - 1;
		for (; i >= 0; i--)
		{
			arr_digits[i] = (temp % 10);
			temp /= 10;
		}
		
		int **substring = (int**)malloc(sizeof(int*) * nr_dig);
		
		
		for (i = 0; i < nr_dig; i++)
		{
			substring[i] = (int*)malloc(sizeof(int) * (nr_dig - i));
			int j;
			for( j =0 ; j < nr_dig - i ; j++)
			{	
				substring[i][j] = 1;
				int k;
				for( k =0 ; k<i+1; k++)
				{ 
					substring[i][j] = substring[i][j] * arr_digits[j+k];
				}
			}				
		}
		
		for (i = 0; i < nr_dig; i++)
		{
			int j = 0;
			for (; j < (nr_dig - i); j++)
			{
				int temp = substring[i][j];
				int i1,j1;
				for (i1 = 0; i1 < nr_dig; i1++)
					for (j1 = 0; j1 < (nr_dig - i1); j1++)
						if (temp == substring[i1][j1])
							if(i == i1 && j == j1)
								continue;
							else
								return 0;
			}
		}
		
		return 1;
	}
