#ifndef SEPT_21_HPP
#define SEPT_21_HPP
#include "Abin_d.hpp"

template<typename t>
void transf(Abin<t>& A);

//PRIVADAS-----------------------------------------------------------------------
template<typename t>
void transf_Rec(typename Abin<t>::nodo n, Abin<t>& A);

template<typename t>
void podar(typename Abin<t>::nodo n, Abin<t>& A);

template<typename t>
bool MenorIgualDescP(typename Abin<t>::nodo n, Abin<t>&A, t x);

template<typename t>
bool MayorIgualAscP(typename Abin<t>::nodo n, Abin<t>&A, t x);
//---------------------------------------------------------------------------------


template<typename t>
void transf(Abin<t>& A){
    if(!A.arbolVacio()){
        transf_Rec(A.hijoIzqdo(A.raiz()), A);
        transf_Rec(A.hijoDrcho(A.raiz()), A);
    }
}

//PRIVADAS------------------------------------------------------------------------
template<typename t>
void transf_Rec(typename Abin<t>::nodo n, Abin<t>& A){
    if(n != Abin<t>::NODO_NULO && (A.hijoIzqdo(n) != Abin<t>::NODO_NULO || A.hijoDrcho(n) != Abin<t>::NODO_NULO)){  //No comprobamos ni raíz ni hojas
        if(MenorIgualDescP(n, A, A.elemento(n)) && MayorIgualAscP(n, A, A.elemento(n)))
            podar(n, A);
        else{
            transf_Rec(A.hijoIzqdo(n), A);
            transf_Rec(A.hijoDrcho(n), A);
        }
    }
}

template<typename t>
void podar(typename Abin<t>::nodo n, Abin<t>& A){
    if(n != Abin<t>::NODO_NULO){    //Postorden
        podar(A.hijoIzqdo(n), A);
        podar(A.hijoDrcho(n), A);

        //Procesamos
        if(A.hijoIzqdo(n) != Abin<t>::NODO_NULO)
            A.eliminarHI(n);
        if(A.hijoDrcho(n) != Abin<t>::NODO_NULO)
            A.eliminarHD(n);
    }
}

template<typename t>
bool MenorIgualDescP(typename Abin<t>::nodo n, Abin<t>&A, t x){
    if(n == Abin<t>::NODO_NULO)
        return true;    //Si el árbol es vacío, no entrará aquí nunca, así que no hay problema
    else{
        return A.elemento(n) >= x && MenorIgualDescP(A.hijoIzqdo(n), A, x) && MenorIgualDescP(A.hijoDrcho(n), A, x);
    }
}

template<typename t>
bool MayorIgualAscP(typename Abin<t>::nodo n, Abin<t>&A, t x){
    if(n == Abin<t>::NODO_NULO)
        return true;    //Si el árbol es vacío, no entrará aquí nunca, así que no hay problema
    else{
        return A.elemento(n) <= x && MayorIgualAscP(A.padre(n), A, x);
    }
}

#endif