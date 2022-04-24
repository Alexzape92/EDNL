#ifndef EJ5_HPP_
#define EJ5_HPP_
#include "abb.hpp"

template<typename t>
struct Conjunto{
    Conjunto(const Abb<t>& a = Abb<t>()): arb{a}{}
    bool pertenece(const t& x) const;
    Abb<t> arb;
};

template<typename t>
Conjunto<t> operator ^(const Conjunto<t>& c1, const Conjunto<t>& c2);

template<typename t>
void rombo_Rec(Conjunto<t>& res, const Conjunto<t>& c1, const Conjunto<t>& c2);


template<typename t>
inline bool Conjunto<t>::pertenece(const t& x) const{
    return !arb.buscar(x).vacio();
}

template<typename t>
Conjunto<t> operator ^(const Conjunto<t>& c1, const Conjunto<t>& c2){
    Conjunto<t> result;
    rombo_Rec(result, c1, c2);
    rombo_Rec(result, c2, c1);

    return result;
}

template<typename t>
void rombo_Rec(Conjunto<t>& res, const Conjunto<t>& c1, const Conjunto<t>& c2){
    if(!c1.arb.vacio()){
        if(!c2.pertenece(c1.arb.elemento()))
            res.arb.insertar(c1.arb.elemento());
        rombo_Rec(res, Conjunto<t>(c1.arb.izqdo()), c2);
        rombo_Rec(res, Conjunto<t>(c1.arb.drcho()), c2);
    }
}

#endif