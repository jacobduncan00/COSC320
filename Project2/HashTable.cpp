#include "HashTable.h"

HashTable::HashTable(){
  head = nullptr;
  tail = nullptr;
}

HashTable::HashTable(const HashTable& out){
  head = nullptr;
  tail = nullptr;
  HashNode* curr = out.tail;
  if(curr == nullptr){
    // Need throw and except
    std::cout << "ERROR" << std::endl;
    return;
  }
  while(curr){
    insertWord(curr->word);
    curr = curr->prev;
  }
}

HashTable::~HashTable(){
  if(head == nullptr){
    // Nothing to delete
    return;
  }
  while(head->next){
    head = head->next;
    delete head->prev;
  }
  delete head;
}

HashTable& HashTable::operator=(const HashTable& rhs){
  // If HashTables are the same
  if(this == &rhs){
    return *this;
  }
  if(head){
    while(head->next){
      head = head->next;
      delete head->prev;
    }
    delete head;
  }
  head = nullptr;
  tail = nullptr;
  HashNode* curr = rhs.tail;
  if(curr == nullptr){
    return *this;
  }
  while(curr){
    insertWord(curr->word);
    curr = curr->prev;
  }
  return *this;
}

HashTable::HashNode* HashTable::genNode(std::string str){
  HashNode* rtn = new HashNode();
  rtn->word = str;
  rtn->next = nullptr;
  rtn->prev = nullptr;
  return rtn;
}

void HashTable::insertWord(std::string str){
  // Make function to generate node
  HashNode* newNode = genNode(str);
  if(head == nullptr){
    head = newNode;
    tail = newNode;
    return;
  }
  newNode->next = head;
  head = newNode;
  head->next->prev = head;
}

void HashTable::print(){
  if(head == nullptr){
    // Need to add throw and catch exception
    std::cout << "List is empty!" << std::endl;
    return;
  }
  HashNode* curr = new HashNode();
  std::cout << std::endl;
  while(curr){
    std::cout << curr->word << " -> ";
    curr = curr->next;
  }
  std::cout << std::endl;
}


