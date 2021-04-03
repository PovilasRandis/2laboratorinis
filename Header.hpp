
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include <deque>
#include <list>

using namespace std;
using namespace chrono;

//Duomenu struktura
struct Studentas {
	string vardas, pavarde;
	vector<int> nd;
	double egz;
	int final;

	bool operator<(Studentas a) {
		return vardas < a.vardas;
	}
};

template <typename P>
void Startas(P&, P&, P&, double []);

template <typename P>
void IvedimasRanka(P&);

template <typename P>
void Rusiavimas(P&, P&, P& , double []);

template <typename P>
void Isvedimas(P&, P&, P&, double []);

template <typename P>
bool IvedimasIsFailo(P&, double []);

void fromMain(double [], char tip);
double Vidurkis(int n, vector<int>&);
bool IvestisYN(string);
int IvestisND(string, bool check0to10 = true);
void generavimas(double []);