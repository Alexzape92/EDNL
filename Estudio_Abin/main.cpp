#include "Abin_d.hpp"
#include "poda_ent.hpp"
#include "abin_E-S.hpp"
#include <iostream>

int main() {
    Abin<int> A;

    rellenarAbin(A, -1);
    poda(2, A);
    imprimirAbin(A);

    return 0;
}