#ifndef AGEN_V_HPP_
#define AGEN_V_HPP_
#include <cassert>
#include <cstdlib>
#include "lista_dina.hpp"

template<typename t>
class Agen{
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;
    explicit Agen(size_t tMax);
    Agen(const Agen& A);
    Agen& operator =(const Agen& A);
    void insertarRaiz(const t& e);
    void insertarHijoIzqdo(nodo n, const t& e);
    void insertarHermDrcho(nodo n, const t& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHermDrcho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const t& elemento(nodo n) const;
    t& elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hermDrcho(nodo n) const;
    ~Agen();
private:
    struct celda{
        t elto;
        nodo padre;
        lista<nodo> hijos;
    };
    
    celda *nodos;
    size_t maxNodos;
    size_t numNodos;
};

template<typename t>
const typename Agen<t>::nodo Agen<t>::NODO_NULO {__SIZE_MAX__};

template<typename t>
Agen<t>::Agen(size_t tMax): nodos(new celda[tMax]), maxNodos(tMax), numNodos(0) {
    for(nodo i = 0; i < tMax; i++)
        nodos[i].padre = NODO_NULO;
}

template<typename t>
void Agen<t>::insertarRaiz(const t& e){
    assert(numNodos == 0);

    nodos[0].elto = e;
    nodos[0].padre = NODO_NULO;

    numNodos = 1;
}

template<typename t>
void Agen<t>::insertarHijoIzqdo(nodo n, const t& e){
    assert(numNodos > 0);           //Árbol no vacío
    assert(n >= 0 && n < maxNodos); //n está dentro del rango (nodo posible)
    assert(numNodos < maxNodos);    //Árbol no lleno
    assert(n == 0 || nodos[n].padre != NODO_NULO);  //Posición ocupada

    nodo i = 1;
    for(i = 1; nodos[i].padre != NODO_NULO; i++);

    nodos[i].elto = e;
    nodos[i].padre = n;
    nodos[n].hijos.insertar(i, nodos[n].hijos.primera());

    numNodos++;
}

template<typename t>
void Agen<t>::insertarHermDrcho(nodo n, const t& e){
    assert(numNodos > 0);           //Árbol no vacío
    assert(n > 0 && n < maxNodos); //n está dentro del rango (nodo posible)
    assert(numNodos < maxNodos);    //Árbol no lleno
    assert(nodos[n].padre != NODO_NULO);  //Posición ocupada

    nodo i = 1;
    for(i = 1; nodos[i].padre != NODO_NULO; i++);

    nodo padre = nodos[n].padre;

    nodos[i].elto = e;
    nodos[i].padre = padre;
    nodos[padre].hijos.insertar(i, nodos[padre].hijos.siguiente(nodos[padre].hijos.buscar(n)));

    numNodos++;
}

template<typename t>
void Agen<t>::eliminarHijoIzqdo(nodo n){
    assert(numNodos > 0);           //Árbol no vacío
    assert(n >= 0 && n < maxNodos); //n está dentro del rango (nodo posible)
    assert(n == 0 || nodos[n].padre != NODO_NULO);  //Posición ocupada
    assert(!nodos[n].hijos.vacia());    //n tiene hijos
    nodo hizq = nodos[n].hijos.primera();
    assert(nodos[hizq].hijos.vacia()); //n no tiene hijos, es una hoja

    nodos[hizq].padre = NODO_NULO;
    nodos[n].hijos.eliminar(nodos[n].hijos.primera());

    numNodos--;
}

template<typename t>
void Agen<t>::eliminarHermDrcho(nodo n){
    assert(numNodos > 0);           //Árbol no vacío
    assert(n > 0 && n < maxNodos); //n está dentro del rango (nodo posible)
    assert(nodos[n].padre != NODO_NULO);  //Posición ocupada
    lista<nodo>& lhp = nodos[nodos[n].padre].hijos;
    assert(lhp.siguiente(lhp.buscar(n)) != lhp.fin());    //n tiene hermano derecho
    nodo hermd = lhp.elemento(lhp.siguiente(lhp.buscar(n)));
    assert(nodos[hermd].hijos.vacia());    //El hermano derecho es una hoja

    nodos[hermd].padre = NODO_NULO;
    lhp.eliminar(lhp.siguiente(lhp.buscar(n)));

    numNodos--;
}

template<typename t>
void Agen<t>::eliminarRaiz(){
    assert(numNodos == 1);  //El árbol está vacío y la raíz es una hoja

    numNodos = 0;
}

template<typename t>
bool Agen<t>::arbolVacio() const{

    return (numNodos == 0);
}

template<typename t>
const t& Agen<t>::elemento(nodo n) const{
    assert(numNodos > 0);  //El árbol no está vacío
    assert(n >= 0 && n < numNodos); //n es válido
    assert(n == 0 || nodos[n].padre != NODO_NULO);    //Posición ocupada

    return nodos[n].elto;    
}

template<typename t>
t& Agen<t>::elemento(nodo n) {
    assert(numNodos > 0);  //El árbol no está vacío
    assert(n >= 0 && n < numNodos); //n es válido
    assert(n == 0 || nodos[n].padre != NODO_NULO);    //Posición ocupada

    return nodos[n].elto;    
}

template<typename t>
typename Agen<t>::nodo Agen<t>::raiz() const{

    return (numNodos > 0) ? 0 : NODO_NULO;
}

template<typename t>
typename Agen<t>::nodo Agen<t>::padre(nodo n) const{

    assert(numNodos > 0);   //Árbol no vacío
    assert(n >= 0 && n < numNodos); //n es válido
    assert(n == 0 || nodos[n].padre != NODO_NULO);  //Posición ocupada

    return nodos[n].padre;
}

template<typename t>
typename Agen<t>::nodo Agen<t>::hijoIzqdo(nodo n) const{

    assert(numNodos > 0);   //Árbol no vacío
    assert(n >= 0 && n < numNodos); //n es válido
    assert(n == 0 || nodos[n].padre != NODO_NULO);  //Posición ocupada

    if(nodos[n].hijos.primera() != nodos[n].hijos.fin())
        return nodos[n].hijos.elemento(nodos[n].hijos.primera());
    else
        return NODO_NULO;
}

template<typename t>
typename Agen<t>::nodo Agen<t>::hermDrcho(nodo n) const{

    assert(numNodos > 0);   //Árbol no vacío
    assert(n >= 0 && n < numNodos); //n es válido
    assert(n == 0 || nodos[n].padre != NODO_NULO);  //Posición ocupada

    if(n == 0)
        return NODO_NULO;

    else{
        lista<nodo>& lhp = nodos[nodos[n].padre].hijos;

        if(lhp.siguiente(lhp.buscar(n)) != lhp.fin())
         return lhp.elemento(lhp.siguiente(lhp.buscar(n)));
        else
            return NODO_NULO;
    }
}

//Constructor de copia, operador de asignación y destructor-------------------------------------------------------------
template<typename t>
Agen<t>::Agen(const Agen<t>& A): nodos(new celda[A.maxNodos]), maxNodos(A.maxNodos), numNodos(A.numNodos){
    for(nodo i = 0; i < numNodos; i++){
        nodos[i] = A.nodos[i];
    }
}

template<typename t>
Agen<t>& Agen<t>::operator=(const Agen<t>& A){
    if(this != &A){
        if(maxNodos != A.maxNodos){
            delete[] nodos;
            maxNodos = A.maxNodos;
            nodos = new celda[maxNodos];
        }
        numNodos = A.numNodos;
        for(nodo i = 0; i < numNodos; i++){
            nodos[i] = A.nodos[i];
        }
    }
    return *this;
}

template<typename t>
Agen<t>::~Agen(){
    delete[] nodos;
}

#endif