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
#include "LevelOrderQueue.h"

using namespace std;

LevelOrderQueue::LevelOrderQueue(){
        front = nullptr;
        tail = nullptr;
        size = 0;
}

LevelOrderQueue::~LevelOrderQueue(){
        while(front != nullptr){
                dequeue();
        }
}

TwoThreeNode* LevelOrderQueue::peek(){
        if(front == nullptr){
                return(nullptr);
        }
        else{
                return(front->nodeVal);
        }
}

void LevelOrderQueue::dequeue(){
        if(front == nullptr){
                return;
        }
        else{
                Node* delNode = front;
                front = front->nextNode;
                delete delNode;
                size--;
        }
}

void LevelOrderQueue::insert(TwoThreeNode* x){
        Node* node = new Node();
        node->nodeVal = x;

        if(size == 0){
                //If this is the first node added to the list
                front = node;
                tail = node;
        }
        else{
                //Add to the back of the queue
                tail->nextNode = node;
                tail = node;
        }

        size++;

        return;
}

bool LevelOrderQueue::isEmpty(){
        if(size == 0){
                return true;
        }
        else{
                return false;
        }
}

void LevelOrderQueue::print(){
        Node* tempNode = front;
        //if list is empty
        if(size == 0){
                cout << "\n";
                return;
        }

        while(tempNode != nullptr){
                cout << tempNode->nodeVal->getValue() << " ";
                tempNode = tempNode->nextNode;
        }
        cout << "\n";

        return;
}
