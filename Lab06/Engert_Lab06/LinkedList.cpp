/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* LinkedList:
*       Singly linked list for use in the open hash table in this lab
*******************************************************************************/
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
        front = nullptr;
        tail = nullptr;
        size = 0;
}

LinkedList::~LinkedList(){
        //empty();
}

void LinkedList::insert(int x){
        Node* node = new Node();
        node->nodeVal = x;

        if(size == 0){
                //If this is the first node added to the list
                front = node;
                tail = node;
        }
        else{
                Node* tempNode = front;
                front = node;
                node->nextNode = tempNode;
        }

        size++;

        return;
}

bool LinkedList::isEmpty(){
        if(size == 0){
                return true;
        }
        else{
                return false;
        }
}

void LinkedList::erase(int x){

        if(isEmpty()){
                cout << "Entered number does not exist in the list.\n";
        }
        else if(front->nodeVal == x){
                Node* tempNode = front;
                front = front->nextNode;

                delete tempNode;
                size--;
        }
        else{
                Node* tempNode = front->nextNode;
                Node* prevNode = front;//Used to re-link the list after deleting a value

                while(tempNode != nullptr){
                        if(tempNode->nodeVal == x){
                                if(tail == tempNode){//if the node we're deleting is the current tail
                                        tail = prevNode;//make the previous node the new tail
                                }
                                        prevNode->nextNode = tempNode->nextNode;

                                        delete tempNode;
                                        size--;
                                        return;
                        }
                        else{
                                //increment tempNode and prevNode
                                tempNode = tempNode->nextNode;
                                prevNode = prevNode->nextNode;
                        }
                }
        }
        cout << "Entered number does not exist in the list.\n";

        return;
}

void LinkedList::print(){
        Node* tempNode = front;
        //if list is empty
        if(size == 0){
                cout << "\n";
                return;
        }

        while(tempNode != nullptr){
                cout << tempNode->nodeVal << " ";
                tempNode = tempNode->nextNode;
        }
        cout << "\n";

        return;
}

Node* LinkedList::find(int x){
        if(size == 0 && front == nullptr){
                //If no values are in the list
                return nullptr;
        }
        else if(front->nodeVal == x){
                //If the value is at the front of the list
                return front;
        }
        else{
                Node* tempNode = front;

                while(tempNode != nullptr){
                        if(tempNode->nodeVal == x){
                                //Value has been found
                                return tempNode;
                        }
                        else{
                                //Increment to the next node in the list
                                tempNode = tempNode->nextNode;
                        }
                }
        }
        return nullptr;

}

//void LinkedList::empty(){
//while(front != nullptr){
//                Node* tempNode = front;
//                front = tempNode->nextNode;
//
//                delete tempNode;
//        }
//}
