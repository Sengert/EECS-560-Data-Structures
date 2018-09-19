/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 03
*
* Quadratic Hash Table:
*       Building a hash table using Quadratic Probing as collision detection
*
*******************************************************************************/
#ifndef QUADRATICHASH_H
#define QUADRATICHASH_H


class QuadraticHash{
public:
        QuadraticHash(int m);
        ~QuadraticHash();

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
