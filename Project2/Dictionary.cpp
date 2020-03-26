#include "Dictionary.h"

// Default Constructor

Dictionary::Dictionary(){
  tableSize = 5000;
  root = nullptr;
  head = nullptr;
  tail = nullptr;
}

Dictionary::Dictionary(int size){
  for(int i = 0; i < size; i++){
    insertBucket(i);
  }
}

// Copy Constructor

Dictionary::Dictionary(const Dictionary& called){
  head = nullptr;
  tail = nullptr;
  HashNode* curr = called.head;
  if(curr == nullptr){
    return;
  }
  while(curr){
    // Insert all words from previous hash table
    // insert(curr->word);
    curr = curr->next;
  }
}

// Destructor

Dictionary::~Dictionary(){
  while(head->next != nullptr){
    head = head->next;
    delete head->prev;
  }
  delete head;
}

Dictionary& Dictionary::operator=(const Dictionary& rhs){
  // Need to go through each HashTable node and their
  // HashNode and copy to new HashTable with new HashNodes
  if(this == &rhs){
    return *this;
  }

  Dictionary rtn(rhs.tableSize);

  if(rhs.root == nullptr){
    std::cout << "Cannot assign an empty hash table!" << std::endl;
    // Need to throw and except later
    exit(1);
  }
  else{
    HashTable* curr = rhs.root;
    while(curr->next != nullptr){
      // Make overloaded HashTable constructor
      HashTable* newNode = new HashTable();
      newNode->hashVal = curr->hashVal;
      newNode->ind = curr->ind;
      newNode->next = curr->next;
      newNode->prev = curr->prev;
      curr = curr->next;
    }
  }
}

size_t Dictionary::strToNum(const std::string& str){
  size_t num = 0;
  int forth = str.length()/4;
  int rem = str.length() % 4;

  int k = 0;
  for(int i = 0; i < forth; i++){
    for(int j = 0; j < 4; j++){
      num += long(str[str.length()-(k+1)])*(1<<7*i);
      k++;
    }
  }
  for(int i = 0; i < rem; i++){
    num += long(str[str.length()-(k+1)])*(1<<7*i);
    k++;
  }
  return num;
}

size_t Dictionary::multHash(size_t num){
  size_t W = pow(2, 64);
  size_t p = 47;
  size_t a = 2971215073;
  size_t rtn = floor(((a * num) % W)/pow(2, 64-p));
  return rtn;
}

void Dictionary::insertHashVal(size_t ins){

}

void Dictionary::insertBucket(int ins){
  // This will be the function we insert hash
  // values into aswell takes a second parameter

  // Need to figure out how to determine what the
  // hash values of these will be
  HashTable* newNode = new HashTable();
  newNode->ind = ins;
  newNode->hashVal = 0;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  if(root == nullptr){
    root = newNode;
  }
  else{
    HashTable* curr = root;
    while(curr->next != nullptr){
      curr = curr->next;
    }
    curr->next = newNode;
  }
}
