//
// Created by shayr on 23/11/2022.
//

#ifndef MVNE_WET1_TREE_H
#define MVNE_WET1_TREE_H

template <class T>
struct node{
    T data;
    node* l;
    node* r;
};

template <class T>
class Tree {
public:
    Tree() = default;
    Tree(const Tree& t) = default;
    ~Tree() = default;
    Tree& operator=(const Tree& q) = default;
    int height(node<T>* n);
    int balanceFactor(node<T>* n);
    node<T>* find(node<T>* n, const T& t);
    node<T>* insert(node<T>* root, const T& t);
    node<T>* RR_rotate(node<T>* root);
    node<T>* LL_rotate(node<T>* root);
    node<T>* RL_rotate(node<T>* root);
    node<T>* LR_rotate(node<T>* root);
    void remove(const T& t);
};

template <class T>
int Tree<T>::height(node<T> *n) {
    int h = 0;
    if(n != nullptr)
    {
        int left_height, right_height;
        left_height = height(n->l);
        right_height = height(n->r);
        h = (left_height > right_height ? left_height : right_height) + 1;
    }
    return h;
}

template<class T>
int Tree<T>::balanceFactor(node<T> *n) {
    int left_height, right_height;
    left_height = height(n->l);
    right_height = height(n->r);
    return left_height - right_height;
}

template<class T>
node<T>* Tree<T>::find(node<T>* n, const T &t) {
    if(n != nullptr) {
        if (t == n->data)
            return n;
        if (t < n->data)
            return find(n->l, t);
        return find(n->r, t);
    }
    return nullptr;
}

template<class T>
node<T> *Tree<T>::insert(node<T> *root, const T &t) {
    if(root == nullptr)
    {
        root = new node<T>();
        root->data = t;
        root->l = nullptr;
        root->r = nullptr;
    }
    else if(t < root->data)
        root->l = insert(root->l,t);
    else if(t >= root->data)
        root->r = insert(root->r,t);
    return root;
}

template<class T>
node<T> *Tree<T>::LL_rotate(node<T> *root) {
    
}




#endif //MVNE_WET1_TREE_H
