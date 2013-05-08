exec: input.o path.o main.c
	gcc -o exec -g path.o input.o main.c -lpthread
input.o: input.c
	gcc -c -g input.c
path.o: path.c
	gcc -c -g path.c

