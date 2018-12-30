

#include "ListMover.hpp"

ListMover::ListMover()
{
    current = NULL;
}

ListMover::ListMover(BinarySearchTree *node)
{
    current = node;
}

bool ListMover::isLast() const
{
    return current == NULL;
}

void ListMover::next() throw(EndList)
{
    if (isLast())
        throw EndList();
    current = current->subTree;
}

void ListMover::back() throw(EndList)
{
    if (isLast())
        throw EndList();
    current = current->upTree;
}

const BinarySearchTree *ListMover::getNode() const throw(NullReferance)
{
    if (current == NULL)
        throw NullReferance();
    return current;
}
