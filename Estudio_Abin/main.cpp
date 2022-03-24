#include "Abin_d.hpp"
#include "sept21.hpp"
#include "abin_E-S.hpp"
#include <iostream>

int main() {
    Abin<int> A;

    rellenarAbin(A, -1);
    transf(A);
    imprimirAbin(A);

    return 0;
}