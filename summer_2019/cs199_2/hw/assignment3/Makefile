output: main.o company.o
	g++ -ansi -Wall -g main.o company.o

main.o: main.cpp
	g++ -c main.cpp

company.o: company.cpp company.h
	g++ -c company.cpp

clean:
	rm *.o a.out
