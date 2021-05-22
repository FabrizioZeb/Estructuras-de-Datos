// Fabrizio Nicolás Zeballos y Jose Javier Aceituno Fuentes
// C101


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Stack.h"
#include "TreeSet.h"

using namespace std;

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N,M;
    int elem;
    TreeSet<int> interval;

    // leer los datos de la entrada
    cin >> N >> M;
    if (! std::cin) {
        return false;
    }
    for(int i = 0; i < N; i++){
        cin >> elem;
        interval.insert(elem);
    }

    int lim_inf, lim_sup;
    for(int i = 0; i < M; i++){
        cin >> lim_inf >> lim_sup;
        cout << interval.count_interval(lim_inf,lim_sup) << endl;
    }
    cout << "---" << endl;

    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}