#include <iostream>
#include "Agen_v.hpp"
#include "agen_E-S.hpp"

int main() {
    Agen<char> A(20);

    rellenarAgen(A, '.');
    imprimirAgen(A);

    return 0;
}