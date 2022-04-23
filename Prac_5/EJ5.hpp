#ifndef EJ5_HPP_
#define EJ5_HPP_
#include "Agen_d.hpp"

struct tCuadrante{
    bool color;
    int supizq1, supizq2, infder1, infder2;
};

bool** matriz(const Agen<tCuadrante>& A);


#endif