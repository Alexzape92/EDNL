#include "EJ4.hpp"
#include "abin_E-S.hpp"
#include <iostream>

int main(){
    Abin<char> A(4, '-');

    rellenarAbin(A, '-');
    imprimirAbin(A);
    
    return 0;
}