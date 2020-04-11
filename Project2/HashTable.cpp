#include "HashTable.h"

// Default constructor

HashTable::HashTable()
{
  head = nullptr;
  tail = nullptr;
}

// Copy Constructor

HashTable::HashTable(const HashTable &out)
{
  head = nullptr;
  tail = nullptr;
  HashNode *curr = out.tail;
  if (curr == nullptr)
  {
    // Need throw and except
    std::cout << "ERROR, HashTable empty" << std::endl;
    return;
  }
  while (curr)
  {
    insertWord(curr->word);
    curr = curr->prev;
  }
}

// Destructor, deletes all nodes in LL

HashTable::~HashTable()
{
  if (head == nullptr)
  {
    // Nothing to delete
    return;
  }
  while (head->next)
  {
    head = head->next;
    delete head->prev;
  }
  delete head;
}

// Overloaded Assignment Operator

HashTable &HashTable::operator=(const HashTable &rhs)
{
  // If HashTables are the same
  if (this == &rhs)
  {
    return *this;
  }
  // Destruct old
  if (head)
  {
    while (head->next)
    {
      head = head->next;
      delete head->prev;
    }
    delete head;
  }
  // Copy contents
  head = nullptr;
  tail = nullptr;
  HashNode *curr = rhs.tail;
  if (curr == nullptr)
  {
    return *this;
  }
  while (curr)
  {
    insertWord(curr->word);
    curr = curr->prev;
  }
  return *this;
}

// Function that generates a new node to be entered into the HashTable
// given a word parameter

HashTable::HashNode *HashTable::genNode(std::string str)
{
  HashNode *rtn = new HashNode();
  rtn->word = str;
  rtn->next = nullptr;
  rtn->prev = nullptr;
  return rtn;
}

// Function that takes a word inserts it into the correct place in the
// HashTable

void HashTable::insertWord(std::string str)
{
  // Gen Node with word
  HashNode *newNode = genNode(str);
  // If head is empty, place node at head
  if (head == nullptr)
  {
    head = newNode;
    tail = newNode;
    return;
  }
  // Place in head and shift
  newNode->next = head;
  head = newNode;
  head->next->prev = head;
}

// Function that prints the words in the LL

void HashTable::print()
{
  if (head == nullptr)
  {
    // Need to add throw and catch exception
    std::cout << "List is empty!" << std::endl;
    return;
  }
  HashNode *curr = head;
  // Traverse linked list and print words in each node
  while (curr)
  {
    std::cout << BOLDGREEN << curr->word << RESET << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}

// Function that determines whether a string is in the
// HashTable / Linked List and returns a boolean

bool HashTable::inTable(std::string str)
{
  // If list is empty, string cannot be in list
  if (head == nullptr)
  {
    return false;
  }
  HashNode *curr = head;
  // Traverse list and look for word
  while (curr)
  {
    if (curr->word == str)
    {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

// Function that traverses the linked list and
// counts the number of nodes, returning the length of the LL

int HashTable::getLen()
{
  int nodes = 0;
  // If LL is empty, return 0
  if (head == nullptr)
  {
    return nodes;
  }
  HashNode *curr = head;
  // Traverse linked list and increment node counter
  while (curr)
  {
    nodes++;
    curr = curr->next;
  }
  return nodes;
}

// Function that returns an array of strings of the words in
// the HashTable

std::string *HashTable::getList()
{
  if (head == nullptr)
  {
    return nullptr;
  }
  HashNode *curr = head;
  std::string *rtn = new std::string[this->getLen()];
  for (int i = 0; curr; i++)
  {
    rtn[i] = curr->word;
    curr = curr->next;
  }
  return rtn;
}

// Function that "clears" the HashTable by deleting
// all the nodes in the HashTable

void HashTable::clear()
{
  if (head == nullptr)
  {
    return;
  }
  while (head->next)
  {
    head = head->next;
    delete head->prev;
  }
  delete head;
  head = nullptr;
  tail = nullptr;
}
