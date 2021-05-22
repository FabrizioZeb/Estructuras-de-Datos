/*
 * bintree_eda.h
 *
 * Implementación del TAD arbol binario con nodos enlazados usando shared_ptr
 *
 *  Estructuras de Datos y Algoritmos
 *  Facultad de Informática
 *  Universidad Complutense de Madrid
 *
 *  Copyright (c) 2017 Enrique Martín Martín. All rights reserved.
 */

#pragma once

#include <stdexcept> // domain_error
#include <algorithm> // max
#include <memory>    // shared_ptr, make_shared
#include <iomanip>   // setw
#include <iostream>  // endl
using namespace std;


template <typename T>
class bintree {
private:
    static const int TREE_INDENTATION = 4;
    
    /*
     Nodo que almacena internamente el elemento (de tipo T)
     y dos 'punteros compartidos', uno al hijo izquierdo y al hijo derecho.
     */
    class Nodo; // Declaración adelantada para poder definir Link
    using Link = shared_ptr<Nodo>; // Alias de tipo

    class Nodo {
    public:
        Link izq;
        T elem;
        Link der;

        Nodo(const T& elem) : izq(nullptr), elem(elem), der(nullptr) {}
        Nodo(Link izq, const T& elem, Link der) : izq(izq), elem(elem), der(der) {}
    };

    // puntero a la raíz
    Link raiz;

    // constructora privada a partir de un puntero a Nodo
    // Para construir los árboles generados por left() y right()
    bintree(Link r) : raiz(r) {} // O(1)

    // Muestra por 'out' una representación del árbol
    // Adaptado de "ADTs, DataStructures, and Problem Solving with C++", Larry Nyhoff, Person, 2015
    void graph_rec(ostream & out, int indent, Link raiz) const { 
    // O(n), donde 'n' es el número de nodos alcanzables desde 'raiz'
        if (raiz != nullptr) {
            graph_rec(out, indent + TREE_INDENTATION, raiz->der);
            out << setw(indent) << " " << raiz->elem << endl;
            graph_rec(out, indent + TREE_INDENTATION, raiz->izq);
        }
    }

public:
    // constructor de árbol vacío
    bintree() : raiz(nullptr) {} // O(1)
    
    // constructor de árbol hoja
    bintree(const T& elem) : raiz(new Nodo(elem)) {} // O(1)

    // constructor de árbol con 2 hijos
    bintree(const bintree<T>& izq, const T& elem, const bintree<T>& der) : // O(1)
        raiz(new Nodo(izq.raiz, elem, der.raiz)) {}

    // valor en la raíz (si existe)
    const T& root() const { // O(1)
        if (empty()) {
            throw std::domain_error("No hay raiz en arbol vacio");
        } else {
            return raiz->elem;
        }
    }
    
    // hijo izquierdo (si existe)
    bintree<T> left() const { // O(1)
        if (empty()) {
            throw std::domain_error("No hay hijos en arbol vacio");
        } else {
            return bintree(raiz->izq);
        }
    }
    
    // hijo derecho (si existe)
    bintree<T> right() const { // O(1)
        if (empty()) {
            throw std::domain_error("No hay hijos en arbol vacio");
        } else {
            return bintree(raiz->der);
        }
    }
    
    // saber si el árbol es vacío 
    bool empty() const { // O(1)
        return (raiz == nullptr);
    }
    
    // altura del árbol
    size_t height() const { // O(n), donde 'n' es el número de nodos en el árbol
        if (empty()) {
            return 0;
        } else {
            size_t hl = left().height();
            size_t hr = right().height();
            return max<size_t>(hl, hr) + 1;
        }
    }

    // Muestra por 'out' una representación del árbol
    // Adaptado de "ADTs, DataStructures, and Problem Solving with C++", Larry Nyhoff, Person, 2015
    void graph(ostream & out) const { // O(n), donde 'n' es el número de nodos en el árbol
        out << "==== Tree =====" << endl;
        graph_rec(out, 0, raiz);
        out << "===============" << endl;
    }
};

