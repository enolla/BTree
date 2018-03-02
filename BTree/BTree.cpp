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
int BTree<T>::recDepth(node* currentNode)
{
    if (!currentNode->left && !currentNode->right)
    {
        return 0;
    }
    else
    {
        int leftDepth = 0;
        int rightDepth = 0;

        if (currentNode->left)
        {
            leftDepth = recDepth(currentNode->left) + 1;
        }

        if (currentNode->right)
        {
            rightDepth = recDepth(currentNode->right) + 1;
        }

        return MAX(leftDepth, rightDepth);

    }


}

template <class T>
void BTree<T>::insert(T data)
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
void BTree<T>::recInsert(node* insertNode, node* currentNode)
{
    insertNode->parent = currentNode;

    if (insertNode->data < currentNode->data)
    {
        if (!currentNode->left)
        {
            currentNode->left = insertNode;
        }
        else
        {
            recInsert(insertNode, currentNode->left);
        }
    }
    else
    {
        if (!currentNode->right)
        {
            currentNode->right = insertNode;
        }
        else
        {
            recInsert(insertNode, currentNode->right);
        }
    }
}


template<class T>
void BTree<T>::clearTree()
{
    recClearTree(root_);
}


template<class T>
void BTree<T>::recClearTree(node* currentNode)
{
    if (currentNode->left)
    {
        recClearTree(currentNode->left);
    }

    if (currentNode->right)
    {
        recClearTree(currentNode->right);
    }

    delete currentNode;

}



template<class T>
void BTree<T>::printTree()
{
    recPrint(root_);
}


template<class T>
void BTree<T>::recPrint(node* currentNode)
{

    if (currentNode->left)
    {
        recPrint(currentNode->left);
    }

    std::cout << currentNode->data << std::endl;

    if (currentNode->right)
    {
        recPrint(currentNode->right);
    }
    
}


