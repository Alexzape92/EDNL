#ifndef ALT_HPP_
#define ALT_HPP
#include "Abin_d.hpp"
#include <algorithm>

template<typename t>
int AlturaAbin(const Abin<t>& A);

template <typename t>
int AlturaNodo(typename Abin<t>::nodo n, const Abin<t>& A);


template<typename t>
int AlturaAbin(const Abin<t>& A){
    return AlturaNodo(A. raiz(), A);
}

template <typename t>
int AlturaNodo(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(AlturaNodo(A.hijoIzqdo(n), A), AlturaNodo(A.hijoDrcho(n), A));
}


#endif