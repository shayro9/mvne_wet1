#include "Tree.h"
#include "iostream"

void printN(node<int>* node)
{
    std::cout << node->data << " ";
}

int main()
{
    Tree<int> test;
    Tree<int> test2;

    test.insert(4);
    test.insert(2);
    test.insert(1);
    test.insert(6);
    test.insert(5);
    test2.insert(3);
    test2.insert(7);
    test2.insert(8);
    test2.insert(9);
    test2.insert(10);

    test.merge(test2,5,5);
    return 0;
}