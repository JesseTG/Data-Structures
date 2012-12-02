#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED

#include <iterator>
#include "list.h"

/*namespace std
{

template<typename T>
class std::iterator<std::bidirectional_iterator_tag, List<T>>
{
    public:

        virtual std::iterator<std::bidirectional_iterator_tag, List<T>>& Type::operator=(Iterator<T>&)       = 0;
        virtual Iterator<T>& Type::operator=(const Iterator<T>&) = 0;

        virtual const Iterator<T>& operator++()    = 0;
        virtual const Iterator<T>& operator++(int) = 0;
        virtual const Iterator<T>& operator--()    = 0;
        virtual const Iterator<T>& operator--(int) = 0;
        virtual T& operator*() = 0;
        virtual const T& operator*() const = 0;
        virtual T* operator->() = 0;
        virtual const T* operator->() const = 0;

        virtual bool operator==(const Iterator<T>& other) { return false; }
                bool operator!=(const Iterator<T>& other) { return !(*this == other); }
        virtual bool operator< (const Iterator<T>& other) { return false; }
                bool operator> (const Iterator<T>& other) { return  other < *this;    }
                bool operator<=(const Iterator<T>& other) { return !(*this > other);  }
                bool operator>=(const Iterator<T>& other) { return !(*this < other);  }

        virtual T operator->()

    protected:
        auto traits = std::iterator_traits<List<T>>();
};

}*/

#endif // ITERATOR_H_INCLUDED
