#pragma once
#include <cstddef>


template <class T>
class BTree
{
    class node
    {
    public:
        node(T init) : data(init), parent(NULL), left(NULL), right(NULL) {}

        T data;
        node* parent;
        node* left;
        node* right;
    };


public:
    BTree() : root_(NULL) {}
    ~BTree() { clearTree(); }

    node* getRoot() { return root_;}
    int getDepth();
    int recDepth(node * currentNode);
    void insert(T data);
    void clearTree();
    void printTree();


private:
    node* root_;


    void recInsert(node * insertNode, node* currentNode);
    void recClearTree(node * currentNode);
    void recPrint(node * currentNode);

};