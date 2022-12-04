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
    LNode<T>* m_last_added;
public:
    List();
    ~List();
    //List(const List<T>& l) = delete;
    List<T>& operator=(const List<T>& l) = delete;

    LNode<T>* getHead();
    LNode<T>* getTail();
    LNode<T>* getLastAdded();

    void insertAfter(LNode<T>* prevNode, T data);
    void remove(LNode<T>* node);
    void insertFront(T data);
    void append(T data);

};

template<class T>
List<T>::List() {
    m_tail = nullptr;
    m_head = nullptr;
    m_last_added = nullptr;
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
    //delete(m_tail);
    //delete(m_last_added);
}

template<class T>
void List<T>::insertAfter(LNode<T> *prevNode, T data) {
    m_last_added = new LNode<T>();
    m_last_added->m_data = data;
    m_last_added->m_next = prevNode->m_next;
    prevNode->m_next = m_last_added;
    m_last_added->m_prev = prevNode;
    if (m_last_added->m_next != nullptr){
        m_last_added->m_next->m_prev = m_last_added;
    }
    else
        m_tail = m_last_added;
}

template<class T>
void List<T>::remove(LNode<T> *node) {
    if ((m_head == nullptr) || (node == nullptr)){
        return;
    }
    if (node == m_head){
        m_head = m_head->m_next;
    }
    else {
        node->m_prev->m_next = node->m_next;

        if (node->m_next != nullptr) {
            node->m_next->m_prev = node->m_prev;
        }
    }
    delete node;
}

template<class T>
void List<T>::insertFront(T data) {
    m_last_added = new LNode<T>();
    m_last_added->m_data = data;
    if(m_head != nullptr){
        m_last_added->m_next = m_head;
        m_head->m_prev = m_last_added;
    }
    m_head = m_last_added;
    if(m_tail == nullptr)
        m_tail = m_last_added;
}

template<class T>
LNode<T> *List<T>::getHead() {
    return m_head;
}

template<class T>
LNode<T> *List<T>::getTail() {
    return m_tail;
}

template<class T>
LNode<T> *List<T>::getLastAdded() {
    return m_last_added;
}

template<class T>
void List<T>::append(T data) {
    m_last_added = new LNode<T>();
    m_last_added->m_data = data;
    m_tail->m_next = m_last_added;
    m_last_added->m_prev = m_tail;
    m_tail = m_last_added;

}
