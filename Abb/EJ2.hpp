#ifndef EJ2_HPP_
#define EJ2_HPP_
#include "abb.hpp"
#include <vector>

template<typename t>
void lista_inorden(std::vector<t>& v, const Abb<t>& A);

template<typename t>
void equilibrar(Abb<t>& A);

template<typename t>
void equilibrar_Rec(const std::vector<t>& v,Abb<t>& A);


template<typename t>
void equilibrar(Abb<t>& A){
    std::vector<t> v;
    lista_inorden(v, A);    //Tenemos en v los vectores en inorden
    Abb<t> R;
    equilibrar_Rec(v, R);
    A = R;
}

template<typename t>
void lista_inorden(std::vector<t>& v, const Abb<t>& A){
    if(!A.vacio()){
        lista_inorden(v, A.izqdo());
        v.push_back(A.elemento());
        lista_inorden(v, A.drcho());
    }
}

template<typename t>
void equilibrar_Rec(const std::vector<t>& v,Abb<t>& A){
    if(!v.empty()){
        int posi_medi = (v.size()+1) / 2 - 1;
        A.insertar(*(v.begin() + posi_medi));

        std::vector<t> vizq, vder;
        for(int i = 0; i < posi_medi; i++)
            vizq.push_back(*(v.begin() + i));
        for(int i = posi_medi + 1; i < v.size(); i++)
            vder.push_back(*(v.begin() + i));
        
        equilibrar_Rec(vizq, A);
        equilibrar_Rec(vder, A);
    }
}

#endif