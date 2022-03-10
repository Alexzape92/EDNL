#include "Abin_d.hpp"
#include "abin_E-S.hpp"
#include "EJ7.hpp"
#include <iostream>

//NO HE HECHO EL 5 Y 6 PORQUE ES IGUAL QUE EL 2 Y EL 3, PERO USANDO EL VECTOR O PUNTEROS EN VEZ DE
//LOS METODOS PÚBLICOS

int main(){
    Abin<int> A;

    rellenarAbin(A, -1);
    if(pseudocomp(A))
        std::cout << "El arbol es pseudocompleto" << std::endl;
    else
        std::cout << "El arbol NO es pseudocompleto" << std::endl;

    return 0;
}