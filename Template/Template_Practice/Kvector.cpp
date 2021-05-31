#include "Kvector.h"
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#ifndef __KVECTOR_CPP__
#define __KVECTOR_CPP__
template <typename T>
Kvector<T>::Kvector(int length, T value) : length(length)
{
    underlying_array = new T[length];
    fill_n(underlying_array, length, value);
    cout << this << " : Kvector(" << length << ", " << value << ")" << endl;
}

template <typename T>
Kvector<T>::Kvector(const Kvector<T> &v)
{
    underlying_array = new T[v.size()];
    memcpy(underlying_array, v.underlying_array, sizeof(int) * v.size());
    length = v.length;
    cout << this << " : Kvector(* " << this << ")" << endl;
}

template <typename T>
Kvector<T>::~Kvector()
{
    cout << this << ": ~Kvector()" << endl;
}

template <typename T>
void Kvector<T>::clear()
{
    delete[] underlying_array;
    underlying_array = nullptr;
    length = 0;
}

template <typename T>
void Kvector<T>::print()
{
    cout << *this << endl;
}

template <typename T>
int Kvector<T>::size() const
{
    return length;
}

template <typename T>
T Kvector<T>::sum() const
{
    if (length < 0)
        return T();
    T s = underlying_array[0];
    for_each(
        underlying_array + 1, underlying_array + length, [&s](auto x)
        { s += x; });
    return s;
}

template <typename T>
Kvector<T> &Kvector<T>::operator=(const Kvector<T> &rhs)
{
    if (length != 0)
    {
        clear();
    }
    length = rhs.length;
    underlying_array = new T[length];
    memcpy(underlying_array, rhs.underlying_array, sizeof(T) * rhs.size());
    return *this;
}

template <typename T>
bool operator==(const Kvector<T> &lhs, const Kvector<T> &rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    for (auto i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator!=(const Kvector<T> &lhs, const Kvector<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
const T &Kvector<T>::operator[](const int idx) const
{
    assert(0 <= idx && idx < size());
    return underlying_array[idx];
}

template <typename T>
T &Kvector<T>::operator[](const int idx)
{
    assert(0 <= idx && idx < size());
    return underlying_array[idx];
}

template <typename T>
ostream &operator<<(ostream &os, const Kvector<T> &vector)
{
    for_each(vector.underlying_array, vector.underlying_array + (vector.length), [&os](T &x)
             { os << x << ' '; });
    return os;
}
#endif