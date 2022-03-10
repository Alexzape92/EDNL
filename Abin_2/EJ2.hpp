#ifndef EJ2_HPP_
#define EJ2_HPP_
#include "Abin_d.hpp"

template<typename t>
Abin<t> reflex(const Abin<t>& A);

template<typename t>
void reflex_Rec(typename Abin<t>::nodo na, typename Abin<t>::nodo nb, const Abin<t>& A, Abin<t>& B);


template<typename t>
Abin<t> reflex(const Abin<t>& A){
    Abin<t> B;      //B = Árbol vacío

    if(A.arbolVacio())
        return B;
    else{
        B.insertarRaiz(A.elemento(A.raiz()));
        reflex_Rec(A.raiz(), B.raiz(), A, B);
        return B;
    }
}

template<typename t>
void reflex_Rec(typename Abin<t>::nodo na, typename Abin<t>::nodo nb, const Abin<t>& A, Abin<t>& B){
    if(A.hijoIzqdo(na) != Abin<t>::NODO_NULO){
        B.insertarHijoDrcho(nb, A.elemento(A.hijoIzqdo(na)));
        reflex_Rec(A.hijoIzqdo(na), B.hijoDrcho(nb), A, B);
    }
    if(A.hijoDrcho(na) != Abin<t>::NODO_NULO){
        B.insertarHijoIzqdo(nb, A.elemento(A.hijoDrcho(na)));
        reflex_Rec(A.hijoDrcho(na), B.hijoIzqdo(nb), A, B);
    }
}



#endif