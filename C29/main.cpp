// Fabrizio Zeballos Jose Javier Aceituno
// C101


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;


// Coste lineal O(mylist.size()).
list<int> resolver(list<int> & mylist) {

    for(auto it = mylist.begin(), prev = mylist.begin(); it != mylist.end();prev = it,it++){
        if(*it < *prev){
            it._M_node = prev._M_node;
            it._M_node->_M_next = it._M_node->_M_next->_M_next;
        }

    }
    return mylist;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    list<int> mylist;
    list<int> res;
    int n;
    // leer los datos de la entrada
    cin >> n;
    while(n != -1){
        mylist.push_back(n);
        cin>> n;
    }

    res = resolver(mylist);
    // escribir sol
    for(auto it = res.begin(); it != res.end(); it++){
        cout << *it ;
        cout << " ";
    }
    cout << endl;
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