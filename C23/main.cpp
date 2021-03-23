// Fabrizio Nicolás Zeballos y Jose Javier Aceituno
// C101


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;

// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int elem;
    Queue<int> cola;
    Queue<int> colegas;
    int pringao;
    // leer los datos de la entrada
    cin>>elem;
    while (elem != -1){
        cola.push_back(elem);
        cin>>elem;
    }
    cin>>pringao;
    cin>>elem;
    while (elem != -1){
        colegas.push_back(elem);
        cin>>elem;
    }
    cout << cola << endl;
    cola.colar(pringao,colegas);
    cout << cola << endl;
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