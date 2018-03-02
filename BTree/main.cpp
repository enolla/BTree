#include <Windows.h>
#include <iostream>
#include "BTree.cpp"
#include <vector>


int main()
{

    
    std::vector<int> myints;
    myints.push_back(6);
    myints.push_back(31432795);
    myints.push_back(1);
    myints.push_back(3);
    myints.push_back(10);
    myints.push_back(3);
    myints.push_back(5);

    BTree<int> myTree;
    
    for (unsigned i = 0; i < myints.size(); ++i)
    {
        myTree.insert(myints[i]);
    }


    myTree.printTree();

    std::cout << myTree.getDepth() << std::endl;
    

    system("pause");
    return 0;
}