//Nombres: Jose Javier Aceituno Fuentes y Fabrizio Nicolás Zeballos
//Usuario DomJudge: Fabrizio Zeballos: C101


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SetOfInts3.h"


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k_elements, sentry = -1;
    int pos;
    int elem;

    SetOfInts3 v;
    cin >> k_elements;
    if (k_elements == 0) {
        return false;
    }

    cin >> elem;
    while(elem != sentry){
        v.add(elem);
        cin >> elem;
    }

    //Algorithm:
    //Complejidad O(v.size) por getMin() y removeMin() pero depende también de k_elements
    for(int i = 0; i < k_elements; i++){
        cout << v.getMin(pos) << " ";
        v.removeMin(pos);
    }
    cout << endl;

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
