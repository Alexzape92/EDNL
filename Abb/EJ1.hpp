#ifndef EJ1_HPP_
#define EJ1_HPP_
#include "abb.hpp"

template<typename t>
void Abb<t>::eliminar_todo(const t& x){
    if(r->elto < x)
        r->der.eliminar_todo(x);
    else if(r->elto > x)
        r->izq.eliminar_todo(x);
    else{
        delete r;   //Esto eliminará r y los subárboles izq y der
        r = nullptr;
    }
}


#endif