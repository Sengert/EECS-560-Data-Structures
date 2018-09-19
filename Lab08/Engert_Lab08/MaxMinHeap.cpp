/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 08
*
* MinMaxHeap and MaxMinHeap:
*       Building a MinMaxHeap and MaxMinHeap based on array implementation,
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/

#include "MaxMinHeap.h"
#include <cmath>
#include <algorithm>

using namespace std;

MaxMinHeap::MaxMinHeap(int* array, int arraySize){
        cout << endl;
        //cout << "[DEBUG]A new MaxMinHeap has been created!\n";
        arr = array;//Copy the array created in main to the array in this MinMaxHeap
        //Initilize lenght of used elements in the array
        length = 0;
        for(int i = 1; i < arraySize; i++){
                if(arr[i] != 0){
                        length++;
                }
                else{
                //        cout << "Length of used elements in MaxMinHeap is : " << length << endl;
                        for(int j = 0; j <= length; j++){
                        //        cout << arr[j] << " ";
                        }
                        //cout << "\n\n";
                        return;
                }
        }
        return;
}

MaxMinHeap::~MaxMinHeap(){
        //Destructor
        //delete arr;
        //arr = nullptr;
        return;
}

//returns the index of the last parent
int MaxMinHeap::FindLastParentIndex(){
        //if array is not empty
        if(arr[1] != 0){
                return(floor((length)/2));
        }
        else{
                return(0);
        }
}

//returns the index of the minimum child of a given parent
int MaxMinHeap::FindMinimumChildIndex(int parentIndex){
        int minChild = parentIndex*2;//Start with the first child

        if(arr[minChild] == 0){
                return(parentIndex);
        }

        //cout << "[DEBUG]Calling FindMinimumChildIndex left side for : " << arr[minChild] << endl;
        int temp = FindMinimumChildIndex(minChild);//left

        if(arr[(minChild + 1)] != 0){
                //cout << "[DEBUG]Calling FindMinimumChildIndex for : " << arr[(minChild + 1)] << endl;
                int temp2 = FindMinimumChildIndex(minChild + 1);//right

                if(arr[temp2] < arr[minChild]){
                        minChild = temp2;
                }
        }

        if(arr[temp] < arr[minChild]){
                //cout << "[DEBUG] : " << arr[minChild] << ", is greater than " << arr[temp] << endl;
                minChild = temp;
        }
        if(arr[parentIndex] < arr[minChild]){
                minChild = parentIndex;
        }


        //cout << "[DEBUG]The minimum index of : " << arr[parentIndex] << " is " << arr[minChild] << endl;
        return(minChild);
}

int MaxMinHeap::FindMaximumChildIndex(int parentIndex){
        int maxChild = parentIndex*2;//Start with the first child

        if(arr[maxChild] == 0){
                //cout << "[DEBUG]No value in this node index : " << maxChild << endl;
                return(parentIndex);
        }

        //cout << "[DEBUG]Calling FindMaximumChildIndex for : " << arr[maxChild] << endl;
        int temp = FindMaximumChildIndex(maxChild);//left
        //cout << "[DEBUG]Calling FindMaximumChildIndex for : " << arr[(maxChild + 1)] << endl;
        if(arr[(maxChild + 1)] != 0){
                int temp2 = FindMaximumChildIndex(maxChild + 1);//right

                if(arr[temp2] > arr[maxChild]){
                        maxChild = temp2;
                }
        }

        if(arr[temp] > arr[maxChild]){
                //cout << "[DEBUG] : " << arr[maxChild] << ", is less than " << arr[temp] << endl;
                maxChild = temp;
        }
        if(arr[parentIndex] > arr[maxChild]){
                maxChild = parentIndex;
        }

        //cout << "[DEBUG]The maximum index of : " << arr[parentIndex] << " is " << arr[maxChild] << endl;
        return(maxChild);
}

void MaxMinHeap::BuildHeap(){
        //Implement using Bottom-Up approach
        bool swapped = true;//Used to continue heapifying until the heap is in the correct order
        while(swapped){
                swapped = false;
                //Start by comparing the last parent with its children
                for(int i = FindLastParentIndex(); i >= 1; i--){
                        int nodeType = floor(log2(i));//Cast the node type as an int so that we can compare using %
                        //If this is a min node then compare it with its minimum child
                        if((nodeType % 2) != 0){
                                //Node is a min node
                                //cout << "[DEBUG]Calling FindMinimumChildIndex for : " << arr[i] << endl;
                                int minChildInd = FindMinimumChildIndex(i);
                                if(arr[i] > arr[minChildInd]){
                                        swap(arr[i], arr[minChildInd]);
                                        swapped = true;//A swap has happened, so re-heapify to ensure no other changes need to be made
                                }
                                //cout << "The node containing " << arr[i] << " is a min node.\n";
                                //cout << "-Its min child is : " << arr[FindMinimumChildIndex(i)] << endl;
                        }
                        else{
                                //Node is a max node
                                //cout << "[DEBUG]Calling FindMaximumChildIndex for : " << arr[i] << endl;
                                int maxChildIndex = FindMaximumChildIndex(i);
                                if(arr[i] < arr[maxChildIndex]){
                                        swap(arr[i], arr[maxChildIndex]);
                                        swapped = true;//A swap has happened, so re-heapify to ensure no other changes need to be made
                                }
                                //cout << "The node containing " << arr[i] << " is a max node.\n";
                        }
                }
        }


        return;
}

void MaxMinHeap::Insert(int x){
        if(arr[1] == 0){
                arr[1] = x;
                length++;
                return;
        }
        else{
                arr[(length + 1)] = x;
                length++;

                BuildHeap();
                return;
        }
}

void MaxMinHeap::DeleteMin(){
        //Heap is empty
        if(arr[1] == 0){
                cout << "The MinMax Heap is already empty!\n";
                return;
        }
        //|H|=1
        else if(arr[2] == 0){
                //delete root
                arr[1] = 0;
                length--;
                return;
        }
        //|H|=2
        else if(arr[3] == 0){
                //replace root with its only child
                arr[2] = 0;
                length--;
                return;
        }
        //|H| = 3
        else if(arr[4] == 0){
                if(arr[2] > arr[3]){
                        swap(arr[2], arr[3]);
                        arr[3] = 0;
                        length--;
                        return;
                }
                else{
                        arr[3] = 0;
                        length--;
                        return;
                }
        }
        //|H| >= 3
        else{
                int r;
                int pS;
                int s = length;
                int x = length;
                //Find the root node to delete
                if(arr[2] < arr[3]){
                        r = 2;
                }
                else{
                        r = 3;
                }
                //Now find the next smallest element under r, which is s
                for(int i = length; i > 1; i--){
                        if(arr[s] > arr[i] && floor(i/4) == r){
                                s = i;
                        }
                }
                //Compare x with s
                if(x <= s){
                        arr[r] = arr[x];
                        arr[x] = 0;
                }
                else if(x > s){
                        arr[r] = arr[s];
                        arr[s] = arr[x];
                        arr[x] = 0;
                        length--;
                        BuildHeap();
                }
                return;
        }
}

void MaxMinHeap::DeleteMax(){
        //Heap is empty
        if(arr[1] == 0){
                cout << "The MinMax Heap is already empty!\n";
                return;
        }
        //|H|=1
        else if(arr[2] == 0){
                //delete root
                arr[1] = 0;
                length--;
                return;
        }
        //|H|=2
        else if(arr[3] == 0){
                //replace root with its only child
                swap(arr[1], arr[2]);
                arr[2] = 0;
                length--;
                return;
        }
        //|H| = 3
        else if(arr[4] == 0){
                if(arr[2] > arr[3]){
                        swap(arr[1], arr[2]);
                        swap(arr[2], arr[3]);
                        arr[3] = 0;
                        length--;
                        return;
                }
                else{
                        swap(arr[1], arr[3]);
                        arr[3] = 0;
                        length--;
                        return;
                }
        }
        //|H| >= 3
        else{
                int r;
                int pS;
                int s = length;
                int x = length;
                //Find the root node to delete
                r = 1;
                //Now find the next largest element under r, which is s
                for(int i = length; i > 1; i--){
                        if(arr[s] < arr[i] && floor(i/4) == r){
                                s = i;
                        }
                }
                //Compare x with s
                if(x >= s){
                        arr[r] = arr[x];
                        arr[x] = 0;
                }
                else if(x < s){
                        arr[r] = arr[s];
                        arr[s] = arr[x];
                        arr[x] = 0;
                        length--;
                        BuildHeap();
                }
                return;
        }
}

void MaxMinHeap::FindMin(){
        if(arr[1] == 0){
                cout << "The MaxMin heap is empty.\n";
        }
        else if(arr[2] == 0){
                cout << "Min value is: " << arr[1] << endl;
        }
        else if(arr[3] == 0){
                cout << "Min value is: " << arr[2] << endl;
        }
        else{
                //The min one of the two children of the root
                int temp = arr[2];

                if(temp < arr[3]){
                        cout << "Min value is: " << temp << endl;
                }
                else{
                        cout << "Min value is: " << arr[3] << endl;
                }
                return;
        }
}

void MaxMinHeap::FindMax(){
        if(arr[1] == 0){
                cout << "The MaxMin heap is empty.\n";
        }
        else{
                cout << "Max value is: " << arr[1] << endl;
        }

        return;
}

void MaxMinHeap::LevelOrder(){
        if(length == 0){
                cout << "The MinMax Heap is empty.\n";
        }
        //Print root

        for(int i = 1; i <= length; i++){
                cout << arr[i] << " ";
        }
        //TODO: Not sure if this is the format you want or not so I stuck with the above ^ format.
        //cout << arr[1] << endl;
        //int lvl=1;
        //for(int i = 1; i < length ; i++){
        //        if(i % 2 != 0){
        //                for(int j = 1; j <= lvl+1; j++){
        //                        cout << arr[i + j] << " ";
        //                }
        //                cout << endl;
        //        }
        //        lvl=lvl*lvl;
        //}

        return;
}
