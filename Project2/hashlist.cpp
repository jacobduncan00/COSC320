#include "hashlist.h"

HashList::HashList(){
  head = null;
  tail = null;
}

HashList::HashList(const HashList& called){
  head = nullptr;
  tail = nullptr;
  HashNode* curr = called.tail;
  if(curr == nullptr){
    return;
  }
  while(curr){

