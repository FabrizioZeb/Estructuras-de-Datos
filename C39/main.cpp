// Fabrrizio Zeballos y Jose Javier Aceituno
// c101


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

using namespace std;
// función que resuelve el problema

//Coste O(n), siendo n el número de nodos del arbol. Va de forma recursiva desde la raíz hasta las hojas
//de izquierda a derecha.
void genealogico(bintree<int> arb, int &geniz,int &gendr, bool &boolg) {
    if (!arb.empty()) {
        if (!arb.left().empty()) {

            if ((arb.root() - arb.left().root()) >= 18) { //supera en al menos 18 años

                if (!arb.right().empty()) {

                    if (arb.left().root() - arb.right().root() >= 2) { //es al menos dos años menos
                        boolg = true;
                        geniz++;
                        genealogico(arb.left(), geniz, gendr, boolg);
                        if(boolg == false) //arboles genealogicos de ambos hijos son tambien correctos
                            return;
                        gendr++;
                        genealogico(arb.right(), geniz, gendr, boolg);
                        if(boolg == false) //arboles genealogicos de ambos hijos son tambien correctos
                            return;
                    }


                    else {
                        boolg = false;
                        return;
                    }


                } else {
                    geniz++;
                    boolg = true;
                    genealogico(arb.left(), geniz, gendr, boolg);
                    if(boolg == false) return; //arboles genealogicos de ambos hijos son tambien correctos
                }
            } else {
                boolg = false;
                return;
            }
        } else if(!arb.right().empty()){
            boolg = false;
            return;
        } else{

            boolg = true;
            return;
        }
    } else {
        boolg = true;
        return;
    }
}


bintree<int> leerArbol(const int &repVacio) {
    int elem;
    std::cin >> elem;
    if (elem == repVacio)
        return bintree<int>();
    else {
        bintree<int> hi = leerArbol(repVacio);
        bintree<int> hd = leerArbol(repVacio);
        return bintree<int>(hi, elem, hd);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> bintree;
    bintree = leerArbol(-1);
    bool valid = false;
    int geniz = 0, gendr = 0;
    //bintree.graph(cout);
    genealogico(bintree, geniz,gendr, valid);
    geniz = max(geniz,gendr);
    if (valid) cout << "SI " << bintree.height() << endl;
    else cout << "NO\n";

    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}