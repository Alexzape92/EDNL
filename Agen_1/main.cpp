#include <iostream>
#include <fstream>
#include "Agen_d.hpp"
#include "agen_E-S.hpp"
#include "EJ4.hpp"

int main() {
    Agen<int> A;

    std::fstream fe("arbol");
    rellenarAgen(fe, A);
    
    poda(11, A);
    imprimirAgen(A);

    return 0;
}