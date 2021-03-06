#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <asm/unistd.h>

	typedef struct complex
	{
		int real;
		int img;
	}cmp_num;
	
	extern int N;
	extern cmp_num *arr;
	extern cmp_num *result;
	
	extern void take_input(char*);
	
	extern void print_numbers(int);
	
	extern void *multiply_all(void*);
	extern cmp_num multiply(cmp_num, cmp_num);
