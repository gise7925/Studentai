#include "head.h"

void Dalykai(vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, vector<Studentas>& stud, int kiekis)
{
    stud.reserve(kiekis + 1);
    stud.resize(kiekis + 1);
    vargsiukai.reserve(kiekis + 1);
    galvociai.reserve(kiekis + 1);
    vargsiukai.resize(kiekis + 1);
    galvociai.resize(kiekis + 1); // rezervuota viena vieta daugiau, kad butu paprasciau skaiciuoti irasus nuo 1

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

    int protKiekis, vargKiekis;
    string failas;

    start = chrono::system_clock::now();
    startEvent = chrono::system_clock::now();
    failas = Generuoti(stud, kiekis); // process
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu sugeneravimas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    Nuskaityti(stud, kiekis, failas);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    Rusiuoti(stud, kiekis);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu rusiavimas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    vargKiekis = 0;
    protKiekis = 0;
    Skirstyti(stud, kiekis, vargKiekis, protKiekis, vargsiukai, galvociai);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu skirstymas i galvociai ir vargsiukai uztruko: " << elapsed_seconds.count() << "s\n";

    string pavadinimasPabir = "vargsiukai" + to_string(kiekis) + ".txt";
    string pavadinimasProt = "galvociai" + to_string(kiekis) + ".txt";

    start = chrono::system_clock::now();
    Isvedimas(vargsiukai, vargKiekis, pavadinimasPabir);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << vargKiekis << " duomenu irasymas i vargsiukai uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    Isvedimas(galvociai, protKiekis, pavadinimasProt);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << protKiekis << " duomenu irasymas i galvociai uztruko: " << elapsed_seconds.count() << "s\n";

    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}
void Skirstyti(vector<Studentas>& stud, int kiekis, int& vargKiekis, int& protKiekis, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai)
{
    for (int i = 1; i <= kiekis; i++) {
        if (stud[i].egz < 5.00) {
            vargsiukai[vargKiekis].vardas = stud[i].vardas;
            vargsiukai[vargKiekis].pavarde = stud[i].pavarde;
            vargsiukai[vargKiekis].egz = stud[i].egz;
             vargKiekis++;
        }
        else {
            galvociai[protKiekis].vardas = stud[i].vardas;
            galvociai[protKiekis].pavarde = stud[i].pavarde;
            galvociai[protKiekis].egz = stud[i].egz;
            protKiekis++;
        }
    }
}
void Rusiuoti(vector<Studentas>& stud, int kiekis)
{
    sort(stud.begin(), stud.end(), Maziau);
}
void Nuskaityti(vector<Studentas>& stud, int kiekis, string failas)
{
    ifstream autoIn(failas);
    stud = {};                                                          //  struktura prilyginama nuliui
    stud.reserve(kiekis + 1);
    stud.resize(kiekis + 1);

    for (int i = 1; i <= kiekis; i++) {
        autoIn >> stud[i].pavarde >> stud[i].vardas >> stud[i].egz;
    }
}
string Generuoti(vector<Studentas>& stud, int kiekis)
{
    stud = {}; // nunullinam struktura
    stud.reserve(kiekis + 1);
    stud.resize(kiekis + 1);
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> balai(1.0, 10.0);
    double egzas;
    string outFileName = "kursiokai" + to_string(kiekis) + ".txt";
    ofstream autoOut(outFileName);
    for (int i = 1; i <= kiekis; i++) {
        stud[i].vardas = "Vardas" + to_string(i);
        stud[i].pavarde = "Pavarde" + to_string(i);
        egzas = balai(mt);
        stud[i].egz = egzas;
        autoOut << left << setw(20) << stud[i].pavarde << setw(20) << stud[i].vardas << setw(20) << setprecision(3) << stud[i].egz << endl;
    }
    return outFileName;
}
bool CompareByLength(const Studentas& a, const Studentas& b)
{
    return a.vardas < b.pavarde;
}
bool Maziau(const Studentas& a, const Studentas& b)
{
    return a.egz < b.egz;
}
void Isvedimas(vector<Studentas> vektorius, int kiekis, string failoPav = "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    ofstream offile(failoPav);
    offile << "Pavarde             Vardas              Galutinis (egz.)\n";
    offile << "--------------------------------------------------------\n";
    for (int i = 0; i < kiekis; i++) {
        offile << left << setw(20) << vektorius[i].pavarde << setw(20) << vektorius[i].vardas << setw(20) << setprecision(3) << vektorius[i].egz << endl;
    }

}
void Isvedimas(vector<Studentas>& stud)
{
    ofstream offile("rezultatai.txt");
    offile << "Pavarde             Vardas              Galutinis (vid.)    Galutinis (med.)    \n";
    offile << "--------------------------------------------------------------------------------\n";
    for (int i = 0; i < stud.size(); i++) {
        offile << left << setw(20) << stud[i].pavarde << setw(20) << stud[i].vardas << setw(20) << setprecision(3) << stud[i].galVid << setw(20) << setprecision(2) << stud[i].galMed << endl;
    }

    //cout << left << setw(20) << pavarde << setw(20) << vardas << setw(20) << setprecision(3) << vid << setw(20) << setprecision(2) << med << endl; 
}
double Vidurkis(vector<double>& nd, double egz)
{
    double vidurkis = 0;
    int dydis = nd.size();
    for (int i = 0; i < dydis; i++) {
        vidurkis += nd[i];
    }

    return vidurkis = 0.4 * (vidurkis / dydis) + 0.6 * egz;
}
double Mediana(vector<double>& nd)
{
    int dydis = nd.size();
    // susortina masyva
    sort(nd.begin(), nd.end());
    // suranda mediana
    if (dydis % 2 == 0)
    {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2;
    }
    else
    {
        return nd[dydis / 2];
    }
}
void DigitCheck(string& stringas, bool check)
{
    while (!check) {
        if (std::any_of(stringas.begin(), stringas.end(), isdigit)) {
            cout << "\nVardas ir pavarde negali tureti skaiciu! Prasome ivesti is naujo: ";
                cin >> stringas;
        }
        else {
            check = true;
        }
    }
}
void SymbolCheck(double& skaicius, bool ok, bool balas)
{
    ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) SymbolCheck(skaicius, ok, balas);
        if (balas) {
            if (skaicius >= 0.0 && skaicius <= 10.0)
            {
                ok = true;
            }
            else {
                cout << "\nBalas turi buti desimtbaleje sistemoje. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
        }
        else {
            if (skaicius < 0.0) {
                cout << "\nNamu darbu kiekis turi buti neneigiamas skaicius. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
            else ok = true;
        }
    }
}
void SymbolCheck(int& skaicius, bool ok, bool balas)
{
    ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) SymbolCheck(skaicius, ok, balas);
        if (balas) {
            if (skaicius >= 0.0 && skaicius <= 10.0)
            {
                ok = true;
            }
            else {
                cout << "\nBalas turi buti intervale [1-10]. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
        }
        else {
            if (skaicius < 0.0) {
                cout << "\nNamu darbu kiekis turi buti neneigiamas skaicius. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
            else ok = true;
        }
    }
}
double VectorSymbolCheck() 
{
    double skaicius;
    bool ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nBloga ivestis. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) VectorSymbolCheck();
        if (skaicius >= 0.0 && skaicius <= 10.0)
        {
            ok = true;
        }
        else {
            cout << "\nBalas turi buti nuo 1-10. Bandykite dar karta: ";
            cin >> skaicius;
        }
    }

    return skaicius;
}
void BoolCheck(bool& check)
{
    int ivestis;
    bool ok = false;
    while (!ok) {
        cin >> ivestis;
        if (cin.fail()) {
            cout << "\nIveskite 0 arba 1: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        else {
            if (ivestis == 0) {
                check = false;
                ok = true;
            }
            else if (ivestis == 1) {
                check = true;
                ok = true;
            }
            else cout << "\nIveskite 0 arba 1: ";
        }

    }
}