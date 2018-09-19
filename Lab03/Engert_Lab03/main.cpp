/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 03
*
* Hash Tables with Quadratic Probing and Double Hashing:
*       Building two different hash tables, one using Quadratic Probing as
*       collision detection and the other using Double Hashing as collision detection
*******************************************************************************/
#include "QuadraticHash.h"
#include "DoubleHash.h"
#include <iostream>
#include <fstream>

using namespace std;
void printChoices();


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;
        int fileChoice;
        int buckets = 53;
        string file;

        cout << "Select which data file to load, 1-5.\n";
        cin >> fileChoice;
        switch(fileChoice){
                case 1 : file = "data1.txt";
                        break;
                case 2 : file = "data2.txt";
                        break;
                case 3 : file = "data3.txt";
                        break;
                case 4 : file = "data4.txt";
                        break;
                case 5 : file = "data5.txt";
                        break;
                default : cout << "Chosen file could not be loaded, exiting...\n";
                        exit(0);
                        break;
        }

////////////////////Populate the hash table/////////////////
        ifstream dataFile;
        dataFile.open(file.c_str());

        int val;
        //dataFile >> val;
        QuadraticHash* quadraticHashTable = new QuadraticHash(buckets);
        DoubleHash* doubleHashTable = new DoubleHash(buckets);

        cout << "Populating the hash table from '" << file << "'............\n";
        //Initilize the hashtables
        while(dataFile >> val){
                quadraticHashTable->Insert(val);
                doubleHashTable->Insert(val);
        }
        dataFile.close();
        cout << "Load factor of hash table with quadratic probing is " << quadraticHashTable->LoadFactor(buckets) << ".\n";
        cout << "Load factor of hash table with quadratic probing is " << doubleHashTable->LoadFactor(buckets) << ".\n";
        cout << "FINISHED populating hash table from '" << file << "'\n\n\n\n";
////////////////////////////////////////////////////////////


        //Run the loop until the user chooses to exit by entering '5'
        while(!isExit){
                printChoices();

                //Choose a funtion to call on the list
                cin >> choice;

                switch(choice){
                        case 1 : cout << "Enter a number to be inserted:\n";
                                int numToInsert;
                                cin >> numToInsert;
                                quadraticHashTable->Insert(numToInsert);
                                cout << "Load factor of hash table with quadratic probing is " << quadraticHashTable->LoadFactor(buckets) << ".\n";
                                doubleHashTable->Insert(numToInsert);
                                cout << "Load factor of hash table with double hashing is " << doubleHashTable->LoadFactor(buckets) << ".\n";

                                break;
                        case 2 : cout << "Enter a number to delete:\n";
                                int numToDelete;
                                cin >> numToDelete;
                                quadraticHashTable->Remove(numToDelete);
                                cout << "Load factor of hash table with quadratic probing is " << quadraticHashTable->LoadFactor(buckets) << ".\n";
                                doubleHashTable->Remove(numToDelete);
                                cout << "Load factor of hash table with double hashing is " << doubleHashTable->LoadFactor(buckets) << ".\n";

                                break;
                        case 3 : cout << "Enter a number to be found:\n";
                                int numToFind;
                                cin >> numToFind;
                                if(quadraticHashTable->Find(numToFind)){
                                        cout << numToFind << " exists in the hash table with quadratic hashing\n";
                                }
                                else{
                                        cout << numToFind << " does not exist in the hash table with quadratic hashing\n";
                                }

                                if(doubleHashTable->Find(numToFind)){
                                        cout << numToFind << " exists in the hash table with double hashing\n";
                                }
                                else{
                                        cout << numToFind << " does not exist in the hash table with double hashing\n";
                                }

                                break;
                        case 4 : cout << "\n";
                                quadraticHashTable->Print();
                                doubleHashTable->Print();
                                break;
                        case 5 : isExit = true;
                                break;
                        default : cout << "Invalid choice, please choose between 1-5.\n";
                                break;
                }

        }
        cout << "Bye bye!\n";
        //end main
}

//Simple print to keep main clean
void printChoices(){
        cout << "\n";
        cout << "*********************************************\n";
        cout << "Please choose one of the following commands: \n";
        cout << "1- Insert \n";
        cout << "2- Delete \n";
        cout << "3- Find \n";
        cout << "4- Print \n";
        cout << "5- Exit \n";
}
