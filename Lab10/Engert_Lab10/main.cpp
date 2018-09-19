/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 10
*
* LeftistHeap and SkewHeap:
*       Building a LeftistHeap and SkewHeap based on tree implementation,
*       Heaps contain Insertion, Concate, DeleteMin, and multiple traversals
*******************************************************************************/
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include <iostream>
#include <fstream>

using namespace std;
void printChoices();


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;
        string file;

////////////////////Populate the hash table/////////////////
        file = "data.txt";
        ifstream dataFile;
        dataFile.open(file.c_str());

        int val;
        //dataFile >> val; -----trims the first value of the data file
        LeftistHeap* leftHeap = new LeftistHeap();
        SkewHeap* skewHeap = new SkewHeap();

        cout << "Populating the SkewHeap and LeftistHeap from '" << file << "'............\n";
        //Initilize the hashtables
        while(dataFile >> val){
                leftHeap->Insert(val);
                skewHeap->Insert(val);
        }
        dataFile.close();
        cout << "FINISHED populating the SkewHeap and LeftistHeap from '" << file << "'\n\n\n\n";
////////////////////////////////////////////////////////////


        //Run the loop until the user chooses to exit by entering '6'
        while(!isExit){
                printChoices();

                //Choose a funtion to call on the list
                cin >> choice;

                switch(choice){
                        case 1 : cout << "Enter the number to be inserted:\n";
                                int numToInsert;
                                cin >> numToInsert;
                                leftHeap->Insert(numToInsert);
                                skewHeap->Insert(numToInsert);
                                break;

                        case 2 : cout << "LeftistHeap : ";
                                leftHeap->DeleteMin();
                                cout << "\nSkewHeap : ";
                                skewHeap->DeleteMin();
                                cout << endl;
                                break;

                        case 3 : cout << "LeftistHeap Preorder : ";
                                leftHeap->Preorder(leftHeap->GetRoot());
                                cout << "\nSkewHeap Preorder : ";
                                skewHeap->Preorder(skewHeap->GetRoot());
                                cout << endl;
                                break;

                        case 4 : cout << "LeftistHeap Inorder : ";
                                leftHeap->Inorder(leftHeap->GetRoot());
                                cout << "\nSkewHeap Inorder : ";
                                skewHeap->Inorder(skewHeap->GetRoot());
                                cout << endl;
                                break;

                        case 5 : cout << "LeftistHeap Levelorder : ";
                                leftHeap->Levelorder();
                                cout << "\nSkewHeap Levelorder : ";
                                skewHeap->Levelorder();
                                cout << endl;
                                break;

                        case 6 : isExit = true;
                                break;

                        default : cout << "Invalid choice, please choose between 1-6.\n";
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
        cout << "1- Insert \n";
        cout << "2- DeleteMin \n";
        cout << "3- Preorder \n";
        cout << "4- Inorder \n";
        cout << "5- Levelorder \n";
        cout << "6- Exit \n";
}
