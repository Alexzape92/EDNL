#include "Abin_d.hpp"
#include "abin_E-S.hpp"
#include "EJ3.hpp"
#include <iostream>

int main(){
    Abin<tOp> A;
    tOp fin;    //Será fin si el operador es f
    fin.f = int();
    fin.op = 'f';

    rellenarAbin(A, fin);
    
    std::cout << "El resultado es: " << operacionAbin(A);
    
    return 0;
}