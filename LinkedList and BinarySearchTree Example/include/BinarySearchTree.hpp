

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cmath>
#include "Node.hpp"
#include "Errors.hpp"

class BinarySearchTree
{
  private:
	Node *root;

	void ArvAdd(Node *&sub_node, const int &yeni);
	bool ArvDelete(Node *&sub_node, const int &yeni);
	bool NodeDelete(Node *&sub_node);

	void Inorder(Node *sub_node) const;
	void Preorder(Node *sub_node) const;
	void Postorder(Node *sub_node) const;

	void LevelPrint(Node *sub_node, int seviye) const;
	int Height(Node *sub_node) const;
	bool Search(Node *sub_node, const int &aranan);
	int MaxNode(Node *root);
	int MinNode(Node *root);

  public:
	BinarySearchTree *upTree;
	BinarySearchTree *subTree;
	BinarySearchTree(BinarySearchTree *up = NULL, BinarySearchTree *sub = NULL);
	bool isEmpty() const;
	void Add(const int &yeni);
	void Delete(const int &item) throw(NotExist);
	int FindMaxNode();
	int FindMinNode();

	void Levelorder() const;

	bool Wanted(const int &aranan);
	void Clear();
	int Height() const;
	~BinarySearchTree();
};

#endif