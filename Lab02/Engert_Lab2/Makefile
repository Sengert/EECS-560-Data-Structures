hashtable: main.o LinkedList.o Hash.o
	g++ -std=c++11 -g -Wall LinkedList.o Hash.o main.o -o hashtable

main.o: Hash.h LinkedList.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

Hash.o: Hash.h Hash.cpp
	g++ -std=c++11 -g -Wall -c Hash.cpp

test: hashtable main.cpp
	./hashtable


clean:
	rm *.o hashtable
