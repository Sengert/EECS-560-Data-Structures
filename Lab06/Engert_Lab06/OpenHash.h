/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* Hash Table:
*       Building a hash table using our previously
*       designed linked list structure
*******************************************************************************/
#ifndef OPENHASH_H
#define OPENHASH_H
#include "LinkedList.h"


class OpenHash{
public:
        OpenHash(int m);
        ~OpenHash();

        void insert(int x);
        void Delete(int x);
        void print();
        int hash(int x);
        bool find(int x);

private:
        int tableSize;
        LinkedList** hashKeys;
        LinkedList* temp;

};

#endif
