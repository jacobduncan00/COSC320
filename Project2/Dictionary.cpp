#include "Dictionary.h"

// Default Constructor

Dictionary::Dictionary(){
  // Need to make HashTable
  // where 80% of cells are used
  // therefore 10k
  arr = new HashTable[10000];
  tableSize = 10000;
  used = new int[tableSize];
  for(int i = 0; i < tableSize; i++){
    used[i] = 0;
  }
}

Dictionary::Dictionary(int size){
  arr = new HashTable[size];
  tableSize = size;
  used = new int[tableSize];
  for(int i = 0; i < tableSize; i++){
    used[i] = 0;
  }
}

// Copy Constructor

Dictionary::Dictionary(const Dictionary& out){
  arr = new HashTable[out.tableSize];
  tableSize = out.tableSize;
  used = new int[out.tableSize];
  for(int i = 0; i < tableSize; i++){
    arr[i] = out.arr[i];
    used[i] = out.used[i];
  }
}

// Destructor

Dictionary::~Dictionary(){
  delete[] arr;
  delete[] used;
}

Dictionary& Dictionary::operator=(const Dictionary& rhs){
  // Need to go through each HashTable node and their
  // HashNode and copy to new HashTable with new HashNodes
  if(this == &rhs){
    return *this;
  }
  // destructing previous
  delete[] arr;
  delete[] used;
  arr = new HashTable[rhs.tableSize];
  tableSize = rhs.tableSize;
  used = new int[rhs.tableSize];
  for(int i = 0; i < tableSize; i++){
    arr[i] = rhs.arr[i];
    used[i] = rhs.used[i];
  }
  return *this;
}

size_t Dictionary::multHash(std::string str){
  size_t w = 64;
  size_t p = 47;
  size_t a = 2971215073;
  size_t sum = 0;
  for(int i = 0; i < str.length(); i++){
    sum += (int)str[i];
  }
  size_t a_times_x = a * sum;
  const size_t ONE = 1;
  size_t two_to_w = ONE << w;
  size_t a_times_x_mod_w = a_times_x & (two_to_w - ONE);
  size_t hash = a_times_x_mod_w >> (w-p);
  return hash;
}

void Dictionary::insertBucket(std::string text){
  arr[multHash(text) > 9999 ? 0 : multHash(text)].insertWord(text);
  used[multHash(text) > 9999 ? 0 : multHash(text)]++;
}

void Dictionary::print(){
  // 10 for testing
  for(int i = 0; i < 10; i++){
    arr[i].print();
  }
}

void Dictionary::printUsed(){
  // 10 for testing
  for(int i = 0; i < 10; i++){
    std::cout << used[i] << std::endl;
  }
}

