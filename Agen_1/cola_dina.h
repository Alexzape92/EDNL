#ifndef COLA_DINA_H_
#define COLA_DINA_H_
#include <cassert>

template <typename t> class cola{
public:
	cola();
	cola(const cola& c);
	cola& operator =(const cola& c);
	bool vacia() const;
	const t& frente() const;
	void push(const t& x);
	void pop();
	~cola();
private:
	struct nodo{
		t elem;
		nodo* sig;

		nodo(const t& x, nodo *p = nullptr): elem(x), sig(p){}
	};
	nodo *fin;
};

template<typename t>
cola<t>::cola():
	fin(nullptr)
{}

template<typename t>
cola<t>::cola(const cola& c):
	fin(nullptr)
{
	if(!c.vacia()){		//En caso de que la cola esté vacía, no deberemos hacer nada más
		nodo *j = c.fin->sig;
		do{
			push(j->elem);
			j = j->sig;
		}while(j != c.fin->sig);
	}
}

template<typename t>
cola<t>& cola<t>::operator =(const cola& c){
	if(this != &c){
		this->~cola();	//Vaciamos la cola actual
		nodo *j = c.fin->sig;
			do{
				push(j->elem);
				j = j->sig;
			}while(j != c.fin->sig);
	}
	return *this;
}

template<typename t>
bool cola<t>::vacia() const{
	return fin == nullptr;
}

template<typename t>
const t& cola<t>::frente() const{
	assert(!vacia());
	return fin->sig->elem;
}

template<typename t>
void cola<t>::push(const t& x){
	if(fin == nullptr){
		nodo *q = new nodo(x);
		q->sig = q;
		fin = q;
	}
	else{
		nodo *q = new nodo(x, fin->sig);
		fin->sig = q;
		fin = q;
	}
}

template<typename t>
void cola<t>::pop(){
	assert(!vacia());
	if(fin->sig == fin){	//Si solo tiene 1 elemento
		delete fin;
		fin = nullptr;
	}
	else{
		nodo *q = fin->sig;
		fin->sig = q->sig;
		delete q;
	}
}

template<typename t>
cola<t>::~cola(){
	while(!vacia()){
		pop();
	}
}

#endif /* COLA_DINA_H_ */
