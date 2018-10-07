programa: main.o llista.o
	gcc -g -o programa main.o llista.o
main.o: main.c llista.c
	gcc -c main.c
llista.o: llista.c
	gcc -c llista.c
clean:
	rm -f programa *.o
