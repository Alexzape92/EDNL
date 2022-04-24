#include "abb.hpp"
#include "Abb-E_S.hpp"
#include "EJ5.hpp"
#include <iostream>

int main(){
    Abb<int> A, B;

    rellenarAbb(A, -1);
    rellenarAbb(B, -1);
    Conjunto<int> cA(A), cB(B);

    imprimirAbb((cA ^ cB).arb);

    return 0;
}