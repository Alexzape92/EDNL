#ifndef EJ2_HPP_
#define EJ2_HPP_
#include "Agen_v.hpp"

template<typename t>
int profAgen(typename Agen<t>::nodo n, const Agen<t>& A);


template<typename t>
int profAgen(typename Agen<t>::nodo n, const Agen<t>& A){
    if(n == Agen<t>::NODO_NULO)
        return -1;
    else{
        return 1 + profAgen(A.padre(n), A);
    }
}

#endif