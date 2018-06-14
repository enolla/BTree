#include "BTree.h"
#include <queue>

#define MAX(x,y) ((x > y) ? x : y)



template<class T>
typename BTree<T>::node* BTree<T>::getRoot()
{
    return root_;
}

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

    
    if (insertNode->data == currentNode->data)
    {
        delete insertNode;
    }
    else if (insertNode->data < currentNode->data)
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

//good god
//https://isocpp.org/wiki/faq/templates#dependent-name-lookup-types

template<class T>
typename BTree<T>::node* BTree<T>::LCA(T data_A, T data_B)
{
    std::queue<typename BTree<T>::node*> nodeQueue_A;
    std::queue<typename BTree<T>::node*> nodeQueue_B;

    dataPath(nodeQueue_A, data_A, root_);
    dataPath(nodeQueue_B, data_B, root_);

    typename BTree<T>::node* prevNodeptr;
    typename BTree<T>::node* currentNodeAptr;
    typename BTree<T>::node* currentNodeBptr;

    prevNodeptr = root_;

    while (!nodeQueue_A.empty() || !nodeQueue_B.empty())
    {
        if (nodeQueue_A.empty())
        {
            currentNodeAptr = nullptr;
        }
        else
        {
            currentNodeAptr = nodeQueue_A.front();
        }

        if (nodeQueue_B.empty())
        {
            currentNodeBptr = nullptr;
        }
        else
        {
            currentNodeBptr = nodeQueue_B.front();
        }

        if (currentNodeAptr != currentNodeBptr) return prevNodeptr;

        nodeQueue_A.pop();
        nodeQueue_B.pop();
        prevNodeptr = currentNodeAptr;
        
    }

    return nullptr;
}

template<class T>
void BTree<T>::dataPath(std::queue<typename BTree<T>::node*>& nodeQueue, T data, node* currentNode)
{
    if (!currentNode) return;
    
    nodeQueue.push(currentNode);
    
    if (currentNode->data == data)
    {
        return;
    }

    currentNode->data > data ? dataPath(nodeQueue, data, currentNode->left) : dataPath(nodeQueue, data, currentNode->right);


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
