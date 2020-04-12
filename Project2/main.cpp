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

Dictionary init_dictionary(std::string fileName)
{

  Dictionary ogdict;
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

    // Reset the reading of the file back to the top
    wordFile.clear();
    wordFile.seekg(0, std::ios::beg);
    Dictionary dict;
    std::string buffer = "";

    // While the current line we are on is not the end of the file
    while (wordFile.peek() != EOF)
    {
      // Get the current line and assign it to buffer
      std::getline(wordFile, buffer);
      // transform the word to lowercase, easier for parsing
      // geeks for geeks, idk if this is the best way to do it ?
      transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
      // insert that word into the Dictionary
      dict.insertBucket(buffer);
    }
    wordFile.close();

    // Scoping the return requires this, also shows Overloaded Assignment Operator
    // works properly
    ogdict = dict;

    // Print Statistics
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Total words = " << BOLDGREEN << lineNum << RESET << std::endl;
    std::cout << "Biggest bucket size = " << BOLDGREEN << ogdict.largestBucket() << RESET << std::endl;
    std::cout << "Smallest bucket size = " << BOLDGREEN << ogdict.smallestBucket() << RESET << std::endl;
    std::cout << "Total number of buckets = " << BOLDGREEN << ogdict.getTableSize() << RESET << std::endl;
    std::cout << "Number of used buckets = " << BOLDGREEN << ogdict.usedBuckets() << RESET << std::endl;
    std::cout << "Average number of nodes in each bucket = " << BOLDGREEN << ogdict.averageBucket() << RESET << std::endl;
    std::cout << "Total time taken = " << BOLDGREEN << elapsed_seconds.count() << "s" << RESET << std::endl;
    std::cout << std::endl;
  }

  return ogdict;
}

void stringParsing(Dictionary dict)
{
  std::string word;
  std::string line;
  int misspelledWords = 0;
  int suggestionCounter = 0;

  std::cout << "Please enter some text: " << std::endl;
  std::cout << "-----------------------" << std::endl;
  std::cout << std::endl;

  std::getline(std::cin, line);
  std::istringstream stream(line);

  double outerSeconds = 0;

  while (stream >> word)
  {
    for (int i = 0, len = word.length(); i < word.length(); i++)
    {
      // Check to see if the word has a punction on it
      // Only some words have this
      if (ispunct(word[i]))
      {
        // If it does, remove it
        word.erase(i--, 1);
        // Get new length of word
        len = word.length();
      }
    }
    auto start = std::chrono::system_clock::now();
    // Once again, transform the word to lower case, easier for parsing
    // and manipulation of the string
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    // If the word is not already in the HashTable
    if (!dict.inHash(word))
    {
      misspelledWords++;
      std::cout << std::endl;
      std::cout << BOLDRED << word << RESET << " is misspelled! Below are the words within one edit distance" << std::endl;
      std::cout << "-----------------------------------------------------------------" << std::endl;
      std::cout << std::endl;

      HashTable suggestions = dict.suggest(word);
      suggestionCounter += suggestions.getLen();

      std::cout << "Suggestions for " << BOLDRED << word << RESET << ": ";
      suggestions.print();
      std::cout << std::endl;

      std::cout << "The following are within two edit distances for all words" << std::endl;
      std::cout << "---------------------------------------------------------" << std::endl;
      std::cout << std::endl;

      // Two-edit distance suggestions printed
      suggestionCounter += dict.suggest(suggestions);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    outerSeconds = elapsed_seconds.count();
  }
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Summary" << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Number of misspelled words = " << BOLDGREEN << misspelledWords << RESET << std::endl;
  std::cout << "Number of suggestions = " << BOLDGREEN << suggestionCounter << RESET << std::endl;
  std::cout << "Time required to find suggestions = " << BOLDGREEN << outerSeconds << "s" << RESET << std::endl;
}

int main(int argc, char **argv)
{
  std::ifstream english("english.txt");
  std::string fileName = "english.txt";
  if (!english.is_open())
  {
    std::cout << "ERROR: english.txt was not opened correctly" << std::endl;
    exit(1);
  }
  welcomeScreen();
  std::cout << BOLDGREEN << "Welcome to the Spell Checker!" << RESET << std::endl;
  std::cout << BOLDRED << "--------------------------------------" << RESET << std::endl;
  std::cout << BOLDGREEN << "Loading the database..." << RESET << std::endl;
  std::cout << BOLDRED << "--------------------------------------" << RESET << std::endl;
  std::cout << std::endl;
  Dictionary master = init_dictionary(fileName);
  std::cout << "--------------------------------------" << std::endl;
  stringParsing(master);
  return 0;
}
