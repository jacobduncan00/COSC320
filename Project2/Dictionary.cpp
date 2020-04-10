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
  for(int i = 0; i < 10; i++){
    arr[i].print();
  }
}

void Dictionary::printUsed(){
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

int Dictionary::averageBucket(){
  int sum = 0;
  for(int i = 0; i < tableSize; i++){
    sum += used[i];
  }
  double rtn = sum / tableSize;
  return (int)rtn;
}

bool Dictionary::inHash(std::string str){
  bool rtn = arr[multHash(str)].inTable(str);
  return rtn;
}

HashTable Dictionary::suggest(std::string str){
  HashTable suggestions;
  replace(suggestions, str);
  add(suggestions, str);
  del(suggestions, str);
  swap(suggestions, str);
  return suggestions;
}

// Make array that gets the total number of suggestions, sum that with the one from the main
// And update total number of suggestions counter

void Dictionary::suggest(HashTable ext) {
	std::string* oneEditWords = ext.getList();
	for (int i = 0; i < ext.getLen(); i++) {
    HashTable moreSuggestions;
    std::cout << "Suggestions for " << BOLDRED << oneEditWords[i] << RESET << ": ";
		replace(moreSuggestions, oneEditWords[i]);
		add(moreSuggestions, oneEditWords[i]);
		del(moreSuggestions, oneEditWords[i]);
		swap(moreSuggestions, oneEditWords[i]);
    moreSuggestions.print();
    moreSuggestions.clear();
    std::cout << std::endl;
	}
	delete [] oneEditWords;
	// return moreSuggestions;
}

void Dictionary::add(HashTable& suggestions, std::string str){
  std::string holdWord = str;
  for(int i = 0; i < str.length(); i++){
    for(char j = 'a'; j <= 'z'; j++){
      str = str.substr(0,i) + j + str.substr(i,holdWord.length());
      if(inHash(str)){
        suggestions.insertWord(str);
      }
      str = holdWord;
    }
  }
}

void Dictionary::del(HashTable& suggestions, std::string str){
  std::string holdWord = str;
  for(int i = 0; i < str.length(); i++){
    str.erase(i, 1);
    if(inHash(str)){
      suggestions.insertWord(str);
    }
    str = holdWord;
  }
}

void Dictionary::swap(HashTable& suggestions, std::string str){
  std::string holdWord = str;
  for(int i = 0; i < holdWord.length(); i++){
    for(int j = i + 1; j < holdWord.length(); j++){
      if(i != j){
        std::swap(str[i], str[j]);
        if(inHash(str)){
          suggestions.insertWord(str);
        }
        str = holdWord;
      }
    }
  }
}

void Dictionary::replace(HashTable& suggestions, std::string str){
  std::string holdWord = str;
  for(int i = 0; i < holdWord.length(); i++){
    for(char j = 'a'; j <= 'z'; j++){
      str[i] = j;
      if(inHash(str)){
        suggestions.insertWord(str);
      }
      str = holdWord;
    }
  }
}
