/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* Double Hash Table:
*       Building a hash table using Double Hashing as collision detection
*
*******************************************************************************/
#include "DoubleHash.h"
#include <iostream>

using namespace std;


DoubleHash::DoubleHash(int m, int initK, int initP){
        //flags for deletion
        k = initK;
        p = initP;
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


DoubleHash::~DoubleHash(){
        delete buckets;
        delete wasOccupied;
}

void DoubleHash::Insert(int x){
        int initHash = x % tableSize;
        //There is no collision for the integer to be inserted into the hash table
        if(buckets[initHash] == -1){
                buckets[initHash] = x;
                wasOccupied[initHash] = 1;
                return;
        }
        //Collision detected perform double hashing to find a new open spot
        else{
                //For this lab k = 10, so run i < 10-1
                for(int i = 0; i < k; i++){
                        if(buckets[Hash(x, i)] == x){
                                //cout << x << " is already in the double hash table.\n";
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

void DoubleHash::Remove(int x){
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


void DoubleHash::Print(){
        //cout << "Hash table with double hashing:\n";
        for(int i = 0; i < tableSize; i++){
                if(buckets[i] != -1){
                        cout << i << ": " << buckets[i] << endl;
                }
        }
        return;
}
//Returns the key that the number 'x' should map to
int DoubleHash::Hash(int x, int iteration){
        //h_i(x) = (h(x) + f_i) % m
        //h(x) = x mod m
        //f_i = i * p-(x % p)
        //int p = 5;//For testing p = 5
        return((x % tableSize) + (iteration * (p - ( x % p))) % tableSize);
}

bool DoubleHash::Find(int x){
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

double DoubleHash::LoadFactor(int n){
        //Load factor = n/k, n is number of elements in the hash table, k is the number of buckets
        int k = 0;
        for(int i = 0; i < tableSize; i++){
                if(buckets[i] != -1){
                        k++;
                }
        }
        return((double)k/n);
}
