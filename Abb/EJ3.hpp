#ifndef EJ3_HPP_
#define EJ3_HPP_
#include "abb.hpp"
#include "EJ2.hpp"

template<typename t>
Abb<t> unionConj(const Abb<t>& c1, const Abb<t>& c2);

template<typename t>
void union_Rec(Abb<t>& res, const Abb<t>&c1, const Abb<t>& c2);


template<typename t>
Abb<t> unionConj(const Abb<t>& c1, const Abb<t>& c2){
    Abb<t> unido;
    union_Rec(unido, c1, c2);
    equilibrar(unido);

    return unido;
}

template<typename t>
void union_Rec(Abb<t>& res, const Abb<t>&c1, const Abb<t>& c2){
    if(!c1.vacio()){
        res.insertar(c1.elemento());
        union_Rec(res, c1.izqdo(), Abb<t>());
        union_Rec(res, c1.drcho(), Abb<t>());
    }
    if(!c2.vacio()){
        res.insertar(c2.elemento());
        union_Rec(res, Abb<t>(), c2.izqdo());
        union_Rec(res, Abb<t>(), c2.drcho());
    }
}

#endif