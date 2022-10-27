#pragma once
#include <iostream>
#include <algorithm>    // std::any_of
#include <iomanip>      // std::setprecision
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <iterator>
#include <chrono>

#include <list>

using namespace std;

struct Studentas {

    string vardas, pavarde;
    int n = 0;
    vector<double> ND;
    double egz = 0, galVid = 0, galMed = 0;
};

void DigitCheck(string& stringas, bool check);
void SymbolCheck(double& skaicius, bool check, bool balas);
void SymbolCheck(int& skaicius, bool check, bool balas);
void BoolCheck(bool& arMediana);
double VectorSymbolCheck();
double Mediana(vector<double>& nd);
double Vidurkis(vector<double>& nd, double egz);
void Isvedimas(vector<Studentas>& stud);
void Isvedimas(vector<Studentas>& stud, int kiekis);
bool CompareByLength(const Studentas& a, const Studentas& b);
string Generuoti(vector<Studentas>& stud, int kiekis);
void Nuskaityti(vector<Studentas>& stud, int kiekis, string failas);
void Rusiuoti(vector<Studentas>& stud, int kiekis);
bool Maziau(const Studentas& a, const Studentas& b);
void Skirstyti(vector<Studentas>& stud, int kiekis, int& vargKiekis, int& protKiekis, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai);
void Isvedimas(vector<Studentas> vektorius, int kiekis, string failoPav);
void Dalykai(vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, vector<Studentas>& stud, int kiekis);
void ContainerTesting_vector(vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, vector<Studentas>& stud, int kiekis);
void ContainerTesting_list(list<Studentas>& vargsiukai, list<Studentas>& galvociai, list<Studentas>& stud, int kiekis);
string Generuoti_list(list<Studentas> stud, int kiekis);
void Nuskaityti_list(list<Studentas>& stud, int kiekis, string failas);
void Isvedimas_list(list<Studentas>& listas, int kiekis, string failoPav);
void Rusiuoti_list(list<Studentas>& stud, int kiekis);
void Skirstyti_list(list<Studentas>& stud, list<Studentas>& vargsiukai, list<Studentas>&galvociai);
bool Compare_5(const Studentas& v);