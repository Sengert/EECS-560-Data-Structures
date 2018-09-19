Lab06: main.o LinkedList.o OpenHash.o DoubleHash.o QuadraticHash.o HashTimer.o
	g++ -std=c++11 -g -Wall LinkedList.o OpenHash.o DoubleHash.o QuadraticHash.o HashTimer.o main.o -o Lab06

main.o: LinkedList.h OpenHash.h DoubleHash.h QuadraticHash.h HashTimer.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

OpenHash.o: OpenHash.h OpenHash.cpp
	g++ -std=c++11 -g -Wall -c OpenHash.cpp

DoubleHash.o: DoubleHash.h DoubleHash.cpp
	g++ -std=c++11 -g -Wall -c DoubleHash.cpp

QuadraticHash.o: QuadraticHash.h QuadraticHash.cpp
	g++ -std=c++11 -g -Wall -c QuadraticHash.cpp

HashTimer.o: HashTimer.h HashTimer.cpp
	g++ -std=c++11 -g -Wall -c HashTimer.cpp

test: Lab06 main.cpp
	./Lab06

clean:
	rm *.o Lab06
