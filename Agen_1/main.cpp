#include <iostream>
#include "Agen_v.hpp"
#include "agen_E-S.hpp"
#include "EJ3.hpp"

int main() {
    Agen<char> A(20);

    rellenarAgen(A, '.');
    std::cout << "La altura es " << AlturaNodoAgen(A.raiz(), A) << std::endl;

    return 0;
}