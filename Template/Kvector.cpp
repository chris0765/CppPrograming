#include "Kvector.h"

template<typename T>
Kvector<T>::Kvector(int sz, T value): len(sz){
    m = new T[len];
    std::fill_n(m, len, value);
    std::cout<<this<<" : kvector(" << len << ", "<< value << ")" << std::endl;
}
template<typename T>
Kvector<T>::Kvector(const Kvector<T>& v){
    m = new T[v.len];
    memcpy(m, v.m, sizeof(T) * v.len);
    len = v.len;
    std::cout<<this<<" : kvector(*" << this << ")" << std::endl;
}
template<typename T>
Kvector<T>::~Kvector(){
    std::cout<<this<<": ~Kvector()"<<std::endl;
}
template<typename T>
Kvector<T>& Kvector<T>::operator=(const Kvector<T>& v){
    if(len != 0)
        clear();
    len = v.len;
    m = new T[len];
    memcpy(m, v.m, sizeof(T) * v.size());
    return *this;
}
template<typename T>
bool operator==(const Kvector<T>& v, const Kvector<T>& w){
    if(v.len != w.len)
        return false;
    for(int i=0; i<v.len; i++)
        if(v[i] != w[i])
            return false;
    return true;
}
template<typename T>
bool operator!=(const Kvector<T>& v, const Kvector<T>& w){
    return !(v==w);
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const Kvector<T>& v){
    for(int i=0; i<v.len; i++){
        if(i == v.len-1){
            os << v[i];
            break;
        }
        os << v[i] << " ";
    }
    return os;
}