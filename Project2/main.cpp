#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include "Dictionary.h"

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

void welcomeScreen()
{
  std::cout << BOLDRED << "**************************************" << RESET << std::endl;
  std::cout << BOLDRED << "**************************************" << RESET << std::endl;
  std::cout << BOLDRED << "**                                  **" << RESET << std::endl;
  std::cout << BOLDRED << "**             WELCOME              **" << RESET << std::endl;
  std::cout << BOLDRED << "**             TO YOUR              **" << RESET << std::endl;
  std::cout << BOLDRED << "**         SPELL CHECKER BY         **" << RESET << std::endl;
  std::cout << BOLDRED << "**           JACOB DUNCAN           **" << RESET << std::endl;
  std::cout << BOLDRED << "**                                  **" << RESET << std::endl;
  std::cout << BOLDRED << "**************************************" << RESET << std::endl;
  std::cout << BOLDRED << "**************************************" << RESET << std::endl;
}

Dictionary *init_dictionary(std::string fileName)
{

  Dictionary *ogdict;
  std::string word = "";
  int lineNum = 0;
  std::ifstream wordFile(fileName);

  if (wordFile.is_open())
  {
    auto start = std::chrono::system_clock::now();

    while (getline(wordFile, word))
    {
      // Get number of words in file
      lineNum++;
    }

    wordFile.clear();
    wordFile.seekg(0, std::ios::beg);
    Dictionary *dict = new Dictionary();
    std::string buffer = "";

    while (wordFile.peek() != EOF)
    {
      std::getline(wordFile, buffer);
      transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
      dict->insertBucket(buffer);
    }
    wordFile.close();

    ogdict = dict;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Total words = " << BOLDGREEN << lineNum << RESET << std::endl;
    std::cout << "Biggest bucket size = " << BOLDGREEN << ogdict->largestBucket() << RESET << std::endl;
    std::cout << "Smallest bucket size = " << BOLDGREEN << ogdict->smallestBucket() << RESET << std::endl;
    std::cout << "Total number of buckets = " << BOLDGREEN << ogdict->getTableSize() << RESET << std::endl;
    std::cout << "Number of used buckets = " << BOLDGREEN << ogdict->usedBuckets() << RESET << std::endl;
    std::cout << "Average number of nodes in each bucket = " << BOLDGREEN << ogdict->averageBucket() << RESET << std::endl;
    std::cout << "Total time taken = " << BOLDGREEN << elapsed_seconds.count() << "s" << RESET << std::endl;
    std::cout << std::endl;
  }

  return ogdict;
}

void stringParsing(Dictionary *dict)
{
  std::string word;
  std::string line;
  int misspelledWords = 0;
  int suggestionCounter = 0;

  std::cout << "Please enter some text: " << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << std::endl;

  std::getline(std::cin, line);
  std::istringstream iss(line);

  double outerSeconds = 0;

  while (iss >> word)
  {
    for (int i = 0, len = word.length(); i < word.length(); i++)
    {
      if (ispunct(word[i]))
      {
        word.erase(i--, 1);
        len = word.length();
      }
    }
    auto start = std::chrono::system_clock::now();
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    if (!dict->inHash(word))
    {
      misspelledWords++;
      std::cout << std::endl;
      std::cout << BOLDRED << word << RESET << " is misspelled! Below are the words within one edit distance" << std::endl;
      std::cout << "---------------------------------------------------------------" << std::endl;
      std::cout << std::endl;

      HashTable suggestions = dict->suggest(word);
      suggestionCounter += suggestions.getLen();

      std::cout << "Suggestions for " << BOLDRED << word << RESET << ": ";
      suggestions.print();
      std::cout << std::endl;

      std::cout << "The following are within two edit distances for all words" << std::endl;
      std::cout << "---------------------------------------------------------" << std::endl;
      std::cout << std::endl;

      // Two-edit distance suggestions printed
      suggestionCounter += dict->suggest(suggestions);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    outerSeconds = elapsed_seconds.count();
  }
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Summary" << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Number of misspelled words = " << misspelledWords << std::endl;
  std::cout << "Number of suggestions = " << suggestionCounter << std::endl;
  std::cout << "Time required to find suggestions = " << outerSeconds << "s" << std::endl;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "This program requires 2 arguments!" << std::endl;
    std::cout << "Looks like you are missing the english.txt file..." << std::endl;
    exit(1);
  }
  welcomeScreen();
  std::cout << "Welcome to the Spell Checker!" << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Loading the database..." << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << std::endl;
  Dictionary *master = init_dictionary(argv[1]);
  std::cout << "--------------------------------------" << std::endl;
  stringParsing(master);
  return 0;
}
