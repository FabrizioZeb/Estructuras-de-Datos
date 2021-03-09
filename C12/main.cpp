// Jose Javier Aceituno Fuentes y Fabrizio Zeballos
// C101

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "SetOfInts3.h"

using namespace std;



// función que resuelve el problema
void resolver(int num) {
    SetOfInts3 set;
    bool feliz = true;
    int sum, digit, numRep;
    set.add(num);
    while (num != 1 && feliz){
        sum = 0;
        while (num > 0){
            digit = num % 10;
            sum += pow(digit,2);
            num /= 10;
        }
        num = sum;
        if(!set.contains(num)) {
            set.add(num);
        }
        else {
            numRep = num;
            feliz = false;
        }
    }
    cout << set;
    if(feliz) cout << "1";
    else cout << numRep <<" 0";
    cout << endl;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    // leer los datos de la entrada
    cin >> n;
    if (! std::cin)
        return false;

    resolver(n);

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