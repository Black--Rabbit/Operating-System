exec: main.c multiply.o input.o
	gcc -o exec -g multiply.o input.o main.c -lpthread
	
multiply.o: multiply.c
	gcc -c -g multiply.c
	
input.o: input.c
	gcc -c -g input.c
