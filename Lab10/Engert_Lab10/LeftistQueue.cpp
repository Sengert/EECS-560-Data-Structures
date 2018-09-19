/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 10
*
* Priority queue for LeftistHeap's Level Order Print
*******************************************************************************/
#include "LeftistQueue.h"
#include "LeftistHeap.h"

using namespace std;

LeftistQueue::LeftistQueue(){
        front = nullptr;
        tail = nullptr;
        size = 0;
}

LeftistQueue::~LeftistQueue(){
        while(front != nullptr){
                dequeue();
        }
}

LNode* LeftistQueue::peek(){
        if(front == nullptr){
                return(nullptr);
        }
        else{
                return(front->nodeVal);
        }
}

void LeftistQueue::dequeue(){
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

void LeftistQueue::insert(LNode* x){
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

bool LeftistQueue::isEmpty(){
        if(size == 0){
                return true;
        }
        else{
                return false;
        }
}

void LeftistQueue::print(){
        Node* tempNode = front;
        //if list is empty
        if(size == 0){
                cout << "\n";
                return;
        }

        while(tempNode != nullptr){
                cout << tempNode->nodeVal->value << " ";
                tempNode = tempNode->nextNode;
        }
        cout << "\n";

        return;
}
