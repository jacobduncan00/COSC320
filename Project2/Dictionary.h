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
    int averageBucket();

    bool inHash(std::string);
    HashTable suggest(std::string);
    void add(HashTable&, std::string);
    void del(HashTable&, std::string);
    void swap(HashTable&, std::string);
    void replace(HashTable&, std::string);

};

#endif

