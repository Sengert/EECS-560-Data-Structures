#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

struct Node{
        Node* nextNode;
        int nodeVal;
};

class List{
        public:
                List();
                ~List();

                void insert(int);
                bool isEmpty();
                void erase(int);
                void print();
                Node* find(int);
                void empty();

        private:
                Node* front;
                Node* tail;
                int size;
};

#endif
