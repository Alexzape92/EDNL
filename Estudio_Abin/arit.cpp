#include "arit.hpp"
#include <algorithm>

int max3(int a, int b, int c){
    return std::max(a, std::max(b, c));
}