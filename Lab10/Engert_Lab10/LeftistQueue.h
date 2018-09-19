/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 10
*
* Priority queue for LeftistHeap's Level Order Print
*******************************************************************************/

#ifndef LEFTISTQUEUE_H
#define LEFTISTQUEUE_H
#include <iostream>
#include "LeftistHeap.h"

using namespace std;
struct LNode;
struct Node{
        Node* nextNode;
        LNode* nodeVal;
};


class LeftistQueue{
        public:
                LeftistQueue();
                ~LeftistQueue();

                int size;

                //Returns a TwoThreeNode pointer looking at the TwoThreeNode
                //in the front of the queue.
                LNode* peek();

                //Removes the TwoThreeNode pointer at the front of the queue.
                void dequeue();

                //Pass a pointer looking at the TwoThreeNode that we want to
                //add to the back of the queue.
                void insert(LNode* x);

                //Returns a bool representing whether or not the queue is empty.
                bool isEmpty();

                //Prints from front to back the values that the TwoThreeNodes contain.
                void print();

        private:
                //Front of the queue
                Node* front;
                //Back of the queue
                Node* tail;

};

#endif
