/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 09
*
* DataTimer:
*       A timer used to measure the performance of different ADTs,
*       including BST, min 5heap, and max 5heap.
*******************************************************************************/
#ifndef DATATIMER_H
#define DATATIMER_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "BST.h"


class DataTimer{
public:
        DataTimer(int m);
        ~DataTimer();

        //Function that we call from main, calls upon DeleteMins(), DeleteMaxes(), and TablePerformance()
        //and keeps track of how many iterations have passed to calculate averages
        void BuildTables();

        //Deletes the minimums for the ADTs
        void DeleteMins();

        //Deletes the maximums for the ADTs
        void DeleteMaxes();

        //Helper function that adds up all the timings for every insertion for
        //each hash table.
        void TablePerformance();

private:
        //Timer variables to calculate amount of time elapsed since the
        //beginning of a call until the end of the function.
        clock_t start;
        clock_t end;
        double duration;

        //For the arrays for the min and max heaps
        int minHeapArray[10000000];
        int maxHeapArray[10000000];

        //the amount of buckets each hashtable has
        int tableSize;
        //the amount of numbers to insert to each hash table
        int numRandomInputs;
        //the array containing random numbers to insert
        int* randomInputs;

        //A pointer to each hash table we want to test
        BST* binarySearchTree;
        MaxHeap* maxHeap;
        MinHeap* minHeap;

        //Variables to store the average timings of each operation
        double binarySearchTreeBuildTime;
        double maxHeapBuildTime;
        double minHeapBuildTime;
        double bstDeleteMinTime;
        double maxHeapDeleteMinTime;
        double minHeapDeleteMinTime;
        double bstDeleteMaxTime;
        double maxHeapDeleteMaxTime;
        double minHeapDeleteMaxTime;
};

#endif
