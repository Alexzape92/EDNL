#include <iostream>
#include "Agen_d.hpp"
#include "agen_E-S.hpp"
//#include "EJ3.hpp"

int main() {
    Agen<char> A;

    rellenarAgen(A, '-');
    imprimirAgen(A);

    return 0;
}