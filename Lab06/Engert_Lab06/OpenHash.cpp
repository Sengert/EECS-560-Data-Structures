/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* Hash Table:
*       Building a hash table using our previously
*       designed linked list structure
*******************************************************************************/
#include "OpenHash.h"
#include <iostream>

using namespace std;


OpenHash::OpenHash(int m){
        tableSize = m;
        hashKeys = new LinkedList*[tableSize];

        for(int i = 0; i < tableSize; i++){
                temp = new LinkedList();
                hashKeys[i] = temp;
        }
}

//I am having trouble with destructors and can not
//get it to work for some reason
OpenHash::~OpenHash(){
        for(int i = 0; i < tableSize; i++){
                //delete hashKeys[i];
        }
}

void OpenHash::insert(int x){

        if(hashKeys[hash(x)]->find(x) == nullptr){
                hashKeys[hash(x)]->insert(x);

                //cout << x << " is added to the hash table\n";
        }
//        else{
//                cout << x << " is duplicated, can't be added to the hash table\n";
//        }

        return;
}

void OpenHash::Delete(int x){
        if(hashKeys[hash(x)]->find(x) == nullptr){
                cout << x << " can't be found in the hash table.\n";
        }
        else{
                hashKeys[hash(x)]->erase(x);
                cout << x << " is deleted from the hash table\n";
        }

        return;
}

void OpenHash::print(){
        for(int i = 0; i < tableSize; i++){
                if(!hashKeys[i]->isEmpty()){
                        cout << i << ": ";
                        hashKeys[i]->print();
                }
        }

        return;
}
//Returns the key that the number 'x' should map to
int OpenHash::hash(int x){
        return (x % tableSize);
}

bool OpenHash::find(int x){
        if(hashKeys[hash(x)]->find(x) != nullptr){
                return true;
        }
        else{
                return false;
        }
}
