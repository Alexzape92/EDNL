#ifndef EJ1_HPP_
#define EJ1_HPP_

#include "Abin_d.hpp"

template<typename t>
int NumNodos(const Abin<t>& A);

//Esta no es necesaria para el usuario del ejercicio 1, pero la debemos poner en el .h porque es una template
template<typename t>
int NumNodos_Rec(typename Abin<t>::nodo n, const Abin<t>& A);

template<typename t>
int NumNodos(const Abin<t>& A){
    return NumNodos_Rec(A.raiz(), A);
}

template<typename t>
int NumNodos_Rec(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return 0;
    else{
        return (1 + NumNodos_Rec(A.hijoIzqdo(n), A) + NumNodos_Rec(A.hijoDrcho(n), A));
    }
}

#endif