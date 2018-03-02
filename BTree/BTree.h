#pragma once
#include <cstddef>


template <class T>
class node
{
public:
    node(T init) : data(init), parent(NULL), left(NULL), right(NULL) {}


private:
    T data;
    node* parent;
    node* left;
    node* right;
};

template <class T>
class BTree
{
public:
    BTree() : root_(NULL), depth_(-1) {}
    ~BTree() { clearTree(); }

    node<T>* getRoot() { return root_;}
    int getDepth();
    int recDepth(node * currentNode);
    void insert(T data);
    void clearTree();

private:
    node<T>* root_;
    int depth_;

    void recInsert(node * insertNode, node* currentNode);

};