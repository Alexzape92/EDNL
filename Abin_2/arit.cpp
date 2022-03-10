#include "arit.hpp"

int powi(int a, int b){
    for(unsigned i = 0; i < b; i++)
        a *= a;
    
    return a;
}