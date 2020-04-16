#include "rb.h"

RBTree::TreeNode *const RBTree::nil = new TreeNode({0, BLACK, nullptr, nullptr, nullptr});

// Default constructor

RBTree::RBTree()
{
  root = nil;
}

// Copying nodes

void RBTree::copy(TreeNode *first)
{
  if (first != nil)
  {
    insert(first->key);
    copy(first->left);
    copy(first->right);
  }
}

// Copy Constructor

RBTree::RBTree(const RBTree &prev)
{
  root = nil;
  copy(prev.root);
}

void RBTree::delMem(TreeNode *first)
{
  if (first != nil)
  {
    delMem(first->left);
    delMem(first->right);
    delete first;
  }
}

// Destructor

RBTree::~RBTree()
{
  delMem(root);
  delete nil;
}

// Overloaded Assignment Operator

RBTree &RBTree::operator=(const RBTree &rhs)
{
  if (this == &rhs)
  {
    return *this;
  }
  delMem(root);
  root = nil;
  copy(rhs.root);
  return *this;
}

// Function that left rotates the subtree

void RBTree::lRotate(TreeNode *pivot)
{
  TreeNode *curr = pivot->right;
  pivot->right = curr->left;
  if (curr->left != nil)
  {
    curr->left->parent = pivot;
  }
  curr->parent = pivot->parent;
  if (pivot->parent == nil)
  {
    root = curr;
  }
  else if (pivot == pivot->parent->left)
  {
    pivot->parent->left = curr;
  }
  else
  {
    pivot->parent->right = curr;
  }
  curr->left = pivot;
  pivot->parent = curr;
}

// Function that right rotates the subtree

void RBTree::rRotate(TreeNode *pivot)
{
  TreeNode *curr = pivot->left;
  pivot->left = curr->right;
  if (curr->right != nil)
  {
    curr->right->parent = pivot;
  }
  curr->parent = pivot->parent;
  if (pivot->parent == nil)
  {
    root = curr;
  }
  else if (pivot == pivot->parent->right)
  {
    pivot->parent->right = curr;
  }
  else
  {
    pivot->parent->left = curr;
  }
  curr->right = pivot;
  pivot->parent = curr;
}

// Function that fixes the rb tree after an insertion

void RBTree::insertFix(TreeNode *in)
{
  while (in->parent->color == RED)
  {
    if (in->parent == in->parent->parent->left)
    {
      TreeNode *temp = in->parent->parent->right;
      if (temp->color == RED)
      {
        in->parent->color = BLACK;
        temp->color = BLACK;
        in->parent->parent->color = RED;
        in = in->parent->parent;
      }
      else
      {
        if (in == in->parent->right)
        {
          in = in->parent;
          lRotate(in);
        }
        in->parent->color = BLACK;
        in->parent->parent->color = RED;
        rRotate(in->parent->parent);
      }
    }
    else
    {
      TreeNode *temp = in->parent->parent->left;
      if (temp->color == RED)
      {
        in->parent->color = BLACK;
        temp->color = BLACK;
        in->parent->parent->color = RED;
        in = in->parent->parent;
      }
      else
      {
        if (in == in->parent->left)
        {
          in = in->parent;
          rRotate(in);
        }
        in->parent->color = BLACK;
        in->parent->parent->color = RED;
        lRotate(in->parent->parent);
      }
    }
  }
  root->color = BLACK;
}

// Function that inserts a new number into the rb tree

void RBTree::insert(int k)
{
  TreeNode *newNode = new TreeNode();
  newNode->key = k;
  if (root == nil)
  {
    root = newNode;
    newNode->parent = nil;
  }
  else
  {
    TreeNode *temp1 = nil;
    TreeNode *temp2 = root;
    while (temp2 != nil)
    {
      temp1 = temp2;
      if (newNode->key < temp2->key)
      {
        temp2 = temp2->left;
      }
      else
      {
        temp2 = temp2->right;
      }
    }
    if (newNode->key < temp1->key)
    {
      temp1->left = newNode;
    }
    else
    {
      temp1->right = newNode;
    }
    newNode->parent = temp1;
  }
  newNode->left = nil;
  newNode->right = nil;
  newNode->color = RED;
  insertFix(newNode);
}

// Function that searches the rb tree for a specific key

RBTree::TreeNode *RBTree::masterSearch(int k)
{
  if (root == nil)
  {
    std::cout << "[master search] Tree is empty" << std::endl;
    return nullptr;
  }
  TreeNode *curr = root;
  while (curr != nil)
  {
    if (curr->key == k)
    {
      return curr;
    }
    else if (curr->key > k)
    {
      curr = curr->left;
    }
    else
    {
      curr = curr->right;
    }
  }
  return nullptr;
}

// Wrapper function for masterSearch

int RBTree::searchTree(int k)
{
  TreeNode *rtn = masterSearch(k);
  if (rtn == nullptr)
  {
    std::cout << "[search] Key was not found in masterSearch" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that gets the smallest key in the rb tree

RBTree::TreeNode *RBTree::masterMin()
{
  if (root == nil)
  {
    std::cout << "[masterMin] Tree is empty" << std::endl;
    return nullptr;
  }
  TreeNode *curr = root;
  while (curr->left != nil)
  {
    curr = curr->left;
  }
  return curr;
}

// Wrapper function for masterMin

int RBTree::findMin()
{
  TreeNode *rtn = masterMin();
  if (rtn == nullptr)
  {
    std::cout << "[findMin] Tree is empty" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that gets the largest key in the rb tree

RBTree::TreeNode *RBTree::masterMax()
{
  if (root == nil)
  {
    std::cout << "[masterMax] Tree is empty" << std::endl;
    return nullptr;
  }
  TreeNode *curr = root;
  while (curr->right != nil)
  {
    curr = curr->right;
  }
  return curr;
}

// Wrapper function for masterMax

int RBTree::findMax()
{
  TreeNode *rtn = masterMax();
  if (rtn == nullptr)
  {
    std::cout << "[findMax] Tree is empty" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that returns the successor of a specific key

RBTree::TreeNode *RBTree::masterSucc(int k)
{
  TreeNode *nodeKey = masterSearch(k);
  if (nodeKey == nullptr)
  {
    std::cout << "[masterSucc] Key was not found in tree" << std::endl;
    return nullptr;
  }
  if (nodeKey->right == nil)
  {
    TreeNode *curr = nodeKey;
    TreeNode *hold = nodeKey;
    while (curr->parent != nil)
    {
      if (curr->parent->left == curr)
      {
        return curr->parent;
      }
      curr = curr->parent;
    }
    return hold;
  }
  TreeNode *curr = nodeKey->right;
  while (curr->left != nil)
  {
    curr = curr->left;
  }
  return curr;
}

// Wrapper function for masterSucc

int RBTree::findSucc(int k)
{
  TreeNode *rtn = masterSucc(k);
  if (rtn == nullptr)
  {
    std::cout << "[findSucc] Successor not found in masterSucc" << std::endl;
    return -1;
  }
  return rtn->key;
}

// Function that prints the rb tree in order style

void RBTree::masterInOrder(TreeNode *first)
{
  if (first != nil)
  {
    masterInOrder(first->left);
    if (first->color == 0)
    {
      std::cout << "[" << first->key << " | RED], ";
    }
    else
    {
      std::cout << "[" << first->key << " | BLACK], ";
    }
    masterInOrder(first->right);
  }
}

// Wrapper function for masterInOrder

void RBTree::inOrder()
{
  masterInOrder(root);
}

// Function that fixes the rb tree after deleting a node

void RBTree::deleteFix(TreeNode *fixMe)
{
  while (fixMe != root && fixMe->color == BLACK)
  {
    if (fixMe == fixMe->parent->left)
    {
      TreeNode *temp = fixMe->parent->right;
      if (temp->color == RED)
      {
        temp->color = BLACK;
        fixMe->parent->color = RED;
        lRotate(fixMe->parent);
        temp = fixMe->parent->right;
      }
      if (temp->left->color == BLACK && temp->right->color == BLACK)
      {
        temp->color = RED;
        fixMe = fixMe->parent;
      }
      else
      {
        if (temp->right->color == BLACK)
        {
          temp->left->color = BLACK;
          temp->color = RED;
          rRotate(temp);
          temp = fixMe->parent->right;
        }
        temp->color = fixMe->parent->color;
        fixMe->parent->color = BLACK;
        temp->right->color = BLACK;
        lRotate(fixMe->parent);
        fixMe = root;
      }
    }
    else
    {
      TreeNode *temp = fixMe->parent->left;
      if (temp->color == RED)
      {
        temp->color = BLACK;
        fixMe->parent->color = RED;
        rRotate(fixMe->parent);
        temp = fixMe->parent->left;
      }
      if (temp->right->color == BLACK && temp->left->color == BLACK)
      {
        temp->color = RED;
        fixMe = fixMe->parent;
      }
      else
      {
        if (temp->left->color == BLACK)
        {
          temp->right->color = BLACK;
          temp->color = RED;
          lRotate(temp);
          temp = fixMe->parent->left;
        }
        temp->color = fixMe->parent->color;
        fixMe->parent->color = BLACK;
        temp->left->color = BLACK;
        rRotate(fixMe->parent);
        fixMe = root;
      }
    }
  }
  fixMe->color = BLACK;
}

// Function that removes a node from the rb tree

void RBTree::delNode(int k)
{
  TreeNode *del = masterSearch(k);
  if (del == nullptr)
  {
    std::cout << "[delNode] Node not found in tree" << std::endl;
    return;
  }
  TreeNode *temp1 = del;
  TreeNode *temp2;
  color_t temp1Color = temp1->color;
  if (del->left == nil)
  {
    temp2 = del->right;
    transplant(del, del->right);
  }
  else if (del->right == nil)
  {
    temp2 = del->left;
    transplant(del, del->left);
  }
  else
  {
    TreeNode *curr = del->right;
    while (curr->left != nil)
    {
      curr = curr->left;
    }
    temp1 = curr;
    temp1Color = temp1->color;
    temp2 = temp1->right;
    if (temp1->parent == del)
    {
      temp2->parent = temp1;
    }
    else
    {
      transplant(temp1, temp1->right);
      temp1->right = del->right;
      temp1->right->parent = temp1;
    }
    transplant(del, temp1);
    temp1->left = del->left;
    temp1->left->parent = temp1;
    temp1->color = del->color;
  }
  delete del;
  if (temp1Color == BLACK)
  {
    deleteFix(temp2);
  }
}

// Function that inserts a subtree at the location of another subtree
// in the rb tree

void RBTree::transplant(TreeNode *a, TreeNode *b)
{
  if (a->parent == nil)
  {
    root = b;
  }
  else if (a->parent->right == a)
  {
    a->parent->right = b;
  }
  else
  {
    a->parent->left = b;
  }
  b->parent = a->parent;
}

// Function that prints the rb tree in tree style

void RBTree::masterPrint(TreeNode *h)
{
  if (h != nil)
  {
    if (h->color == 0)
    {
      std::cout << "[" << h->key << " | RED], ";
    }
    else
    {
      std::cout << "[" << h->key << " | BLACK], ";
    }
    masterPrint(h->left);
    masterPrint(h->right);
  }
}

// Wrapper function for masterPrint

void RBTree::print()
{
  masterPrint(root);
}