#ifndef EJ4_HPP_
#define EJ4_HPP_
#include "Agen_d.hpp"

template<typename t>
bool ternario(const Agen<t>& A);

template<typename t>
bool ternario_Rec(typename Agen<t>::nodo n,const Agen<t>& A);

template<typename t>
int numHijos(typename Agen<t>::nodo n, const Agen<t>& A);



template<typename t>
bool ternario(const Agen<t>& A){
    if(A.arbolVacio())
        return true;
    else
        return ternario_Rec(A.raiz(), A);
}

template<typename t>
bool ternario_Rec(typename Agen<t>::nodo n,const Agen<t>& A){
    int nh = numHijos(n, A);
    if(nh == 0)
        return true;
    else if(nh == 3){
        bool res = true;
        typename Agen<t>::nodo hijo = A.hijoIzqdo(n);
        while(res && hijo != Agen<t>::NODO_NULO){
            res = ternario_Rec(hijo, A);
            hijo = A.hermDrcho(hijo);
        }
        return res;
    }
    else
        return false;
}

template<typename t>
int numHijos(typename Agen<t>::nodo n, const Agen<t>& A){
    int res = 0;
    typename Agen<t>::nodo hijo = A.hijoIzqdo(n);

    while(hijo != Agen<t>::NODO_NULO){
        res++;
        hijo = A.hermDrcho(hijo);
    }

    return res;
}

#endif