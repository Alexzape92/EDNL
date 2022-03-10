#include "EJ3.hpp"

//Privada
float operacionAbin_Rec(Abin<tOp>::nodo n, const Abin<tOp>& A);


float operacionAbin(const Abin<tOp>& A){
    return operacionAbin_Rec(A.raiz(), A);
}

std::ostream& operator <<(std::ostream& os, const tOp& ope){
    os << ope.op << ", " << ope.f;
    
    return os;
}

std::istream& operator >>(std::istream& is, tOp& ope){
    std::cout << "\nIntroduce el operador: ";
    is >> ope.op;
    std::cout << "Introduce el operando: ";
    is >> ope.f;

    return is;
}

bool operator !=(const tOp& ope1, const tOp& ope2){
    return (ope1.op != ope2.op);
}

//Privada
float operacionAbin_Rec(Abin<tOp>::nodo n, const Abin<tOp>& A){
    if(A.hijoIzqdo(n) == Abin<tOp>::NODO_NULO)  //Solo comprobamos un hijo, pues las operaciones permitidas
        return A.elemento(n).f;                 //Son binarias (los nodos tienen 2 hijos o 0)
    else{
        switch(A.elemento(n).op) {
            case '+': return operacionAbin_Rec(A.hijoIzqdo(n), A) + operacionAbin_Rec(A.hijoDrcho(n), A); break;
            case '-': return operacionAbin_Rec(A.hijoIzqdo(n), A) - operacionAbin_Rec(A.hijoDrcho(n), A); break;
            case '*': return operacionAbin_Rec(A.hijoIzqdo(n), A) * operacionAbin_Rec(A.hijoDrcho(n), A); break;
            case '/': return operacionAbin_Rec(A.hijoIzqdo(n), A) / operacionAbin_Rec(A.hijoDrcho(n), A); break;
        }
    }
}