/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 05
*
* Two-Three Trees with level order print:
*       Building a 2-3 tree from an input data file, the tree contains
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/
#include "TwoThreeTree.h"
#include "LevelOrderQueue.h"
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
        TwoThreeTree* tree = new TwoThreeTree();

        cout << "Populating the 2-3 Tree from '" << file << "'............\n";
        //Initilize the hashtables
        while(dataFile >> val){
                tree->Insert(val);
        }
        dataFile.close();
        cout << "FINISHED populating the 2-3 Tree from '" << file << "'\n\n\n\n";
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
                                tree->Insert(numToInsert);
                                break;

                        case 2 : tree->DeleteMin();
                                break;

                        case 3 : tree->DeleteMax();
                                break;

                        case 4 : if(tree->FindMin(tree->root) != nullptr){
                                        cout << "The minimum value is : " << tree->FindMin(tree->root)->getValue() << endl;
                                }
                                else{
                                        cout << "The tree is empty.\n";
                                }
                                break;

                        case 5 : if(tree->FindMax(tree->root) != nullptr){
                                cout << "The maximum value is : " << tree->FindMax(tree->root)->getValue() << endl;
                                }
                                else{
                                                cout << "The tree is empty.\n";
                                }
                                break;

                        case 6 : cout << "Enter a number to find:\n";
                                int numToFind;
                                cin >> numToFind;

                                if(tree->Find(numToFind) == nullptr){
                                        cout << numToFind << " does not exist in the tree.\n";
                                }
                                else{
                                        cout << numToFind << " exists in the tree.\n";
                                }
                                break;

                        case 7 : cout << "Enter the number to be deleted:\n";
                                int numToDelete;
                                cin >> numToDelete;
                                tree->Delete(numToDelete);
                                break;

                        case 8 : tree->LevelOrder();
                                break;

                        case 9 : isExit = true;
                                break;


                        default : cout << "Invalid choice, please choose between 1-9.\n";
                                break;
                }

        }
        cout << "Bye bye!\n";

        delete tree;
        tree = nullptr;
        //end main
}

//Simple print to keep main clean
void printChoices(){
        cout << "\n";
        cout << "*************************************************************************\n";
        cout << "Please choose one of the following commands: \n";
        cout << "1- Insert \n";
        cout << "2- DeleteMin \n";
        cout << "3- DeleteMax \n";
        cout << "4- FindMin \n";
        cout << "5- FindMax \n";
        cout << "6- Find \n";
        cout << "7- Delete \n";
        cout << "8- Level order\n";
        cout << "9- Exit \n";
}
