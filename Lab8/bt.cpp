#include "bt.h"

// Default Constructor

BinaryTree::BinaryTree(){
  root = nullptr;
}

// Function that performs a deep copy
// Wrapper function for copy constructor

void BinaryTree::masterCopy(TreeNode* node){
  if(node){
    insert(node->key);
    masterCopy(node->left);
    masterCopy(node->right);
  }
}

// Copy Constructor 

BinaryTree::BinaryTree(const BinaryTree& old){
  root = nullptr;
  masterCopy(old.root);
}

// Deallocates memory that was assigned
// Wrapper function for destructor

void BinaryTree::masterDelMem(TreeNode* node){
  if(node){
    masterDelMem(node->left);
    masterDelMem(node->right);
    delete node;
  }
}

// Destructor

BinaryTree::~BinaryTree(){
  masterDelMem(root);
}

// Overloaded Assignment Operator
// Uses destructor wrapper and copy constructor
// wrapper in order to perform a copy of a binary
// tree to another binary tree and deallocate 
// necessary memory from previous

BinaryTree& BinaryTree::operator=(const BinaryTree& rhs){
  if(this == &rhs){
    return *this;
  }
  masterDelMem(root);
  root = nullptr;
  masterCopy(rhs.root);
  return *this;
}

// Function that generates a TreeNode

BinaryTree::TreeNode* BinaryTree::masterGenNode(int num){
  TreeNode* rtn = new TreeNode();
  rtn->key = num;
  rtn->left = nullptr;
  rtn->right = nullptr;
  rtn->parent = nullptr;
  return rtn;
}

// Function that inserts a new TreeNode into
// the binary tree with a given key

void BinaryTree::insert(int num){
  TreeNode* newNode = masterGenNode(num);
  TreeNode* curr = root;
  TreeNode* prev = nullptr;
  while(curr){
    prev = curr;
    if(newNode->key < curr->key){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
  }

  if(prev == nullptr){
    root = newNode;
    return;
  }

  if(newNode->key < prev->key){
    prev->left = newNode;
  }
  else{
    prev->right = newNode;
  }
  newNode->parent = prev;
}

// Wrapper function for the master search
// function

int BinaryTree::search(int num){
  TreeNode* rtn = masterSearch(num);
  if(rtn == nullptr){
    std::cout << num << " was not found in the Binary Tree" << std::endl;
    // std::cout << "Returning -1" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that searches through the BinaryTree
// for a specific key and returns the node with 
// that key

BinaryTree::TreeNode* BinaryTree::masterSearch(int num){
  if(root == nullptr){
    std::cout << "masterSearch: Binary Tree is empty!" << std::endl;
    return nullptr;
  }
  TreeNode* curr = root;
  while(curr){
    if(curr->key == num){
      return curr;
    }
    else if(curr->key > num){
      curr = curr->left;
    }
    else if(curr->key < num){
      curr = curr->right;
    }
  }
  return nullptr;
}

// Wrapper function for the master 
// minimum function 

int BinaryTree::minimum(){
  TreeNode* rtn = masterMin();
  if(rtn == nullptr){
    std::cout << "minimum: Tree is empty" << std::endl;
    // std::cout << "minimum: Returning -1" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that searches the entire Binary Tree
// for the node with the smallest key

BinaryTree::TreeNode* BinaryTree::masterMin(){
  TreeNode* rtn = root;
  if(rtn == nullptr){
    std::cout << "masterMinimum: Binary Tree is empty!" << std::endl;
    std::cout << "masterMinimum: Returning nullptr" << std::endl;
    return nullptr;
  }
  while(rtn->left){
    rtn = rtn->left;
  }
  return rtn;
}

// Wrapper function for the master
// maximum function 

int BinaryTree::maximum(){
  TreeNode* rtn = masterMax();
  if(rtn == nullptr){
    std::cout << "maximum: Tree is empty" << std::endl;
    // std::cout << "maximum: Returning -1" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that searches the entire Binary Tree
// for the node with the largest key

BinaryTree::TreeNode* BinaryTree::masterMax(){
  TreeNode* rtn = root;
  if(rtn == nullptr){
    std::cout << "masterMax: Binary Tree is empty!" << std::endl;
    std::cout << "masterMax: Returning nullptr" << std::endl;
    return nullptr;
  }
  while(rtn->right){
    rtn = rtn->right;
  }
  return rtn;
}

// Wrapper functionm for the master
// successor function

int BinaryTree::successor(int num){
  TreeNode* rtn = masterSuccessor(num);
  if(rtn == nullptr){
    std::cout << "successor: Successor not found" << std::endl;
    // std::cout << "successor: Returning -1" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that returns the next node
// in the tree, after the node with the key passed
// to the function

BinaryTree::TreeNode* BinaryTree::masterSuccessor(int num){
  TreeNode* key = masterSearch(num);
  if(key == nullptr){
    std::cout << "masterSearch: key is not in BT" << std::endl;
    std::cout << "masterSearch: returning nullptr" << std::endl;
    return nullptr;
  }
  if(key->right == nullptr){
    TreeNode* curr = key;
    TreeNode* prev = key;
    while(curr->parent){
      if(curr->parent->left == curr){
        return curr->parent;
      }
      curr = curr->parent;
    }
    return prev;
  }
  TreeNode* curr = key->right;
  while(curr->left){
    curr = curr->left;
  }
  return curr;
}

// Wrapper function for master
// inorder function

void BinaryTree::inorder(){
  masterInorder(root);
}

// Function that prints the Binary Tree
// in 'inorder' form
// ascending order

void BinaryTree::masterInorder(TreeNode* node){
  if(node){
    masterInorder(node->left);
    std::cout << node->key << " ";
    masterInorder(node->right);
  }
}

// Wrapper function for master
// print function

void BinaryTree::print(){
  masterPrint(root);
}

// Function that prints the binary
// tree in its normal tree form
// cannot understand from line view

void BinaryTree::masterPrint(TreeNode* node){
  if(node){
    std::cout << node->key << " ";
    masterPrint(node->left);
    masterPrint(node->right);
  }
}



