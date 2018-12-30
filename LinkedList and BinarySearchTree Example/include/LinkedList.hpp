
#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP

#include <string>
#include <cstring>
#include <iomanip>
#include <ctime>
#include "ListMover.hpp"
#include "BinarySearchTree.hpp"

#include "Errors.hpp"

class LinkedList
{
  private:
	BinarySearchTree *headNode;
	BinarySearchTree *lastNode;

	int counter;

	ListMover PreviousWithLocation(int location) const throw(Overflow);
	ListMover First();

  public:
	LinkedList();
	~LinkedList();
	bool isEmpty() const;
	int lenght() const;
	void printOnLocation(int location);
	void Add(const int &item);
	void Add(const int &item, int location) throw(Overflow);

	void Clear();
	void DeleteMaxNode();
	void DeleteMinNode();
	void printNodes();

	void DeleteOnLocation(int location) throw(Overflow);
	void Delete(const BinarySearchTree *tree) throw(NotExist);
	int Find(const BinarySearchTree *tree) const throw(NotExist);
};
#endif