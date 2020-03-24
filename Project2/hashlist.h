#ifndef HASHLIST_H
#define HASHLIST_H

#include <string>
#include <iostream>

class HashList { 
  private:
    struct HashNode {
      std::string word;
      HashNode* next;
      HashNode* prev;
    };
    HashNode* head;
    HashNode* tail;

  public:
    HashList();
    HashList(const HashList&);
    ~HashList();
    HashList& operator=(const HashList&);

    // Takes string and inserts it as a node
    // at the head of the list

    void insert(std::string);
};

#endif
