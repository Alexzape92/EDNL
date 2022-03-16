#ifndef EJ3_HPP_
#define EJ3_HPP_
#include "Agen_v.hpp"
#include <algorithm>

template<typename t>
int deseqAgen(const Agen<t>& A);

template<typename t>
int deseqAgen_rec(typename Agen<t>::nodo n, const Agen<t>& A);

template<typename t>
int AlturaNodoAgen(typename Agen<t>::nodo n, const Agen<t>& A);


template<typename t>
int AlturaNodoAgen(typename Agen<t>::nodo n, const Agen<t>& A){
    if(n == Agen<t>::NODO_NULO)
        return -1;
    else{
        int altmax = 0;
        typename Agen<t>::nodo hijo = A.hijoIzqdo(n);
        
        if(hijo != Agen<t>::NODO_NULO)
            altmax++;

        int alt = altmax;
        while(hijo != Agen<t>::NODO_NULO){
            alt = 1;
            alt = std::max(alt + AlturaNodoAgen(hijo, A), altmax);
            if(alt > altmax)
                altmax = alt;
            hijo = A.hermDrcho(hijo);
        }

        return altmax;
    }
}


#endif