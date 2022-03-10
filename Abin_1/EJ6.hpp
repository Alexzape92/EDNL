#ifndef EJ6_HPP_
#define EJ6_HPP_
#include "Abin_d.hpp"
#include "EJ2.hpp"
#include <algorithm>

template<typename t>
int Deseq(const Abin<t>& A);

template<typename t>
int Deseq_Rec(typename Abin<t>::nodo n, const Abin<t>& A);

//PRIVADAS
int maxi(int a, int b, int c);


template<typename t>
int Deseq(const Abin<t>& A){
    return Deseq_Rec(A.raiz(), A);
}

template<typename t>
int Deseq_Rec(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n != Abin<t>::NODO_NULO){
        return maxi(abs(Altura_Rec(A.hijoIzqdo(n), A) - Altura_Rec(A.hijoDrcho(n), A)), 
        Deseq_Rec(A.hijoIzqdo(n), A), Deseq_Rec(A.hijoDrcho(n), A));
    }
    else
        return 0;
}

#endif