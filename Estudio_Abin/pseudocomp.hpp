#ifndef PSEUDOCOMP_HPP_
#define PSEUDOCOMP_HPP_
#include "Abin_d.hpp"
#include "alt.hpp"
#include "prof.hpp"

template<typename t>
bool pseudocomp(const Abin<t>& A);

template<typename t>
bool pseudocomp_Rec(typename Abin<t>::nodo n, const Abin<t>& A, int altura);

//Privada
template<typename t>
int numHijos(typename Abin<t>::nodo n, const Abin<t>& A);


template<typename t>
bool pseudocomp(const Abin<t>& A){
    return pseudocomp_Rec(A. raiz(), A, AlturaAbin(A));
}

template<typename t>
bool pseudocomp_Rec(typename Abin<t>::nodo n, const Abin<t>& A, int altura){
    if(n == Abin<t>::NODO_NULO)
        return true;    //Árboles vacíos o con un sólo nivel (sólo nodo raíz) son pseudocompletos
    else if(ProfNodo(n, A) == altura - 1)
        return numHijos(n, A) != 1; //Nunca se llama con n == NODO_NULO, por eso no lo comprobamos en la función
    else
        return pseudocomp_Rec(A.hijoIzqdo(n), A, altura) && pseudocomp_Rec(A.hijoDrcho(n), A, altura);
}


//Privada
template<typename t>
int numHijos(typename Abin<t>::nodo n, const Abin<t>& A){
    int hijos = 0;
    if(A.hijoIzqdo(n) != Abin<t>::NODO_NULO)
        hijos++;
    if(A.hijoDrcho(n) != Abin<t>::NODO_NULO)
        hijos++;

    return hijos;
}



#endif