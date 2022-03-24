#ifndef DESEQ_HPP_
#define DESEQ_HPP
#include "Abin_d.hpp"
#include "alt.hpp"
#include "arit.hpp"
#include <cmath>

template<typename t>
int DeseqAbin(const Abin<t>& A);

template<typename t>
int DeseqAbin_Rec(typename Abin<t>::nodo n, const Abin<t>& A);



template<typename t>
int DeseqAbin(const Abin<t>& A){
    return DeseqAbin_Rec(A.raiz(), A);
}

template<typename t>
int DeseqAbin_Rec(typename Abin<t>::nodo n, const Abin<t>& A){
    if(n == Abin<t>::NODO_NULO)
        return 0;
    else{
        int Deseqn = abs(AlturaNodo(A.hijoIzqdo(n), A) - AlturaNodo(A.hijoDrcho(n), A));
        return max3(Deseqn, DeseqAbin_Rec(A.hijoIzqdo(n), A), DeseqAbin_Rec(A.hijoDrcho(n), A));
    }
}


#endif