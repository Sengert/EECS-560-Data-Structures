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
#include "HashTimer.h"

using namespace std;

HashTimer::HashTimer(int m, int initK, int initP){
        //Initilize all timings at 0.00s
        openHashBuildTime = 0.00;
        doubleHashBuildTime = 0.00;
        quadraticHashBuildTime = 0.00;
        openSuccessTime = 0.00;
        openFailTime = 0.00;
        doubleSuccessTime = 0.00;
        doubleFailTime = 0.00;
        quadraticSuccessTime = 0.00;
        quadraticFailTime = 0.00;
        tableSize = m;

        numSearches = (tableSize)/100;//Amount of numbers that will be searched for
        randomSearches = new int[numSearches];//container for numbers to search for
        k = initK;
        p = initP;

        srand(time(NULL));//Initilize random seed
}

HashTimer::~HashTimer(){
        //Destructor
}

void HashTimer::TablePerformance(){

        //Run through input sizes from .1 and .01 to .5 and .05 for inputs and searches
        for(int i = 1; i <= 5; i++){
                //Reset array size each iteration so it will hold more random numbers
                numRandomInputs = (tableSize * i)/10;
                randomInputs = new int[numRandomInputs];

                for(int j = 0; j < 5; j++){
                        srand(time(NULL));
                        //Re-populate the random arrays
                        for(int k = 0; k < numRandomInputs; k++){
                                randomInputs[k] = rand() % (5*tableSize) + 1;
                        }
                        for(int k = 0; k < numSearches; k++){
                                randomSearches[k] = rand() % (5*tableSize) + 1;
                        }

                        BuildTables();//Populate the hash tables with the random numbers
                        SearchTables();//Search for random numbers in the hash tables
                }
                //Average out the timings
                openHashBuildTime = openHashBuildTime/5.0;
                doubleHashBuildTime = doubleHashBuildTime/5.0;
                quadraticHashBuildTime = quadraticHashBuildTime/5.0;
                openSuccessTime = openSuccessTime/5.0;
                openFailTime = openFailTime/5.0;
                doubleSuccessTime = doubleSuccessTime/5.0;
                doubleFailTime = doubleFailTime/5.0;
                quadraticSuccessTime = quadraticSuccessTime/5.0;
                quadraticFailTime = quadraticFailTime/5.0;

                //Print average timings for this iteration to console.
                cout << "-------------------------Input Size : " << numRandomInputs << "------------------------\n";
                cout << "Avg time to insert to   open hash table is : " << openHashBuildTime << " seconds." << endl;
                cout << "Avg time to insert to double hash table is : " << doubleHashBuildTime << " seconds." << endl;
                cout << "Avg time to insert to quadratic hash table is : " << quadraticHashBuildTime << " seconds." << endl;
                cout << "-------------------------Searching Size : " << numSearches << "---------------------\n" << endl;
                cout << "Open Hash with chaining :\n";
                cout << "Successful search time : " << openSuccessTime << ". " << "Unsuccessful search time : " << openFailTime << ".\n";
                cout << "Double Hashing :\n";
                cout << "Successful search time : " << doubleSuccessTime << ". " << "Unsuccessful search time : " << doubleFailTime << ".\n";
                cout << "Quadratic Probing :\n";
                cout << "Successful search time : " << quadraticSuccessTime << ". " << "Unsuccessful search time : " << quadraticFailTime << ".\n";
                cout << "\n\n";

        }

        return;
}

//Helper function that times the insert function of each hashtable for all the random numbers
void HashTimer::BuildTables(){
        openHashTable = new OpenHash(tableSize);
        doubleHashTable = new DoubleHash(tableSize, k, p);
        quadraticHashTable = new QuadraticHash(tableSize, k);
        //Build the tables add each insert time onto the total time of each table
        for(int i = 0; i < numRandomInputs; i++){
                //open hashing
                start = clock();
                openHashTable->insert(randomInputs[i]);
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                openHashBuildTime = openHashBuildTime + duration;
                //double hashing
                start = clock();
                doubleHashTable->Insert(randomInputs[i]);
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                doubleHashBuildTime = doubleHashBuildTime + duration;
                //quadratic probing
                start = clock();
                quadraticHashTable->Insert(randomInputs[i]);
                duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                quadraticHashBuildTime = quadraticHashBuildTime + duration;
        }

        return;
}

//Helper function that times the search function of each hashtable for all the random numbers
void HashTimer::SearchTables(){
        for(int i = 0; i < numSearches; i++){
                //open hashing
                start = clock();
                if(openHashTable->find(randomSearches[i])){
                        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                        openSuccessTime = openSuccessTime + duration;//found
                }
                else{
                        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                        openFailTime = openFailTime + duration;//not found
                }
                //double hashing
                start = clock();
                if(doubleHashTable->Find(randomSearches[i])){
                        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                        doubleSuccessTime = doubleSuccessTime + duration;//found
                }
                else{
                        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                        doubleFailTime = doubleFailTime + duration;//not found
                }
                //quadratic probing
                //
                //
                //
                //TODO: Was having problems correcting my Find() function in
                //QuadraticHash.cpp so I commented this timing out.
                //
                //
                //
                /*
                start = clock();
                if(quadraticHashTable->Find(randomSearches[i])){
                        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                        quadraticSuccessTime = quadraticSuccessTime + duration;//found
                }
                else{
                        duration = ((clock() - start)/(double) CLOCKS_PER_SEC);
                        quadraticFailTime = quadraticFailTime + duration;//not found
                }*/
        }

        delete openHashTable;
        delete doubleHashTable;
        delete quadraticHashTable;

        return;
}
