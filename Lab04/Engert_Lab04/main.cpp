/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 04
*
* Binary search tree (BST) with tree traversals:
*       Building a binary search tree from an input data file, the tree contains
*       multiple min/max functions and traversals
*******************************************************************************/
#include "BST.h"
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
        BST* binarySearchTree = new BST();

        cout << "Populating the BST from '" << file << "'............\n";
        //Initilize the hashtables
        while(dataFile >> val){
                binarySearchTree->Insert(val);
        }
        dataFile.close();
        cout << "FINISHED populating the BST from '" << file << "'\n\n\n\n";
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
                                binarySearchTree->Insert(numToInsert);
                                break;

                        case 2 : binarySearchTree->DeleteMin(binarySearchTree->root);
                                break;

                        case 3 : binarySearchTree->DeleteMax(binarySearchTree->root);
                                break;

                        case 4 : cout << "Enter the number to be deleted:\n";
                                int numToDelete;
                                cin >> numToDelete;
                                binarySearchTree->Delete(numToDelete);
                                break;

                        case 5 : if(binarySearchTree->FindMin(binarySearchTree->root) == nullptr){
                                        cout << "The binary search tree is empty.\n";
                                }
                                else{
                                        cout << binarySearchTree->FindMin(binarySearchTree->root)->value << " is the smallest element\n";
                                }
                                break;

                        case 6 : if(binarySearchTree->FindMax(binarySearchTree->root) == nullptr){
                                        cout << "The binary search tree is empty.\n";
                                }
                                else{
                                        cout << binarySearchTree->FindMax(binarySearchTree->root)->value << " is the largest element\n";
                                }
                                break;

                        case 7 : binarySearchTree->Preorder(binarySearchTree->root);
                                break;

                        case 8 : binarySearchTree->Inorder(binarySearchTree->root);
                                break;

                        case 9 : binarySearchTree->Postorder(binarySearchTree->root);
                                break;

                        case 10 : isExit = true;
                                break;

                        default : cout << "Invalid choice, please choose between 1-10.\n";
                                break;
                }

        }
        cout << "Bye bye!\n";
        binarySearchTree = nullptr;
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
        cout << "4- Delete \n";
        cout << "5- FindMin \n";
        cout << "6- FindMax \n";
        cout << "7- Preorder \n";
        cout << "8- Inorder \n";
        cout << "9- Postorder \n";
        cout << "10- Exit \n";
}
