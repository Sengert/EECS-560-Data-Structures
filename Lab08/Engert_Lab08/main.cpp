/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 08
*
* MinMaxHeap and MaxMinHeap:
*       Building a MinMaxHeap and MaxMinHeap based on array implementation,
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/
#include "MinMaxHeap.h"
#include "MaxMinHeap.h"
#include <iostream>
#include <fstream>

using namespace std;
void printChoices();


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;
        string file;

        //Initialized when the program is ran with commands
        string whichHeap = argv[1];
        cout << "[DEBUG] " << whichHeap << endl;



        //Arrays for the min heap and max heap
        int minMaxHeapArray[500];
        int maxMinHeapArray[500];
        for(int i = 0; i < 500; i++){
                minMaxHeapArray[i] = 0;
                maxMinHeapArray[i] = 0;
        }

        //Root starts at A[1] for MinMaxHeaps
        int fileIterator = 1;


////////////////////Populate the MinMax Heap/////////////////
                file = "data.txt";
                ifstream dataFile;
                dataFile.open(file.c_str());

                int val;

                cout << "Populating MinMax Heap from '" << file << "'............\n";
                //Initilize the heap arrays
                while(dataFile >> val){
                        minMaxHeapArray[fileIterator] = val;
                        fileIterator++;
                }
                dataFile.close();

                MinMaxHeap* minMaxHeap = new MinMaxHeap(minMaxHeapArray, 500);
                //Build/adjust the arrays
                minMaxHeap->BuildHeap();
                cout << "FINISHED populating the MinMax Heap from '" << file << "'\n\n\n\n";
////////////////////////////////////////////////////////////

////////////////////Populate the MaxMin Heap/////////////////

                MaxMinHeap* maxMinHeap = new MaxMinHeap(maxMinHeapArray, 500);

                file = "data.txt";
                ifstream dataFileTwo;
                dataFileTwo.open(file.c_str());

                cout << "Populating MinMax Heap from '" << file << "'............\n";
                //Initilize the heap arrays
                while(dataFileTwo >> val){
                        maxMinHeap->Insert(val);
                }
                dataFile.close();

                cout << "FINISHED populating the MaxMin Heap from '" << file << "'\n\n\n\n";
////////////////////////////////////////////////////////////

        //Run the loop until the user chooses to exit by entering '5'
        while(!isExit){
                printChoices();

                //Choose a funtion to call on the list
                cin >> choice;

                switch(choice){
                        case 1 : cout << "Enter the number to be inserted:\n";
                                int numToInsert;
                                cin >> numToInsert;
                                if(whichHeap == "minmax"){
                                        minMaxHeap->Insert(numToInsert);
                                }
                                else{
                                        maxMinHeap->Insert(numToInsert);
                                }
                                break;

                        case 2 : if(whichHeap == "minmax"){
                                        minMaxHeap->DeleteMin();
                                }
                                else{
                                        maxMinHeap->DeleteMin();
                                }
                                break;

                        case 3 : if(whichHeap == "minmax"){
                                        minMaxHeap->FindMin();
                                }
                                else{
                                        maxMinHeap->FindMin();
                                }
                                break;

                        case 4 : if(whichHeap == "minmax"){
                                        minMaxHeap->FindMax();
                                }
                                else{
                                        maxMinHeap->FindMax();
                                }
                                break;

                        case 5 : if(whichHeap == "minmax"){
                                        minMaxHeap->DeleteMax();
                                }
                                else{
                                        maxMinHeap->DeleteMax();
                                }
                                break;

                        case 6 : if(whichHeap == "minmax"){
                                        minMaxHeap->LevelOrder();
                                }
                                else{
                                        maxMinHeap->LevelOrder();
                                }
                                break;

                        case 7 : isExit = true;
                                break;

                        case 9 : //Case used for debugging
                                //cout << "The last parent index is : " << minMaxHeap->FindLastParentIndex() << endl;
                                minMaxHeap->BuildHeap();
                                break;

                        default : cout << "Invalid choice, please choose between 1-9.\n";
                                break;
                }

        }
        cout << "Bye bye!\n";
        delete minMaxHeap;
        //delete maxHeap;

        minMaxHeap = nullptr;
        //maxHeap = nullptr;
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
}
