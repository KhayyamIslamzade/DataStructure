
#ifndef LISTMOVER_HPP
#define LISTMOVER_HPP

#include "Errors.hpp"
#include "BinarySearchTree.hpp"

class ListMover
{
  public:
	BinarySearchTree *current;
	ListMover();
	ListMover(BinarySearchTree *node);
	bool isLast() const;
	void next() throw(EndList);
	void back() throw(EndList);
	const BinarySearchTree *getNode() const throw(NullReferance);
	// ~ListMover();
};
#endif