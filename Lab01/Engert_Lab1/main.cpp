/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 01
*
* Singly Linked List:
*       To review pointers and recursion in C++
*
*******************************************************************************/
#include "List.h"
#include <fstream>

using namespace std;
void printChoices();
void populateList(List*);


int main(int argc, char** argv) {
        bool isExit = false;
        int choice;

        List* list = new List();

        populateList(list);
        cout << "data.txt elements : ";
        list->print();


        //Run the loop until the user chooses to exit by entering '5'
        while(!isExit){
                printChoices();

                //Choose a funtion to call on the list
                cin >> choice;
                //choice = 5;
                switch(choice){
                        case 1 : cout << "Enter a number to be inserted into the list:\n";
                                int numToInsert;
                                cin >> numToInsert;
                                try{
                                        list->insert(numToInsert);
                                }
                                catch(invalid_argument& e){
                                        cout << "Invalid input.\n";
                                        continue;
                                }
                                break;
                        case 2 : cout << "Enter a number to be deleted from the list:\n";
                                int numToErase;
                                cin >> numToErase;
                                try{
                                        list->erase(numToErase);
                                }
                                catch(invalid_argument& e){
                                        cout << "Invalid input.\n";
                                        continue;
                                }
                                break;
                        case 3 : cout << "Enter a number to be found:\n";
                                int numToFind;
                                cin >> numToFind;
                                try{
                                        if(list->find(numToFind) == nullptr){
                                                cout << "Entered number does not exist in the list.\n";
                                        }
                                        else{
                                                cout << "Entered number exists in the list.\n";
                                        }
                                }
                                catch(invalid_argument& e){
                                        cout << "Invalid input.\n";
                                        continue;
                                }

                                break;
                        case 4 : cout << "List: ";
                                list->print();
                                break;
                        case 5 : isExit = true;
                                break;
                        default : cout << "Invalid choice, please choose between 1-5.\n";
                                break;
                }

        }
        cout << "Exiting...\n";
        //end main
}
//Function used to build the Linked List from the data.txt file
void populateList(List* l){
        string file = "data.txt";
        ifstream dataFile;

        dataFile.open(file.c_str());

        int val;
        while(dataFile >> val){
                l->insert(val);
        }
        dataFile.close();
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
