
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

class Studentas{
    private:
        string vardas, pavarde;
        int final;

    public: 
        void setVardas(string _vardas, string _pavarde){
            vardas = _vardas;
            pavarde = _pavarde;
        }

        void setfinal(int _final){
            final = _final;
        }

        string aVardas(){
            return vardas;
        }

        string aPavarde(){
            return pavarde;
        }

        int afinal(){
            return final;
        }

        bool operator<(Studentas a){
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
void Rusiavimas2(P&, P&, double []);

template <typename P>
void Isvedimas(P&, P&, P&, double []);

template <typename P>
bool IvedimasIsFailo(P&, double []);

void fromMain(double [], char tip);
double Vidurkis(int n, vector<int>&);
bool IvestisYN(string);
int IvestisND(string, bool check0to10 = true);
void generavimas(double []);
bool DaugiauNei4(int);