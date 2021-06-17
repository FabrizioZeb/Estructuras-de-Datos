
#ifndef SETOFINTS3_H_
#define SETOFINTS3_H_

#include "Error.h"

template <class T>
class SetOfInts3 {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
	private:
		static const int MAXSIZE = 100;

		int elems[MAXSIZE];
		int size;

		bool isFull() const;
		void binSearch(int x,bool& found,int& pos) const;
		int binSearchAux(int x, int a, int b) const;
		void shiftRightFrom(int i);
		void shiftLeftFrom(int i);

	public:
		SetOfInts3();
		int getSize() const;
		bool isEmpty() const;
		void add(T x); //throws Error
		bool contains(T x) const;
		void remove(T x);
		void join(const SetOfInts3& set);
		void intersect(const SetOfInts3& set);
		T getMax(int &pos);
		T getMin(int &pos);
		void removeMin(int &pos);
		void removeMax(int &pos);
        void write(ostream& sOut);

/*        template<class U>
		friend istream& operator>>(istream& sIn,SetOfInts3<T>& set);
        template<class U>
		friend ostream& operator<<(ostream& sOut,SetOfInts3<T>& set);*/
};
template <class T>
SetOfInts3<T>::SetOfInts3() {
    size = 0;
}


// Public methods

template<class T>
void SetOfInts3<T>::write(ostream& sOut){
    for (int i = 0; i < size-1; i++)
        sOut << elems[i] << " ";
    if (size > 0) sOut << elems[size-1];
}


template <class T>
int SetOfInts3<T>::getSize() const {
    return size;
}
template <class T>
bool SetOfInts3<T>::isEmpty() const{
    return (size == 0);
}
template <class T>
void SetOfInts3<T>::add(T x){ //throws Error
    bool found;
    int pos;

    binSearch(x,found,pos);
    if (!found){
        if (isFull())
            throw Error("Cannot add: The set is full");
        else {
            shiftRightFrom(pos+1);
            elems[pos+1] = x;
            size++;
        }
    }
}
template <class T>
void SetOfInts3<T>::remove(T x){
    bool found;
    int pos;

    binSearch(x,found,pos);
    if (found) {
        shiftLeftFrom(pos);
        size--;
    }
}
template <class T>
bool SetOfInts3<T>::contains(T x) const {
    bool found;
    int pos;

    binSearch(x,found,pos);
    return found;
}

template <class T>
void SetOfInts3<T>::join(const SetOfInts3& set) {
    throw Error("Join operation not supported");
}

template <class T>
void SetOfInts3<T>::intersect(const SetOfInts3& set) {
    throw Error("Intersection operation not supported");
}

//Complejidad de O(size)
template <class T>
T SetOfInts3<T>::getMax(int & pos) {
    T max = elems[0];
    pos = 0;
    for(int i = 1; i < size; i++){
        if(elems[i] > max){
            max = elems[i];
            pos = i;
        }
    }
    return max;
}
//Complejidad de O(size)
template <class T>
T SetOfInts3<T>::getMin(int & pos) {
    T min = elems[0];
    pos = 0;
    for(int i = 1; i < size; i++){
        if(elems[i] < min){
            min = elems[i];
            pos = i;
        }
    }
    return min;
}
//Complejidad O(size)
template <class T>
void SetOfInts3<T>::removeMax(int &pos) {
    shiftLeftFrom(pos);
    size--;
}
//Complejidad O(size)
template <class T>
void SetOfInts3<T>::removeMin(int &pos) {
    shiftLeftFrom(pos);
    size--;
}

/*
template <class U>
istream& operator>>(istream& sIn, SetOfInts3<U>& set) {
    int n;
    int d;
    sIn >> n;
    set.size = 0;
    if (sIn.fail()) return sIn;
    for (int i = 0; i < n; i++){
        sIn >> d;
        set.add(d);
    }
    return sIn;
}

template <class U>
ostream& operator<<(ostream& sOut, SetOfInts3<U>& set) {
    sOut << "";
    for (int i = 0; i < set.size-1; i++)
        sOut << set.elems[i] << " ";
    if (set.size > 0) sOut << set.elems[set.size-1];
    sOut << "";
    return sOut;
}
*/


// Private methods
template <class T>
bool SetOfInts3<T>::isFull() const {
    return size == MAXSIZE;
}

template <class T>
int SetOfInts3<T>::binSearchAux(int x, int a, int b) const {
    // Pre: elems está ordenado entre 0 .. size-1
    //      ( 0 <= a <= size ) && ( -1 <= b <= size ) && ( a <= b+1 )
    //      todos los elementos a la izquierda de 'a' son <= x
    //      todos los elementos a la derecha de 'b' son > x

    int p, m;

    if (a == b + 1)
        p = a - 1;
    else if (a <= b) {
        m = (a + b) / 2;
        if (elems[m] <= x)
            p = binSearchAux(x,m + 1,b);
        else
            p = binSearchAux(x,a,m - 1);
    }
    return p;
    // Post: devuelve el mayor índice i (0 <= i <= size-1) que cumple
    //       elems[i] <= x
    //       si x es menor que todos los elementos de elems, devuelve -1
}

template <class T>
void SetOfInts3<T>::binSearch(int x, bool& found, int& pos) const {
    // Pre: los size primeros elementos de elems están ordenados
    //      size >= 0

    pos = binSearchAux(x, 0, size-1);
    found = (pos >= 0) && (pos < size) && (elems[pos] == x);

    // Post : devuelve el mayor índice i (0 <= i <= size-1) que cumple
    //        elems[i] <= x
    //        si x es menor que todos los elementos de elems, devuelve -1
    //        found es true si x esta en elems[0..size-1]
}

template <class T>
void SetOfInts3<T>::shiftRightFrom(int i){
    for (int j = size; j > i; j--)
        elems[j] = elems[j-1];
}

template <class T>
void SetOfInts3<T>::shiftLeftFrom(int i){
    for (; i < size-1; i++)
        elems[i] = elems[i+1];
}


#endif /* SETOFINTS3_H_ */
