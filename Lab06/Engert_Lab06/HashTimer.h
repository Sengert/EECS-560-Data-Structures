/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 06
*
* HashTimer:
*       A timer used to measure the performance of different hash tables,
*       including open hashing with chaining, closed hashing with quadratic probing,
*       and double hashing.
*******************************************************************************/
#ifndef HASHTIMER_H
#define HASHTIMER_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "OpenHash.h"
#include "DoubleHash.h"
#include "QuadraticHash.h"


class HashTimer{
public:
        HashTimer(int m, int initK, int initP);
        ~HashTimer();

        //Function that we call from main, calls upon SearchTables() and TablePerformance()
        //and keeps track of how many iterations have passed to calculate averages
        void BuildTables();

        //Helper function that adds up all the timings for successful and Unsuccessful
        //searches for each hash table.
        void SearchTables();

        //Helper function that adds up all the timings for every insertion for
        //each hash table.
        void TablePerformance();

private:
        //Timer variables to calculate amount of time elapsed since the
        //beginning of a call until the end of the function.
        clock_t start;
        clock_t end;
        double duration;

        //k for double hashing and quadratic probing
        int k;
        //p for double hashing
        int p;
        //the amount of buckets each hashtable has
        int tableSize;
        //the amount of numbers to insert to each hash table
        int numRandomInputs;
        //the amount of numbers to look for in each hash table
        int numSearches;
        //Array containers to hold randomly generated numbers
        int* randomInputs;
        int* randomSearches;

        //A pointer to each hash table we want to test
        OpenHash* openHashTable;
        DoubleHash* doubleHashTable;
        QuadraticHash* quadraticHashTable;

        //Variables to store the average timings of each operation
        double openHashBuildTime;
        double quadraticHashBuildTime;
        double doubleHashBuildTime;
        double openSuccessTime;
        double quadraticSuccessTime;
        double doubleSuccessTime;
        double openFailTime;
        double quadraticFailTime;
        double doubleFailTime;
};

#endif
