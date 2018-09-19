/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 07
*
* Min-5 heap and Max-5 heap:
*       Building a min and max - 5 heaps based on array implementation,
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/
#include "MinHeap.h"
#include "MaxHeap.h"
#include <iostream>
#include <fstream>

using namespace std;
void printChoices();


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;
        string file;
        //Arrays for the min heap and max heap
        int minHeapArray[500];
        int maxHeapArray[500];
        for(int i = 0; i < 500; i++){
                minHeapArray[i] = 0;
                maxHeapArray[i] = 0;
        }

        int fileIterator = 0;


////////////////////Populate the hash table/////////////////
        file = "data.txt";
        ifstream dataFile;
        dataFile.open(file.c_str());

        int val;
        //dataFile >> val; -----trims the first value of the data file


        cout << "Populating heaps from '" << file << "'............\n";
        //Initilize the heap arrays
        while(dataFile >> val){
                minHeapArray[fileIterator] = val;
                maxHeapArray[fileIterator] = val;
                fileIterator++;
        }
        dataFile.close();

        MinHeap* minHeap = new MinHeap(minHeapArray, 500);
        MaxHeap* maxHeap = new MaxHeap(maxHeapArray, 500);
        //Build/adjust the arrays
        minHeap->BuildHeap();
        maxHeap->BuildHeap();

        cout << "FINISHED populating the heaps from '" << file << "'\n\n\n\n";
////////////////////////////////////////////////////////////
        int whichHeap;
        cout << "Select which heap you would like to use. (1 for min heap, 2 for max heap)\n";
        cin >> whichHeap;

        //Which heap to call functions on
        while(whichHeap != 1 && whichHeap != 2){
                cout << "Invalid selection, please enter 1 or 2.\n";
                cin >> whichHeap;
        }
        //Run the loop until the user chooses to exit by entering '5'
        while(!isExit){
                printChoices();

                //Choose a funtion to call on the list
                cin >> choice;

                switch(choice){
                        case 1 : cout << "Enter the number to be inserted:\n";
                                int numToInsert;
                                cin >> numToInsert;
                                if(whichHeap == 1){
                                        minHeap->Insert(numToInsert);
                                }
                                else{
                                        maxHeap->Insert(numToInsert);
                                }
                                break;

                        case 2 : if(whichHeap == 1){
                                        minHeap->DeleteMin();
                                }
                                else{
                                        maxHeap->DeleteMin();
                                }
                                break;

                        case 3 : if(whichHeap == 1){
                                        minHeap->FindMin();
                                }
                                else{
                                        maxHeap->FindMin();
                                }
                                break;

                        case 4 : if(whichHeap == 1){
                                        minHeap->FindMax();
                                }
                                else{
                                        maxHeap->FindMax();
                                }
                                break;

                        case 5 : if(whichHeap == 1){
                                        minHeap->DeleteMax();
                                }
                                else{
                                        maxHeap->DeleteMax();
                                }
                                break;

                        case 6 : if(whichHeap == 1){
                                        minHeap->LevelOrder();
                                }
                                else{
                                        maxHeap->LevelOrder();
                                }
                                break;

                        case 7 : isExit = true;
                                break;

                        case 8 : cout << "Select which heap you would like to use. (1 for min heap, 2 for max heap)\n";
                                cin >> whichHeap;
                                while(whichHeap != 1 && whichHeap != 2){
                                        cout << "Invalid selection, please enter 1 or 2.\n";
                                        cin >> whichHeap;
                                }
                                break;

                        default : cout << "Invalid choice, please choose between 1-9.\n";
                                break;
                }

        }
        cout << "Bye bye!\n";
        delete minHeap;
        delete maxHeap;

        minHeap = nullptr;
        maxHeap = nullptr;
        //end main
}

//Simple print to keep main clean
void printChoices(){
        cout << "\n";
        cout << "*************************************************************************\n";
        cout << "Please choose one of the following commands: \n";
        cout << "1- Insert \n";
        cout << "2- DeleteMin \n";
        cout << "3- FindMin\n";
        cout << "4- FindMax \n";
        cout << "5- DeleteMax \n";
        cout << "6- LevelOrder \n";
        cout << "7- Exit\n";
        cout << "8- Switch heaps\n";
}
