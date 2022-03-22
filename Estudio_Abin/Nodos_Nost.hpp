#ifndef NODOS_NOST_HPP_
#define NODOS_NOST_HPP_
#include "Abin_d.hpp"
#include <iostream>

template<typename t>
int numNost(const Abin<t>& A);

template<typename t>
int numNost_Rec(typename Abin<t>::nodo n, const Abin<t>& A);

template<typename t>
bool esNost(typename Abin<t>::nodo n, const Abin<t>& A);

template<typename t>
int antecesoresP(typename Abin<t>::nodo n, const Abin<t>& A);

template<typename t>
int descendientesP(typename Abin<t>::nodo n, const Abin<t>& A);


template<typename t>
int numNost(const Abin<t>& A){
    return numNost_Rec(A.raiz(), A);
}

template<typename t>
int numNost_Rec(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return 0;
    else{
        if(esNost(n, A))    //Nunca le llegará un nulo, no lo debemos comprobar
            return 1 + numNost_Rec(A.hijoIzqdo(n), A) + numNost_Rec(A.hijoDrcho(n), A);
        else
            return numNost_Rec(A.hijoIzqdo(n), A) + numNost_Rec(A.hijoDrcho(n), A);
    }
}

template<typename t>
bool esNost(typename Abin<t>::nodo n, const Abin<t>& A){
    int ant = antecesoresP(n, A), des = descendientesP(n, A) - 1;
    std::cout << "NODO '" << A.elemento(n) << "' : " << ant << " antecesores y " << des << " descendientes propios" << std::endl;
    return (ant > des);
}

template<typename t>
int antecesoresP(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return -1;
    else{
        return 1 + antecesoresP(A.padre(n), A);
    }
}

template<typename t>
int descendientesP(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return 0;
    else{
        return 1 + descendientesP(A.hijoIzqdo(n), A) + descendientesP(A.hijoDrcho(n), A);
    }
}

#endif