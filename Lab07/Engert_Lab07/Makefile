Lab07: main.o MinHeap.o MaxHeap.o
	g++ -std=c++11 -g -Wall MinHeap.o MaxHeap.o main.o -o Lab07

main.o: MinHeap.h MaxHeap.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -std=c++11 -g -Wall -c MinHeap.cpp

Maxheap.o: MaxHeap.h MaxHeap.cpp
	g++ -std=c++11 -g -Wall -c MaxHeap.cpp


test: Lab07 main.cpp
	./Lab07

clean:
	rm *.o Lab07
