CFLAGS = -std=c11 -pedantic -Wall -O0 -g
# -std=c11: Specify the input is C 2011
# -pedantic: Strictly adhere to the Standard
# -Wall: Enable all warnings
# -O0: Disable all optimizations
# -g: Enable GDB information (“symbols”)

hw1: hw1_plinko.c board.o monte_carlo_test.o
	gcc $(CFLAGS) -o hw1 hw1_plinko.c board.o monte_carlo_test.o

board.o: board.c
	gcc -c -o board.o board.c

monte_carlo_test.o: monte_carlo_test.c
	gcc -c -o monte_carlo_test.o monte_carlo_test.c


clean:
	rm -f *.o hw1 
#-f "force," which ignores non-existent files and overrides any confirmation prompts
