#ifndef EJ7_HPP_
#define EJ7_HPP_
#include "Abin_d.hpp"
#include "EJ2.hpp"

template <typename t>
bool pseudocomp(const Abin<t> &A);

template <typename t>
bool pseudo_Rec(typename Abin<t>::nodo n, const Abin<t> &A);

template <typename t>
int numHijos(typename Abin<t>::nodo n, const Abin<t> &A);

template <typename t>
bool pseudocomp(const Abin<t> &A)
{
    return pseudo_Rec(A.raiz(), A);
}

template <typename t>
bool pseudo_Rec(typename Abin<t>::nodo n, const Abin<t> &A)
{
    if (n == Abin<t>::NODO_NULO)
        return true;
    else
    {
        if (Altura_Rec(n, A) == 1)
        {
            return numHijos(n, A) == 2;
        }
        else
            return pseudo_Rec(A.hijoIzqdo(n), A) && pseudo_Rec(A.hijoDrcho(n), A);
    }
}

// PRIVADAS
//--------------------------------------
template <typename t>
int numHijos(typename Abin<t>::nodo n, const Abin<t> &A)
{
    int res = 0;
    if (A.hijoIzqdo(n) != Abin<t>::NODO_NULO)
        res++;
    if (A.hijoDrcho(n) != Abin<t>::NODO_NULO)
        res++;

    return res;
}

#endif