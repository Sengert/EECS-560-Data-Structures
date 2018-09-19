Lab3: main.o QuadraticHash.o DoubleHash.o
	g++ -std=c++11 -g -Wall QuadraticHash.o DoubleHash.o main.o -o Lab3

main.o: QuadraticHash.h DoubleHash.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

QuadraticHash.o: QuadraticHash.h QuadraticHash.cpp
	g++ -std=c++11 -g -Wall -c QuadraticHash.cpp

DoubleHash.o: DoubleHash.h DoubleHash.cpp
	g++ -std=c++11 -g -Wall -c DoubleHash.cpp

test: Lab3 main.cpp
	./Lab3


clean:
	rm *.o Lab3
