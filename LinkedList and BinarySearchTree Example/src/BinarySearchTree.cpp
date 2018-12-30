

#include "BinarySearchTree.hpp"

void BinarySearchTree::ArvAdd(Node *&sub_node, const int &yeni)
{
	if (sub_node == NULL)
		sub_node = new Node(yeni);
	else if (yeni < sub_node->item)
		ArvAdd(sub_node->left, yeni);
	else if (yeni > sub_node->item)
		ArvAdd(sub_node->right, yeni);
	else
		return; // Ayn� eleman var.
}
bool BinarySearchTree::ArvDelete(Node *&sub_node, const int &yeni)
{
	if (sub_node == NULL)
	{
		return false; //Eleman yok
	}

	if (sub_node->item == yeni)
	{
		return NodeDelete(sub_node);
	}

	else if (yeni < sub_node->item)
	{
		return ArvDelete(sub_node->left, yeni);
	}

	else
	{
		return ArvDelete(sub_node->right, yeni);
	}
}

bool BinarySearchTree::NodeDelete(Node *&sub_node)
{

	Node *deletedNode = sub_node;

	if (sub_node->right == NULL)
		sub_node = sub_node->left;
	else if (sub_node->left == NULL)
		sub_node = sub_node->right;
	else
	{
		deletedNode = sub_node->left;
		Node *parentNode = sub_node;
		while (deletedNode->right != NULL)
		{
			parentNode = deletedNode;
			deletedNode = deletedNode->right;
		}
		sub_node->item = deletedNode->item;
		if (parentNode == sub_node)
			sub_node->left = deletedNode->left;
		else
			parentNode->right = deletedNode->left;
	}
	delete deletedNode;
	return true;
}

void BinarySearchTree::LevelPrint(Node *sub_node, int seviye) const
{
	if (sub_node == NULL)
		return;
	if (seviye == 0)
		cout << sub_node->item << " ";
	else
	{
		LevelPrint(sub_node->left, seviye - 1);
		LevelPrint(sub_node->right, seviye - 1);
	}
}
int BinarySearchTree::Height(Node *sub_node) const
{
	if (sub_node == NULL)
		return -1; // Ortada d���m yoksa y�kseklik anlams�zd�r. Kodun �al��mas� ad�na -1 verilmektedir.
	return 1 + max(Height(sub_node->left), Height(sub_node->right));
}
bool BinarySearchTree::Search(Node *sub_node, const int &aranan)
{
	if (sub_node == NULL)
		return false;
	if (sub_node->item == aranan)
		return true;
	if (aranan < sub_node->item)
		return Search(sub_node->left, aranan);
	if (aranan > sub_node->item)
		return Search(sub_node->right, aranan);
}

BinarySearchTree::BinarySearchTree(BinarySearchTree *up, BinarySearchTree *sub)
{
	root = NULL;
	upTree = up;
	subTree = sub;
}
bool BinarySearchTree::isEmpty() const
{
	return root == NULL;
}
void BinarySearchTree::Add(const int &yeni)
{
	ArvAdd(root, yeni);
}
void BinarySearchTree::Delete(const int &item) throw(NotExist)
{
	if (ArvDelete(root, item) == false)
	{
		throw NotExist();
	}
}
int BinarySearchTree::MaxNode(Node *rt)
{
	if (rt == NULL)
		return -1;

	// Return maximum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	int res = rt->item;
	int lres = MaxNode(rt->left);
	int rres = MaxNode(rt->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return res;
}

int BinarySearchTree::MinNode(Node *rt)
{

	/* loop down to find the leftmost leaf */
	while (rt->left != NULL)
	{
		rt = rt->left;
	}
	return (rt->item);
}
int BinarySearchTree::FindMaxNode()
{
	return MaxNode(root);
}
int BinarySearchTree::FindMinNode()
{
	return MinNode(root);
}

void BinarySearchTree::Levelorder() const
{
	int h = Height();
	for (int level = 0; level <= h; level++)
		LevelPrint(root, level);
}
bool BinarySearchTree::Wanted(const int &aranan)
{
	return Search(root, aranan);
}
void BinarySearchTree::Clear()
{
	while (!isEmpty())
		NodeDelete(root);
}
int BinarySearchTree::Height() const
{
	return Height(root);
}
BinarySearchTree::~BinarySearchTree()
{
	Clear();
}
