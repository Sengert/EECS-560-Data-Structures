/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 09
*
* DataTimer:
*       A timer used to measure the performance of different ADTs,
*       including BST, min 5heap, and max 5heap.
*******************************************************************************/
#include "DataTimer.h"

using namespace std;

DataTimer::DataTimer(int m){
        //Initilize all timings at 0.00s
        binarySearchTreeBuildTime = 0.00;
        maxHeapBuildTime = 0.00;
        minHeapBuildTime = 0.00;
        bstDeleteMaxTime = 0.00;
        maxHeapDeleteMaxTime = 0.00;
        minHeapDeleteMaxTime = 0.00;
        bstDeleteMinTime = 0.00;
        maxHeapDeleteMinTime = 0.00;
        minHeapDeleteMinTime = 0.00;
        tableSize = m;

        for(int i = 0; i < 10000000; i++){
                minHeapArray[i] = 0;
                maxHeapArray[i] = 0;
        }

        srand(time(NULL));//Initilize random seed
}

DataTimer::~DataTimer(){
        //Destructor
}

void DataTimer::TablePerformance(){

        //Run through input sizes from .1 and .01 to .5 and .05 for inputs and searches
        for(int i = 1; i <= 5; i++){
                //Reset array size each iteration so it will hold more random numbers
                numRandomInputs = (1000000*i);
                randomInputs = new int[numRandomInputs];

                for(int j = 0; j < 5; j++){
                        srand(time(NULL));
                        //Re-populate the random arrays
                        for(int k = 0; k < numRandomInputs; k++){
                                randomInputs[k] = rand() % (5*tableSize) + 1;
                        }

                        BuildTables();//Populate the ADTs and time how long it takes to build them
                        DeleteMins();//Search for random numbers in the hash tables
                        DeleteMaxes();
                }
                //Average out the timings
                binarySearchTreeBuildTime = binarySearchTreeBuildTime/5.0;
                maxHeapBuildTime = maxHeapBuildTime/5.0;
                minHeapBuildTime = minHeapBuildTime/5.0;
                bstDeleteMinTime = bstDeleteMinTime/5.0;
                maxHeapDeleteMinTime = maxHeapDeleteMinTime/5.0;
                minHeapDeleteMinTime = minHeapDeleteMinTime/5.0;
                bstDeleteMaxTime = bstDeleteMaxTime/5.0;
                maxHeapDeleteMaxTime = maxHeapDeleteMaxTime/5.0;
                minHeapDeleteMaxTime = minHeapDeleteMaxTime/5.0;

                //Print average timings for this iteration to console.
                cout << "-------------------Build Input Size : " << numRandomInputs << "------------------------\n";
                cout << "Avg time to insert the binary search tree is : " << binarySearchTreeBuildTime << " seconds." << endl;
                cout << "Avg time to build the max 5 heap is : " << maxHeapBuildTime << " seconds." << endl;
                cout << "Avg time to build the min 5 heap is : " << minHeapBuildTime << " seconds." << endl;
                cout << endl;
                cout << "-------------------------Average DeleteMin times for : " << (numRandomInputs*.001) <<" deletions--\n" << endl;
                cout << "Binary Search Tree DeleteMin() : \n";
                cout << "Average time to delete the minimum : " << bstDeleteMinTime << ".\n";
                cout << "Max 5 heap DeleteMin() : \n";
                cout << "Average time to delete the minimum : " << maxHeapDeleteMinTime << ".\n";
                cout << "Min 5 heap DeleteMin() :\n";
                cout << "Average time to delete the minimum : " << minHeapDeleteMinTime << ".\n";
                cout << endl;
                cout << "-------------------------Average DeleteMax times for : " << (numRandomInputs*.001) <<" deletions--\n" << endl;
                cout << "Binary Search Tree DeleteMax() : \n";
                cout << "Average time to delete the maximum : " << bstDeleteMaxTime << ".\n";
                cout << "Max 5 heap DeleteMax() : \n";
                cout << "Average time to delete the maximum : " << maxHeapDeleteMaxTime << ".\n";
                cout << "Min 5 heap DeleteMax() :\n";
                cout << "Average time to delete the maximum : " << minHeapDeleteMaxTime << ".\n";

        }

        return;
}

//Helper function that times the building of each data structure
void DataTimer::BuildTables(){
        binarySearchTree = new BST();
        maxHeap = new MaxHeap(maxHeapArray, 10000000);
        minHeap = new MinHeap(minHeapArray, 10000000);
        //Build the tables add each insert time onto the total time of each table
        for(int i = 0; i < numRandomInputs; i++){
                //BST
                start = clock();
                binarySearchTree->Insert(randomInputs[i]);
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                binarySearchTreeBuildTime = binarySearchTreeBuildTime + duration;
        }
        //max 5 heap
        for(int i = 0; i < numRandomInputs; i++){
                maxHeapArray[i] = randomInputs[i];
        }
        start = clock();
        maxHeap->BuildHeap();
        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
        maxHeapBuildTime = maxHeapBuildTime + duration;
        //min 5 heap
        for(int i = 0; i < numRandomInputs; i++){
                minHeapArray[i] = randomInputs[i];
        }
        start = clock();
        minHeap->BuildHeap();
        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
        minHeapBuildTime = minHeapBuildTime + duration;

        return;
}

void DataTimer::DeleteMins(){
        for(int i = 0; i < (numRandomInputs*.001); i++){
                //binary search tree
                start = clock();
                binarySearchTree->DeleteMin(binarySearchTree->root);
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                bstDeleteMinTime = bstDeleteMinTime + duration;//found

                //max 5 heap
                start = clock();
                maxHeap->DeleteMin();
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                maxHeapDeleteMinTime = maxHeapDeleteMinTime + duration;//found

                //min 5 heap
                start = clock();
                minHeap->DeleteMin();
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                minHeapDeleteMinTime = minHeapDeleteMinTime + duration;//found
        }

        //delete binarySearchTree;
        //delete maxHeap;
        //delete minHeap;

        return;
}

void DataTimer::DeleteMaxes(){
        for(int i = 0; i < (numRandomInputs*.001); i++){
                //binary search tree
                start = clock();
                binarySearchTree->DeleteMax(binarySearchTree->root);
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                bstDeleteMaxTime = bstDeleteMaxTime + duration;//found

                //max 5 heap
                start = clock();
                maxHeap->DeleteMax();
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                maxHeapDeleteMaxTime = maxHeapDeleteMaxTime + duration;//found

                //min 5 heap
                start = clock();
                minHeap->DeleteMax();
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                minHeapDeleteMaxTime = minHeapDeleteMaxTime + duration;//found
        }

        delete binarySearchTree;

        return;
}
