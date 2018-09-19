/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* LinkedList:
*       Singly linked list for use in the open hash table in this lab
*******************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

struct Node{
        Node* nextNode;
        int nodeVal;
};

class LinkedList{
        public:
                LinkedList();
                ~LinkedList();

                int size;

                void insert(int);
                bool isEmpty();
                void erase(int);
                void print();
                Node* find(int);
                //void empty();

        private:
                Node* front;
                Node* tail;

};

#endif
