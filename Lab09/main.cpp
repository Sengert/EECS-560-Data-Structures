/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* Experimental profiling on hash tables
*       Timing different functions on open hash tables, double hash tables,
*       and quadratic hash tables.
*******************************************************************************/
#include "MaxHeap.h"
#include "MinHeap.h"
#include "BST.h"
#include "DataTimer.h"
#include <iostream>
#include <fstream>

using namespace std;
void printChoices();


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;

        DataTimer* timer = new DataTimer(10000000);

        //Run the loop until the user chooses to exit by entering '3'
        while(!isExit){
                printChoices();

                //Choose a funtion to call on the list
                cin >> choice;

                switch(choice){
                        case 1 : //cout << "What is the table size?\n";
                                 //cin >> sizeOfTable;
                                //populateTables(sizeOfTable, 4, 5);
                                break;

                        case 2 : timer->TablePerformance();
                                break;

                        case 3 : isExit = true;
                                break;

                        default : cout << "Invalid choice, please choose between 1-3.\n";
                                break;
                }

        }
        cout << "Bye bye!\n";
        //end main
}


//Simple print to keep main clean
void printChoices(){
        cout << "\n";
        cout << "*************************************************************************\n";
        cout << "Please choose one of the following commands: \n";
        cout << "1- [DEBUGGING] \n";
        cout << "2- Performance Comparison \n";
        cout << "3- Exit \n";
}
