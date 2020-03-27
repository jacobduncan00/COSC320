#include <queue>
#include "bt.h"

BinaryTree::BinaryTree(){
  root = nullptr;
}

void BinaryTree::copy(TreeNode* node){
  if(node){
    insert(node->key);
    copy(node->left);
    copy(node->right);
  }
}

BinaryTree::BinaryTree(const BinaryTree& old){
  root = nullptr;
  copy(old.root);
}

void BinaryTree::delMem(TreeNode* node){
  if(node){
    delMem(node->left);
    delMem(node->right);
    delete node;
  }
}

BinaryTree::~BinaryTree(){
  delMem(root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& rhs){
  if(this == &rhs){
    return *this;
  }
  delMem(root);
  root = nullptr;
  copy(rhs.root);
  return *this;
}

BinaryTree::TreeNode* BinaryTree::genNode(int num){
  TreeNode* rtn = new TreeNode();
  rtn->key = num;
  rtn->left = nullptr;
  rtn->right = nullptr;
  rtn->parent = nullptr;
  return rtn;
}


void BinaryTree::insert(int num){
  TreeNode* newNode = genNode(num);
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

bool BinaryTree::search(int num){
  TreeNode* rtn = masterSearch(num);
  if(rtn == nullptr){
    return false;
  }
  return true;
}

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

int BinaryTree::minimum(){
  TreeNode* curr = root;
  if(curr == nullptr){
    std::cout << "minimum: Binary Tree is empty!" << std::endl;
    std::cout << "minimum: Returning -1" << std::endl;
    return -1;
  }
  while(curr->left){
    curr = curr->left;
  }
  return curr->key;
}

int BinaryTree::maximum(){
  TreeNode* curr = root;
  if(curr == nullptr){
    std::cout << "maximum: Binary Tree is empty!" << std::endl;
    std::cout << "maximum: Returning -1" << std::endl;
    return -1;
  }
  while(curr->right){
    curr = curr->right;
  }
  return curr->key;
}

int BinaryTree::successor(int num){
  TreeNode* rtn = masterSuccessor(num);
  if(rtn == nullptr){
    std::cout << "successor: Successor not found" << std::endl;
    std::cout << "successor: Returning -1" << std::endl;
    return -1;
  }
  return rtn->key;
}

BinaryTree::TreeNode* BinaryTree::masterSuccessor(int num){
  TreeNode* key = masterSearch(num);
  if(key == nullptr){
    std::cout << "masterSearch: key not found" << std::endl;
    std::cout << "masterSearch: returning nullptr to successor" << std::endl;
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

void BinaryTree::inorder(){
  masterInorder(root);
}

void BinaryTree::masterInorder(TreeNode* node){
  if(node){
    masterInorder(node->left);
    std::cout << node->key << " ";
    masterInorder(node->right);
  }
}

void BinaryTree::print(){
  masterPrint(root);
}

void BinaryTree::masterPrint(TreeNode* node){
  if(node){
    std::cout << node->key << " ";
    masterPrint(node->left);
    masterPrint(node->right);
  }
}



