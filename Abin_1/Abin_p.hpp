#ifndef ABIN_P_HPP_
#define ABIN_P_HPP_
#include <cstdlib>
#include <cassert>

template <typename t>
class Abin{
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;
    Abin(size_t tamMax);
    Abin(const Abin& a);
    Abin& operator =(const Abin& a);
    void insertarRaiz(const t& x);
    void insertarHI(nodo n, const t& x);
    void insertarHD(nodo n, const t& x);
    void eliminarHI(nodo n);
    void eliminarHD(nodo n);
    void eliminarRaiz();
    bool vacio() const;
    const t& elemento(nodo n) const;
    t& elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoI(nodo n) const;
    nodo hijoD(nodo n) const;
    ~Abin();
private:
    struct celda{
        t elto;
        nodo padre, hijoI, hijoD;

        celda(const t& x = t(), nodo p = NODO_NULO, nodo hi = NODO_NULO, nodo hd = NODO_NULO): elto(x), padre(p),
        hijoI(hi), hijoD(hd) {}
    };
    celda *arbol;
    size_t tMax;
    size_t numNodos;
};

template<typename t>
const typename Abin<t>::nodo Abin<t>::NODO_NULO = __SIZE_MAX__;

template<typename t>
Abin<t>::Abin(size_t tamMax): arbol(new celda[tamMax]), tMax(tamMax), numNodos(0) {}

template<typename t>
Abin<t>::Abin(const Abin<t>& a): arbol(new celda[a.tMax]), tMax(a.tMax), numNodos(a.numNodos){
    for(Abin<t>::nodo i = 0; i <= numNodos; i++)
        arbol[i] = a.arbol[i];
}

template<typename t>
Abin<t>& Abin<t>::operator =(const Abin<t>& a){
    if(this != &a){
        if(tMax != a.tMax){
            delete[] arbol;
            tMax = a.tMax;
            arbol = new celda[tMax];
        }
        numNodos = a.numNodos;
        for(Abin<t>::nodo i = 0; i <= numNodos; i++)
        arbol[i] = a.arbol[i];
    }

    return *this;
}

template<typename t>
void Abin<t>::insertarRaiz(const t& x){
    assert(numNodos == 0);

    arbol[0] = celda(x);
    numNodos++;
}

template<typename t>
void Abin<t>::insertarHI(nodo n, const t& x){
    assert(n >= 0 && n < numNodos);
    assert(numNodos < tMax);
    
    arbol[numNodos] = celda(x, n);
    arbol[n].hijoI = numNodos;
    numNodos++;
}

template<typename t>
void Abin<t>::insertarHD(nodo n, const t& x){
    assert(n >= 0 && n < numNodos);
    assert(numNodos < tMax);
    
    arbol[numNodos] = celda(x, n);
    arbol[n].hijoD = numNodos;
    numNodos++;
}

template<typename t>
void Abin<t>::eliminarHI(nodo n){
    assert(n >=0 && n < numNodos);
    assert(arbol[arbol[n].hijoI].hijoI == NODO_NULO);
    assert(arbol[arbol[n].hijoI].hijoD == NODO_NULO);

    //Borramos el nodo
    arbol[arbol[n].hijoI] = arbol[numNodos - 1];

    //Cambiamos el apuntador padre de los hijos de numNodos-1
    if(arbol[numNodos-1].hijoI != NODO_NULO)
        arbol[arbol[numNodos-1].hijoI].padre = arbol[n].hijoI;
    if(arbol[numNodos-1].hijoD != NODO_NULO)
        arbol[arbol[numNodos-1].hijoD].padre = arbol[n].hijoI;

    //CAMBIAR EL APUNTADOR(HIJO) DEL PADRE DE numNodos-1 (encontrar primero si este es I o D)
    if(arbol[arbol[numNodos-1].padre].hijoI == numNodos-1)
        arbol[arbol[numNodos-1].padre].hijoI = arbol[n].hijoI;
    else
        arbol[arbol[numNodos-1].padre].hijoD = arbol[n].hijoI;
   

    arbol[n].hijoI = NODO_NULO;
    numNodos--;
}

template<typename t>
void Abin<t>::eliminarHD(nodo n){
    assert(n >=0 && n < numNodos);
    assert(arbol[arbol[n].hijoD].hijoI == NODO_NULO);
    assert(arbol[arbol[n].hijoD].hijoD == NODO_NULO);

    arbol[arbol[n].hijoD] = arbol[numNodos - 1];
       //Borramos el nodo
    if(arbol[numNodos-1].hijoI != NODO_NULO)
        arbol[arbol[numNodos-1].hijoI].padre = arbol[n].hijoD;
    if(arbol[numNodos-1].hijoD != NODO_NULO)
        arbol[arbol[numNodos-1].hijoD].padre = arbol[n].hijoD;

    //CAMBIAR EL APUNTADOR(HIJO) DEL PADRE DE numNodos-1 (encontrar primero si este es I o D)
    if(arbol[arbol[numNodos-1].padre].hijoI == numNodos-1)
        arbol[arbol[numNodos-1].padre].hijoI = arbol[n].hijoD;
    else
        arbol[arbol[numNodos-1].padre].hijoD = arbol[n].hijoD;
   

    arbol[n].hijoD = NODO_NULO;
    numNodos--;
}

template<typename t>
void Abin<t>::eliminarRaiz(){
    assert(numNodos == 1);

    numNodos--;
}

template<typename t>
bool Abin<t>::vacio() const{

    return numNodos == 0;
}

template<typename t>
const t& Abin<t>::elemento(nodo n) const{

    return arbol[n].elto;
}

template<typename t>
t& Abin<t>::elemento(nodo n){
    assert(n >= 0 && n < numNodos);

    return arbol[n].elto;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::raiz() const{

    return (numNodos == 0) ? NODO_NULO : 0;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::hijoI(nodo n) const{
    assert(n >= 0 && n < numNodos);

    return arbol[n].hijoI;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::hijoD(nodo n) const{
    assert(n >= 0 && n < numNodos);

    return arbol[n].hijoD;
}

template<typename t>
typename Abin<t>::nodo Abin<t>::padre(nodo n) const{
    assert(n >= 0 && n < numNodos);

    return arbol[n].padre;
}

template<typename t>
Abin<t>::~Abin(){
    
    delete[] arbol;
}




#endif