/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 02
*
* Hash Table:
*       Building a hash table using our previously
*       designed linked list structure
*******************************************************************************/
#include "Hash.h"
#include <iostream>

using namespace std;

int tableSize;

Hash::Hash(int m){
        tableSize = m;
        hashKeys = new LinkedList[tableSize];

        for(int i = 0; i < tableSize; i++){
                hashKeys[i] = LinkedList();
                hashKeys[i].size = 0;
        }
}

//I am having trouble with destructors and can not
//get it to work for some reason
Hash::~Hash(){
        for(int i = 0; i < tableSize; i++){
                //delete hashKeys[i];
        }
}

void Hash::insert(int x){

        if(hashKeys[hash(x)].find(x) == nullptr){
                hashKeys[hash(x)].insert(x);
                //cout << "[DEBUG]Hashing '" << x << "' to the list at index : " << hash(x) << endl;

                cout << x << " is added to the hash table\n";
        }
        else{
                cout << x << " is duplicated, can't be added to the hash table\n";
        }

        return;
}

void Hash::Delete(int x){
        if(hashKeys[hash(x)].find(x) == nullptr){
                cout << x << " can't be found in the hash table.\n";
        }
        else{
                hashKeys[hash(x)].erase(x);
                cout << x << " is deleted from the hash table\n";
        }

        return;
}

void Hash::print(){
        for(int i = 0; i < tableSize; i++){
                cout << i << ": ";
                hashKeys[i].print();
        }

        return;
}
//Returns the key that the number 'x' should map to
int Hash::hash(int x){
        return (x % tableSize);
}

bool Hash::find(int x){
        if(hashKeys[hash(x)].find(x) != nullptr){
                return true;
        }
        else{
                return false;
        }
}
