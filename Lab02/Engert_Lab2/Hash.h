/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 02
*
* Hash Table:
*       Building a hash table using our previously
*       designed linked list structure
*******************************************************************************/
#ifndef HASH_H
#define HASH_H
#include "LinkedList.h"


class Hash{
public:
        Hash(int m);
        ~Hash();

        void insert(int x);
        void Delete(int x);
        void print();
        int hash(int x);
        bool find(int x);

private:
        int tableSize;
        LinkedList* hashKeys;

};

#endif
