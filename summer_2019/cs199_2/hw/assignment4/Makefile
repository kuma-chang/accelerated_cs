output: main.o activity_tracker.o
	g++ -ansi -Wall -g main.o activity_tracker.o

main.o: main.cpp
	g++ -c main.cpp

company.o: activity_tracker.cpp activity_tracker.h
	g++ -c activity_tracker.cpp

clean:
	rm *.o a.out
