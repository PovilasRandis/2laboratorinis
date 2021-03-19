#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>

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

void IvedimasRanka(vector<Studentas>& A);	//Duomen? ?vedimo ir skaitymo funkcija
bool IvedimasIsFailo(vector<Studentas>& A, double Laik[]);	//Duomen? skaitymo i� failo funkcija
double Vidurkis(vector<int>& paz);			//Vidurkio skai?iavimo funkcija
double Mediana(vector<int>& paz);			//Medianos skai?iavimo funkcija
void Isvedimas(vector<Studentas>& A, double Laik[]); //rezultatu isvedimo funkcija
bool IvestisYN(string tip);					//Teksto tikrinimo funkcija
int IvestisND(string tekstas, bool check0to10 = true);	//Skai?i? tikrinimo funkcija
void RandomPridejimas(vector<int>& nd);		//Atsitiktini? skai?i? generavimo funkcija
void generavimas(double Laik[]);			// failo generavimo funkcija
void Rusiavimas(vector<Studentas>& A, vector<Studentas>& Sup, vector<Studentas>& Inf, char VidMed, double Laik[]); //rezultatu rusiavimo funkcija