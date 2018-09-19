Lab08: main.o MaxMinHeap.o MinMaxHeap.o
	g++ -std=c++11 -g -Wall MaxMinHeap.o MinMaxHeap.o main.o -o Lab08

main.o: MaxMinHeap.h MinMaxHeap.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MaxMinHeap.o: MaxMinHeap.h MaxMinHeap.cpp
	g++ -std=c++11 -g -Wall -c MaxMinHeap.cpp

MinMaxheap.o: MinMaxHeap.h MinMaxHeap.cpp
	g++ -std=c++11 -g -Wall -c MinMaxHeap.cpp

minmax: Lab08 main.cpp
	./Lab08 minmax

maxmin: Lab08 main.cpp
	./Lab08 maxmin

test: Lab08 main.cpp
	./Lab08

clean:
	rm *.o Lab08
