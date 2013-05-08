Name : Abhinav Misra
ID: 2011B2A7580G
List of File:

	1. main.c : It is the main file that drives the airport program. It takes the file name of the input file as command line argument.
	2. q2_input.c : It is used to take input and pass it on to the main file.
	3. baggage.c : This acts as the baggage counter and forks luggage security, weight and boarding pass.
	4. luggage_security.c : Corresponds to Luggage Security Counter.
	5. weight.c : Corresponds to the weight process.
	6. boarding_pass.c : Corresponds to the boarding pass functionality.
	7. immigration.c : This is the immigration counter of the airport and forks visa and passport processes.
	8. visa.c : Corresponds to the visa process.
	9. passport.c : Corresponds to the passport process.
	10. security.c : Implements the security module of the airport.
	11. male_security : Corresponds to the both male and female security checks.
	12. main_header.h : Header which contains the struct used to carry out all the functions and also the function prototypes.
	13. Makefile : Makefile to compile the project.
	
How to compile:

	$make
	will compile the project and generate an executable called exec.
	
How to use:

	$./exec <file name>
	<file name> is the file name of the input file containing all the data regarding the passenger.
	
Description:

	main.c is the main airport process which will fork baggage counter, immigration and security check processes. Different modules signal each other so as to carry on with the execution. The main aspect of how a particular sub part comes to know which passenger it is attending is by reading the pointer*.txt file which specifies the address of the passenger currently in that process.
	
Not Done:
	What not done:
		1. waiting lounge and boarding modules not prepared.
	Why
		1. Lack of proper understanding of signal tranfer b/w processes.
		2. Unpredictable behaviour of printf and fprintf.

BUGS:

	The output is different most of the times. The buffer is creating some problem which I was not able to resolve. Unflushed buffer is causing certain things not to comme up to the level. 
	
	Had put fflush most of the places the over come the above prlbem.	
