// Fabrizio Nicolás Zeballos y Jose Javier Aceituno Fuentes
// C101

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Arbin.h"
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    Arbin<int> ar = ar.leerArbol(-1);
    if(!ar.esVacio()){

        List<int> res = *ar.leafNodes();
        for(List<int>::Iterator it = res.begin(); it != res.end(); it++){
            cout << *it << ' ';
        }
        cout << "\n";
    }
    else cout << endl;
    // leer los datos de la entrada
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