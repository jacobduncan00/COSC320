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

    void masterDelMem(TreeNode*);
    void masterCopy(TreeNode*);
    void masterInorder(TreeNode*);
    void masterPrint(TreeNode*);
    TreeNode* masterMin();
    TreeNode* masterMax();
    TreeNode* masterSuccessor(int);
    TreeNode* masterGenNode(int);
    TreeNode* masterSearch(int);

  public:

    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);
    void insert(int);
    int search(int);
    int minimum();
    int maximum();
    int successor(int);
    void inorder();
    void remove(int);
    void print();

};

#endif
