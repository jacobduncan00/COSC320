#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include "HashTable.h"

class Dictionary{

  private:

    HashTable* arr;
    // # of buckets
    int tableSize;
    int* used;

    // manipulating the word after spell checking
    void manipulate(HashTable&, std::string, std::string);

  public:

    Dictionary();
    Dictionary(const Dictionary&);
    ~Dictionary();
    Dictionary& operator=(const Dictionary&);

    size_t multHash(std::string);

    void print();
    void printUsed();

    void insertBucket(std::string);
    int smallestBucket();
    int largestBucket();
    int usedBuckets();
    int getTableSize();
    double averageBucket();

    bool inTable(std::string);
    HashTable suggestions(std::string);

};

#endif

