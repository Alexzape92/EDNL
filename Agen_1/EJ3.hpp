#ifndef EJ3_HPP_
#define EJ3_HPP_
#include "Agen_d.hpp"
#include "cola_dina.h"
#include <algorithm>

template<typename t>
int deseqAgen(const Agen<t>& A);

template<typename t>
int deseqAgen_rec(typename Agen<t>::nodo n, const Agen<t>& A);

template<typename t>
int AlturaNodoAgen(typename Agen<t>::nodo n, const Agen<t>& A);


template<typename t>
int deseqAgen(const Agen<t>& A){
    return deseqAgen_rec(A.raiz(), A);
}

/*template<typename t>
int deseqAgen_rec(typename Agen<t>::nodo n, const Agen<t>& A){
    cola<t> C;
    int altmax = 0, alt = 0;
    do{
        
    }
}*/

template<typename t>
int AlturaNodoAgen(typename Agen<t>::nodo n, const Agen<t>& A){
    int altmax = 0, alt = 0;
    typename Agen<t>::nodo hijo = A.hijoIzqdo(n);

    while(hijo != Agen<t>::NODO_NULO){
        alt = 1 + AlturaNodoAgen(hijo, A);  //Calculamos la altura para ese hijo
        altmax = std::max(altmax, alt);
        hijo = A.hermDrcho(hijo);
    }
    return altmax;
}

#endif