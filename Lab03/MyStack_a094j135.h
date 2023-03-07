#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>
#include <algorithm>

#include "MyVector_a094j135.h"

template <typename DataType>
class MyStack : private MyVector<DataType>
{  
  public:

    // default constructor
    explicit MyStack(size_t initSize = 0)
    {
        // code begins
        MyVector<DataType>::resize(initSize);
        // code ends
    }

    // copy constructor
    MyStack(const MyStack & rhs) : MyVector<DataType>(rhs)
    {
        // code begins
        
        // code ends
    }

    // move constructor
    MyStack(MyStack && rhs) : MyVector<DataType>(std::move(rhs))
    {
        // code begins

        // code ends
    }

    // destructor
    ~MyStack() 
    {
        delete [] this->m_data;
    }

    // copy assignment
    MyStack & operator= (const MyStack & rhs)
    {
        // code begins
        if (this != &rhs) {
            MyVector<DataType>::operator=(rhs);
        }

        return *this;
        // code ends
    }

    // move assignment
    MyStack & operator= (MyStack && rhs)
    {
        // code begins
        if (this != &rhs) {
            MyVector<DataType>::operator=(std::move(rhs));
        }

        return *this;
        // code ends
    }

    // insert x to the stack
    void push(const DataType & x)
    {
        // code begins
        if (this->size() == this->capacity()) {
            this->resize(this->size() + 1);
        }

        this->m_data[this->size()] = x;
        this->m_size++;
        // code ends
    }

    // insert x to the stack
    void push(DataType && x)
    {
        // code begins
        if (this->size() == this->capacity()) {
            this->resize(this->size() + 1);
        }

        this->m_data[this->size()] = std::move(x);
        this->m_size++;
        // code ends
    }

    // remove the last element from the stack
    void pop(void)
    {
        // code begins
        if (this->size() == 0) {
            return;
        }

        this->m_size--;
        // code ends
    }

    // access the last element of the stack
    const DataType & top(void) const
    {
        // code begins

        // code ends
    }

    // check if the stack is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins
        if (this->size() == 0) {
            return true;
        }

        return false;
        // code ends
    }

    // access the size of the stack
    size_t size() const
    {
        // code begins
        if (this->m_size == 0) {
            return 0;
        }

        return this->m_size;
        // code ends
    }

    // access the capacity of the stack
    size_t capacity(void) const 
    {
        // code begins
        if (this->m_capacity == 0) {
            return 0;
        }

        return this->m_capacity;
        // code ends
    }

};


#endif // __MYSTACK_H__