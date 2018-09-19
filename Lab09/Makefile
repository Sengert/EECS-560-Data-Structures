Lab09: main.o BST.o MaxHeap.o MinHeap.o DataTimer.o
	g++ -std=c++11 -g -Wall BST.o MaxHeap.o MinHeap.o DataTimer.o main.o -o Lab09

main.o: BST.h MaxHeap.h MinHeap.h DataTimer.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BST.o: BST.h BST.cpp
	g++ -std=c++11 -g -Wall -c BST.cpp

MaxHeap.o: MaxHeap.h MaxHeap.cpp
	g++ -std=c++11 -g -Wall -c MaxHeap.cpp

MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -std=c++11 -g -Wall -c MinHeap.cpp

DataTimer.o: DataTimer.h DataTimer.cpp
	g++ -std=c++11 -g -Wall -c DataTimer.cpp

test: Lab09 main.cpp
	./Lab09

clean:
	rm *.o Lab09
