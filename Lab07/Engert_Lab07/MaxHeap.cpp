/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 07
*
* Min-5 heap and Max-5 heap:
*       Building a min and max - 5 heaps based on array implementation,
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/

#include "MaxHeap.h"
#include <cmath>
#include <algorithm>

using namespace std;

MaxHeap::MaxHeap(int* array, int arraySize){
        cout << endl;
        cout << "[DEBUG]A new MaxHeap has been created.\n";
        arr = array;
        //Initilize length
        length = 0;
        for(int i = 0; i < arraySize; i++){
                if(arr[i] != 0){
                        length++;
                }
                else{
                        cout << "Max heap length is : " << length << endl;
                        for(int j = 0; j < length; j++){
                                cout << arr[j] << " ";
                        }
                        cout << endl;
                        cout << endl;
                        return;
                }
        }

        return;
}

MaxHeap::~MaxHeap(){
        //Destructor
        //delete arr;
        //arr = nullptr;
        return;
}

//returns the index of the last parent
int MaxHeap::FindLastParentIndex(){
        //(length-1) is the last leaf in the heap
        if(arr[0] != 0){
                return(floor(((length-1)-1)/5));
        }
        else{
                return(0);
        }
}

//returns the index of the minimum child of a given parent
int MaxHeap::FindMaximumChildIndex(int parentIndex){
        //Initilize as the first child
        int maxChild = ((parentIndex*5)+1);

        //Now compare the first child with the rest of the children
        for(int j = 2; j <= 5; j++){
                if(arr[((parentIndex*5)+j)] == 0){
                        return(maxChild);//The next leaf does not exist
                }
                if(arr[maxChild] < arr[((parentIndex*5)+j)]){
                        //The next child is larger
                        maxChild = ((parentIndex*5)+j);
                }
        }

        return(maxChild);
}

void MaxHeap::BuildHeap(){
        bool swapped = true;//Used to continue heapifying until the heap is in the correct order
        while(swapped){
                swapped = false;
                //Use bottom up approach
                //Start by comparing the last parent using FindLastParent(), with its children.
                for(int i = FindLastParentIndex(); i >= 0; i--){
                        //Compare the parent with its smallest child, if it is smaller
                        //then swap it with that child
                        int maxChildInd = FindMaximumChildIndex(i);
                        if(arr[i] < arr[maxChildInd]){
                                //cout << "[DEBUG]BuildHeap()--->SWAP\n";
                                swap(arr[i], arr[maxChildInd]);
                                swapped = true;//A swap has happened, so re-heapify to ensure no other changes need to be made
                        }
                }
        }

        return;
}

void MaxHeap::Insert(int x){
        //Add the value at the end of the array, or as a the last leaf in the heap
        arr[length] = x;
        length++;
        //Heapify the heap if needed
        BuildHeap();

        return;
}

void MaxHeap::DeleteMin(){
        if(arr[0] == 0){
                cout << "The min heap is already empty.\n";
                return;
        }

        //Start a linear search from the last leaf, A[floor((last used index in array - 1)/5) + 1]
        int minValueIndex = floor(((length - 2)/5) + 1);
        for(int i = floor(((length - 2)/5) + 1); i < length; i++){
                if(arr[minValueIndex] > arr[i]){
                        minValueIndex = i;//Found a new max value
                }
        }
        //Move the maximum value to the end of the array and replace it with the
        //old end of the array.
        swap(arr[minValueIndex], arr[length - 1]);
        arr[length - 1] = 0;
        length--;

        //Now heapify if needed.
        BuildHeap();
        return;
}

void MaxHeap::DeleteMax(){
        if(arr[0] == 0){
                cout << "The max heap is already empty.\n";
                return;
        }

        arr[0] = arr[(length - 1)];//Overwrite the root with the last leaf value
        arr[(length - 1)] = 0;//"Delete" the last leaf
        length--;

        //Now heapify if needed.
        BuildHeap();
        return;
}

void MaxHeap::FindMin(){
        if(arr[0] == 0){
                cout << "The max heap is empty.\n";
        }
        //Start a linear search from the last leaf, A[floor((last used index in array - 1)/5) + 1]
        int j = floor(((length -2)/5)+1);
        int minValue = arr[j];

        for(int i = floor(((length - 2)/5) + 1); i < length; i++){
                if(arr[i] < minValue){
                        minValue = arr[i];//Found a new min value
                }
        }
        //Finished checking all the leaves
        cout << "Min value: " << minValue << endl;//Print the min value

        return;
}

void MaxHeap::FindMax(){
        if(arr[0] == 0){
                cout << "The max heap is empty.\n";
        }
        else{
                cout << "Max value: " << arr[0] << endl;
        }

        return;
}

//Prints all the children under parent at index x
void MaxHeap::PrintChildren(int x){
        for(int j = 1; j <= 5; j++){
                if(arr[((5*x)+j)] == 0){
                        return;
                }
                cout << arr[((5*x)+j)] << " ";
        }
}


void MaxHeap::LevelOrder(){
        if(length == 0){
                cout << "The Min Heap is empty.\n";
                return;
        }
        //Print root
        cout << arr[0] << endl;
        PrintChildren(0);
        cout << endl;

        for(int i = 1; i <= FindLastParentIndex(); i++){
                PrintChildren(i);
                if(i != FindLastParentIndex()){
                        cout << " - ";
                }
                else{
                        cout << endl;
                }
        }

        return;
}
