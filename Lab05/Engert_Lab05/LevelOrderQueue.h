/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 05
*
* Two-Three Trees with level order print:
*       Priority queue for use with the TwoThreeTree implementation, this is
*       the LinkedList lab, but has been modified to be a LinkedList of nodes
*       containing TwoThreeNode pointers.
*******************************************************************************/

#ifndef LEVELORDERQUEUE_H
#define LEVELORDERQUEUE_H
#include <iostream>
#include "TwoThreeTree.h"
#include "TwoThreeNode.h"

using namespace std;

struct Node{
        Node* nextNode;
        TwoThreeNode* nodeVal;
};

class LevelOrderQueue{
        public:
                LevelOrderQueue();
                ~LevelOrderQueue();

                int size;

                //Returns a TwoThreeNode pointer looking at the TwoThreeNode
                //in the front of the queue.
                TwoThreeNode* peek();

                //Removes the TwoThreeNode pointer at the front of the queue.
                void dequeue();

                //Pass a pointer looking at the TwoThreeNode that we want to
                //add to the back of the queue.
                void insert(TwoThreeNode* x);

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
