Lab05: main.o TwoThreeTree.o LevelOrderQueue.o TwoThreeNode.o
	g++ -std=c++11 -g -Wall TwoThreeTree.o LevelOrderQueue.o TwoThreeNode.o main.o -o Lab05

main.o: LevelOrderQueue.h TwoThreeTree.h TwoThreeNode.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

TwoThreeTree.o: TwoThreeTree.h TwoThreeTree.cpp
	g++ -std=c++11 -g -Wall -c TwoThreeTree.cpp

LevelOrderQueue.o: LevelOrderQueue.h LevelOrderQueue.cpp
	g++ -std=c++11 -g -Wall -c LevelOrderQueue.cpp

TwoThreeNode.o: TwoThreeNode.h TwoThreeNode.cpp
	g++ -std=c++11 -g -Wall -c TwoThreeNode.cpp

test: Lab05 main.cpp
	./Lab05


clean:
	rm *.o Lab05
