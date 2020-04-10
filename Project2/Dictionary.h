#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include "HashTable.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

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
    void suggest(HashTable);
    void add(HashTable&, std::string);
    void del(HashTable&, std::string);
    void swap(HashTable&, std::string);
    void replace(HashTable&, std::string);

};

#endif

