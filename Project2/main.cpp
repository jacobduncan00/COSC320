#include <iostream>
#include <fstream>
#include <chrono>
#include "Dictionary.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

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
