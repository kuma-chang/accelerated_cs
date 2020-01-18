output: main.o music_search.o bst.o
	g++ -ansi -Wall -g main.o music_search.o bst.o

main.o: main.cpp
	g++ -c main.cpp

music_search.o: music_search.cpp music_search.h
	g++ -c music_search.cpp

bst.o: bst.cpp bst.h
	g++ -c bst.cpp

clean:
	rm *.o a.out
