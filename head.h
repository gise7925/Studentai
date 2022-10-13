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
//void isvedimas(string &vardas, string &pavarde, double &vid, double &med);
void Isvedimas(vector<Studentas>& stud);
void Isvedimas(vector<Studentas>& stud, int kiekis);
//void failoNuskaitymas(vector<Studentas>& eilinis, string &ndCheck, int& ndCount, int& stKiekis);
bool CompareByLength(const Studentas& a, const Studentas& b);
string Generuoti(vector<Studentas>& stud, int kiekis);
void Nuskaityti(vector<Studentas>& stud, int kiekis, string failas);
void Rusiuoti(vector<Studentas>& stud, int kiekis);
bool Maziau(const Studentas& a, const Studentas& b);
void Skirstyti(vector<Studentas>& stud, int kiekis, int& vargKiekis, int& protKiekis, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai);
void Isvedimas(vector<Studentas> vektorius, int kiekis, string failoPav);
void Dalykai(vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, vector<Studentas>& stud, int kiekis);
