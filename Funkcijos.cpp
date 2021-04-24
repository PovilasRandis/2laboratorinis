#include "Header.hpp"

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

void fromMain(double Laik[], char tip){
    if (tip == 'V'){
        vector<Studentas> A;
        vector<Studentas> Inf;
        vector<Studentas> Sup;
        Startas(A, Inf, Sup, Laik);
    }
    else if (tip == 'L'){
        list<Studentas> A;
        list<Studentas> Inf;
        list<Studentas> Sup;
        Startas(A, Inf, Sup, Laik);
    }
    else {
        deque<Studentas> A;
        deque<Studentas> Inf;
        deque<Studentas> Sup;
        Startas(A, Inf, Sup, Laik);
    }
}

template <typename P>

void Startas(P& A, P& Inf, P& Sup, double Laik[]){
    if (IvestisYN("generuotis duomenu faila"))
        generavimas(Laik);
        
    if (IvestisYN("skaityti duomenis is tekstinio failo")){
        if (IvedimasIsFailo(A, Laik))
            Isvedimas(A, Inf, Sup, Laik);
    }
    else {
        IvedimasRanka(A);
        Isvedimas(A, Inf, Sup, Laik);
    }
}

template <typename P>
//Duomenu ivedimo ir skaitymo funkcija
void IvedimasRanka(P& A){
    bool atsit = IvestisYN("generuoti balus atsitiktinai");
    int nd = 0;
    if (IvestisYN("zinomas namu darbu skaicius"))
        nd = (IvestisND("Namu darbu skaicius: ", false));
    
    do {
        Studentas laikinas;
        cout << A.size() << " studento pavarde: ";
        cin >> A.back().pavarde;
        cout << A.size() << " studento vardas: ";
        cin >> A.back().vardas;
        if (!atsit){
            if (A.front().nd.size() == 0 && nd == 0){
                do {
                    A.back().nd.push_back(IvestisND("Namu darbo ivertinimas"));
                } while (IvestisYN("prideti dar 1 namu darba"));
            }
            else {
                for (int i=0; i<(nd ? nd : A.front().nd.size()); i++)
                    A.back().nd.push_back(IvestisND("Namu darbo ivertinimas"));
            }        
            A.back().egz = IvestisND("Egzamino ivertinimas");
        }
        else {
            if (A.front().nd.size() == 0 && nd == 0){
                do {
                    A.back().nd.push_back(dist(mt));
                } while (IvestisYN("prideti dar 1 namu darba"));
            }
            else {
                for (int i=0; i<(nd? nd : A.front().nd.size()); i++)
                    A.back().nd.push_back(dist(mt));
            }
            A.back().egz = dist(mt);
        }
    } while (IvestisYN("prideti dar 1 studenta"));
}
template <typename P>
//Duomenu skaitymo is failo funkcija
bool IvedimasIsFailo(P& A, double Laik[]){
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
            in >> A.back().vardas >> A.back().pavarde;
            for (int i=0; i<nd; i++){
                in >> sk;
                A.back().nd.push_back(sk);
            }
            in >> A.back().egz;
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

template <typename P>
//Rezultatu isvedimo funkcija
void Isvedimas(P& A, P& Inf, P& Sup, double Laik[]){
    bool skirstymas2 = IvestisYN("skirstyti studentus i 2 atskirus konteinerius");
    if (skirstymas2)
        Rusiavimas(A, Sup, Inf, Laik);
    else
        Rusiavimas2(A, Inf, Laik);

    auto start = system_clock::now();                   

    ofstream outS("RezultataiSup.txt");
    ofstream outI("RezultataiInf.txt");

    outS << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
    outI << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
    outS << "------------------------------------------------------------" << endl;
    outI << "------------------------------------------------------------" << endl;

    for (auto elem : Sup)
        outS <<fixed<<left<<setw(25)<< elem.vardas <<setw(25)<< elem.pavarde << elem.final << endl;
    for (auto elem : Inf)
        outI <<fixed<<left<<setw(25)<< elem.vardas <<setw(25)<< elem.pavarde << elem.final << endl;
    outS.close();
    outI.close();

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[3] = diff.count();

    double laikas = 0;
    cout << endl;
    if (Laik[0] != 0){
        laikas += Laik[0];
        cout << endl << "Duomenu generavimo ir irasymo i faila laikas: " << Laik[0] << " s" << endl;
    }
    if (Laik[1] != 0){
        laikas += Laik[1];
        cout << "Duomenu skaitymo laikas: " << Laik[1] << " s" << endl;
    }
    if (Laik[2] != 0){
        laikas += Laik[2];
        cout << "Studentu rusiavimo laikas: " << Laik[2] << " s" << endl;
    }
    if (Laik[3] != 0){
        laikas += Laik[3];
        cout << "Isvedimo i failus laikas: " << Laik[3] << " s" << endl;
    }
    cout << "Bendras laikas: " << laikas << " s" <<  endl;
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
template <typename P>
//rezultatu rusiavimo funkcija
void Rusiavimas(P& A, P& Sup, P& Inf, double Laik[]){
    auto start = system_clock::now();     

    for (auto elem : A){
        elem.final = round(0.4 * Vidurkis(elem.nd) + 0.6 * elem.egz);
        if (elem.final < 5)
            Inf.push_back(elem);
        else
            Sup.push_back(elem);
    }

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();       
}
bool MaziauUz5(Studentas A){
    return (A.final < 5);
}

template <typename P>
void Rusiavimas2(P& A, P& Inf, double Laik[]){
    auto start = system_clock::now();     

    copy_if(A.begin(), A.end(), back_inserter(Inf), MaziauUz5);
    A.erase(remove_if(A.begin(), A.end(), MaziauUz5), A.end());

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();       
}