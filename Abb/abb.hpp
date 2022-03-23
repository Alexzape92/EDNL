#ifndef ABB_HPP_
#define ABB_HPP_

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
    const t& elemento() const;
    const Abb& izqdo() const;
    const Abb& drcho() const;
    ~Abb();
private:
    struct celda{
        t elto;
        Abb izq, der;

        celda(const t& x = t(), Abb AI = Abb(), Abb AD = Abb()): elto{x}, izq{AI}, der(AD) {}
    };
    
    celda *r;

    //METODOS PRIVADOS
    const t& minMax() const;
};

template<typename t>
Abb<t>::Abb(): r{nullptr}{}

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
    if(r->izq.r == nullptr && r->der.r == nullptr)
        delete r;
    else if(r->izq.r == nullptr){
        r->elto = r->izq.r->elto;
        delete r->izq.r;
        r->izq.r = nullptr;
    }
    else if(r->der.r == nullptr){
        r->elto = r->der.r->elto;
        delete r->der.r;
        r->der.r = nullptr;
    }
    else{   //Aqui tene subárbol izquierdo y derecho
        Abb sust = minMax();
        r->elto = sust.r->elto;
    }
}


#endif