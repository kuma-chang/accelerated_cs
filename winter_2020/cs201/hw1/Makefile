CFLAGS = -std=c11 -pedantic -Wall -O0 -g
# -std=c11: Specify the input is C 2011
# -pedantic: Strictly adhere to the Standard
# -Wall: Enable all warnings
# -O0: Disable all optimizations
# -g: Enable GDB information (“symbols”)

hw1: hw1_plinko #test1

plinko: hw1_plinko.c
	gcc $(CFLAGS) -o hw1_plinko hw1_plinko.c

#test1: part1.o part2.o
#	gcc -o test1 part1.o part2.o

#part1.o: part1.c
#	gcc -c -o part1.o part1.c

#part2.o: part2.c
#	gcc -c -o part2.o part2.c

clean:
	rm -f *.o hw1_plinko #test1
#-f "force," which ignores non-existent files and overrides any confirmation prompts
