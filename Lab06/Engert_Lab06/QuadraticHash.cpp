/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* Quadratic Hash Table:
*       Building a hash table using Quadratic Probing as collision detection
*
*******************************************************************************/
#include "QuadraticHash.h"
#include <iostream>

using namespace std;


QuadraticHash::QuadraticHash(int m, int initK){
        //flags for deletion
        k = initK;
        tableSize = m;
        buckets = new int[tableSize];
        wasOccupied = new bool[tableSize];

        for(int i = 0; i < m ; i++){
                //Using -1 to define an empty bucket in the hash table this will
                //work as long as the data files do not contain negative integers
                buckets[i] = -1;
                wasOccupied[i] = 0;
        }
}


QuadraticHash::~QuadraticHash(){
        delete buckets;
        delete wasOccupied;
}

void QuadraticHash::Insert(int x){
        int initHash = x % tableSize;
        //There is no collision for the integer to be inserted into the hash table
        if(buckets[initHash] == -1){
                buckets[initHash] = x;
                wasOccupied[initHash] = 1;
                return;
        }
        //Collision detected perform double hashing to find a new open spot
        else{
                for(int i = 0; i < k; i++){
                        if(buckets[Hash(x, i) == x]){
                                //cout << x << " is already in the quadratic hash table.\n";
                                return;
                        }
                        if(buckets[Hash(x, i)] == -1){
                                //Found an empty bucket insert the element
                                buckets[Hash(x, i)] = x;
                                wasOccupied[Hash(x, i)] = 1;//wasOccupied[i] = 1;
                                return;
                        }
                }
        }
        return;
}

void QuadraticHash::Remove(int x){
        if(!Find(x)){
                cout << x << " does not exist in the hash table with quadratic hashing\n";
        }
        else{
                for(int i = 0; i < k; i++){
                        if(buckets[Hash(x, i)] == x){
                                buckets[Hash(x, i)] = -1;
                                cout << "Successfully deleted " << x << " from the hash table with quadratic probing\n";
                        }
                }
        }
        return;
}

//Prints only the buckets that contain an element
void QuadraticHash::Print(){
        //cout << "Hash table with quadratic probing:\n";
        for(int i = 0; i < tableSize; i++){
                if(buckets[i] != -1){
                        cout << i << ": " << buckets[i] << endl;
                }
        }
        return;
}
//Returns the key that the number 'x' should map to
int QuadraticHash::Hash(int x, int iteration){
        //h_i(x) = (h(x) + f_i) % m
        //h(x) = x mod m
        //f_i = i^2
        return(((x % tableSize) + (iteration * iteration)) % tableSize);
}

bool QuadraticHash::Find(int x){

        int initHash = x % tableSize;
        if(buckets[initHash] == x){
                 return(true);
        }
        else if(buckets[initHash] == -1 && wasOccupied[initHash] == 0){
                return(false);
        }
        else{
                for(int i = 1; i < tableSize; i++){
                        if(buckets[Hash(x, i)] == x){
                                return(true);
                        }
                }
        }
        return(false);
}

double QuadraticHash::LoadFactor(int n){
        //Load factor = n/k, n is number of elements in the hash table, k is the number of buckets
        int k = 0;
        for(int i = 0; i < tableSize; i++){
                if(buckets[i] != -1){
                        k++;
                }
        }
        return((double)k/n);
}
