#pragma
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <vector>
#include <sstream>
#include <random>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct studentas
{
    string vard;
    string pavard;
    vector <int> nd;
    int egz;
    float gal;
    float galmed;
};

void Exists_test(const string& name);
void Skaicius(int& a);
void Ivestisranka(vector <studentas>& stud);
int Kiekpazymiu();
void Ivestis(vector <studentas>& stud);
bool Palyginimas(studentas& a, studentas& b);
void Isvestis(vector <studentas> stud);
void Failugeneracija(int kieknd);
void Failgen(int kieknd, int kiekstud);

void Greicioanalizevector(int kiekstud);
void Rusiavimasvector(vector <studentas>& stud, vector <studentas>& vargsiukai, vector <studentas>& galvociai);

void Greicioanalizelist(int kiekstud);
void Rusiavimaslist(list <studentas>& stud, list <studentas>& vargsiukai, list <studentas>& galvociai);
void Vargsiukaiifaila(int kieknd, vector <studentas> vargsiukai, int kiekstud);
void Galvociaiifaila(int kieknd, vector <studentas> galvociai, int kiekstud);

//antra strategija

void Greicioanalizevector2(int kiekstud);
void Rusiavimasvector2(vector <studentas>& stud, vector <studentas>& nend);
void Vargsiukaiifaila2(int kieknd, vector <studentas> vargsiukai, int kiekstud);
void Galvociaiifaila2(int kieknd, vector <studentas> stud, int kiekstud);

void Greicioanalizelist2(int kiekstud);
void Rusiavimaslist2(list <studentas>& stud, list <studentas>& vargsiukai);
void Vargsiukaiifailalist2(int kieknd, list <studentas> nend, int kiekstud);
void Galvociaiifailalist2(int kieknd, list <studentas> stud, int kiekstud);

