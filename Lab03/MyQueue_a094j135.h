#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>
#include <algorithm>

#include "MyVector_a094j135.h"

template <typename DataType>
class MyQueue : private MyVector<DataType>
{  
  private:
    size_t dataStart, dataEnd;

    // changes the size of the array to newSize
    void resize(size_t newSize)
    {
        // code begins
        size_t currSize = this->size();
        if (newSize == currSize) return;

        DataType* newData = new DataType[newSize];

        for (size_t i = 0; i < std::min(currSize, newSize); ++i) 
        {
            newData[i] = this->operator[](i);
        }

        dataStart = 0;
        dataEnd = std::min(currSize, newSize);

        delete[] this->m_data;
        this->m_data = newData;
        this->m_capacity = newSize;
        // code ends
    }

    // requests for newCapacity amount of space
    void reserve(size_t newCapacity)
    {
        // code begins
        if (newCapacity <= this->m_capacity) {
            return;
        }

        MyVector<DataType> temp(newCapacity);
        for (size_t i = 0; i < this->size(); ++i) {
            temp[i] = this->operator[](i);
        }

        dataStart = 0;
        dataEnd = size;
        this->swap(temp);

        // code ends
    }

  public:

    // default constructor
    explicit MyQueue(size_t initSize = 0)
    {
        // code begins
        if (newCapacity <= this->m_capacity) {
            return; // no need to allocate more memory
        }

        DataType* newData = new DataType[newCapacity];

        for (size_t i = 0; i < this->size(); ++i) {
            newData[i] = this->operator[](i);
        }

        delete[] this->m_data;
        this->m_data = newData;
        this->m_capacity = newCapacity;
        // code ends
    }

    // copy constructor
    MyQueue(const MyQueue & rhs)
    {
        // code begins
        dataStart = 0;
        dataEnd = rhs.size();
        // code ends
    }

    // move constructor
    MyQueue(MyQueue && rhs)
    {
        // code begins
        dataStart = 0;
        dataEnd = rhs.size();

        rhs.dataStart = 0;
        rhs.dataEnd = 0;
        // code ends
    }

    // destructor
    ~MyQueue()
    {
        // code begins

        // code ends
    }

    // copy assignment
    MyQueue & operator= (const MyQueue & rhs)
    {
        // code begins
        delete[] this->m_data;
        // code ends
    }

    // move assignment
    MyQueue & operator= (MyQueue && rhs)
    {
        // code begins
        if (this != &rhs) {
            delete[] this->m_data;
            this->m_data = rhs.m_data;
            this->m_capacity = rhs.m_capacity;
            this->m_size = rhs.m_size;
            dataStart = rhs.dataStart;
            dataEnd = rhs.dataEnd;

            rhs.m_data = nullptr;
            rhs.m_capacity = 0;
            rhs.m_size = 0;
            rhs.dataStart = 0;
            rhs.dataEnd = 0;
        }
        // code ends
    }

    // insert x into the queue
    void enqueue(const DataType & x)
    {
        // code begins
        if (this->size() == this->capacity()) {
            this->resize(this->capacity() * 2);
        }

        this->operator[](dataEnd) = x;
        dataEnd = (dataEnd + 1) % this->capacity();
        // code ends
    }

    // insert x into the queue
    void enqueue(DataType && x)
    {
        // code begins
        if (this->size() == this->capacity()) {
            this->resize(this->capacity() * 2);
        }

        this->operator[](dataEnd) = std::move(x);
        dataEnd = (dataEnd + 1) % this->capacity();
        // code ends
    }

    // remove the first element from the queue
    void dequeue(void)
    {
        // code begins
        if (this->empty()) {
            return;
        }

        dataStart = (dataStart + 1) % this->capacity();
        this->pop_front();
        // code ends
    }

    // access the first element of the queue
    const DataType & front(void) const
    {
        // code begins
        if (this->empy()) {
            throw std::out_of_range("Queue is empty");
        }

        return this->operator[](dataStart);
        // code ends
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins
        return this->size() == 0;
        // code ends
    }

    // access the size of the queue
    size_t size() const
    {
        // code begins
        return (dataEnd - dataStart + this->capacity()) % this->capacity(
        // code ends
    }

    // access the capacity of the queue
    size_t capacity(void) const 
    {
        // code begins
        return this->m_capacity;
        // code ends
    }

};

#endif // __MYQUEUE_H__