#ifndef __MYNUMBER_H__
#define __MYNUMBER_H__

#include <algorithm>
#include <iostream>
using namespace std;

template <typename DataType>
class MyNumber
{
public:
    explicit MyNumber(DataType rhs = 0) // default constructor
    {
        num = new DataType(rhs);
    }

    MyNumber(const MyNumber<DataType> &rhs) // copy constructor with a MyNumber instance
    {
        num = new DataType(*rhs.num);
    }

    MyNumber(MyNumber<DataType> &&rhs) // move constructor with a MyNumber instance
    {
        num = rhs.num;
        rhs.num = nullptr;
    }

    MyNumber &operator=(const MyNumber<DataType> &rhs) // copy assignment with a MyNumber instance
    {
        if (this != &rhs) {
            auto tmp = new DataType(*rhs.num);
            delete num;
            num = tmp;
        }
        return *this;
    }

    MyNumber &operator=(MyNumber<DataType> &&rhs) // move assignment with a MyNumber instance
    {
        if (this != &rhs) {
            delete num;
            num = rhs.num;
            rhs.num = nullptr;
        }
        return *this;
    }

    ~MyNumber(void) // destructor
    {
        delete num;
    }

    DataType read(void) const
    {
        return *num;
    }

    void write(DataType rhs)
    {
        auto tmp = new DataType(rhs);
        std::swap(tmp, num);
        delete tmp;
    }

private:
    /* data */
    DataType *num;
};

#endif // __MYVECTOR_H__