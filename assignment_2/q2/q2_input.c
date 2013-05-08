#include "main_header.h"
	
	
	passenger **input (char *file_name)
	{
		FILE *ptr = fopen (file_name,"r");
		
		
		int nr_passengers;
		
//		fscanf (ptr, "%d", *nr_passengers);
		fscanf (ptr, "%d", &nr_passengers);
		
		
		
		passenger **arr = (passenger**)malloc(sizeof(passenger*) * nr_passengers);
		
		int i = 0;
		for (; i < nr_passengers; i++)
		{
			arr[i] = (passenger*)malloc(sizeof(passenger));
			fscanf (ptr, "%d", &(arr[i] -> ret_flag));
			fscanf (ptr, "%s %s %s %s %s %s %s", (arr[i] -> entry_time), (arr[i] -> entry_date), (arr[i] -> ticket_nr), (arr[i] -> flight_nr), (arr[i] -> flight_time), (arr[i] -> flight_date), (arr[i] -> destination));
			if ((arr[i] -> ret_flag) == 1)
			{
				fscanf (ptr, "%s %s %s %s %s", (arr[i] -> return_ticket_nr), (arr[i] -> return_flight_nr), (arr[i] -> return_time), (arr[i] -> return_date), (arr[i] -> return_to));
			}
			fscanf (ptr, "%s %s %s %s %s %s %s", (arr[i] -> passport_nr), (arr[i] -> passport_exp_date), (arr[i] -> nationality), (arr[i] -> visa_exp_date), (arr[i] -> visa_country), (arr[i] -> first_name), (arr[i] -> last_name));
			
			fscanf (ptr, " %c %d %d", &(arr[i] -> gender), &(arr[i] -> age), &(arr[i] -> nr_of_bags));
			arr[i] -> weight_of_bags = (double*)malloc(sizeof(double) * (arr[i] -> nr_of_bags));
			
			int j = 0;
			for (; j < (arr[i] -> nr_of_bags); j++)
				fscanf (ptr, "%lf", &(arr[i] -> weight_of_bags[j]));
			
			arr[i] -> contents = (int**)malloc(sizeof(int*) * (arr[i] -> nr_of_bags));
			for (j = 0; j < (arr[i] -> nr_of_bags); j++)
			{
				(arr[i] -> contents[j]) = (int*)malloc(sizeof(int) * 10);
				int k = 0;
				for (; k < 10; k++)
					fscanf (ptr, "%d", &(arr[i] -> contents[j][k])); 
			}
		}
		
		fclose (ptr);
		
/*		for ( i = 0; i < nr_passengers; i++)
		{
			printf ("%d\n", (arr[i] -> ret_flag));
			printf ("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", (arr[i] -> entry_time), (arr[i] -> entry_date), (arr[i] -> ticket_nr), (arr[i] -> flight_nr), (arr[i] -> flight_time), (arr[i] -> flight_date), (arr[i] -> destination));
			if ((arr[i] -> ret_flag) == 1)
			{
				printf ("%s\n%s\n%s\n%s\n%s\n", (arr[i] -> return_ticket_nr), (arr[i] -> return_flight_nr), (arr[i] -> return_time), (arr[i] -> return_date), (arr[i] -> return_to));
			}
			printf ("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", (arr[i] -> passport_nr), (arr[i] -> passport_exp_date), (arr[i] -> nationality), (arr[i] -> visa_exp_date), (arr[i] -> visa_country), (arr[i] -> first_name), (arr[i] -> last_name));
			
			printf ("%c\n%d\n%d\n", (arr[i] -> gender), (arr[i] -> age), (arr[i] -> nr_of_bags));
			
			int j = 0;
			for (; j < (arr[i] -> nr_of_bags); j++)
				printf ("%lf\t", (arr[i] -> weight_of_bags[j]));
			
			printf ("\n");
			for (j = 0; j < (arr[i] -> nr_of_bags); j++)
			{
				int k = 0;
				for (; k < 10; k++)
					printf ("%d\t", (arr[i] -> contents[j][k]));
				printf ("\n"); 
			}
		}
*/		
		
		return arr;
	}
		
