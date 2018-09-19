/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 07
*
* Min-5 heap and Max-5 heap:
*       Building a min and max - 5 heaps based on array implementation,
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>

using namespace std;


class MaxHeap{
        public:
                MaxHeap(int* array, int arraySize);
                ~MaxHeap();

                //Attempts to heapify the heap if it needs it by rearranging
                //the leaves with each parent
                void BuildHeap();

                //Inserts a value to the end of the used portion of the array,
                //then calls BuildHeap() to rearrange if needed
                void Insert(int x);

                //Deletes the minimum value in the heap, then calls BuildHeap()
                //to rearrange if needed
                void DeleteMin();

                //Deletes the maximum value in the heap, then calls BuildHeap()
                //to rearrange if needed
                void DeleteMax();

                //Prints the minimum value stored in the heap
                void FindMin();

                //Prints the maximum value stored in the heap
                void FindMax();

                //Prints the heap out in level order
                void LevelOrder();

                //Finds the index of the last parent in the heap, returns an
                //int representing this index
                int FindLastParentIndex();

                //Finds the index of the child containing the smallest value,
                //for the passed in parent, returns an int representing this value
                int FindMaximumChildIndex(int parentIndex);

                //Prints all the children of the passed parent from left to right
                //as they are stored in the array
                void PrintChildren(int x);

        private:
                int* arr;
                int length;//Length of the portion of the array being used

};

#endif
