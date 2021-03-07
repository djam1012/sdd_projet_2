all: main

main: biblioH.o entreeSortieH.o main.o
	gcc biblioH.o entreeSortieH.o main.o -o main -lm

biblioH.o: biblioH.c biblioH.h
	gcc -c biblioH.c -o biblioH.o -lm

entreeSortieH.o: entreeSortieH.c entreeSortieH.h biblioH.h
	gcc -c entreeSortieH.c -o entreeSortieH.o -lm

main.o: main.c biblioH.h entreeSortieH.h
	gcc -c main.c -o main.o -lm

clean:
	rm -f *.o
	rm -f main
