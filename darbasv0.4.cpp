#include "Header.hpp"

int main() {
	int stud = 0;
	vector<Studentas> A;
	double Laik[4]{};

    if (IvestisYN("generuotis duomenu faila"))
        generavimas(Laik);
        
    if (IvestisYN("skaityti duomenis is tekstinio failo")){
        if (IvedimasIsFailo(A, Laik))
            Isvedimas(A, Laik);
    }
    else {
        IvedimasRanka(A);
        Isvedimas(A, Laik);
    }
	
}


