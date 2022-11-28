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
    node* parent;
};

template <class T>
class Tree {
private:
    node<T>* m_root;

    int balanceFactor(node<T> *n);
    node<T>* find(node<T> *root, const T& t);
    node<T>* insert(node<T> *root, const T& t);
    node<T>* removeNode(node<T> *root, const T& t);
    node<T>* minValueNode(node<T> *root);
    node<T>* balance(node<T> *bad_node);
    node<T>* RR_rotate(node<T> *root);
    node<T>* LL_rotate(node<T> *root);
    node<T>* RL_rotate(node<T> *root);
    node<T>* LR_rotate(node<T> *root);

    void preOrder(node<T>* root, void (*func)(node<T>*));
    void inOrder(node<T>* root, void (*func)(node<T>*));
    void postOrder(node<T>* root, void (*func)(node<T>*));

protected:
    int height(node<T>* n);

public:
    Tree();
    Tree(const Tree& t)=default;
    ~Tree()=default;
    Tree& operator=(const Tree& q)=default;

    node<T>* find(const T& t);
    void insert(const T& t);
    void remove(const T& t);

    void preOrder(void (*func)(node<T>*));
    void inOrder(void (*func)(node<T>*));
    void postOrder(void (*func)(node<T>*));
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
    m_root = insert(m_root,t);
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

template<class T>
node<T>* Tree<T>::find(node<T>* root, const T &t) {
    if(root != nullptr) {
        if (t == root->data)
            return root;
        if (t < root->data)
            return find(root->l, t);
        else
            return find(root->r, t);
    }
    return nullptr;
}

template<class T>
node<T>* Tree<T>::find(const T &t) {
    return find(m_root,t);
}

template<class T>
node<T> *Tree<T>::minValueNode(node<T> *root) {
    if(root == nullptr)
        return nullptr;

    if(root->l == nullptr)
        return root;

    return minValueNode(root->l);
}

template<class T>
node<T> *Tree<T>::removeNode(node<T> *root, const T &t) {
    if(root == nullptr)
        return root;


    if(t < root->data) {
        root->l = removeNode(root->l,t);
    }

    else if(t > root->data)
        root->r = removeNode(root->r,t);

    else{
        if(root->r == nullptr && root->l == nullptr) {
            return nullptr;
        }
        else if (root->l == nullptr) {
            node<T>* temp = root->r;
            delete(root);
            return temp;
        }
        else if (root->r == nullptr) {
            node<T>* temp = root->l;
            delete(root);
            return temp;
        }

        node<T>* temp = minValueNode(root->r);
        root->data = temp->data;
        root->r = removeNode(root->r,temp->data);
    }
    return root;
}

template<class T>
void Tree<T>::remove(const T &t) {
    node<T>* new_node = removeNode(m_root,t);
    int h = 0, new_h = -1;
    while(h != new_h) {
        h = height(new_node);
        balance(new_node);
        new_h = height(new_node);
    }
}

template<class T>
void Tree<T>::inOrder(node<T>* root, void (*func)(node<T> *)) {
    if(root == nullptr)
        return;

    inOrder(root->l,func);
    func(root);
    inOrder(root->r,func);
}

template<class T>
void Tree<T>::inOrder(void (*func)(node<T> *)) {
    inOrder(m_root,func);
}

template<class T>
void Tree<T>::preOrder(node<T> *root, void (*func)(node<T> *)) {
    if(root == nullptr)
        return;

    func(root);
    preOrder(root->l,func);
    preOrder(root->r,func);
}

template<class T>
void Tree<T>::preOrder(void (*func)(node<T> *)) {
    preOrder(m_root, func);
}

template<class T>
void Tree<T>::postOrder(node<T> *root, void (*func)(node<T> *)) {
    if(root == nullptr)
        return;

    postOrder(root->l,func);
    postOrder(root->r,func);
    func(root);
}

template<class T>
void Tree<T>::postOrder(void (*func)(node<T> *)) {
    postOrder(m_root, func);
}


#endif //MVNE_WET1_TREE_H
