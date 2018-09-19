/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* Experimental profiling on hash tables
*       Timing different functions on open hash tables, double hash tables,
*       and quadratic hash tables.
*******************************************************************************/
#include "LinkedList.h"
#include "OpenHash.h"
#include "DoubleHash.h"
#include "QuadraticHash.h"
#include "HashTimer.h"
#include <iostream>
#include <fstream>

using namespace std;
void printChoices();
void populateTables(int tableSize, int k, int p);
string file;


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;
        int sizeOfTable;
        int m = 1000003;
        int k = 20;
        int p = 997;


        HashTimer* timer = new HashTimer(m, k, p);

        //Run the loop until the user chooses to exit by entering '3'
        while(!isExit){
                printChoices();

                //Choose a funtion to call on the list
                cin >> choice;

                switch(choice){
                        case 1 : cout << "What is the table size?\n";
                                 cin >> sizeOfTable;
                                populateTables(sizeOfTable, 4, 5);
                                break;

                        case 2 : timer->TablePerformance();
                                break;

                        case 3 : isExit = true;
                                break;

                        default : cout << "Invalid choice, please choose between 1-9.\n";
                                break;
                }

        }
        cout << "Bye bye!\n";
        //end main
}

void populateTables(int tableSize, int k, int p){
        OpenHash* oh = new OpenHash(tableSize);
        DoubleHash* dh = new DoubleHash(tableSize, k, p);
        QuadraticHash* qh = new QuadraticHash(tableSize, k);

        ////////////////////Populate the hash table/////////////////
                file = "data.txt";
                ifstream dataFile;
                dataFile.open(file.c_str());

                int val;
                //dataFile >> val; -----trims the first value of the data file

                cout << "Populating the hash tables from '" << file << "'............\n";
                //Initilize the hashtables
                while(dataFile >> val){
                        oh->insert(val);
                        dh->Insert(val);
                        qh->Insert(val);
                }
                dataFile.close();
                cout << "FINISHED populating the hash tables from '" << file << "'\n\n\n\n";
        ////////////////////////////////////////////////////////////

        cout << "Open Hashing:\n";
        oh->print();
        cout << endl;

        cout << "Hash Table with Quadratic Probing:\n";
        qh->Print();
        cout << endl;

        cout << "Hash Table with Double Hashing:\n";
        dh->Print();
        cout << endl;
}

//Simple print to keep main clean
void printChoices(){
        cout << "\n";
        cout << "*************************************************************************\n";
        cout << "Please choose one of the following commands: \n";
        cout << "1- Test HashTables \n";
        cout << "2- Performance Comparison \n";
        cout << "3- Exit \n";
}
