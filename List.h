//
// Created by amida on 30/11/2022.
//

#ifndef MVNE_LIST_H
#define MVNE_LIST_H

#endif //MVNE_LIST_H

template<class T>
struct LNode {
    T m_data;
    LNode *m_next;
    LNode *m_prev;
};


template<class T>
class List{
private:
    LNode<T>* m_head;
    LNode<T>* m_tail;
public:
    List();
    ~List();
    //List(const List<T>& l) = delete;
    List<T>& operator=(const List<T>& l) = delete;

    void insertAfter(LNode<T>* prevNode, T data);
    void remove(LNode<T>* node);
    void insertFront(T data);
    void append(T data);
    LNode<T>* getHead();
    LNode<T>* getTail();
    List(LNode<T>* head, LNode<T>* tail);


};

template<class T>
List<T>::List() {
    m_tail = nullptr;
    m_head = nullptr;
}

template<class T>
List<T>::~List() {
    LNode<T>* curr_node = m_head->m_next;
    while (curr_node)
    {
        delete(curr_node->m_prev);
        curr_node = curr_node->m_next;
    }
    delete(m_head);
    delete(m_tail);
}

template<class T>
void List<T>::insertAfter(LNode<T> *prevNode, T data) {
    LNode<T>* newNode = new LNode<T>();
    newNode->m_data = data;
    newNode->m_next = prevNode->m_next;
    prevNode->m_next = newNode;
    newNode->m_prev = prevNode;
    if (newNode->m_next != nullptr){
        newNode->m_next->m_prev = newNode;
    }
}

template<class T>
void List<T>::remove(LNode<T> *node) {
    if ((m_head == nullptr) || (node == nullptr)){
        return;
    }
    if (node == m_head){
        m_head->m_next = node->m_next;
    }
    else{
        node->m_prev->m_next = node->m_next;
    }
    if (node->m_next != nullptr){
        node->m_next->m_prev = node->m_prev;
    }
    delete node;
}

template<class T>
void List<T>::insertFront(T data) {
    LNode<T>* newNode = new LNode<T>();
    newNode->m_data = data;
    m_head = newNode;
    m_tail = newNode;
}

template<class T>
void List<T>::append(T data) {
    LNode<T>* newNode = new LNode<T>();
    newNode->m_data = data;
    newNode->m_prev = m_tail;
    m_tail->m_next = newNode;
    m_tail = newNode;

}

template<class T>
LNode<T> *List<T>::getTail() {
    return m_tail;
}

template<class T>
LNode<T> *List<T>::getHead() {
    return m_head;
}

template<class T>
List<T>::List(LNode<T> *head, LNode<T>* tail) {
    insertFront(head->m_data);
    head = head->m_next;
    while(head != tail){
        append(head->m_data);
        head = head->m_next;
    }

}
