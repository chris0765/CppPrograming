#ifndef _KVECTOR_H_
#define _KVECTOR_H_
#include <iostream>

template<typename T>
class Kvector;
template<typename T>
bool operator==(const Kvector<T>& v, const Kvector<T>& w);
template<typename T>
bool operator!=(const Kvector<T>& v, const Kvector<T>& w);
template<typename T>
std::ostream& operator<<(std::ostream& os, const Kvector<T>& v);

template<typename T>
class Kvector{
protected:
    T *m;
    int len;
public:
    Kvector<T>(int sz = 0, T value = 0);
    Kvector<T>(const Kvector<T>& v);
    ~Kvector<T>();
    void print() const{std::cout << "Kvector\n";}
    void clear(){delete[] m;m = nullptr;len = 0;}
    int size() const{return len;}
    T sum() const{
        if(!len) return T();
        T s = m[0];
        for(int i=1; i<len; i++) s += m[i];
        return s;
    }
    Kvector<T>& operator=(const Kvector<T>& v);
    friend bool operator==<>(const Kvector<T>& v, const Kvector<T>& w);
    friend bool operator!=<>(const Kvector<T>& v, const Kvector<T>& w);
    T& operator[](int idx){return m[idx];}
    const T& operator[](int idx) const {return m[idx];}
    friend std::ostream& operator<<<>(std::ostream& os, const Kvector<T>& v);
};

#endif