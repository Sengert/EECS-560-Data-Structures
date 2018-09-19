/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 08
*
* MinMaxHeap and MaxMinHeap:
*       Building a MinMaxHeap and MaxMinHeap based on array implementation,
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/

#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H
#include <iostream>

using namespace std;


class MinMaxHeap{
        public:
                MinMaxHeap(int* array, int arraySize);
                ~MinMaxHeap();

                //Attempts to heapify the heap if it needs it by rearranging
                //the leaves with each parent
                void BuildHeap();

                //Inserts a value to the end of the used portion of the array,
                //then calls BuildHeap() to rearrange if needed
                void Insert(int x);

                //Deletes the minimum value in the heap, then follows steps
                //to reorganize the heap
                void DeleteMin();

                //Deletes the maximum value in the heap, then follows steps
                //to reorganize the heap
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
                int FindMinimumChildIndex(int parentIndex);

                //Finds the index of the child containing the largest value,
                //for the passed in parent, returns an int representing this value
                int FindMaximumChildIndex(int parentIndex);

        private:
                int* arr;
                int length;//Length of the portion of the array being used

};

#endif
