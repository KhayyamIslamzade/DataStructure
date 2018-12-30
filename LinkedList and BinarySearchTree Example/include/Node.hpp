
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

using namespace std;

class Node
{
public:
  int item;
  Node *left;
  Node *right;

  Node(const int &item, Node *lft = NULL, Node *rht = NULL);
  ~Node();
};
#endif