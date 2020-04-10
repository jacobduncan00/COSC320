#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

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

    void clear();
    HashNode* genNode(std::string);
    void insertWord(std::string);
    void print();
    bool inTable(std::string);
    int getLen();
    std::string* getList();
};

#endif
