// Fabrizio Nicolás Zeballos y Jose Javier Aceituno
// C101


#include <sstream> //para strinstream
#include <iostream>
#include <fstream>
#include <string>
#include "HashMap.h"
#include <list>


//Hay que elegir un diccionario.
//¿Necesitamos que esté ordenado? ¿Que no lo esté?
//  No necesitamos que el diccionario estés ordenado por lo tanto Elegimos un Hashmap
typedef HashMap<string,int> Diccionario;
typedef HashMap<char,list<string>> Resultado;

//Método para leer un diccionario
void leerDiccionario(Diccionario& diccionario){
    string linea;
    getline(cin, linea);
    stringstream lin(linea); //procesar la línea
    string clave;
    int valor;
    while (lin >> clave) {
        lin >> valor;
        diccionario.insert(clave,valor);
    }
}

//Método que hace el problema. Recibe los diccionarios antiguo y nuevo.
//Debe devolver los cambios en alguna/s estructura/s adecuada/s
//Coste O(n+k) ~ O(n) siendo n el número de claves que posee el Diccionario antiguo y k el número de inserciones que se hacen en las listas.
void calcularCambios(const Diccionario& DiccionarioAntiguo,const Diccionario& DiccionarioNuevo, Resultado &Resultados){
    list<string> add,remove,change;
    if(DiccionarioNuevo.empty()){
        for(auto it = DiccionarioAntiguo.cbegin(); it != DiccionarioAntiguo.cend(); it++)
            add.push_back(it.key());

        if(!add.empty()) {
            add.sort();
            Resultados.insert('+', add);
        }
    }
    else
    {
        for (auto it = DiccionarioAntiguo.cbegin(), it2 = DiccionarioNuevo.cbegin();
             it != DiccionarioAntiguo.cend(); it++, it2++) {
            int pso = 0;
            if (!DiccionarioNuevo.contains(it.key())) {

                add.push_back(it2.key());
                remove.push_back(it.key());


            } else {
                if (it.value() != it2.value()) {

                    change.push_back(it.key());

                }
            }
            pso++;
        }
        if(!add.empty()) {
            add.sort();
            Resultados.insert('+', add);
        }
        if(!remove.empty()) {
            remove.sort();
            Resultados.insert('-', remove);
        }
        if(!change.empty()) {
            change.sort();
            Resultados.insert('*', change);
        }
    }



}

//Método para escribir por pantalla los cambios en los diccionarios.

// La impresión por pantalla es menos eficiente ya que tengo que iterar por la lista para imprimir todos los valores de cada clave.
// Si no copiase la lista en la linea 93 podría ser más eficiente pero no tengo mucha idea de como hacerlo y me da error, en la corrección que suba en
// el campus intentaré solucionarlo. He intentado ordenar el órden en el que salen las claves *,+,- pero me da también error.
void printCambios(const Resultado& Res){
    if(Res.empty())
        cout << "Sin cambios" << endl << "---";
    else {
        for(auto it = Res.cbegin(); it != Res.cend(); it++){
            cout << it.key() << " ";
            list<string> co = it.value();
            for (auto it_list = co.begin(); it_list != co.end(); it_list++) {
                cout << *it_list << " ";
            }
            cout << endl;
        }
        /*char claves[3] = {'+','-','*'};
        for (int i = 0; i < 3 ; ++i) {
            auto it = Res.find(claves[i]);
            if(it.key() == '+' || it.key() == '-' || it.key() == '*') {
                cout << it.key() << " ";
                list<string> co = it.value();
                for (auto it_list = co.begin(); it_list != co.end(); it_list++) {
                    cout << *it_list << " ";
                }
            }
            cout << endl;
        }*/
        cout << "---";
    }


    }

//Esqueleto para resuelve caso: leemos los diccionarios, calculamos
//los cambios y los sacamos por pantalla.
void resuelveCaso(){
    Diccionario DiccionarioAntiguo,DiccionarioNuevo;
    Resultado Res;
    leerDiccionario(DiccionarioAntiguo);
    leerDiccionario(DiccionarioNuevo);
    calcularCambios(DiccionarioAntiguo,DiccionarioNuevo,Res);
    printCambios(Res);
    cout << endl;
}

//Método main.
int main(){
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore(1); //ignorar salto de línea
    for (int i = 0; i < numCasos; i++){
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}










































