#ifndef MVNE_WET1_TREE_H
#define MVNE_WET1_TREE_H

#include "exception"
#include "new"

template <class T>
struct node{
    T data;
    node* l;
    node* r;
    node* parent;
};

template <class T>
class Tree {
public:
    Tree();
    explicit Tree(node<T>*);
    ~Tree();
    void DestroyRecursive(node<T>* node);
    Tree(const Tree& t) = default;
    Tree& operator=(const Tree& q)=default;

    node<T>* find(const T& t);
    void insert(T& t);
    void remove(const T& t);

    node<T>* getMax();
    void setMax();
    node<T>* findMaxSmaller(const T& t);
    node<T>* findMinBigger(const T& t);
    void merge(Tree<T>& t, int n, int m);

    void tree2ArrayInOrder(T * output, bool (*cond)(node<T>*));

    void tree2ArrayInOrder(T * output);
    void tree2IDArrayInOrder(int * output);
    void preOrder(void (*func)(node<T>*));
    void inOrder(void (*func)(node<T>*,int),int num);
    void postOrder(void (*func)(node<T>*));

private:
    node<T>* m_root;
    node<T>* m_max;

    int balanceFactor(node<T> *n);
    node<T>* findNode(node<T> *root, const T& t);
    node<T>* findMaxSmallerNode(node<T>* root, const T& t);
    node<T>* findMinBiggerNode(node<T>* root, const T& t);
    node<T>* insertNode(node<T> *root, const T& t);
    node<T>* removeNode(node<T> *root, const T& t);
    node<T>* minValueNode(node<T> *root);
    node<T>* maxValueNode(node<T> *root);
    node<T>* balance(node<T> *bad_node);

    node<T>* RR_rotate(node<T> *root);
    node<T>* LL_rotate(node<T> *root);
    node<T>* RL_rotate(node<T> *root);
    node<T>* LR_rotate(node<T> *root);

    void preOrder(node<T>* root, void (*func)(node<T>*));
    void inOrder(node<T>* root, void (*func)(node<T>*,int),int num);
    void postOrder(node<T>* root, void (*func)(node<T>*));
    int tree2ArrayInOrder_rec(node<T>* root, T *output, int index, bool (*cond)(node<T>*));
    int tree2IDArrayInOrder_rec(node<T> *root, int *output, int index);
    node<T>* sortedArray2Tree( T *input,int start, int end);
    int height(node<T>* n);
};

template<class T>
void Tree<T>::DestroyRecursive(node<T>* node)
{
    if (node)
    {
        DestroyRecursive(node->l);
        DestroyRecursive(node->r);
        if(node == m_root)
            m_root = nullptr;
        if(node == m_max)
            m_max = nullptr;
        delete(node);
    }
}

template<class T>
Tree<T>::~Tree() {
    if(m_root)
        DestroyRecursive(m_root);
}

template<class T>
Tree<T>::Tree(node<T>* node) : Tree(){
    m_root = node;
    setMax();
}

template<class T>
node<T>* Tree<T>::findMaxSmaller(const T &t) {

    return findMaxSmallerNode(m_root, t);
}
template<class T>
node<T>* Tree<T>::findMinBigger(const T &t) {
    return findMinBiggerNode(m_root, t);
}


template<class T>
node<T>* Tree<T>::findMinBiggerNode(node<T> *root, const T &t) {
    if(root == nullptr)
        return nullptr;
    if(!root->l && !root->r) {
        if (root->data <= t)
            return nullptr;
        else
            return root;
    }
    if(root->data < t)
        return findMinBiggerNode(root->r,t);
    else if(root->data > t) {
        node<T>* right_smallest_max = findMinBiggerNode(root->l,t);
        if(right_smallest_max)
            return root->data < right_smallest_max->data ? root : right_smallest_max;
        else
            return root;
    }
    else{
        if(root->r)
            return minValueNode(root->r);
        else
            return nullptr;
    }
}
template<class T>
node<T>* Tree<T>::findMaxSmallerNode(node<T> *root, const T &t) {
    if(root == nullptr)
        return nullptr;
    if(!root->l && !root->r) {
        if (root->data >= t)
            return nullptr;
        else
            return root;
    }
    if(root->data > t)
        return findMaxSmallerNode(root->l,t);
    else if(root->data < t) {
        node<T>* right_smallest_max = findMaxSmallerNode(root->r,t);
        if(right_smallest_max)
            return root->data > right_smallest_max->data ? root : right_smallest_max;
        else
            return root;
    }
    else{
        if(root->l)
            return maxValueNode(root->l);
        else
            return nullptr;
    }
}

template<class T>
node<T> *Tree<T>::maxValueNode(node<T> *root){
    if(root == nullptr)
        return nullptr;
    if (root->r == nullptr){
        return root;
    }
    return maxValueNode(root->r);
}


template <class T>
Tree<T>::Tree() : m_root(nullptr), m_max(nullptr)
{}

template <class T>
node<T>* Tree<T>::getMax() {
    return m_max;
}

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
    if(!n)
        return 0;

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
node<T> *Tree<T>::insertNode(node<T> *root, const T& t) {
    if(root == nullptr)
    {
        root = new node<T>();
        root->data = t;
        root->l = nullptr;
        root->r = nullptr;

        if(m_max == nullptr)
            m_max = root;
        if (t > m_max->data){
            m_max = root;
        }
    }
    else if(t < root->data) {
        root->l = insertNode(root->l, t);
        root = balance(root);

    }
    else if(t >= root->data) {
        root->r = insertNode(root->r, t);
        root = balance(root);
    }
    return root;
}

template<class T>
void Tree<T>::insert(T &t) {
    m_root = insertNode(m_root,t);
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
node<T>* Tree<T>::findNode(node<T>* root, const T &t) {
    if(root != nullptr) {
        if (t == root->data)
            return root;
        if (t < root->data)
            return findNode(root->l, t);
        else
            return findNode(root->r, t);
    }
    return nullptr;
}

template<class T>
node<T>* Tree<T>::find(const T &t) {
    return findNode(m_root,t);
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

    else if(t > root->data) {
        if (root->r->data == m_max->data){
            m_max = root;
        }
        root->r = removeNode(root->r, t);
    }

    else{
        if(root->r == nullptr && root->l == nullptr) {
            if(root == m_root)
            {
                m_root = nullptr;
                m_max = nullptr;
            }
            delete(root);
            return nullptr;
        }
        else if (root->l == nullptr) {
            node<T>* temp = root->r;
            if(root == m_root)
                m_root = temp;
            delete(root);
            return temp;
        }
        else if (root->r == nullptr) {
            node<T>* temp = root->l;
            if(root == m_root)
                m_root = temp;
            delete(root);
            return temp;
        }

        node<T>* temp = minValueNode(root->r); //complexity issue
        if(temp == m_max)
            m_max = root;
        root->data = temp->data;
        root->r = removeNode(root->r,temp->data);
    }
    int h = 0, new_h = -1;
    while(h != new_h)
    {
        h = height(root);
        if(root == m_root)
            m_root = balance(root);
        else
            root = balance(root);
        new_h = height(root);
    }
    return root;
}

template<class T>
void Tree<T>::remove(const T &t) {
    removeNode(m_root,t);
}

template<class T>
void Tree<T>::inOrder(node<T>* root, void (*func)(node<T> *,int), int num) {
    if(root == nullptr)
        return;

    inOrder(root->l,func, num);
    func(root,num);
    inOrder(root->r,func, num);
}

template<class T>
void Tree<T>::inOrder(void (*func)(node<T> *,int), int num) {
    inOrder(m_root,func,num);
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

template<class T>
void Tree<T>::tree2IDArrayInOrder(int *output) {
    tree2IDArrayInOrder_rec(m_root, output, 0);
}

template<class T>
int Tree<T>::tree2IDArrayInOrder_rec(node<T> *root, int *output, int index) {
    if(root == nullptr)
        return index;

    index = tree2IDArrayInOrder_rec(root->l, output, index);
    output[index++] = (int)root->data;
    return tree2IDArrayInOrder_rec(root->r, output, index);

}

template<class T>
void Tree<T>::tree2ArrayInOrder(T * output, bool (*cond)(node<T>*)) {
    tree2ArrayInOrder_rec(m_root,output,0,cond);
}

template <class T>
bool cond_all(node<T>*)
{
    return true;
}

template<class T>
void Tree<T>::tree2ArrayInOrder(T *output) {
    tree2ArrayInOrder_rec(m_root,output, 0, cond_all);
}

template<class T>
int Tree<T>::tree2ArrayInOrder_rec(node<T> *root, T *output, int index, bool (*cond)(node<T>*)) {
    if(root == nullptr)
        return index;

    index = tree2ArrayInOrder_rec(root->l,output,index,cond);
    if(cond(root))
        output[index++] = root->data;
    return tree2ArrayInOrder_rec(root->r,output,index, cond);

}

template<class T>
node<T>* Tree<T>::sortedArray2Tree(T *input, int start, int end) {
    if(start > end)
        return nullptr;

    int mid = (start + end)/2;
    try {
        node<T> *root = new node<T>();
        root->data = input[mid];
        root->l = sortedArray2Tree(input,start,mid - 1);
        root->r = sortedArray2Tree(input,mid + 1, end);
        if(m_max != nullptr) {
            if (input[mid] > m_max->data) {
                m_max = root;
            }
        }
        else
            m_max = root;
        return root;
    }
    catch (std::bad_alloc& e) {
        throw e;
    }
}

template<class T>
void Tree<T>::merge(Tree<T> &t,const int n,const int m) {
    try {
        T *array1 = new T[n];
        T *array2 = new T[m];
        T *merged_array = new T[n+m];

        int k = 0, j = 0;

        this->tree2ArrayInOrder(array1);
        t.tree2ArrayInOrder(array2);

        while (k < n && j < m) {
            if (array1[k] < array2[j]) {
                merged_array[k + j] = array1[k];
                k++;
            } else {
                merged_array[k + j] = array2[j];
                j++;
            }
        }
        if (k >= n)
            for (; j < m; ++j) {
                merged_array[k + j] = array2[j];
            }
        else
            for (; k < n; ++k) {
                merged_array[k + j] = array1[k];
            }

        t.DestroyRecursive(t.m_root);
        DestroyRecursive(m_root);
        node<T>* temp = sortedArray2Tree(merged_array, 0, k + j - 1);
        delete[] array1;
        delete[] array2;
        delete[] merged_array;
        m_root = temp;
        setMax();
    }
    catch (...) {
        throw std::bad_alloc();
    }
}

template<class T>
void Tree<T>::setMax() {
    m_max = maxValueNode(m_root);
}

#endif //MVNE_WET1_TREE_H
