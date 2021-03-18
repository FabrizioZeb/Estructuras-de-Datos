// Fabrizio Nicolás Zeballos y Jose Javier Aceituno Fuentes
// C101 C02


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Stack.h"


//Coste O(s.size()) si el espacio de la pila no se llena. En el caso en que esté lleno tomará O(pila.size() * s.size()) redimensionarla para que quepan los nuevos elementos.
bool equilibrada(std:: string s) {
    Stack <char> pila;
    int i = 0;
    while (i < s.size()){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') pila.push(s[i]);
        else if(s[i] == ')'){
            if(!pila.empty() && pila.top() == '(')
                pila.pop();
            else
                pila.push(s[i]);
        }
        else if(s[i] == ']') {
            if (!pila.empty() && pila.top() == '[')
                pila.pop();
            else
                pila.push(s[i]);
        }
        else if(s[i] == '}') {
            if (!pila.empty() && pila.top() == '{')
                pila.pop();
            else
                pila.push(s[i]);
        }
        i++;
    }
    if(pila.empty()) return true;
    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std :: string s;
    // leer los datos de la entrada
    std :: getline(std:: cin, s);
    if (! std::cin)
        return false;

    if(equilibrada(s)) std :: cout << "SI\n";
    else std :: cout << "NO\n";

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