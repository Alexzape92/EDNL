#include "Abin_d.hpp"
#include "Nodos_Nost.hpp"
#include "abin_E-S.hpp"
#include <iostream>

int main() {
    Abin<char> A;

    rellenarAbin(A, '-');
    std::cout << "El número de nodos nostálgicos es: " << numNost(A) << std::endl;

    return 0;
}