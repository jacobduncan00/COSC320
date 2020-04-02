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
    };

    TreeNode* root;

    // back bone function that destructs the Binary Tree
    void masterDelMem(TreeNode*);
    // back bone function that copies a Binary Tree to another Binary Tree
    void masterCopy(TreeNode*);
    // Essential function that replaces a subtree of the current Binary Tree with
    // that of another subtree
    void transplant(TreeNode*, TreeNode*);
    // back bone function that arranges the Binary Tree to be printed 'in-order'
    void masterInorder(TreeNode*);
    // back bone function that prints the Binary Tree
    void masterPrint(TreeNode*);
    // back bone function that finds the node with the smallest key
    TreeNode* masterMin();
    // back bone function that finds the node with the largest key
    TreeNode* masterMax();
    // back bone function that finds the successor of a given node
    TreeNode* masterSuccessor(int);
    // back bone function that returns a node with a certain key
    TreeNode* masterSearch(int);

  public:

    // Constructor
    BinaryTree();
    // Copy Constructor
    BinaryTree(const BinaryTree&);
    // Destuctor
    ~BinaryTree();
    // Overloaded Assignment Operator
    BinaryTree& operator=(const BinaryTree&);
    // Function that generates a new node with given key
    TreeNode* genNode(int);
    // Function that inserts a node with a given key into the Binary Tree
    void insert(int);
    // Wrapper function for masterSearch
    int search(int);
    // Wrapper function for masterMin
    int minimum();
    // Wrapper function for masterMax
    int maximum();
    // Wrapper function for masterSuccessor
    int successor(int);
    // Function that removes a node with a specific key from the Binary Tree
    void removeNode(int);
    // Wrapper function for masterInorder
    void inorder();
    // Function that removes a node with a specific key from the Binary Tree
    // Wrapper function for masterPrint
    void print();

};

#endif
