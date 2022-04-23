#ifndef ABB_E_S_HPP_
#define ABB_E_S_HPP_
#include "abb.hpp"
#include <iostream>

template<typename t>
void rellenarAbb(Abb<t>& A, const t& fin){
    t x = t();
    std::cin >> x;
    while(x != fin){
        A.insertar(x);
        std::cin >> x;
    }
}

template<typename t>
void imprimirAbb(const Abb<t>& A){
    if(A.vacio())
        std::cout << "Arbol vacio" << std::endl;
    else{
        std::cout << A.elemento() << std::endl;
        if(!A.izqdo().vacio()){
            std::cout << "Hijo izquierdo de " << A.elemento() << ": ";
            imprimirAbb(A.izqdo());
        }
        if(!A.drcho().vacio()){
            std::cout << "Hijo derecho de " << A.elemento() << ": ";
            imprimirAbb(A.drcho());
        }
    }
}


#endif

