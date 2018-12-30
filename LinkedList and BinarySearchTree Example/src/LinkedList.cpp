

#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    headNode = new BinarySearchTree();
    lastNode = new BinarySearchTree();
    counter = 0;
    srand(time(0));
}

ListMover LinkedList::PreviousWithLocation(int location) const throw(Overflow)
{
    if (location < 0 || location > lenght())
        throw Overflow();
    int index = 0;
    ListMover listMover(headNode);

    while (!listMover.isLast() && location != index++) //girilen konuma gore ListMover getirir.
        listMover.next();
    return listMover;
}
void LinkedList::printOnLocation(int location)
{
    ListMover listMover = PreviousWithLocation(location);
}
ListMover LinkedList::First()
{
    if (isEmpty())
        throw EmptyList();
    return ListMover(headNode->subTree);
}

bool LinkedList::isEmpty() const
{
    return headNode->subTree == NULL;
}

int LinkedList::lenght() const
{
    return counter;
}

void LinkedList::Add(const int &height)
{
    Add(height, lenght());
}
void LinkedList::printNodes()
{
    if (isEmpty())
    {
        cout << "Liste bos";
    }
    else
    {
        ListMover listMover = First();
        for (; !listMover.isLast(); listMover.next())
        {
            cout << "Tree Adress : " << listMover.current << "  ";
            listMover.current->Levelorder();
            cout << setw(10) << "max:" << listMover.current->FindMaxNode();
            cout << " min:" << listMover.current->FindMinNode();
            cout << "\n";
        }
    }
}
void LinkedList::Add(const int &height, int location) throw(Overflow)
{
    ListMover listMover;
    try
    {
        listMover = PreviousWithLocation(location);
    }
    catch (Overflow ts)
    {
        throw ts;
    }

    //yeni eklenicek dugumun konumu
    BinarySearchTree *itemNext = listMover.current->subTree;
    listMover.current->subTree = new BinarySearchTree(listMover.current, itemNext);

    lastNode = listMover.current->subTree;
    if (itemNext != NULL) //
        itemNext->upTree = listMover.current->subTree;
    int random_number;

    while ((listMover.current->subTree->Height() < height))
    {
        random_number = (rand() % 999) + 1;
        listMover.current->subTree->Add(random_number);
    }

    counter++;
}

void LinkedList::Delete(const BinarySearchTree *tree) throw(NotExist)
{
    try
    {
        int konum = Find(tree);
        DeleteOnLocation(konum);
    }
    catch (NotExist e)
    {
        throw e;
    }
}
void LinkedList::DeleteOnLocation(int location) throw(Overflow)
{
    try
    {
        ListMover listMover = PreviousWithLocation(location);
        BinarySearchTree *tmp = listMover.current->subTree;
        listMover.current->subTree = listMover.current->subTree->subTree;
        if (tmp->subTree != NULL)
            tmp->subTree->upTree = tmp;
        delete tmp;
        counter--;
    }
    catch (Overflow ts)
    {
        throw ts;
    }
}

int LinkedList::Find(const BinarySearchTree *tree) const throw(NotExist)
{
    if (isEmpty())
        throw NotExist();
    int indeks = 0;
    for (ListMover listMover(headNode->subTree); !listMover.isLast(); listMover.next())
    {
        if (listMover.getNode() == tree)
            return indeks;
        indeks++;
    }
    return indeks;
}

void LinkedList::DeleteMinNode()
{
    if (isEmpty())
    {
        cout << "Liste bos";
    }
    else
    {

        ListMover listMover = First();

        int min = listMover.current->FindMinNode();
        BinarySearchTree *tree = listMover.current;
        for (; !listMover.isLast(); listMover.next())
        {
            if (min > listMover.current->FindMinNode())
            {
                min = listMover.current->FindMinNode();
                tree = listMover.current;
            }
        }
        cout << "deleted min : " << min;
        if (tree->Height() > 1)
        {
            tree->Delete(min);
        }
        else
        {
            tree->Delete(min);

            Delete(tree);
        }
        tree = NULL;
    }
}

void LinkedList::Clear()
{
    while (!isEmpty())
        Delete(First().getNode());
}

void LinkedList::DeleteMaxNode()
{
    if (isEmpty())
    {
        cout << "Liste bos";
    }
    else
    {
        ListMover listMover = First();

        int max = listMover.current->FindMaxNode();
        BinarySearchTree *tree = listMover.current;
        for (; !listMover.isLast(); listMover.next())
        {
            if (max < listMover.current->FindMaxNode())
            {
                max = listMover.current->FindMaxNode();
                tree = listMover.current;
            }
        }
        cout << "deleted max : " << max;
        if (tree->Height() > 1)
        {
            tree->Delete(max);
        }
        else
        {
            tree->Delete(max);
            Delete(tree);
        }
        tree = NULL;
    }
}

LinkedList::~LinkedList()
{

    delete headNode;
    delete lastNode;
}
