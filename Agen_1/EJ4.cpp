#include "Agen_d.hpp"
#include "EJ4.hpp"
#include <iostream>

Agen<int>::nodo buscar(Agen<int>::nodo n, int x, const Agen<int>& A);

void poda_Rec(Agen<int>::nodo n, Agen<int>& A);


void poda(int x, Agen<int>& A){
    poda_Rec(buscar(A.raiz(), x, A), A);
}

Agen<int>::nodo buscar(Agen<int>::nodo n, int x, const Agen<int>& A){
    if(n == Agen<int>::NODO_NULO)
        return Agen<int>::NODO_NULO;
    else{
        if(A.elemento(n) == x)
            return n;
        else{
            Agen<int>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<int>::NODO_NULO){
                Agen<int>::nodo buscarHijo = buscar(hijo, x, A);
                if(buscarHijo != Agen<int>::NODO_NULO)
                    return buscarHijo;
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void poda_Rec(Agen<int>::nodo n, Agen<int>& A){
    if(n != Agen<int>::NODO_NULO){
        Agen<int>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<int>::NODO_NULO){
            poda_Rec(hijo, A);
            hijo = A.hermDrcho(hijo);
        }

        while(A.hijoIzqdo(n) != Agen<int>::NODO_NULO){  //Borramos todos los hijos de n
            A.eliminarHijoIzqdo(n);
        }
    }
}