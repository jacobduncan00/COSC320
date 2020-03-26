#include <iostream>
#include <fstream>
#include <chrono>
#include "Dictionary.h"

Dictionary* init_dictionary(std::string fileName){

  Dictionary* ogdict;
  std::string word = "";
  int lineNum = 0;
  size_t tableSize = 10000;
  std::ifstream wordFile(fileName);

  if(wordFile.is_open()){

    std::cout << "Opened file" << std::endl;
    auto start = std::chrono::system_clock::now();

    while(getline(wordFile, word)){
      // Get number of words in file
      lineNum++;
    }

    wordFile.seekg(0, std::ios::beg);
    Dictionary* dict = new Dictionary(tableSize); 
    std::string buffer = "";

    // while(wordFile >> buffer && 0 < lineNum){
      // Need to check if word is hashable
      // then insert into dictionary
      // Need to hash word before inserting
      // size_t hashVal = dict->multHash(buffer);
      // dict->insertHashVal(hashVal);
    // }

    ogdict = dict;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << "Time to load buckets: " << elapsed_seconds.count() << "s" << std::endl;
    // dict.time_to_load= elapsed_seconds.count();
    // Print stats for loading
    // Make this a public Dictionary function
    wordFile.close();
    std::cout << "Closed file" << std::endl;

  }

  return ogdict;

}


int main(int argc, char** argv){
  Dictionary* master = init_dictionary(argv[1]);
  size_t num = master->strToNum("Hi my name is Jacob");
  size_t index = master->multHash(num);
  /*
  Dictionary* test;
  std::string tester = "hi";
  test->multHash(tester);
  */
  return 0;
}
