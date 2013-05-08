#include "header.h"

	int N;
	cmp_num *arr;
	cmp_num *result;
	
	int main(int argc, char *argv[])
	{
		take_input(argv[1]);
//		print_numbers(N);

		int i;
//		for(i = 0; i < N; i++)
//			printf("real = %d\timaginary = %d\n", arr[i].real, arr[i].img);

		pthread_attr_t attr;
		pthread_attr_init(&attr);

		while(N)
		{
			int old_N = N;
		
			int flag = (N % 2)? 1 : 0;	// flag to check odd or even. 
			N /= 2;
			int size = (flag) ? N + 1: N;
			
			result = (cmp_num*)malloc(sizeof(cmp_num) * size);
			
			pthread_t tid_arr[N];
			int index = 0;
						
			int args[N];			
			for(i = 0; i < N; i++)
			{
				args[i] = i;
				pthread_create(&tid_arr[i], &attr, multiply_all, &args[i]); // thread creation.
//				pthread_join(tid_arr[index], NULL);
			}
			
			for(; index < N; index++)
				pthread_join(tid_arr[index], NULL);	//waiting for created threads.
			
			
//			printf("below 2nd while\n");
			
			if(flag)	// get the last number to the array.
			{
//				printf("!! %d\n", i);
				result[size - 1].real = arr[old_N - 1].real;
				result[size - 1].img = arr[old_N - 1].img;
				N += 1;
			}
		
			print_numbers(N);
			free(arr);
			arr = result;	//swap the arrays.
			if(N == 1)
				break;
			
			
		}

		
//		printf("55\n");
//		print_numbers(1);
		
		return 0;
	}
	
	void print_numbers(int size)
	{
		int x = 0;
		for(; x < size; x++)
			printf("%d + i %d\n", result[x].real, result[x].img);
		printf("\n");
	}
		
		
