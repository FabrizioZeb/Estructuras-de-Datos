/**
  @file TreeSet.h

  Implementaci�n din�mica del TAD Set utilizando
  �rboles de b�squeda.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Marco Antonio Gómez Martín y Miguel Gómez-Zamalloa, 2018
*/
#ifndef __TREESET_H
#define __TREESET_H

#include "Exceptions.h"

#include "Stack.h" // Usado internamente por los iteradores

/**
 Implementaci�n din�mica del TAD Set utilizando
 �rboles de b�squeda (no auto-balanceados).

 Las operaciones son:

 - TreeSetVacio: operaci�n generadora que construye
 un conjunto vacío (�rbol de b�squeda vac�o).

 - Insert(elem): generadora que a�ade un
 nuevo elem al conjunto. Si elem ya estaba no se hace nada.

 - erase(elem): operaci�n modificadora. Elimina
 elem del conjunto.  Si elem no est� la operaci�n no tiene efecto.

 - contains(elem): operaci�n observadora. Determina si elem
 pertenece conjunto.

 - empty(): operacion observadora que indica si
 el conjunto es vacío.

 @author Marco Antonio Gómez Martín
 @author Miguel Gómez-Zamalloa
 */
template <class T>
class TreeSet {

private:

	/**
	 Clase nodo que almacena internamente el dato
	 y los punteros al hijo izquierdo y al hijo derecho.
	 */
	class Nodo {
	public:
		Nodo() : _iz(NULL), _dr(NULL) {}
		Nodo(const T &elem)
			: _elem(elem), _iz(NULL), _dr(NULL) {}
		Nodo(Nodo *iz, const T &elem, Nodo *dr)
			: _elem(elem), _iz(iz), _dr(dr) {}

		T _elem;
		Nodo *_iz;
		Nodo *_dr;

	};

	//Coste O(logn) si el árbol está balanceado, en caso contrario el coste es aproximadamente O(n), siendo n el número de nodos del árbol.
	void dfs(Nodo* nodo,T const & lower, T const & upper, int & ret) const{
        if(nodo != NULL) { // Si el árbol está vacio o se llega al final de esa rama no accede a la funcionamiento de abajo.
            if(nodo->_elem >= lower && nodo->_elem <= upper) // Mientras esté dentro del intervalo aumenta en 1 ret (Número de elementos comprendidos en dicho intervalo).
                ret++;
            if(lower != nodo->_elem) //Si lower == nodo-> _elem , significa que todos los elementos a la izquierda son menores que lower, por lo tanto no revisamos esa rama izquierda
                if(nodo->_iz != NULL && nodo->_iz->_elem >= lower)
                  dfs(nodo->_iz,lower,upper,ret); // Llammada recursiva a la raíz del hijo izquierdo
            if(upper != nodo->_elem) //Y viceversa si upper == nodo-> _elem , los elementos a la derecha son mayores que el intervalo (upper), por lo que no revisamos la rama derecha desde ese nodo.
                if(nodo->_dr != NULL && nodo->_dr->_elem <= upper)
                  dfs(nodo->_dr,lower,upper,ret); // Llamada recursiva a la raíz del hijo dcho.
        }
	}

public:

	/** Constructor; operacion EmptyTreeSet */
	TreeSet() : _ra(NULL) {
	}

	/** Destructor; elimina la estructura jer�rquica de nodos. */
	~TreeSet() {
		libera();
		_ra = NULL;
	}

	/**
	 Operaci�n generadora que a�ade un nuevo elemento al conjunto.
	 @param elem T nuevo.
 	 Si elem ya se hab�a insertado previamente no se hace nada
	 */
	void insert(const T &elem) {
		_ra = insertaAux(elem, _ra);
	}

	/**
	 Operaci�n modificadora que elimina un elemento del conjunto.
	 Si elem no exist�a la operaci�n no tiene efecto.
	 @param elem T a eliminar.
	 */
	void erase(const T &elem) {
		_ra = borraAux(_ra, elem);
	}

	/**
	 Operaci�n observadora que comprueba si elem pertenece al conjunto.
	 @param elem T por el que se pregunta.
	 @return true si el conjunto contiene elem.
	 */
	bool contains(const T &elem) const {
		return (buscaAux(_ra, elem) != NULL) ? true : false;
	}

	/**
	 Operaci�n observadora que comprueba si el conjunto es vacío.
	 */
	bool empty() const {
		return _ra == NULL;
	}


    int count_interval(T const& lower, T const& upper) const {
	    int ret = 0;
        if(_ra == NULL) return 0;
        else {
            //Función auxiliar. En esta función está comentado el coste y el funcionamiento.
            dfs(_ra,lower,upper,ret);
        }
        return ret;
    }




    // //
	// ITERADOR CONSTANTE Y FUNCIONES RELACIONADAS
	// //

	/**
	 Clase interna que implementa un iterador que permite
	 recorrer el �rbol pero no permite modificarlo.
	 */
	class ConstIterator {
	public:
		ConstIterator() : _act(NULL) {}

		void next() {
			if (_act == NULL) throw InvalidAccessException();

			// Si hay hijo derecho, saltamos al primero
			// en inorden del hijo derecho
			if (_act->_dr!=NULL)
				_act = primeroInOrden(_act->_dr);
			else {
				// Si no, vamos al primer ascendiente
				// no visitado. Para eso consultamos
				// la pila; si ya est� vac�a, no quedan
				// ascendientes por visitar
				if (_ascendientes.empty())
					_act = NULL;
				else {
					_act = _ascendientes.top();
					_ascendientes.pop();
				}
			}
		}

		const T &elem() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_elem;
		}

		const T& operator*() const {
			return elem();
		}

		bool operator==(const ConstIterator &other) const {
			return _act == other._act;
		}

		bool operator!=(const ConstIterator &other) const {
			return !(this->operator==(other));
		}

		ConstIterator &operator++() {
			next();
			return *this;
		}

		ConstIterator operator++(int) {
			ConstIterator ret(*this);
			operator++();
			return ret;
		}

	protected:
		// Para que pueda construir objetos del tipo iterador
		friend class TreeSet;

		ConstIterator(Nodo *act) {
			_act = primeroInOrden(act);
		}

		/**
		 Busca el primer elemento en inorden de
		 la estructura jer�rquica de nodos pasada
		 como par�metro; va apilando sus ascendientes
		 para poder "ir hacia atr�s" cuando sea necesario.
		 @param p Puntero a la ra�z de la subestructura.
		 */
		Nodo *primeroInOrden(Nodo *p) {
			if (p == NULL)
				return NULL;

			while (p->_iz != NULL) {
				_ascendientes.push(p);
				p = p->_iz;
			}
			return p;
		}

		// Puntero al nodo actual del recorrido
		// NULL si hemos llegado al final.
		Nodo *_act;

		// Ascendientes del nodo actual a�n por visitar
		Stack<Nodo*> _ascendientes;
	};

	/**
	 Devuelve el iterador constante al principio del recorrido inorden (elemento m�s peque�o).
	 @return iterador al principio del recorrido;
	 coincidir� con cend() si el conjunto es vacío.
	 */
	ConstIterator cbegin() const {
		return ConstIterator(_ra);
	}

	/**
	 @return Devuelve un iterador al final del recorrido (fuera de �ste).
	 */
	ConstIterator cend() const {
		return ConstIterator(NULL);
	}

	ConstIterator find(const T &c) const {
		Stack<Nodo*> ascendientes;
		Nodo *p = _ra;
		while ((p != NULL) && (p->_elem != c)) {
			if (p->_elem > c) {
				ascendientes.push(p);
				p = p->_iz;
			} else
				p = p->_dr;
		}
		ConstIterator ret;
		ret._act = p;
		if (p != NULL)
			ret._ascendientes = ascendientes;
		return ret;
	}

	// //
	// ITERADOR NO CONSTANTE Y FUNCIONES RELACIONADAS
	// //

	/**
	 Clase interna que implementa un iterador sobre
	 la �rbol de b�squeda que permite recorrerlo. Este iterador
	 tampoco permite modificaciones de la estructura y es por tanto
	 igual al ConstIterator. Se mantienen ambos por consistencia con
	 el resto de contenedores.
	 */
	class Iterator {
	public:
		Iterator() : _act(NULL) {}

		void next() {
			if (_act == NULL) throw InvalidAccessException();

			// Si hay hijo derecho, saltamos al primero
			// en inorden del hijo derecho
			if (_act->_dr!=NULL)
				_act = primeroInOrden(_act->_dr);
			else {
				// Si no, vamos al primer ascendiente
				// no visitado. Para eso consultamos
				// la pila; si ya est� vac�a, no quedan
				// ascendientes por visitar
				if (_ascendientes.empty())
					_act = NULL;
				else {
					_act = _ascendientes.top();
					_ascendientes.pop();
				}
			}
		}

		const T &elem() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_elem;
		}

		const T& operator*() const {
			return elem();
		}

		bool operator==(const Iterator &other) const {
			return _act == other._act;
		}

		bool operator!=(const Iterator &other) const {
			return !(this->operator==(other));
		}

		Iterator &operator++() {
			next();
			return *this;
		}

		Iterator operator++(int) {
			Iterator ret(*this);
			operator++();
			return ret;
		}

	protected:
		// Para que pueda construir objetos del
		// tipo iterador
		friend class TreeSet;

		Iterator(Nodo *act) {
			_act = primeroInOrden(act);
		}

		/**
		 Busca el primer elemento en inorden de
		 la estructura jer�rquica de nodos pasada
		 como par�metro; va apilando sus ascendientes
		 para poder "ir hacia atr�s" cuando sea necesario.
		 @param p Puntero a la ra�z de la subestructura.
		 */
		Nodo *primeroInOrden(Nodo *p) {
			if (p == NULL)
				return NULL;

			while (p->_iz != NULL) {
				_ascendientes.push(p);
				p = p->_iz;
			}
			return p;
		}

		// Puntero al nodo actual del recorrido
		// NULL si hemos llegado al final.
		Nodo *_act;

		// Ascendientes del nodo actual
		// a�n por visitar
		Stack<Nodo*> _ascendientes;
	};

	/**
	 Devuelve el iterador al principio del recorrido.
	 @return iterador al principio del recorrido inorden;
	 coincidir� con final() si el conjunto es vac�o.
	 */
	Iterator begin() {
		return Iterator(_ra);
	}

	/**
	 @return Devuelve un iterador al final del recorrido (fuera de �ste).
	 */
	Iterator end() const {
		return Iterator(NULL);
	}

	Iterator find(const T &e) {
		Stack<Nodo*> ascendientes;
		Nodo *p = _ra;
		while ((p != NULL) && (p->_elem != e)) {
			if (p->_elem > e) {
				ascendientes.push(p);
				p = p->_iz;
			} else
				p = p->_dr;
		}
		Iterator ret;
		ret._act = p;
		if (p != NULL)
			ret._ascendientes = ascendientes;
		return ret;
	}


	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL  A LA CLASE
	// //

	/** Constructor copia */
	TreeSet(const TreeSet<T> &other) : _ra(NULL) {
		copia(other);
	}

	/** Operador de asignaci�n */
	TreeSet<T> &operator=(const TreeSet<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

protected:

	/**
	 Constructor protegido que crea un �rbol
	 a partir de una estructura jer�rquica de nodos previamente creada.
	 Se utiliza en hijoIz e hijoDr.
	 */
	TreeSet(Nodo *raiz) : _ra(raiz) {
	}

	void libera() {
		libera(_ra);
	}

	void copia(const TreeSet &other) {
		_ra = copiaAux(other._ra);
	}

private:



	/**
	 Elimina todos los nodos de una estructura arb�rea que comienza con el puntero ra.
	 Se admite que el nodo sea NULL (no habr� nada que liberar).
	 */
	static void libera(Nodo *ra) {
		if (ra != NULL) {
			libera(ra->_iz);
			libera(ra->_dr);
			delete ra;
		}
	}

	/**
	 Copia la estructura jer�rquica de nodos pasada
	 como par�metro (puntero a su raiz) y devuelve un
	 puntero a una nueva estructura jer�rquica, copia
	 de anterior (y que, por tanto, habr� que liberar).
	 */
	static Nodo *copiaAux(Nodo *ra) {
		if (ra == NULL)
			return NULL;

		return new Nodo(copiaAux(ra->_iz),
						ra->_elem,
						copiaAux(ra->_dr));
	}

	/**
	 Inserta un elem en la estructura jer�rquica
	 que comienza en el puntero pasado como par�metro.
	 Ese puntero se admite que sea NULL, por lo que se crear�
	 un nuevo nodo que pasar� a ser la nueva ra�z de esa
	 estructura jer�rquica. El m�todo devuelve un puntero a la
	 ra�z de la estructura modificada. En condiciones normales
	 coincidir� con el par�metro recibido; s�lo cambiar� si
	 la estructura era vac�a.
	 @param elem T a insertar. Si ya aparec�a en la
	 estructura de nodos, no se hace nada.
	 @param p Puntero al nodo ra�z donde insertar la pareja.
	 @return Nueva ra�z (o p si no cambia).
	 */
	static Nodo *insertaAux(const T &elem, Nodo *p) {

		if (p == NULL) {
			return new Nodo(elem);
		} else if (p->_elem == elem) {
			return p;
		} else if (elem < p->_elem) {
			p->_iz = insertaAux(elem, p->_iz);
			return p;
		} else { // (elem > p->_elem)
			p->_dr = insertaAux(elem, p->_dr);
			return p;
		}
	}

	/**
	 Busca un elemento en la estructura jer�rquica de
	 nodos cuya ra�z se pasa como par�metro, y devuelve
	 el nodo en el que se encuentra (o NULL si no est�).
	 @param p Puntero a la ra�z de la estructura de nodos
	 @param elem T a buscar
	 */
	static Nodo *buscaAux(Nodo *p, const T &elem) {
		if (p == NULL)
			return NULL;

		if (p->_elem == elem)
			return p;

		if (elem < p->_elem)
			return buscaAux(p->_iz, elem);
		else
			return buscaAux(p->_dr, elem);
	}

	/**
	 Elimina (si existe) el elemento de la estructura jer�rquica
	 de nodos apuntada por p. Si el elemento aparec�a en la propia ra�z,
	 �ste cambiar�, por lo que se devuelve la nueva ra�z. Si no cambia
	 se devuelve p.

	 @param p Ra�z de la estructura jer�rquica donde borrar elem.
	 @param elem T a borrar.
	 @return Nueva ra�z de la estructura, tras el borrado. Si la ra�z
	 no cambia, se devuelve el propio p.
	*/
	static Nodo *borraAux(Nodo *p, const T &elem) {

		if (p == NULL)
			return NULL;

		if (elem == p->_elem) {
			return borraRaiz(p);
		} else if (elem < p->_elem) {
			p->_iz = borraAux(p->_iz, elem);
			return p;
		} else { // elem > p->_elem
			p->_dr = borraAux(p->_dr, elem);
			return p;
		}
	}

	/**
	 Borra la ra�z de la estructura jer�rquica de nodos
	 y devuelve el puntero a la nueva ra�z que garantiza
	 que la estructura sigue siendo v�lida para un �rbol de
	 b�squeda (elems ordenados).
	 */
	static Nodo *borraRaiz(Nodo *p) {

		Nodo *aux;

		// Si no hay hijo izquierdo, la ra�z pasa a ser
		// el hijo derecho
		if (p->_iz == NULL) {
			aux = p->_dr;
			delete p;
			return aux;
		} else
		// Si no hay hijo derecho, la ra�z pasa a ser
		// el hijo izquierdo
		if (p->_dr == NULL) {
			aux = p->_iz;
			delete p;
			return aux;
		} else {
		// Convertimos el elemento m�s peque�o del hijo derecho
		// en la ra�z.
			return mueveMinYBorra(p);
		}
	}

	/**
	 M�todo auxiliar para el borrado; recibe un puntero a la
	 ra�z a borrar. Busca el elemento m�s peque�o del hijo derecho
	 que se convertir� en la ra�z (que devolver�), borra la antigua
	 ra�z (p) y "cose" todos los punteros, de forma que ahora:

	   - El m�nimo pasa a ser la ra�z, cuyo hijo izquierdo y
	     derecho eran los hijos izquierdo y derecho de la ra�z
	     antigua.
	   - El hijo izquierdo del padre del elemento m�s peque�o
	     pasa a ser el antiguo hijo derecho de ese m�nimo.
	 */
	static Nodo *mueveMinYBorra(Nodo *p) {

		// Vamos bajando hasta que encontramos el elemento
		// m�s peque�o (aquel que no tiene hijo izquierdo).
		// Vamos guardando tambi�n el padre (que ser� null
		// si el hijo derecho es directamente el elemento
		// m�s peque�o).
		Nodo *padre = NULL;
		Nodo *aux = p->_dr;
		while (aux->_iz != NULL) {
			padre = aux;
			aux = aux->_iz;
		}

		// aux apunta al elemento m�s peque�o.
		// padre apunta a su padre (si el nodo es hijo izquierdo)

		// Dos casos dependiendo de si el padre del nodo con
		// el m�nimo es o no la ra�z a eliminar
		// (=> padre != NULL)
		if (padre != NULL) {
			padre->_iz = aux->_dr;
			aux->_iz = p->_iz;
			aux->_dr = p->_dr;
		} else {
			aux->_iz = p->_iz;
		}

		delete p;
		return aux;
	}

	/**
	 Puntero a la ra�z de la estructura jer�rquica de nodos.
	 */
	Nodo *_ra;
};

#endif // __TREESET_H

