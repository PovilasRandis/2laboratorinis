#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <random>

using namespace std;

struct Studentas {
	string vardas, pavarde;
	vector <int> nd;
	int egz;
	double gal;
};

void Ivedimas(int& stud, int& n, Studentas A[]);
double Vidurkis(int n, vector <int> paz, int egza);
double Mediana(int n, vector <int> paz, int egza);
void Isvedimas(int a, int n, Studentas A[]);
void IvestisYN(char& naujas, string tip);

void IvestisND(int a, int n, Studentas A[]);
void IvestisEgzaminas(int a, Studentas A[]);
int AtsitiktinisSkaicius(int min, int maxi);

int main() {
	int a = 0;
	int n = 0;
	Studentas A[100];

	Ivedimas(a, n, A);
	Isvedimas(a, n, A);
}

void Ivedimas(int& a, int& n, Studentas A[]) {
	char naujasStud = 'Y';
	char naujasND = 'Y';

	while (toupper(naujasStud) == 'Y') {
		cout << a + 1 << " studento pavarde: ";
		cin >> A[a].pavarde;
		cout << a + 1 << " studento vardas: ";
		cin >> A[a].vardas;
		if (n == 0) {
			IvestisND(a, n, A);
			n++;
			IvestisYN(naujasND, "namu darba");
			while (toupper(naujasND) == 'Y') {
				IvestisND(a, n, A);
				n++;
				IvestisYN(naujasND, "namu darba");
			}
		}
		else {
			for (int i = 0; i < n; i++)
				IvestisND(a, i, A);
		}
		a++;
		IvestisEgzaminas(a, A);
		IvestisYN(naujasStud, "studenta");
	}
}

double Vidurkis(int n, vector <int> paz, int egza) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += paz[i];
	return ((double)sum / n)*0.4 + 0.6*egza;
}

double Mediana(int n, vector <int> paz, int egza) {
	if (n % 2 != 0)
		return (paz[n / 2])*0.4 + 0.6*egza;
	else
		return (((double)paz[n / 2 - 1] + paz[n / 2]) / 2)*0.4 + 0.6*egza;
}

void Isvedimas(int a, int n, Studentas A[]) {
	//ofstream out("ats.txt");

	char VidMed;
	cout << "Rodyti vidurki ar mediana? [V/M]: ";
	cin >> VidMed;

	while (toupper(VidMed) != 'V' && toupper(VidMed) != 'M') {
		cout << "Kazka neteisingai ivedete!" << endl << "Rodyti vidurki ar mediana? [V/M]: ";
		cin >> VidMed;
	}

	if (VidMed == 'V') {
		cout << "Pavarde     Vardas      Galutinis (Vid.)" << endl;
		cout << "---------------------------------------" << endl;
		for (int i = 0; i < a; i++)
			cout << fixed << left << setw(12) << A[i].pavarde << setw(12) << A[i].vardas << setprecision(2) << Vidurkis(n, A[i].nd, A[a].egz) << endl;
	}
	else {
		cout << "Pavarde     Vardas      Galutinis (Med.)" << endl;
		cout << "---------------------------------------" << endl;
		for (int i = 0; i < a; i++)
			cout << fixed << left << setw(12) << A[i].pavarde << setw(12) << A[i].vardas << setprecision(2) << Mediana(n, A[i].nd, A[a].egz) << endl;
	}
}

void IvestisYN(char& naujas, string tip) {
	cout << "Ar prideti dar 1 " << tip << "? [Y/N]: ";
	cin >> naujas;
	while (toupper(naujas) != 'Y' && toupper(naujas) != 'N') {
		cout << "Kazka neteisingai ivedete!" << endl << "Ar prideti dar 1 " << tip << "? [Y/N]: ";
		cin >> naujas;
	}
}


void IvestisND(int a, int n, Studentas A[]) {
	string laik;
	string i = "y";
	cout << a + 1 << " studento " << n + 1 << " namu darbo ivertinimas [0-10], (Jei norite gauti atsitiktini skaiciu, iveskite y): ";
	cin >> laik;
	if (laik == i)
	{
		laik = AtsitiktinisSkaicius(1, 9)+49;
	}
	else
	{
		while (laik.length() != 1 || (laik.length() == 1 && (laik[0] - '0' < 0 || laik[0] - '0' > 10))) {
			cout << "Kazka neteisingai ivedete!" << endl << a + 1 << " studento " << n + 1 << " namu darbo ivertinimas [0-10], (Jei norite gauti atsitiktini skaiciu, iveskite y): ";
			cin >> laik;
		}
	}

	A[a].nd.push_back(laik[0] - '0');
}

void IvestisEgzaminas(int a, Studentas A[])
{
	string laiki;
	string i = "y";
	cout << a << " studento egzamino rezultatas [0-10], (Jei norite gauti atsitiktini skaiciu, iveskite y): ";
	cin >> laiki;
	if (laiki == i)
	{
		laiki = AtsitiktinisSkaicius(1, 9)+49;
	}
	else
	{
		while (laiki.length() != 1 || (laiki.length() == 1 && (laiki[0] - '0' < 0 || laiki[0] - '0' > 10))) {
			cout << "Kazka neteisingai ivedete!" << endl << a + 1 << " studento egzamino rezultatas [0-10], (Jei norite gauti atsitiktini skaiciu, iveskite y): ";
			cin >> laiki;
		}
	}
	A[a].egz = laiki[0] - '0';
}
int AtsitiktinisSkaicius(int min, int maxi)
{
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((maxi + 1) - min);
}




