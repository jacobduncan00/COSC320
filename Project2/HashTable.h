#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

class HashTable {

  private:

    struct HashNode {
      std::string word;
      HashNode* next;
      HashNode* prev;
    };

    HashNode* head;
    HashNode* tail;

  public:

    HashTable();
    HashTable(const HashTable&);
    ~HashTable();
    HashTable& operator=(const HashTable&);
    void insertWord(std::string);
    void print();

};

#endif
