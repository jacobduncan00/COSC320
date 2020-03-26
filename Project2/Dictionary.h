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

  public:

    Dictionary();
    Dictionary(int);
    Dictionary(const Dictionary&);
    ~Dictionary();
    Dictionary& operator=(const Dictionary&);

    size_t multHash(std::string);
    void insertBucket(std::string);
    void print();
    void printUsed();

};

#endif

