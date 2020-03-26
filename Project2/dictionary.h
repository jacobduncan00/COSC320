#ifndef DICTIONARY_H
#define DICTIONARY_H 

#include <iostream>
#include <iomanip>
#include <math.h>

class Dictionary{

  private:

    struct HashTable{

      int ind;
      size_t hashVal;
      HashTable* next;
      HashTable* prev;

    };

    // Number of buckets
    int tableSize;
    HashTable* root;
    HashTable* end;

    struct HashNode {

      // Need to convert word to hash
      std::string word;
      HashNode* next;
      HashNode* prev;
      HashTable* header;

    };

    HashNode* head;
    HashNode* tail;

  public:

    size_t buckets = 0;
    double time_to_load = 0;

    // Default constructor

    Dictionary();

    // Overloaded constructor
    // takes in the size of the 
    // HashTable

    Dictionary(int);

    // Function that performs
    // hashing based off the
    // multiplication method
    //

    size_t strToNum(const std::string&);

    size_t multHash(size_t);

    // Inserts a value of size_t
    // datatype into the HashTable

    void insertBucket(int);


    void insertHashVal(size_t);

    // Copy constructor that copies
    // contents of one HashTable
    // to another

    Dictionary(const Dictionary&);

    // Destructor that deallocates memory
    // from HashTable

    ~Dictionary();

    // Overloaded assignment operator to 
    // assign one hash table to another

    Dictionary& operator=(const Dictionary&);
};

#endif

