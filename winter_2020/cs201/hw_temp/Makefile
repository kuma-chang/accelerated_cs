CFLAGS = -Wall -std=c11 -pedantic -O0
# -std=c11: Specify the input is C 2011
# -pedantic: Strictly adhere to the Standard
# -Wall: Enable all warnings
# -O0: Disable all optimizations
# -g: Enable GDB information (“symbols”)

all: temp test1

temp: temp.c
	gcc $(CFLAGS) -o temp temp.c

test1: part1.o part2.o
	gcc -o test1 part1.o part2.o

part1.o: part1.c
	gcc -c -o part1.o part1.c

part2.o: part2.c
	gcc -c -o part2.o part2.c

clean:
	rm -f *.o temp test1
#-f "force," which ignores non-existent files and overrides any confirmation prompts
