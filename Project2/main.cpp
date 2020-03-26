#include <iostream>
#include <fstream>
#include <chrono>
#include "Dictionary.h"

Dictionary* init_dictionary(std::string fileName){

  Dictionary* ogdict;
  std::string word = "";
  int lineNum = 0;
  std::ifstream wordFile(fileName);

  if(wordFile.is_open()){

    std::cout << "Opened file" << std::endl;
    auto start = std::chrono::system_clock::now();

    while(getline(wordFile, word)){
      // Get number of words in file
      lineNum++;
    }

    wordFile.clear();
    wordFile.seekg(0, std::ios::beg);
    Dictionary* dict = new Dictionary(lineNum);
    std::string buffer = "";

    while(wordFile.peek() != EOF){
      wordFile >> buffer;
      // std::cout << "Word: " << buffer << std::endl;
      dict->insertBucket(buffer);
    }

    ogdict = dict;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << "Total words in table: " << lineNum << std::endl;
    // Need to figure this out
    std::cout << "Largest bucket size: ";
    std::cout << "Smallest bucket size: ";
    std::cout << "Total # of buckets: ";
    std::cout << "Average # of items in bucket: ";
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
  if(argc != 2){
    std::cout << "This program requires 2 arguments!" << std::endl;
    exit(1);
  }
  Dictionary* master = init_dictionary(argv[1]);
  master->print();
  return 0;
}
