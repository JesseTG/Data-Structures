#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

#include "list.h"
#include "sequence.h"

template<class T>
class Vector : public Sequence<T>
{
    public:
        Vector() : head(nullptr) {};
       ~Vector();

        void append(const T&);
        void clear() {};
        void insert(const T&, const int) {};
        void pop_tail() {};
        void pop_head() {};
        void prepend(const T&) {};
        void remove(const int) {}
        void reverse() {};
        void swap(const int, const int) {};

        bool has(const T&) const { return false; };
        int size() const { return 0; };
        T& operator[](const int pos) { return get(pos); }
        T& operator[](const int pos) const { return get(pos); }
        T& get(const int pos) const { return *(head + pos); }

        T* getFirst() { return head; }

    private:
        T* head;
        T* tail;
};

template<class T>
Vector<T>::~Vector()
{
    while (head != nullptr) {
        std::cout << head << "  " << tail << std::endl;
        delete head;
        std::cout << head << "  " << tail << " Deleted" << std::endl;
    }
}

template<class T>
void Vector<T>::append(const T& element)
{
    if (head == nullptr) {
    //If this vector has no elements...
        head  = new T(element);
        tail  = head;
    }
    else {
        ++tail = new T(element);
    }
    std::cout << head << "  " << tail << std::endl;
}

#endif // VECTOR_H_INCLUDED
