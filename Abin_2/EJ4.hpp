#ifndef EJ4_HPP_
#define EJ4_HPP_
#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include "arit.hpp"

template<typename t>
class Abin{
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;
    Abin(size_t Hm, const t& v);
    Abin(const Abin<t>& A);
    Abin<t>& operator =(const Abin<t>& A);
    void insertarRaiz(const t& x);
    void insertarHijoIzqdo(nodo n, const t& x);
    void insertarHijoDrcho(nodo n, const t& x);
    void eliminarHI(nodo n);
    void eliminarHD(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const {return eltos[tMax/2] == elem_vacio;}
    const t& elemento(nodo n) const;
    t& elemento(nodo n);
    nodo raiz() const {return tMax/2;}
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    ~Abin();
private:
    size_t Hmax;
    size_t tMax;    //Lo guardamos para no tener que estar calculandolo todo el rato
    t *eltos, elem_vacio;

    int altmax(nodo n, const Abin<t>& A) const;
    int profundidad(nodo n, const Abin<t>& A) const;
};

template<typename t>
const typename Abin<t>::nodo Abin<t>::NODO_NULO(SIZE_MAX);

template<typename t>
Abin<t>::Abin(size_t Hm, const t& v):Hmax(Hm), tMax(powi(2, Hmax+1) - 1) , eltos(new t[tMax]), elem_vacio(v)
{
    for(size_t i = 0; i < tMax; i++)
        eltos[i] = elem_vacio;
}

template<typename t>
void Abin<t>::insertarRaiz(const t& x){
    assert(eltos[tMax/2] == elem_vacio);    //Comprobamos que el árbol está vacío

    eltos[tMax/2] = x;
}

template<typename t>
void Abin<t>::insertarHijoIzqdo(nodo n, const t& x){
    assert(eltos[tMax/2] != elem_vacio);    //El árbol no está vacío
    assert(n >= 0 && n < tMax);             //Nodo válido

    unsigned h = altmax(n, *this);
    assert(eltos[n - powi(2, h-1)] == elem_vacio);  //El nodo no tiene hijo izquierdo

    eltos[n - powi(2, h-1)] = x;
}

template<typename t>
void Abin<t>::insertarHijoDrcho(nodo n, const t& x){
    assert(eltos[tMax/2] != elem_vacio);    //El árbol no está vacío
    assert(n >= 0 && n < tMax);             //Nodo válido

    unsigned h = altmax(n, *this);
    assert(eltos[n + powi(2, h-1)] == elem_vacio);  //El nodo no tiene hijo derecho

    eltos[n + powi(2, h-1)] = x;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::padre(nodo n) const {
    assert(eltos[tMax/2] != elem_vacio);    //El árbol no está vacío
    assert(n >= 0 && n < tMax);             //Nodo válido

    unsigned h = altmax(n, *this);
    if(n % powi(2, h+2) == powi(2, h) - 1)
        return (eltos[n + powi(2, h)] == elem_vacio ? NODO_NULO : n + powi(2, h));
    else
        return (eltos[n - powi(2, h)] == elem_vacio ? NODO_NULO : n - powi(2, h));
    
}

template<typename t>
typename Abin<t>::nodo Abin<t>::hijoIzqdo(nodo n) const{
    //---------------------
    //Asserts
    //---------------------
    unsigned h = altmax(n, *this);

    return (eltos[n - powi(2, h-1)] == elem_vacio) ? NODO_NULO : n - powi(2, h-1);
} 

template<typename t>
typename Abin<t>::nodo Abin<t>::hijoDrcho(nodo n) const{
    //---------------------
    //Asserts
    //---------------------
    unsigned h = altmax(n, *this);

    return (eltos[n + powi(2, h-1)] == elem_vacio) ? NODO_NULO : n + powi(2, h-1);
} 

template<typename t>
const t& Abin<t>::elemento(nodo n) const{
    //----------------
    //Asserts
    //----------------
    return eltos[n];
}

template<typename t>
t& Abin<t>::elemento(nodo n){
    //----------------
    //Asserts
    //----------------
    return eltos[n];
}

template<typename t>
Abin<t>::~Abin(){
    delete[] eltos;
}


//PRIVADAS-------------------------------------------------------------
template<typename t>
int Abin<t>::profundidad(nodo n, const Abin<t>& A) const{
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

template<typename t>
int Abin<t>::altmax(nodo n, const Abin<t>& A) const{
    return Hmax - profundidad(n, A);
}


#endif