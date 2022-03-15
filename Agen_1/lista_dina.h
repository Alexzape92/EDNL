

#ifndef LISTA_DINA_H_
#define LISTA_DINA_H_
#include <cassert>

template<typename t> class lista{
struct nodo;
public:
	typedef nodo* posicion;
	lista();
	lista(const lista<t>& l);
	lista<t>& operator =(const lista<t>& l);
	bool vacia() const {return cabecera->sig == nullptr;}
	void insertar(const t& x, posicion p);
	void eliminar(posicion p);
	const t& elemento(posicion p) const {assert(p->sig != nullptr); return p->sig->elem;}
	t& elemento(posicion p) {assert(p->sig != nullptr); return p->sig->elem;}
	posicion buscar(const t& x) const;
	posicion primera() const {return cabecera;}
	posicion siguiente(posicion p) const {assert(p->sig != nullptr); return p->sig;}
	posicion anterior(posicion p) const;
	posicion fin() const;
	~lista();
private:
	struct nodo{
		t elem;
		nodo *sig;

		nodo(const t& x, nodo *p = nullptr): elem(x), sig(p) {};
	};

	nodo* cabecera;
};

template<typename t>
lista<t>::lista():
	cabecera(new nodo(0))
{}

template<typename t>
lista<t>::lista(const lista<t>& l):
	cabecera(new nodo(0))
{
	if(!l.vacia()){
		nodo *o = l.cabecera;
		nodo *d = cabecera;
		while(o->sig != nullptr){
			o = o->sig;
			nodo *q = new nodo(o->elem);
			d->sig = q;
			d = d->sig;
		}
	}
}

template<typename t>
lista<t>& lista<t>::operator =(const lista<t>& l){
	if(this != &l){
		this->~lista();	//Borramos la lista actual
		cabecera = new nodo(0);
		if(!l.vacia()){
			nodo *o = l.cabecera;
			nodo *d = cabecera;
			while(o->sig != nullptr){
				o = o->sig;
				nodo *q = new nodo(o->elem);
				d->sig = q;
				d = d->sig;
			}
		}
	}
	return *this;
}

template<typename t>
void lista<t>::insertar(const t& x, lista<t>::posicion p){
	if(vacia()){
		cabecera->sig = new nodo(x);
	}
	else{
		nodo *q = new nodo(x, p->sig);
		p->sig = q;
	}
}

template<typename t>
void lista<t>::eliminar(lista<t>::posicion p){
	assert(!vacia());
	nodo *q = p->sig;
	p->sig = q->sig;
	delete q;
}

template<typename t>
typename lista<t>::posicion lista<t>::buscar(const t& x) const {
	nodo *q = cabecera;
	while(q->sig != nullptr && q->sig->elem != x)
		q = q->sig;
	return q;
}

template<typename t>
typename lista<t>::posicion lista<t>::anterior(lista<t>::posicion p) const{
	assert(p != cabecera);
	nodo *q = cabecera;
	while(q->sig != p)
		q = q->sig;
	return q;
}

template<typename t>
typename lista<t>::posicion lista<t>::fin() const {
	nodo *q = cabecera;
	while(q->sig != nullptr)
		q = q->sig;
	return q;
}

template<typename t>
lista<t>::~lista(){
	while(!vacia()){
		eliminar(primera());
	}
}


#endif /* LISTA_DINA_H_ */
