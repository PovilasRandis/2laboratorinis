#include "Header.hpp"

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

//Duomenu ivedimo ir skaitymo funkcija
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
//Duomenu skaitymo is failo funkcija
bool IvedimasIsFailo(vector<Studentas>& A, double Laik[]){

    int failas;
    cout << "Failo skaicius, is kurio bus atliktas skaitymas [Studentai ... .txt]: ";
    while (!(cin >> failas) || failas < 1){
        cout << "Neteisinga ivestis!" << endl;
        cin.clear();
		cin.ignore(128, '\n');
    }

    auto start = system_clock::now();

    try {
        ifstream in("Studentai" + to_string(failas) + ".txt");
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
        cout << "Ivyko klaida su failo skaitymu arba failas neegzistuoja!" << endl;
        return false;
    }

    auto end  = system_clock::now();
    duration<double> diff = end - start;
    Laik[1] = diff.count();

    return true;
}

//Vidurkio skaiciavimo funkcija
double Vidurkis(vector<int>& paz) {
	int sum = 0;
	for (int i = 0; i < paz.size(); i++)
		sum += paz[i];
	return ((double)sum / paz.size())*0.4;
}
//Medianos skaiciavimo funkcija
double Mediana(vector<int>& paz) {
	int n = paz.size();
	sort(paz.begin(), paz.end());
	if (n % 2 != 0)
		return paz[n / 2];
	else
		return ((double)paz[n / 2 - 1] + paz[n / 2]) / 2;
}
//Rezultatu isvedimo funkcija
void Isvedimas(vector<Studentas>& A, double Laik[]){
    char VidMed;
    cout << "Rodyti vidurki ar mediana? [V/M]: ";
    cin >> VidMed;
    while (toupper(VidMed) != 'V' && toupper(VidMed) != 'M'){
        cout << "Neteisinga ivestis!" << endl << "Rodyti vidurki ar mediana? [V/M]: ";
        cin >> VidMed;
    }

    sort(A.begin(), A.end());
    vector<Studentas> Sup;
    vector<Studentas> Inf;

    auto start = system_clock::now();               
    Rusiavimas(A, Sup, Inf, VidMed, Laik);
    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();

    start = system_clock::now();                   

    ofstream outS("RezultataiSup.txt");		//rezultatu failu atidarymas
    ofstream outI("RezultataiInf.txt");
    if (toupper(VidMed) == 'V'){
        outS << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
        outI << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
    }
    else {
        outS << "Pavarde                  Vardas             Galutinis (Med.)" << endl;
        outI << "Pavarde                  Vardas             Galutinis (Med.)" << endl;
    }
    outS << "------------------------------------------------------------" << endl;
    outI << "------------------------------------------------------------" << endl;
    for (int i=0; i<Sup.size(); i++)
        outS <<fixed<<left<<setw(25)<< Sup[i].vardas <<setw(25)<< Sup[i].pavarde << Sup[i].final << endl;

    for (int i=0; i<Inf.size(); i++)
        outI <<fixed<<left<<setw(25)<< Inf[i].vardas <<setw(25)<< Inf[i].pavarde << Inf[i].final << endl;
    outS.close();		//rezultatu failu uzdarymas
    outI.close();

    end = system_clock::now();
    diff = end - start;
    Laik[3] = diff.count();
	//laiko matavimu rezultatu isvedimas
    if (Laik[0] != 0)
        cout << endl << "Duomenu generavimo ir irasymo i faila laikas: " << Laik[0] << " s" << endl;
    if (Laik[1] != 0)
        cout << "Duomenu skaitymo laikas: " << Laik[1] << " s" << endl;
    cout << "Studentu rusiavimo laikas: " << Laik[2] << " s" << endl;
    cout << "Isvedimo i failus laikas: " << Laik[3] << " s" << endl;
}
//ivedimo teksto tikrinimas
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
//ivedimo skaiciu tikrinimas
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
//Atsitiktiniu skaiciu generavimo funkcija
void RandomPridejimas(vector<int>& nd) {
	nd.push_back(dist(mt));
	cout << nd.back();
}
//failo generavimo funkcija
void generavimas(double Laik[]) 
{
	int stud, nd;
    stud = IvestisND("Studentu skaicius: ", false);
    nd = IvestisND("Namu darbu skaicius: ", false);

    auto start = system_clock::now();

    ofstream out("Studentai" + to_string(stud) + ".txt");
    out <<fixed<<setw(25)<<left<< "Vardas" <<setw(25)<< "Pavarde";
    for (int i=1; i<=nd; i++)
        out <<fixed<<setw(10)<<left<< "ND" + to_string(i);
    out << "Egz." << endl;

    for (int i=1; i<stud; i++){
        out <<fixed<<setw(25)<<left<< "Vardas" + to_string(i) <<setw(25)<< "Pavarde" + to_string(i);
        for (int i=0; i<nd; i++)
            out <<fixed<<setw(10)<<left<< dist(mt);
        out << dist(mt) << endl;
    }
    out <<fixed<<setw(25)<<left<< "Vardas" + to_string(stud) <<setw(25)<< "Pavarde" + to_string(stud);
    for (int i=0; i<nd; i++)
        out <<fixed<<setw(10)<<left<< dist(mt);
    out << dist(mt);
    out.close();

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[0] = diff.count();

    if (!IvestisYN("toliau testi programa"))
        exit(1);
}
//rezultatu rusiavimo funkcija
void Rusiavimas(vector<Studentas>& A, vector<Studentas>& Sup, vector<Studentas>& Inf, char VidMed, double Laik[]){       
    double (*func)(vector<int>&){&Vidurkis};
    if (toupper(VidMed) == 'M')
        func = &Mediana;

    for (int i=0; i<A.size(); i++){
        A[i].final = round(0.4 * func(A[i].nd) + 0.6 * A[i].egz);
        if (A[i].final < 5)
            Inf.push_back(A[i]);
        else
            Sup.push_back(A[i]);
    }
}
