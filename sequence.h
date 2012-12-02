#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED

template<class T>
class Sequence {

    public:
        virtual void append(const T&)            = 0;
        virtual void clear()                     = 0;
        virtual void insert(const T&, const int) = 0;
        virtual void pop_tail()                  = 0;
        virtual void pop_head()                  = 0;
        virtual void prepend(const T&)           = 0;
        virtual void remove(const int)           = 0;
        virtual void reverse()                   = 0;
        virtual void swap(const int, const int)  = 0;

        virtual bool has(const T&)        const  = 0;
        virtual int size()                const  = 0;
        virtual T&  operator[](const int)        = 0;
        virtual T&  operator[](const int) const  = 0;
        virtual T& get(const int pos)     const  = 0;

};

#endif // SEQUENCE_H_INCLUDED
