//
// Created by amida on 29/11/2022.
//

#ifndef MVNE_WET1_LINKEDLIST_H
#define MVNE_WET1_LINKEDLIST_H

template <class T>
struct LinkedListNode
{
    T data;
    LinkedListNode *next;
    LinkedListNode *prev;

    LinkedListNode(const T &data)
            : data(data), next(nullptr), prev(nullptr){};
    LinkedListNode(const LinkedListNode &node) = default;
    ~LinkedListNode() = default;
};

template <class T>
struct LinkedList
{

    typedef LinkedListNode<T> *Node;


    Node head;
    Node tail;


    LinkedList() : head(nullptr), tail(nullptr){};
    ~LinkedList(); // TBD remove all nodes
    Node insert(const T &data);
    void remove(Node &node_to_remove);
    const bool isEmpty()
    {
        return !head && head == tail;
    }
    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list)
    {
        Node iterator = list.head;
        while (iterator)
        {
            os << iterator->data;
            iterator = iterator->next;
            if (iterator)
                os << "->";
        }
        os << std::endl;
        return os;
    }
};
template <class T>
LinkedList<T>::~LinkedList()
{
    Node iterator = head;
    while (iterator)
    {
        Node temp_node = iterator;
        iterator = iterator->next;
        delete temp_node;
    }
}
template <class T>
void LinkedList<T>::remove(Node &node_to_remove)
{
    if (node_to_remove->prev)
    {
        node_to_remove->prev->next = node_to_remove->next;
    }
    if (node_to_remove->next)
    {
        node_to_remove->next->prev = node_to_remove->prev;
    }

    // Update head & tail
    head = head == node_to_remove ? node_to_remove->next : head;
    tail = tail == node_to_remove ? node_to_remove->prev : tail;

    delete node_to_remove;
}
template <class T>
LinkedListNode<T> *LinkedList<T>::insert(const T &data) {
    Node *to_allocate = nullptr;
    if (!head && head == tail) {
        to_allocate = &head;
    } else {
        to_allocate = &(tail->next);
    }

    *to_allocate = new LinkedListNode<T>(data);

    (*to_allocate)->prev = tail;
    tail = (*to_allocate);
    return (*to_allocate);
}

#endif //MVNE_WET1_LINKEDLIST_H