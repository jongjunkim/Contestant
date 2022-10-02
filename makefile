all: program2

program2: main.o Minheap.o Contestant.o
			g++ main.o Minheap.o Contestant.o -o program2

main.o: main.cpp Contestant.h Minheap.h
			g++ -c main.cpp

Minheap.o: Minheap.h Minheap.cpp
			g++ -c Minheap.cpp 

Contestant.o: Contestant.h Contestant.cpp
			g++ -c Contestant.cpp 

clean:
	rm -f *.o program2