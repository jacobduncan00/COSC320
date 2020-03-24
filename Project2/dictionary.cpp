#include "dictionary.h"

// Default Constructor

Dictionary::Dictionary(){
  // initializes new HashList to half
  // a million elements
  arr = new HashList[500000];
  length = 500000;
}

// Copy Constructor

Dictionary::Dictionary(const Dictionary& og){
  arr = new HashList[og.length];
  length = og.length;
  for(int i = 0; i < length; i++){
    arr[i] = og.arr[i];
  }
}

// Destructor

Dictionary::~Dictionary(){
  delete[] arr;
}

Dictionary& Dictionary::operator=(const Dictionary& rhs){
  if (this == &rhs) {
    return *this;
  }

  delete[] arr;

  arr = new HashList[rhs.length];
  length = rhs.length;

  for(int i = 0; i < length; i++){
    arr[i] = rhs.arr[i];
  }

  return *this;

}



