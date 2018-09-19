sll: main.o List.o
	g++ -std=c++11 -g -Wall List.o main.o -o sll

main.o: List.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

List.o: List.h List.cpp
	g++ -std=c++11 -g -Wall -c List.cpp

test: sll main.cpp
	./sll


clean:
	rm *.o sll
