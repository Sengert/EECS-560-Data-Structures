/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 10
*
* LeftistHeap and SkewHeap:
*       Building a LeftistHeap and SkewHeap based on tree implementation,
*       Heaps contain Insertion, Concate, DeleteMin, and multiple traversals
*******************************************************************************/

#ifndef SKEWHEAP_H
#define SKEWHEAP_H
#include <iostream>
#include "LeftistHeap.h"

using namespace std;

struct LNode;

class SkewHeap{
        public:
                SkewHeap();
                ~SkewHeap();

                //Unused
                void BuildHeap();
                //Creates a new node and Concates it to the existing structure
                void Insert(int x);
                //Deletes the root, then Concates the two remaining subtrees
                void DeleteMin();
                //Prints the root, which contains the smallest value in the heap
                //O(1)
                void FindMin();
                //Recursive function that will merge two skew heaps, can also be used
                //with insertion, just treat the new node as a heap.
                LNode* Concate(LNode* H1, LNode* H2);
                //Preorder traversal print
                void Preorder(LNode* curNode);
                //Inorder traversal print
                void Inorder(LNode* curNode);
                //Level order traversal print using a priority queue
                void Levelorder();
                //Returns a pointer to the root node of the heap
                LNode* GetRoot();



        private:
                LNode* root;
};

#endif
