#include "BTree.h"

#define MAX(x,y) ((x > y) ? x : y)


template<class T>
int BTree<T>::getDepth()
{
    if (!root_)
    {
        return -1;
    }

    return recDepth(root_);
}


template <class T>
int BTree::recDepth(node* currentNode)
{
    if (!currentNode->left && !currentNode->right)
    {
        return 0;
    }
    else
    {
        int leftDepth = recDepth(currentNode->left);
        int rightDepth = recDepth(currentNode->right);

    }


}

template <class T>
void BTree::insert(T data)
{
    node* insertNode = new node(data);

    if (!root_)
    {
        root_ = insertNode;
        return;
    }

    recInsert(insertNode, root_);

}

template <class T>
void BTree::recInsert(node* insertNode, node* currentNode)
{
    insertNode->parent = currentNode;

    if (insertNode->data < currentNode->data)
    {

    }
}


template<class T>
void BTree<T>::clearTree()
{
}
