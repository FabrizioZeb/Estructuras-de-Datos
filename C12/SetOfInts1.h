
#ifndef SETOFINTS1_H_
#define SETOFINTS1_H_

#include "Error.h"

class SetOfInts1 {
	// Conjuntos de enteros representados como vectores no ordenados y con repeticiones
	private:
		static const int MAXSIZE = 150;

		int elems[MAXSIZE];
		int size;

		bool isFull() const;
		void linSearch(int x, int left, int right, bool& found, int& pos) const;

	public:
		SetOfInts1();
		bool isEmpty() const;
		void add(int x); //throws Error
		bool contains(int x) const;
		void remove(int x);
		void join(const SetOfInts1& set);
		void intersect(const SetOfInts1& set);
		friend istream& operator>>(istream& sIn,SetOfInts1& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts1& set);
};

#endif /* SETOFINTS1_H_ */
