#include "Agen_d.hpp"
#include "EJ4.hpp"
#include "agen_E-S.hpp"
#include <iostream>

int main(){
    Agen<char> A;
    rellenarAgen(A, '-');

    if(ternario(A))
        std::cout << "El árbol dado ES ternario" << std::endl;
    else
        std::cout << "El árbol dado NO ES ternario" << std::endl;
    
    return 0;
}