#ifndef EJ3_HPP_
#define EJ3_HPP_
#include "Abin_d.hpp"
#include <iostream>

struct tOp{
    //Atributos
    char op;
    float f;
    //Métodos
    friend std::ostream& operator <<(std::ostream& os, const tOp& ope);
    friend std::istream& operator >>(std::istream& is, tOp& ope);
    friend bool operator !=(const tOp& ope1, const tOp& ope2);
};

float operacionAbin(const Abin<tOp>& A);



#endif