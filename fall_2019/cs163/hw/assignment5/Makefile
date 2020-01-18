output: main.o rational_number.o 
	g++ -Wall -g main.o rational_number.o 

main.o: main.cpp
	g++ -g -c main.cpp

rational_number.o: rational_number.cpp rational_number.h
	g++ -g -c rational_number.cpp

clean:
	rm *.o a.out
