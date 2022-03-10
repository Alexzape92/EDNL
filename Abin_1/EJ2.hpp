#ifndef EJ2_HPP_
#define EJ2_HPP_

#include <algorithm>
#include "Abin_d.hpp"

template<typename t>
int Altura(const Abin<t>& A);

template<typename t>
int Altura_Rec(typename Abin<t>::nodo n, const Abin<t>& A);


template<typename t>
int Altura(const Abin<t>& A){
    return Altura_Rec(A.raiz(), A);
}

template<typename t>
int Altura_Rec(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return -1;
    else{
        return (1 + std::max(Altura_Rec(A.hijoIzqdo(n), A), Altura_Rec(A.hijoDrcho(n), A)));
    }
}

#endif
