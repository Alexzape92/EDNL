#ifndef EJ4_HPP_
#define EJ4_HPP_
#include <cassert>
#include <cstdlib>
#include <cmath>
#include "arit.hpp"

template<typename t>
class Abin{
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;
    Abin(size_t Hm);
    Abin(const Abin<t>& A);
    Abin<t>& operator =(const Abin<t>& A);
    void insertarRaiz(const t& x);
    void insertarHijoIzqdo(nodo n, const t& x);
    void insertarHijoDrcho(nodo n, const t& x);
    void eliminarHI(nodo n);
    void eliminarHD(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const t& elemento(nodo n) const;
    t& elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    ~Abin();
private:
    t* eltos;
    size_t Hmax;
    size_t tMax;    //Lo guardamos para no tener que estar calculandolo todo el rato

    int altura(nodo n, const Abin<t>& A);
    int profundidad(nodo n, const Abin<t>& A);
};

template<typename t>
const typename Abin<t>::nodo Abin<t>::NODO_NULO(std::SIZE_MAX);

template<typename t>
Abin<t>::Abin(size_t Hm):Hmax(Hm), tMax(powi(2, Hm+1) - 1) , eltos(new t[tMax])
{}

template<typename t>
void Abin<t>::insertarRaiz(const t& x){
    eltos[tMax/2] = x;
}

template<typename t>
void Abin<t>::insertarHijoIzqdo(nodo n, const t& x){
    eltos[n/2] = x;
}

template<typename t>
void Abin<t>::insertarHijoDrcho(nodo n, const t& x){
    eltos[n + n/2] = x;     //27 -> 29 = n + n/log2
}


//PRIVADAS-------------------------------------------------------------
template<typename t>
int Abin<t>::profundidad(nodo n, const Abin<t>& A){
    nodo i = A.raiz();
    int prof = 0;

    while(i != n){
        if(n > i)
            i = A.hijoDrcho(i);
        else
            i = A.hijoIzqdo(i);
        prof++;
    }

    return prof;
}

#endif