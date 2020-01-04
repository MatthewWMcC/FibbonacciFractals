FLAGS=-Wall -ansi -g -O2 -pg

main_fib.o: main_fib.c bmp.h
	gcc -c -o main_fib.o main_fib.c $(FLAGS)

timing.o: timing.c
	gcc -c -o timing.o timing.c $(FLAGS)

bmp.o: bmp.c
	gcc -c -o bmp.o bmp.c $(FLAGS)

fib.o: fib.c bmp.h
	gcc -c -o fib.o fib.c $(FLAGS)

fib: main_fib.o timing.o bmp.o fib.o
	gcc -o fib main_fib.o fib.o bmp.o timing.o $(FLAGS)

runall:
	./fib 7 10 10 10 100 100 fib7.bmp
	./fib 9 10 10 10 400 400 fib9.bmp
	./fib 25 10 10 2 3000 3000 fib25.bmp
	./fib 26 10 10 4 7000 7000 fib26.bmp
	./fib 30 10 10 2 13000 13000 fib30.bmp
	
	./fib 34 100 100 2 28000 28000 fib34.bmp

clean:
	rm -f fib *.o *.bmp



