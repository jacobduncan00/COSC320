#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "hashlist.h"

class Dictionary {
  private:
    HashList* arr;
    int length;

  public:
    Dictionary();
    Dictionary(const Dictionary&);
    ~Dictionary();
    Dictionary& operator=(const Dictionary&);
};

#endif
