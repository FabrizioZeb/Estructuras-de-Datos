// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SetOfInts3.h"

using namespace std;

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
template <class T>
void solve(T fin) {
    // leer los datos de la entrada
    int k;
    T elem;
    SetOfInts3<T> set;
    cin >> k;

    int pos;

    while (k > 0) {
        cin >> elem;
        if (!set.contains(elem)) {
            set.add(elem);
            k--;
        }
    }

    cin >> elem;
    while (elem != fin){

        if(!set.contains(elem) && set.getMin(pos) < elem){
            set.removeMin(pos);
            set.add(elem);
        }

        cin >> elem;
    }

    set.write(cout);
    cout << endl;

    // escribir sol


}


bool resuelveCaso() {

    char StringOrInts;
    cin >> StringOrInts;

    if (!cin) return false;

    if (StringOrInts == 'N') solve(-1);
    else if (StringOrInts == 'P') {
        solve(string("FIN"));
    }
    else return false;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}