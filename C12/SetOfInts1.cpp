
#include <iostream>
using namespace std;

#include "Error.h"
#include "SetOfInts1.h"


// Constructors

SetOfInts1::SetOfInts1() {
	size = 0;
}


// Public methods

bool SetOfInts1::isEmpty() const {
	return (size == 0);
}

void SetOfInts1::add(int x){ //throws Error
	if (isFull()) throw Error("Cannot add: The set is full");
	else {
		elems[size] = x;
		size++;
	}
}

void SetOfInts1::remove(int x){
	bool found;
	int pos;
	linSearch(x,0,size,found,pos);
	while (found){
		size--;
		elems[pos] = elems[size];
    }
		linSearch(x,pos,size,found,pos);
	}

bool SetOfInts1::contains(int x) const {
	bool found;
	int pos;

	linSearch(x,0,size,found,pos);
	return found;
}

void SetOfInts1::join(const SetOfInts1& set) {
	throw Error("Join operation not supported");
}

void SetOfInts1::intersect(const SetOfInts1& set) {
	throw Error("Intersection operation not supported");
}


istream& operator>>(istream& sIn, SetOfInts1& set) {
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

ostream& operator<<(ostream& sOut, SetOfInts1& set) {
	sOut << "{";
	for (int i = 0; i < set.size-1; i++)
		sOut << set.elems[i] << ",";
	if (set.size > 0) sOut << set.elems[set.size-1];
	sOut << "}";
	return sOut;
}


// Private methods

bool SetOfInts1::isFull() const {
	return size == MAXSIZE;
}

void SetOfInts1::linSearch(int x, int left, int right, bool& found, int& pos) const {
// P: elems tiene al menos right elementos

	int i;

	if (left >= right) {
		found = false;
		pos = right;
	} else {
		found = false;
		i = left;
		while (!found && (i < right)) {
			found = elems[i] == x;
			if (!found)
				i++;
		}
		pos = i;
	}
	// Q :  found es true si existe un i en el intervalo left..right-1
	//        tal que elems[i] == x
	//      si found es true entonces pos = el minimo i en
	//        el intervalo left..right-1 tal que elems[i] == x
	//      si no found entonces pos == right
}
