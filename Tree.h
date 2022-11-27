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
    node* f;
};

template <class T>
class Tree {
private:
    node<T>* m_root;

    int height(node<T>* n);
    int balanceFactor(node<T> *n);
    node<T>* find(node<T>* n, const T& t);
    node<T>* insert(node<T> *root, const T& t);
    node<T>* balance(node<T> *bad_node);
    node<T>* RR_rotate(node<T> *root);
    node<T>* LL_rotate(node<T> *root);
    node<T>* RL_rotate(node<T> *root);
    node<T>* LR_rotate(node<T> *root);

public:
    Tree();
    Tree(const Tree& t) = default;
    ~Tree() = default;
    Tree& operator=(const Tree& q) = default;

    void remove(const T& t);
    void insert(const T& t);
    T* find(const T& t);
    

};
template <class T>
Tree<T>::Tree() : m_root(nullptr)
{}

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
node<T>* Tree<T>::balance(node<T> *bad_node) {
    int factor = balanceFactor(bad_node);
    int son_factor;
    switch (factor) {
        case 2:
            son_factor = balanceFactor(bad_node->l);
            if( son_factor >= 0)
                return LL_rotate(bad_node);
            else
                return LR_rotate(bad_node);
        case -2:
            son_factor = balanceFactor(bad_node->r);
            if( son_factor <= 0)
                return RR_rotate(bad_node);
            else
                return RL_rotate(bad_node);
        default:
            return bad_node;
    }
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
    else if(t < root->data) {
        root->l = insert(root->l, t);
        root = balance(root);
    }
    else if(t >= root->data) {
        root->r = insert(root->r, t);
        root = balance(root);
    }
    return root;
}

template<class T>
void Tree<T>::insert(const T &t) {
    if(this->m_root == nullptr)
    {
        m_root = new node<T>();
        m_root->data = t;
        m_root->l = nullptr;
        m_root->r = nullptr;
    }
    else if(t < m_root->data) {
        m_root->l = insert(m_root->l, t);
        m_root = balance(m_root);
    }
    else if(t >= m_root->data) {
        m_root->r = insert(m_root->r, t);
        m_root = balance(m_root);
    }
}

template<class T>
node<T>* Tree<T>::LL_rotate(node<T> *root) {
    node<T> *temp = root->l;
    root->l = temp->r;
    temp->r = root;
    return temp;
}

template<class T>
node<T>*  Tree<T>::RR_rotate(node<T> *root) {
    node<T> *temp = root->r;
    root->r = temp->l;
    temp->l = root;
    return temp;
}

template<class T>
node<T>*  Tree<T>::RL_rotate(node<T> *root) {
    root->r = LL_rotate(root->r);
    return RR_rotate(root);
}

template<class T>
node<T>*  Tree<T>::LR_rotate(node<T> *root) {
    root->l = RR_rotate(root->l);
    return LL_rotate(root);
}


#endif //MVNE_WET1_TREE_H
