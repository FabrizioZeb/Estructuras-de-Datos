// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>

using namespace std;

struct tElem{
    int v;
    int i;
};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0)
        return false;

    deque <tElem> queueK, candidatesMax;

    tElem max = { 0,-1 };
    int value;

    for (int i = 0; i < k; i++) {
        cin >> value;
        if (value > max.v) {
            max = { value, i };
        }
        queueK.push_back({value,i});
    }

    deque <tElem> aux = queueK;
    int maxCandidate = 0;

    while (!aux.empty()) {
        if (aux.back().v > maxCandidate && aux.back().i != max.i) {
            maxCandidate = aux.back().v;
            candidatesMax.push_back(aux.back());
        }
        aux.pop_back();
    }

    cout << max.v;
    if (n > k) cout << " ";
    for (int i = k; i < n; ++i) {
        cin >> value;
        if (!candidatesMax.empty() && candidatesMax.back().i == queueK.front().i)
            candidatesMax.pop_back();

        if (queueK.front().v == max.v) {
            if (!candidatesMax.empty()) {
                max = candidatesMax.back();
                candidatesMax.pop_back();
            }
            else {
                max = { value,i };
            }
        }

        queueK.pop_front();
        if (value > max.v) {
            max = { value, i };
            if (!candidatesMax.empty()) candidatesMax.clear();

        }

        else {
            if (candidatesMax.empty()) candidatesMax.push_back({ value,i });
            else {
                if (value >= candidatesMax.front().v) {
                    while (!candidatesMax.empty() && value >= candidatesMax.front().v)
                        candidatesMax.pop_front();
                }
                candidatesMax.push_front({ value,i });
            }
        }

        queueK.push_back({ value,i });
        cout << max.v;
        if (i < n - 1) cout << " ";

    }
    cout << '\n';
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
