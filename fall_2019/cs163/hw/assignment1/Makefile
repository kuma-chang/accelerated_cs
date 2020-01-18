output: main.o company.o
	g++ -ansi -Wall -g main.o psu_classes.o

main.o: main.cpp
	g++ -c main.cpp

company.o: psu_classes.cpp psu_classes.h
	g++ -c psu_classes.cpp

clean:
	rm *.o a.out
