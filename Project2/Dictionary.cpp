#include "Dictionary.h"

// Default Constructor

Dictionary::Dictionary(){
  arr = new HashTable[10000];
  tableSize = 10000;
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
  }
  for(int i = 0; i < tableSize; i++){
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
  }
  for(int i = 0; i < tableSize; i++){
    used[i] = rhs.used[i];
  }
  return *this;
}

size_t Dictionary::multHash(std::string str){
  size_t w = pow(2,32);
  size_t p = 19;
  size_t a = 2971215073;
  size_t sum = 0;
  for(size_t i = 0; i < str.length(); i++){
    sum += ((size_t)(str[i])) * (i * 5);
  }
  size_t rtn = floor(((a * sum) % w)/pow(2,32-p));
  return rtn % tableSize;
}

void Dictionary::insertBucket(std::string str){
  arr[multHash(str)].insertWord(str);
  used[multHash(str)]++;
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

int Dictionary::smallestBucket(){
  int min = 10000;
  for(int i = 0; i < tableSize; i++){
    if(used[i] < min && used[i] > 0){
      min = used[i];
    }
  }
  return min;
}

// Iterates through used Dictionary nodes
// and finds the one with the biggest tableSize

int Dictionary::largestBucket(){
  int max = 0;
  for(int i = 0; i < tableSize; i++){
    if(used[i] > max){
      max = used[i];
    }
  }
  return max;
}

// iterates through used Dictionary nodes
// and counts which nodes hold more than 0 elements

int Dictionary::usedBuckets(){
  int count = 0;
  for(int i = 0; i < tableSize; i++){
    if(used[i] > 0){
      count++;
    }
  }
  return count;
}

int Dictionary::getTableSize() {
  return tableSize;
}

double Dictionary::averageBucket(){
  double sum = 0;
  for(int i = 0; i < tableSize; i++){
    sum += used[i];
  }
  double rtn = sum / (double)tableSize;
  return rtn;
}


