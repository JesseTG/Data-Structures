/*
 * list.h
 *
 *  Created on: Nov 30, 2012
 *      Author: jesse
 */

#ifndef LIST_H_
#define LIST_H_

#define SWAP(x, y) auto temp = (x); x = (y); y = temp

#include <iostream>

template<class T>
struct Node
{
    Node()                                   : prev(nullptr), next(nullptr) {};
    Node(Node<T>* p, const T& e, Node<T>* n) : prev(p), element(e), next(n) {};

    Node<T>* prev   ;
    T        element;
    Node<T>* next   ;
};

template<class T>
class List
{
    public:
        List() : head(nullptr), tail(nullptr) {};
       ~List() { clear(); }                     ;

        void append(const T&)           ;
        void append(List<T>&)           ;
        void clear()                    ;
        void insert(const T&, const int);
        void pop_tail()                 ;
        void pop_head()                 ;
        void prepend(const T&)          ;
        void remove(const int)          ;
        void reverse()                  ;
        void swap(const int, const int) ;

        bool has(const T&) const;

        bool empty()  const                 { return head == nullptr;       }

        int size() const {
            int size = 0;
            for (Node<T>* n = head; n != nullptr; ++size, n = n->next);
            return size;
        }

        T&  operator[](int pos)             { return get(pos);              }
        T&  operator[](const int pos) const { return get(pos);              }
        T&  get(const int pos)              { return getNode(pos)->element; }

        Node<T>* getFirst() { return head; }
        Node<T>* getLast()  { return tail; }

    private:
        Node<T>* head;
        Node<T>* tail;

        void makeFirstNode(const T& element) {
            head = new Node<T>(nullptr, element, nullptr);
            tail = head;
        }

        Node<T>* getNode(const int pos) {
            Node<T>* node = head;
            for (int i = 0; i < pos; ++i, node = node->next);
            return node;
        }


};

template<class T>
void List<T>::clear()
{
    while (head != nullptr) {
    //Iterate through the list...
        Node<T>* temp = head->next;
        delete head;
        head = temp;
    }
}

template<class T>
bool List<T>::has(const T& element) const
{
    Node<T>* node = head;
    while (node != nullptr) {
        if (node->element == element)
            return true;
        else
            node = node->next;
    }
    return false;
}

template<class T>
void List<T>::append(const T& element)
{
    if (empty()) {
    //If the list holds no elements...
        makeFirstNode(element);
    }
    else {
        tail->next = new Node<T>(tail, element, nullptr);
        tail       = tail->next;
    }
}

template<class T>
void List<T>::append(List<T>& other)
{
    for (Node<T>* node = other.getFirst(); node != nullptr; node = node->next) {
        tail->next       = node;
        tail->next->prev = tail;
        tail = tail->next;
    }
    other = List();
}

template<class T>
void List<T>::prepend(const T& element)
{
    if (empty()) {
        makeFirstNode(element);
    }
    else {
        head->prev = new Node<T>(nullptr, element, head);
        head       = head->prev;
    }
}

template<class T>
void List<T>::pop_head()
{
    head = head->next;
    delete head->prev;
}

template<class T>
void List<T>::pop_tail()
{
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
}

template<class T>
void List<T>::insert(const T& element, const int pos)
{
    if (pos == 0 || pos == size) {
    //If the given position is the first or last element...
        if      (pos == 0)    prepend(element);
        else if (pos == size) append(element);
    }
    else {
        Node<T>* node       = getNode(pos);
        Node<T>* newnode    = new Node<T>(node->prev, element, node);
        newnode->prev->next = newnode;
        newnode->next->prev = newnode;
    }
}

template<class T>
void List<T>::swap(const int pos1, const int pos2)
{
    if (pos1 == pos2) return;

    Node<T>* node1 = getNode(pos1);
    Node<T>* node2 = getNode(pos2);

    Node<T> temp = node1;

    node1->prev->next = node2;
    node1->next->prev = node2;
    //Reroute node1's surrounding nodes

    node2->prev->next = node1;
    node2->next->prev = node1;
    //Reroute node2's surrounding nodes

    node1->prev = node2->prev;
    node1->next = node2->next;
    //Reroute node1

    node2->prev = temp->prev;
    node2->next = temp->next;
    //Reroute node2
}

#endif /* LIST_H_ */
