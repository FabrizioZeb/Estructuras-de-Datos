// Jose Javier Aceituno Fuentes y Fabrizio Zeballos
// C101

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "SetOfInts1.h"

using namespace std;



// función que resuelve el problema

void digitos(int &num, int & sum){
    int digit;
    sum = 0;
    while (num > 0){
        digit = num % 10;
        sum += pow(digit,2);
        num /= 10;
    }
}

bool esFeliz(int num){
    int sum, numRep;
    bool feliz = true;
    SetOfInts1 set;
    set.add(num);
    cout << num << " ";
    while(num != 1 && feliz) {
        digitos(num, sum);
        num = sum;
        if (!set.contains(num)) {
            set.add(num);
            cout << num << " ";
        } else {
            numRep = num;
            feliz = false;
        }
    }
    if(!feliz) cout << numRep << " ";
    return feliz;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    // leer los datos de la entrada
    cin >> n;
    if (!cin) {
        return false;
    }


    if(esFeliz(n)) cout << "1\n";
    else cout << "0\n";
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


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}