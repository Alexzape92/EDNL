#include "arit.hpp"

unsigned powi(unsigned a, unsigned b){
    unsigned res = 1;
    for(unsigned i = 0; i < b; i++)
        res *= a;
    
    return res;
}