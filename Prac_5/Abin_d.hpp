#ifndef ABIN_D_HPP_
#define ABIN_D_HPP_
#include <cassert>

template <typename t>
class Abin{
    struct celda;
public:
    typedef celda* nodo;
    static const nodo NODO_NULO;
    Abin();
    Abin(const Abin& a);
    Abin& operator =(const Abin& a);
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
    struct celda{
        t elto;
        nodo padre, hijoI, hijoD;

        celda(const t& x = t(), nodo p = NODO_NULO, nodo hi = NODO_NULO, nodo hd = NODO_NULO): elto(x), padre(p),
        hijoI(hi), hijoD(hd) {}
    };
    nodo arbol;

    //METODOS PRIVADOS
    nodo copiar(nodo n);
    void destruirNodos(nodo& n);
};

template<typename t>
const typename Abin<t>::nodo Abin<t>::NODO_NULO(nullptr);

template<typename t>
Abin<t>::Abin(): arbol(NODO_NULO){}

template<typename t>
Abin<t>::Abin(const Abin<t>& a): arbol(NODO_NULO){
    arbol = copiar(a.arbol);
}

template<typename t>
Abin<t>& Abin<t>::operator =(const Abin<t>& a){
    if(this != &a){
        this->~Abin();
        arbol = copiar(a.arbol);
    }

    return *this;
}

template<typename t>
void Abin<t>::insertarRaiz(const t& x){
    assert(arbol == NODO_NULO);

    arbol = new celda(x);
}

template<typename t>
void Abin<t>::insertarHijoIzqdo(nodo n, const t& x){
    assert(n != NODO_NULO);
    assert(n->hijoI == NODO_NULO);
    
    n->hijoI = new celda(x, n);
}

template<typename t>
void Abin<t>::insertarHijoDrcho(nodo n, const t& x){
    assert(n != NODO_NULO);
    assert(n->hijoD == NODO_NULO);
    
    n->hijoD = new celda(x, n);
}

template<typename t>
void Abin<t>::eliminarHI(nodo n){
    assert(n != NODO_NULO);
    assert(n->hijoI != NODO_NULO);
    assert(n->hijoI->hijoI == NODO_NULO && n->hijoI->hijoD == NODO_NULO);

    delete n->hijoI;
    n->hijoI = NODO_NULO;
}

template<typename t>
void Abin<t>::eliminarHD(nodo n){
    assert(n != NODO_NULO);
    assert(n->hijoD != NODO_NULO);
    assert(n->hijoD->hijoI == NODO_NULO && n->hijoD->hijoD == NODO_NULO);

    delete n->hijoD;
    n->hijoD = NODO_NULO;
}

template<typename t>
void Abin<t>::eliminarRaiz(){
    assert(arbol != NODO_NULO);
    assert(arbol->hijoI == NODO_NULO && arbol->hijoD == NODO_NULO);

    delete arbol;
    arbol = NODO_NULO;
}

template<typename t>
bool Abin<t>::arbolVacio() const{

    return arbol == NODO_NULO;
}

template<typename t>
const t& Abin<t>::elemento(nodo n) const{
    assert(n != NODO_NULO);

    return n->elto;
}

template<typename t>
t& Abin<t>::elemento(nodo n){
    assert(n != NODO_NULO);

    return n->elto;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::raiz() const{

    return arbol;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::hijoIzqdo(nodo n) const{
    assert(n != NODO_NULO);

    return n->hijoI;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::hijoDrcho(nodo n) const{
    assert(n != NODO_NULO);

    return n->hijoD;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::padre(nodo n) const{
    assert(n != NODO_NULO);

    return n->padre;
}

template<typename t>
Abin<t>::~Abin(){
    
    destruirNodos(arbol);

}


//------------------------------------------------------------------------------
//METODOS PRIVADOS
//------------------------------------------------------------------------------
template<typename t>
typename Abin<t>::nodo Abin<t>::copiar(typename Abin<t>::nodo n){
    nodo m = NODO_NULO;

    if(n != NODO_NULO){
        m = new celda(n->elto);
        m->hijoI = copiar(n->hijoI);       //Copiamos el subarbol izquierdo
        if(m->hijoI != NODO_NULO)
            m->hijoI->padre = m;
        m.hijoD = copiar(n->hijoD);
        if(m->hijoD != NODO_NULO)
            m->hijoD->padre = m;
    }

    return m;
}

template<typename t>
void Abin<t>::destruirNodos(nodo& n){
    if(n != NODO_NULO){
        nodo hi = n->hijoI, hd = n->hijoD;

        delete n;
        n = NODO_NULO;
        if(hi != NODO_NULO)
            destruirNodos(hi);
        if(hd != NODO_NULO)
            destruirNodos(hd);
    }
}



#endif
