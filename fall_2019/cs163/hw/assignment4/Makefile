output: main.o uno.o cards_players.o
	g++ -ansi -Wall -g main.o uno.o cards_players.o

run:
	valgrind ./a.out

debug:
	g++ -ansi -Wall -g -fsanitize=leak main.o uno.o cards_players.o

main.o: main.cpp
	g++ -c main.cpp

uno.o: uno.cpp uno.h
	g++ -c uno.cpp

cards_players.o: cards_players.cpp cards_players.h
	g++ -c cards_players.cpp

clean:
	rm *.o a.out
