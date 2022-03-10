#ifndef EJ1_HPP_
#define EJ1_HPP_
#include "Abin_d.hpp"

template<typename t>
bool Simi(const Abin<t>& A1, const Abin<t>& A2);

template<typename t>
bool Simi_Rec(typename Abin<t>::nodo n1, typename Abin<t>::nodo n2, const Abin<t>& A1, const Abin<t>& A2);


template<typename t>
bool Simi(const Abin<t>& A1, const Abin<t>& A2){
    return Simi_Rec(A1.raiz(), A2.raiz(), A1, A2);
}

template<typename t>
bool Simi_Rec(typename Abin<t>::nodo n1, typename Abin<t>::nodo n2, const Abin<t>& A1, const Abin<t>& A2){
    if(n1 == Abin<t>::NODO_NULO && n2 == Abin<t>::NODO_NULO)
        return true;
    else{
        if(n1 == Abin<t>::NODO_NULO || n2 == Abin<t>::NODO_NULO)
            return false;
        else{
            return Simi_Rec(A1.hijoIzqdo(n1), A2.hijoIzqdo(n2), A1, A2) && 
            Simi_Rec(A1.hijoDrcho(n1), A2.hijoDrcho(n2), A1, A2);
        }
    }
}

#endif