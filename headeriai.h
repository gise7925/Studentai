#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setfill;
using std::left;
using std::setprecision;
using std::vector;
using std::ifstream;
using std::istringstream;

//atsitiktiniams skaiciams
using std::mt19937;
using Laikas = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> intDistribution;

struct Studentas;

//funkcijos
void NeteisingasIvedimas();
bool ArVienSkaiciai(const string s);
bool ArEgzistuoja(string DuomFailas);
string AtsakymoIvedimas();
int IvedimasIntervale(int pradzia, int pabaiga, bool Breakinimui);
double RaskVidurki(vector<int> pazymiai, int pazymiuSk);
double RaskMediana(vector<int> pazymiai, int pazymiuSk);
double GalutinisBalas(double ndRez, int egzaminas);
int GeneruokAtsitiktiniSkaiciu(int pradzia, int pabaiga);
void NuskaitykDuomenis(string DuomFailas, vector <Studentas>& studentai, bool& ArReikiaIvesti);
bool PagalVardus(Studentas s1, Studentas s2);
void DuomenuIsvedimasFaile(vector <Studentas>studentai);
void IprastinisDuomIsvedimas(vector <Studentas>studentai);
