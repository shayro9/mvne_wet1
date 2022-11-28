#include "Tree.h"
#include "iostream"

void printN(node<int>* node)
{
    std::cout << node->data << " ";
}

int main()
{
    Tree<int> test;

    test.insert(4);
    test.insert(2);
    test.insert(1);
    test.insert(6);
    test.insert(5);
    test.insert(3);
    test.insert(7);
    test.insert(8);
    test.insert(9);
    test.insert(10);
    test.inOrder(printN);
    std::cout<< "\n";
    test.preOrder(printN);
    std::cout<< "\n";
    test.postOrder(printN);
    test.remove(5);
    std::cout<< "\n";
    test.inOrder(printN);
    return 0;
}