//Nombres: Jose Javier Aceituno Fuentes y Fabrizio Nicolás Zeballos
//Usuario DomJudge: Fabrizio Zeballos: C101


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SetOfInts3.h"




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k_elements, sentry = -1;
    int num;
    int pos;
    SetOfInts3 v;
    cin >> k_elements;
    if (k_elements == 0) {
        return false;
    }

    /*  Coste del Algoritmo: (k = k_elements y n = size)
     *  En peor caso, en el que n sea igual a k el coste es lineal ya que depende de k, si todos los números son distintos
     *  el coste del algoritmo es el mismo que el de la función add, O(size) u O(k), ya que el coste de contains(num) es O(logn).
     *  Si k = n y hay números repetidos el coste sigue siendo O(size) u O(k) ya que si el número está repetido no lo añade.
     *  Y si k <= n el coste O(size).
    */

    cin >> num;
    while(num != sentry){
        if(!v.contains(num) && v.getSize() < k_elements){
            v.add(num);
        }
        else if(!v.contains(num) && v.getMax(pos) > num){
            v.removeMax(pos);
            v.add(num);
        }
        cin >> num;
    }

    cout << v << endl;

    return true;
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
