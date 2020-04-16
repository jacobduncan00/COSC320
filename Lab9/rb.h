#ifndef RB_H
#define RB_H

#include <iostream>

enum color_t
{
  RED,
  BLACK
};

class RBTree
{
private:
  struct TreeNode
  {
    int key;
    color_t color;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
  };
  TreeNode *root;
  static TreeNode *const nil;

  void delMem(TreeNode *);
  void copy(TreeNode *);
  void transplant(TreeNode *, TreeNode *);
  void lRotate(TreeNode *);
  void rRotate(TreeNode *);
  void insertFix(TreeNode *);
  void deleteFix(TreeNode *);
  void masterPrint(TreeNode *);
  void masterInOrder(TreeNode *);
  TreeNode *masterSearch(int);
  TreeNode *masterMin();
  TreeNode *masterMax();
  TreeNode *masterSucc(int);

public:
  // Default Constructor
  RBTree();
  // Copy Constructor
  RBTree(const RBTree &);
  // Destructor
  ~RBTree();
  // Overloaded assignment operator
  RBTree &operator=(const RBTree &);
  // wrapper function for masterInsert
  void insert(int);
  // delete node out of the tree
  void delNode(int);
  // wrapper function for masterPrint
  void print();
  // wrapper function for masterInorder
  void inOrder();
  // wrapper function for masterSearch
  int searchTree(int);
  // wrapper function for masterMin
  int findMin();
  // wrapper function for masterMax
  int findMax();
  // wrapper function for masterSucc
  int findSucc(int);
};

#endif