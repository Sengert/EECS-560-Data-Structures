Lab04: main.o BST.o
	g++ -std=c++11 -g -Wall BST.o main.o -o Lab04

main.o: BST.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BST.o: BST.h BST.cpp
	g++ -std=c++11 -g -Wall -c BST.cpp

test: Lab04 main.cpp
	./Lab04


clean:
	rm *.o Lab04
