#include "EJ5.hpp"

void matriz_Rec(Agen<tCuadrante>::nodo n, bool**& mat, const Agen<tCuadrante>& A);


bool** matriz(const Agen<tCuadrante>& A){
    bool **res = new bool *[A.elemento(A.raiz()).infder1 + 1];
    for(int row = 0; row != A.elemento(A.raiz()).infder2; row++)
        res[row] = new bool[A.elemento(A.raiz()).infder2 + 1];

    matriz_Rec(A.raiz(), res, A);
    return res;
}

void matriz_Rec(Agen<tCuadrante>::nodo n, bool**& mat, const Agen<tCuadrante>& A){
    if(A.hijoIzqdo(n) == Agen<tCuadrante>::NODO_NULO)
        for(int i = A.elemento(n).supizq1; i < A.elemento(n).infder1; i++)
            for(int j = A.elemento(n).supizq2; i < A.elemento(n).infder2; j++)
                mat[i][j] = A.elemento(n).color;
    else{
        Agen<tCuadrante>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<tCuadrante>::NODO_NULO){
            matriz_Rec(hijo, mat, A);
            hijo = A.hermDrcho(hijo);
        }
    }
}