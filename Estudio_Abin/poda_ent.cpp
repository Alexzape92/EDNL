#include "Abin_d.hpp"
#include "poda_ent.hpp"

//PRIVADAS-PROTOTIPO---------------------------------------
Abin<int>::nodo buscar(int e, const Abin<int>& A);
Abin<int>::nodo buscar_Rec(Abin<int>::nodo n, int e, const Abin<int> A);
void borrar_Rec(Abin<int>::nodo n, Abin<int>& A);
//---------------------------------------------------------


void poda(int x, Abin<int>& A){
    Abin<int>::nodo posi = buscar(x, A);

    borrar_Rec(posi, A);    //Borramos todo el subárbol de posi, menos el propio posi
    if(A.hijoIzqdo(A.padre(posi)) == posi)
        A.eliminarHI(A.padre(posi));
    else
        A.eliminarHD(A.padre(posi));
}


//PRIVADAS-IMPLEMENTACION---------------------------------------
Abin<int>::nodo buscar(int e, const Abin<int>& A){
    return buscar_Rec(A.raiz(), e, A);
}

Abin<int>::nodo buscar_Rec(Abin<int>::nodo n, int e, const Abin<int> A){
    if(n == Abin<int>::NODO_NULO || A.elemento(n) == e)
        return n;
    else{
        Abin<int>::nodo izq = buscar_Rec(A.hijoIzqdo(n), e, A);
        if(izq != Abin<int>::NODO_NULO) 
            return izq;
        else 
            return buscar_Rec(A.hijoDrcho(n), e, A);
    }
}

void borrar_Rec(Abin<int>::nodo n, Abin<int>& A){
    if(n != Abin<int>::NODO_NULO){
        borrar_Rec(A.hijoIzqdo(n), A);
        borrar_Rec(A.hijoDrcho(n), A);

        if(A.hijoIzqdo(n) != Abin<int>::NODO_NULO)
            A.eliminarHI(n);
        if(A.hijoDrcho(n) != Abin<int>::NODO_NULO)
            A.eliminarHD(n);
    }
}
//--------------------------------------------------------------