#ifndef EJ1_HPP_
#define EJ1_HPP_
#include "Agen_d.hpp"
#include <algorithm>

template<typename t>
int gradoAgen(const Agen<t>& A);

template<typename t>
int gradoAgen_Rec(typename Agen<t>::nodo n, const Agen<t>& A);

template<typename t>
int numhijos(typename Agen<t>::nodo n, const Agen<t>& A);

template<typename t>
int numhermanos(typename Agen<t>::nodo n, const Agen<t>& A);



template<typename t>
int gradoAgen(const Agen<t>& A){
    return gradoAgen_Rec(A.raiz(), A);
}

template<typename t>
int gradoAgen_Rec(typename Agen<t>::nodo n, const Agen<t>& A){
    if (n == Agen<t>::NODO_NULO)
        return 0;
    else{
        int gr = numhijos(n, A);
        typename Agen<t>::nodo hijo = A.hijoIzqdo(n, A);
        while(hijo != Agen<t>::NODO_NULO){
            gr = std::max(gr, gradoAgen_Rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return gr;
    }
}

//AUXILIARES-------------------------------------------------------------------

template<typename t>
int numhijos(typename Agen<t>::nodo n, const Agen<t>& A){
    if(A.hijoIzqdo(n) == Agen<t>::NODO_NULO)
        return 0;
    else
        return numhermanos(A.hijoIzqdo(n), A);
}

template<typename t>
int numhermanos(typename Agen<t>::nodo n, const Agen<t>& A){
    if(n == Agen<t>::NODO_NULO)
        return 0;
    else
        return 1 + numhermanos(A.hermDrcho(n), A);
}







#endif