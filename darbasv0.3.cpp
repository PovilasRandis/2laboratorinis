#include "Header.h"

int main() {
	int stud = 0;
	vector<Studentas> A;

	if (IvestisYN("skaityti duomenis is tekstinio failo"))
		IvedimasIsFailo(A);
	else
		IvedimasRanka(A);
		Isvedimas(A);
}


