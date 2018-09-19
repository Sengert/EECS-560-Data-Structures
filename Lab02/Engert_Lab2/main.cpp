/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 02
*
* Hash Table:
*       Building a hash table using our previously
*       designed linked list structure
*******************************************************************************/
#include "LinkedList.h"
#include "Hash.h"
#include <fstream>

using namespace std;
void printChoices();


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;

////////////////////Populate the hash table/////////////////
        string file = "data.txt";
        ifstream dataFile;
        dataFile.open(file.c_str());

        int val;
        dataFile >> val;
        Hash* hashtable = new Hash(val);

        cout << "Populating the hash table from '" << file << "'............\n";
        //Initilize the hashtable
        while(dataFile >> val){
                hashtable->insert(val);
        }
        dataFile.close();
        cout << "FINISHED populating hash table from '" << file << "'\n\n\n\n\n\n\n\n\n\n";
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
                                hashtable->insert(numToInsert);

                                break;
                        case 2 : cout << "Enter a number to delete:\n";
                                int numToDelete;
                                cin >> numToDelete;
                                hashtable->Delete(numToDelete);

                                break;
                        case 3 : cout << "Enter a number to be found:\n";
                                int numToFind;
                                cin >> numToFind;
                                if(hashtable->find(numToFind)){
                                        cout << "Found " << numToFind << " in the hash table!\n";
                                }
                                else{
                                        cout << numToFind << " can't be found in the hash table.\n";
                                }

                                break;
                        case 4 : cout << "\n";
                                hashtable->print();
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
