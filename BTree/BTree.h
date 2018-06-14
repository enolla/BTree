#pragma once
#include <cstddef>
#include <queue>


template <class T>
class BTree
{
public:
    class node
    {
    public:
        node();
        node(T init) : data(init), parent(NULL), left(NULL), right(NULL) {}

        T data;
        node* parent;
        node* left;
        node* right;
        void operator=(node* rhs){this = rhs}
        bool operator!=(node* rhs){lhs == rhs? return false: return true}
    };


    BTree() : root_(NULL) {}
    ~BTree() { clearTree(); }

    node* getRoot();
    node* LCA(T data_A, T data_B);
    int getDepth();
    int recDepth(node * currentNode);
    void insert(T data);
    void clearTree();
    void printTree();


private:
    node* root_;


    void dataPath(std::queue<node*>& nodeStack, T data, node * currentNode);
    void recInsert(node * insertNode, node* currentNode);
    void recClearTree(node * currentNode);
    void recPrint(node * currentNode);

};
