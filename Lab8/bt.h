#ifndef BT_H
#define BT_H

#include <iostream>

class BinaryTree {

  private:

    struct TreeNode {
      int key;
      TreeNode* left;
      TreeNode* right;
      TreeNode* parent;

      TreeNode& operator=(const TreeNode& rhs){
        if(this == &rhs){
          return *this;
        }
        delete[] this;
        this->key=rhs.key;
        this->left=rhs.left;
        this->right=rhs.right;
        this->parent=rhs.parent;
        return *this;
      }
    };

    TreeNode* root;

    TreeNode* newNode(int num){
      TreeNode* newNode = new TreeNode();
      newNode->key = num;
      newNode->left = newNode->right = nullptr;
      newNode->parent = nullptr;
      return newNode;
    }

    TreeNode* masterInsert(TreeNode* node, int num){
      if(root == nullptr){
        node = newNode(num);
        return node;
      }

      if(num < node->key){
        TreeNode* left = masterInsert(node->left, num);
        node->left = left;
        left->parent = node;
      }

      else if(num > node->key){
        TreeNode* right = masterInsert(node->right, num);
        node->right = right;
        right->parent = node;
      }

      return node;
    }

    void masterPrint(TreeNode* node, int space){
      if(node == nullptr){
        std::cout << "BT is empty!" << std::endl;
        return;
      }

      space+=10;

      masterPrint(root->right, space);
      std::cout << std::endl;

      for(int i = 10; i < space; i++){
        std::cout << " ";
        std::cout << root->key << "\n";
      }
      masterPrint(root->left, space);
    }

  public:
    BinaryTree();
    void copy(TreeNode*);
    BinaryTree(const BinaryTree&);
    void delMem(TreeNode*);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);
    TreeNode* genNode(int);
    void insert(int);
    bool search(int);
    TreeNode* masterSearch(int);
    int minimum();
    int maximum();
    int successor(int);
    TreeNode* masterSuccessor(int);
    void inorder();
    void masterInorder(TreeNode*);
    void remove(int);
    void print();
    void masterPrint(TreeNode*);
};

#endif
