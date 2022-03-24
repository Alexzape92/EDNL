#ifndef ALT_HPP_
#define ALT_HPP
#include "Abin_d.hpp"

template <typename t>
int ProfNodo(typename Abin<t>::nodo n, const Abin<t>& A);


template <typename t>
int ProfNodo(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return -1;
    else
        return 1 + ProfNodo(A.padre(n), A);
}


#endif