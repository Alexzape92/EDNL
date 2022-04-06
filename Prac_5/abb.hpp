#ifndef ABB_HPP_
#define ABB_HPP_
#include <cassert>

template<typename t>
class Abb{
    struct celda;
public:
    Abb();
    Abb(const Abb& a);
    Abb& operator =(const Abb& a);
    const Abb& buscar(const t& x) const;
    void insertar(const t& x);
    void eliminar(const t& x);
    bool vacio() const {return r == nullptr;}
    const t& elemento() const {assert(r != nullptr); return r->elto;}
    const Abb& izqdo() const {assert(r != nullptr); return r->izq;}
    const Abb& drcho() const {assert(r != nullptr); return r->der;}
    ~Abb();
private:
    struct arbol{
        t elto;
        Abb izq, der;

        celda(const t& x = t(), Abb AI = Abb(), Abb AD = Abb()): elto{x}, izq{AI}, der(AD) {}
    };
    
    arbol *r;

    //METODOS PRIVADOS
    t borrarMin();
    void copiar(const Abb<t>& A);
};

template<typename t>
Abb<t>::Abb(): r{nullptr}{}

template<typename t>
Abb<t>::Abb(const Abb<t>& A): r{nullptr}{
    if(A.r != nullptr){

    }
}

template<typename t>
const Abb<t>& Abb<t>::buscar(const t& x) const{
    if(r->elto == x)
        return *this;
    else if(r->elto < x)
        return r->izq.buscar(x);
    else
        return r->der.buscar(x);
}

template<typename t>
void Abb<t>::insertar(const t& x){
    if(r == nullptr)
        r = new celda(x);
    else{
        if(x < r->elto)
            r->izq.insertar(x);
        if(x > r->elto)
            r->der.insertar(x);
    }
}

template<typename t>
void Abb<t>::eliminar(const t& x){
    if(r != nullptr){
        if(x > r->elto)
            r->der.eliminar(x);
        else if(x < r->elto)
            r->izq.eliminar(x);
        else{
            if(r->izq.r == nullptr && r->der.r == nullptr){
                delete r;
                r = nullptr;
            }
            else if(r->izq.r == nullptr){
                arbol *ori = r->der.r;
                r->der.r = nullptr;     //Evita destruir el subárbol derecho
                delete r;
                r = ori;
            }
            else if(dest.r->der.r == nullptr){
                arbol *ori = r->izq.r;izq
                r->izq.r = nullptr;     //Evita destruir el subárbol izquierdo
                delete r;
                r = ori;
            }
            else   //Aqui tene subárbol izquierdo y derecho
                r->elto = r->der.borrarMin();
        }
    }
}



//PRIVADAS---------------------------------------
template<typename t>
t Abb<t>::borrarMin(){
    if(r->izq.r == nullptr){
        t res = r->elto;
        if(r->der.r != nullptr){
            arbol dere = r->der;
            delete r;
            r = dere;
        }
        else{
            delete r;
            r = nullptr;
        }
        return res;
    }
    else{
        return r->izq.borrarMin();
    }
}

template<typename t>
void Abb<t>::copiar(const Abb<t>& A){
    if(r != nullptr){
        r->elto = A.r->elto;
        if(A.r->izq.r != nullptr){
            r->izq.r = new arbol();
            r->izq.copiar(A.r->izq);
        }
        if(A.r->der.r != nullptr){
            r->der.r = new arbol();
            r->der.copiar(A.r->der);
        }
    }
}


#endif