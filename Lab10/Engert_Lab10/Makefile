Lab10: main.o LeftistHeap.o SkewHeap.o LeftistQueue.o
	g++ -std=c++11 -g -Wall LeftistHeap.o SkewHeap.o LeftistQueue.o main.o -o Lab10

main.o: LeftistHeap.h SkewHeap.h LeftistQueue.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp
	g++ -std=c++11 -g -Wall -c LeftistHeap.cpp

SkewHeap.o: SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -g -Wall -c SkewHeap.cpp

LeftistQueue.o: LeftistQueue.h LeftistQueue.cpp
	g++ -std=c++11 -g -Wall -c LeftistQueue.cpp

test: Lab10 main.cpp
	./Lab10

clean:
	rm *.o Lab10
