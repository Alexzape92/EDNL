#ifndef EJ3_HPP_
#define EJ3_HPP_
#include "Abin_d.hpp"

template<typename t>
int Prof(typename Abin<t>::nodo n, const Abin<t>& A);


template<typename t>
int Prof(typename Abin<t>::nodo n, const Abin<t>& A){
    if (n == Abin<t>::NODO_NULO)
        return -1;
    else{
        return 1+Prof(A.padre(n), A);
    }
}

#endif