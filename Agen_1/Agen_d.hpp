#ifndef AGEN_D_HPP_
#define AGEN_D_HPP_
#include <cassert>
#include <cstdlib>

/*-------------------------------------------------------
IMPLEMENTAR CONSTRUCTOR COPIA, OP ASIGNACIÓN Y DESTRUCTOR
---------------------------------------------------------*/

template<typename t>
class Agen{
struct celda;
public:
    typedef celda* nodo;
    static const nodo NODO_NULO;
    explicit Agen();
    Agen(const Agen& A);
    Agen& operator =(const Agen& A);
    void insertarRaiz(const t& e);
    void insertarHijoIzqdo(nodo n, const t& e);
    void insertarHermDrcho(nodo n, const t& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHermDrcho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const{return r == NODO_NULO;}
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
        celda *padre, *hizq, *hermd;

        celda(const t& x = t(), celda *p = nullptr, celda *he = nullptr), celda *hi = nullptr: elto(x), 
        padre(p), hizq(hi), hermd(he) {}
    };

    celda *r;
};

template<typename t>
const typename Agen<t>::nodo Agen<t>::NODO_NULO {nullptr};

template<typename t>
Agen<t>::Agen(): r(nullptr){}

template<typename t>
void Agen<t>::insertarRaiz(const t& x){
    assert(r == nullptr);   //El árbol está vacío
    r = new celda(x);
}

template<typename t>
void Agen<t>::insertarHijoIzqdo(nodo n, const t& x){
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);

    celda *nuevohi = new celda(x, n, n->hizq);
    n->hizq = nuevohi;
}

template<typename t>
void Agen<t>::insertarHermDrcho(nodo n, const t& x){
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);

    celda *nuevohd = new celda(x, n->padre, n->hermd);
    n->hermd = nuevohd;
}

template<typename t>
void Agen<t>::eliminarHijoIzqdo(nodo n){
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);
    assert(n->hizq != NODO_NULO);   //Existe el hijo izquierdo
    assert(n->hizq->hizq == NODO_NULO); //Y es hoja

    celda *hi = n->hizq;
    n->hizq = hi->hermd;
    delete hi;
}

template<typename t>
void Agen<t>::eliminarHermDrcho(nodo n){
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);
    assert(n->hermd != NODO_NULO);          //Existe el hermano derecho
    assert(n->hermd->hizq == NODO_NULO);    //Y es hoja

    celda *hd = n->hermd;
    n->hermd = hd->hermd;
    delete hd;
}

template<typename t>
void Agen<t>::eliminarRaiz(){
    assert(r != NODO_NULO);         //El árbol no está vacío
    assert(r->hizq == NODO_NULO);   //Y sólo tiene la raíz

    delete r;
    r = NODO_NULO;
}

template<typename t>
const t& Agen<t>::elemento(nodo n) const{
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);

    return n->elto;
}

template<typename t>
t& Agen<t>::elemento(nodo n){
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);

    return n->elto;
}

template<typename t>
typename Agen<t>::nodo Agen<t>::raiz() const{
    return r;
}

template<typename t>
typename Agen<t>::nodo Agen<t>::padre(nodo n) const{
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);

    return n->padre;
}

template<typename t>
typename Agen<t>::nodo Agen<t>::hijoIzqdo(nodo n) const{
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);

    return n->hizq;
}

template<typename t>
typename Agen<t>::nodo Agen<t>::hermDrcho(nodo n) const{
    assert(r != NODO_NULO);
    assert(n != NODO_NULO);

    return n->hermd;
}


#endif