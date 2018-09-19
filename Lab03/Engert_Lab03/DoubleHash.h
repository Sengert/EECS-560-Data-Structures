/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 03
*
* Double Hash Table:
*       Building a hash table using Double Hashing as collision detection
*
*******************************************************************************/
#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H


class DoubleHash{
public:
        DoubleHash(int m);
        ~DoubleHash();

        void Insert(int x);
        void Remove(int x);
        void Print();
        int Hash(int x, int iteration);
        bool Find(int x);
        double LoadFactor(int n);

private:
        int tableSize;
        int* buckets;
        bool* wasOccupied;


};

#endif
