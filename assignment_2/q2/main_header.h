#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

	typedef struct passenger
	{
		int ret_flag;
		char entry_time[6], entry_date[11], ticket_nr[8], flight_nr[6], flight_time[6], flight_date[11], destination[11], return_ticket_nr[8], return_flight_nr[6], return_time[6], return_date[11], return_to[11], passport_nr[11], passport_exp_date[11], nationality[11], visa_exp_date[11], visa_country[11], first_name[11], last_name[11];
		char gender;
		int age;
		int nr_of_bags;
		double *weight_of_bags;
		int **contents;
	}passenger;
	
	extern passenger **input (char*);
	extern void baggage_counter ();
	extern void luggage_security ();
	extern int is_palindrome (int);
	extern int is_colourfull (int);
	extern void weight (pid_t);
	extern void boarding_pass (pid_t);
	extern void baggage (pid_t);
	
	extern void immigration ();
	extern void passport ();
	extern void visa ();
	extern int check_date (char*, char*);
	
