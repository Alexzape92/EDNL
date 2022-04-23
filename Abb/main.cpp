#include "abb.hpp"
#include "Abb-E_S.hpp"
#include "EJ2.hpp"
#include <iostream>

int main(){
    Abb<int> A;

    rellenarAbb(A, -1);
    equilibrar(A);
    imprimirAbb(A);

    return 0;
}