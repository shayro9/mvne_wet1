#include "Tree.h"
int main()
{
    Tree<int> test;
    node<int>* root = nullptr;
    root = test.insert(root,1);
    root = test.insert(root,2);
    root = test.insert(root,3);
    root = test.insert(root,4);
    root = test.insert(root,5);
    return 0;
}