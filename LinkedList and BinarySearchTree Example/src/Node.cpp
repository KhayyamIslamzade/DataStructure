

#include "Node.hpp"

Node::Node(const int &item, Node *lft, Node *rht)
{
	this->item = item;
	left = lft;
	right = rht;
}
Node::~Node()
{
}