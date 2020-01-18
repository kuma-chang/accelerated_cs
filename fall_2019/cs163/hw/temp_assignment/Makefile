output: main.o company.o
	g++ -ansi -Wall -g main.o temp.o

main.o: main.cpp
	g++ -c main.cpp

company.o: temp.cpp temp.h
	g++ -c temp.cpp

clean:
	rm *.o a.out
