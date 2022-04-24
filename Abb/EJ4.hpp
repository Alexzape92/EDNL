#ifndef EJ4_HPP_
#define EJ4_HPP_
#include "abb.hpp"
#include "EJ2.hpp"

template<typename t>
Abb<t> interseccionConj(const Abb<t>& c1, const Abb<t>& c2);

template<typename t>
void interseccion_Rec(Abb<t>& res, const Abb<t>& c1, const Abb<t>& c2);


template<typename t>
Abb<t> interseccionConj(const Abb<t>& c1, const Abb<t>& c2){
    Abb<t> intersecado;
    interseccion_Rec(intersecado, c1, c2);
    equilibrar(intersecado);

    return intersecado;
}

template<typename t>
void interseccion_Rec(Abb<t>& res, const Abb<t>& c1, const Abb<t>& c2){
    if(!c1.vacio()){    //Solo hace falta recorrer un árbol, pues todos los posibles elementos de la interseccion han de estar en ambos
        if(!c2.buscar(c1.elemento()).vacio())
            res.insertar(c1.elemento());
        interseccion_Rec(res, c1.izqdo(), c2);
        interseccion_Rec(res, c1.drcho(), c2);
    }
}


#endif