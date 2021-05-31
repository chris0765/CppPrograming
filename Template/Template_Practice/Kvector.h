#ifndef __KVECTOR_H__
#define __KVECTOR_H__
#include <algorithm>
#include <cstring>
#include <iostream>

template <typename T>
class Kvector;
template <typename T>
bool operator==(const Kvector<T> &v, const Kvector<T> &w);
template <typename T>
bool operator!=(const Kvector<T> &v, const Kvector<T> &w);
template <typename T>
std::ostream &operator<<(std::ostream &os, const Kvector<T> &v);

template <typename T>
class Kvector
{
protected:
    T *underlying_array;
    int length;

public:
    Kvector<T>(int length = 0, T value = 0);
    Kvector<T>(const Kvector<T> &v);
    ~Kvector<T>();

    void print();
    void clear();
    int size() const;
    T sum() const;

    Kvector<T> &operator=(const Kvector<T> &rhs);
    friend bool operator==<>(const Kvector<T> &lhs, const Kvector<T> &rhs);
    friend bool operator!=<>(const Kvector<T> &lhs, const Kvector<T> &rhs);
    friend std::ostream &operator<<<>(std::ostream &os, const Kvector<T> &v);

    const T &operator[](const int) const;
    T &operator[](const int);
};

#include "Kvector.cpp"
#endif