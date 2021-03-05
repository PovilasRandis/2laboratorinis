#include "Header.hpp"

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

//Duomen? ?vedimo ir skaitymo funkcija
void IvedimasRanka(vector<Studentas>& A) {
	bool atsit = IvestisYN("generuoti balus atsitiktinai");
	int nd = 0;
	if (IvestisYN("zinomas namu darbu skaicius"))
		nd = (IvestisND("Namu darbu skaicius: ", false));

	do {
		A.resize(A.size() + 1);
		cout << A.size() << " studento vardas: ";
		cin >> A[A.size() - 1].vardas;
		cout << A.size() << " studento pavarde: ";
		cin >> A[A.size() - 1].pavarde;
		if (!atsit) {
			if (A[0].nd.size() == 0 && nd == 0) {
				do {
					A[A.size() - 1].nd.push_back(IvestisND("Namu darbo ivertinimas"));
				} while (IvestisYN("prideti dar 1 namu darba"));
			}
			else {
				for (int i = 0; i < (nd ? nd : A[0].nd.size()); i++)
					A[A.size() - 1].nd.push_back(IvestisND("Namu darbo ivertinimas"));
			}
			A[A.size() - 1].egz = IvestisND("Egzamino ivertinimas");
		}
		else {
			if (A[0].nd.size() == 0 && nd == 0) {
				do {
					RandomPridejimas(A[A.size() - 1].nd);
				} while (IvestisYN("prideti dar 1 namu darba"));
			}
			else {
				for (int i = 0; i < (nd ? nd : A[0].nd.size()); i++)
					RandomPridejimas(A[A.size() - 1].nd);
			}
			A[A.size() - 1].egz = dist(mt);
		}

	} while (IvestisYN("prideti dar 1 studenta"));
}
//Duomen? skaitymo i� failo funkcija
bool IvedimasIsFailo(vector<Studentas>& A) {
	int failas;
	cout << "Failas is kurio bus atliktas skaitymas [1-3]: ";
	while (!(cin >> failas) || failas < 1 || failas > 3) {
		cout << "Neteisinga ivestis!" << endl << "Failas is kurio bus atliktas skaitymas [1-3]: ";
		cin.clear();
		cin.ignore(128, '\n');
	}
	string failoPav;
	if (failas == 1)
		failoPav = "Studentai10000.txt";
	else if (failas == 2)
		failoPav = "Studentai100000.txt";
	else
		failoPav = "Studentai1000000.txt";
	ifstream in(failoPav);

	try {
        ifstream in(failoPav);
        in.exceptions(ifstream::failbit | ifstream::badbit);
        int nd = -3;
        string tekst;
        while (tekst != "Egz."){
            in >> tekst;
            nd++;
        }
        int sk;
        while (!in.eof()){
            A.resize(A.size()+1);
            in >> A[A.size()-1].vardas >> A[A.size()-1].pavarde;
            for (int i=0; i<nd; i++){
                in >> sk;
                A[A.size()-1].nd.push_back(sk);
            }
            in >> A[A.size()-1].egz;
        }
        in.close();
    }
    catch (exception ex){
        cout << "Ivyko klaida su failo skaitymu arba failas neegzistuoja!" <<endl;
        return false;
    }
    return true;
}

//Vidurkio skai?iavimo funkcija
double Vidurkis(vector<int>& paz) {
	int sum = 0;
	for (int i = 0; i < paz.size(); i++)
		sum += paz[i];
	return ((double)sum / paz.size())*0.4;
}
//Medianos skai?iavimo funkcija
double Mediana(vector<int>& paz) {
	int n = paz.size();
	sort(paz.begin(), paz.end());
	if (n % 2 != 0)
		return paz[n / 2];
	else
		return ((double)paz[n / 2 - 1] + paz[n / 2]) / 2;
}
//Rezultat? i�vedimo funkcija
void Isvedimas(vector<Studentas> A) {
	ofstream out("Rezultatai.txt");
	char VidMed;
	cout << "Rodyti vidurki ar mediana? [V/M]: ";
	cin >> VidMed;
	sort(A.begin(), A.end());

	while (toupper(VidMed) != 'V' && toupper(VidMed) != 'M') {
		out << "Neteisinga ivestis!" << endl << "Rodyti vidurki ar mediana? [V/M]: ";
		cin >> VidMed;
	}
	if (toupper(VidMed) == 'V') {
		out << "Pavarde        Vardas         Galutinis (Vid.)" << endl;
		out << "----------------------------------------------" << endl;
		for (int i = 0; i < A.size(); i++)
			out << fixed << left << setw(15) << A[i].vardas << setw(15) << A[i].pavarde << setprecision(0) << round(0.4 * Vidurkis(A[i].nd) + 0.6 * A[i].egz) << endl;
	}
	else {
		out << "Pavarde        Vardas         Galutinis (Med.)" << endl;
		out << "----------------------------------------------" << endl;
		for (int i = 0; i < A.size(); i++)
			out << fixed << left << setw(15) << A[i].vardas << setw(15) << A[i].pavarde << setprecision(0) << round(0.4 * Mediana(A[i].nd) + 0.6 * A[i].egz) << endl;
	}
	out.close();
}
//?vedimo teksto tikrinimas
bool IvestisYN(string tekstas) {
	char naujas;
	cout << "Ar " << tekstas << "? [Y/N]: ";
	cin >> naujas;
	while (toupper(naujas) != 'Y' && toupper(naujas) != 'N') {
		cout << "Neteisinga ivestis! [Y/N]: ";
		cin >> naujas;
	}
	if (toupper(naujas) == 'Y')
		return true;
	else
		return false;
}
//?vedimo skai?i? tikrinimas
int IvestisND(string tekstas, bool check0to10) {
	int sk;
	cout << tekstas << (check0to10 ? " [0-10]: " : "");
	while (!(cin >> sk) || (check0to10 ? (sk < 0 || sk > 10) : false)) {
		cout << "Neteisinga ivestis!" << endl << tekstas << (check0to10 ? " [0-10]: " : "");
		cin.clear();
		cin.ignore(128, '\n');
	}
	return sk;
}
//Atsitiktini? skai?i? generavimo funkcija
void RandomPridejimas(vector<int>& nd) {
	nd.push_back(dist(mt));
	cout << nd.back();
}