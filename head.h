

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <vector>
#include <sstream>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::vector;
using std::to_string;


struct data {
    std::string vardas, pavarde;
    double galutinis = 0;
    std::vector<int> paz;
    int egz = 0;
};

bool IsNumber(std::string);
bool isNumber(std::string);
int InputNumber(std::string);
void ReadFromFile(std::vector<data>&);
bool InputBool(std::string);
double Vidurkis(std::vector<int>);
double Mediana(std::vector<int>);
void Input(data&);
void GalutinisResult(std::vector<data>&, bool);
std::string Output(data&);
bool RusiuokPagalVarda(data, data);
bool RusiuokPagalPavarde(data, data);
