output: main.o purchase.o ordered_list.o queue.o stack.o
	g++ -ansi -Wall -g main.o purchase.o ordered_list.o queue.o stack.o

main.o: main.cpp
	g++ -g -c main.cpp

purchase.o: purchase.cpp purchase.h
	g++ -g -c purchase.cpp

ordered_list.o: ordered_list.cpp ordered_list.h
	g++ -g -c ordered_list.cpp

queue.o: queue.cpp queue.h
	g++ -g -c queue.cpp

stack.o: stack.cpp stack.h
	g++ -g -c stack.cpp

clean:
	rm *.o a.out
