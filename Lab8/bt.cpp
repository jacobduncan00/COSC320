#include <queue>
#include "bt.h"

BinaryTree::BinaryTree(){
  root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree& old){
  
}

BinaryTree::~BinaryTree(){
  delete[] root;
}



void BinaryTree::insert(int num){
  masterInsert(root, num);
  std::cout << "Successfully inserted " << num << " into the Binary Tree" << std::endl;
}

bool BinaryTree::search(int num){
  if(root == NULL){
    return false;
  }
  if(root->key == num){
    return true;
  }
  std::queue<TreeNode*> q;
  q.push(root);
  while(q.empty() == false){
    TreeNode* curr = q.front();
    if(curr->key == num){
      return true;
    }
    q.pop();
    if(curr->left != NULL){
      q.push(curr->left);
    }
    if(curr->right != NULL){
      q.push(curr->right);
    }
  }
  return false;
}

void BinaryTree::print(){
  masterPrint(root, 0);
}

void BinaryTree::printNode(TreeNode* node){
  std::cout << "Key: " << node->key << std::endl;
} 


