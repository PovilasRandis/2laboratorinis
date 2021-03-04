#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

//Duomen? strukt?ra
struct Studentas {
	string vardas, pavarde;
	vector<int> nd;
	double egz;

	bool operator<(Studentas a) {
		return vardas < a.vardas;
	}
};

void IvedimasRanka(vector<Studentas>& A);	//Duomen? ?vedimo ir skaitymo funkcija
void IvedimasIsFailo(vector<Studentas>& A);	//Duomen? skaitymo i� failo funkcija
double Vidurkis(vector<int>& paz);			//Vidurkio skai?iavimo funkcija
double Mediana(vector<int>& paz);			//Medianos skai?iavimo funkcija
void Isvedimas(vector<Studentas> A);		//Duomen? i�vedimo funkcija
bool IvestisYN(string tip);					//Teksto tikrinimo funkcija
int IvestisND(string tekstas, bool check0to10 = true);	//Skai?i? tikrinimo funkcija
void RandomPridejimas(vector<int>& nd);		//Atsitiktini? skai?i? generavimo funkcija