#include "mylib.hpp"

struct duomenys {
    string Vard, Pav;
    int paz[10] = { 0 };
    int egz;
    float Galutinis = 0;
};

void Mediana(int pazymiai[]) 
{
    int sk = 0; 
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] > 0)
        {
            sk++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            sk--;
            break;
        }
    }
    if (sk % 2 == 0) 
    {
        cout << float(((pazymiai[sk/ 2 - 1]) + (pazymiai[(sk / 2)])) / 2.0);
    }
    else
    {
        cout << pazymiai[(sk / 2)];
    }
    cout <<endl;
}

int generuojami_pazymiai() 
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

void automatiskai_ivedami_pazymiai(duomenys Eil[], int i, int viso_pazymiu) 
{
    Eil[i].egz = generuojami_pazymiai();
    for (int x = 0; x < viso_pazymiu; x++)
    {
        Eil[i].paz[x] = generuojami_pazymiai();
    }
    Eil[i].Galutinis = Eil[i].Galutinis / viso_pazymiu;
    Eil[i].Galutinis = Eil[i].Galutinis * 0.4 + 0.6 * Eil[i].egz;

}

void ivedimas_ranka(duomenys Eil[], int i) 
{
    do {
        cout << "Iveskite studento egzamino pazymi:\n";
        cin >> Eil[i].egz;
    } while (Eil[i].egz < 0 || Eil[i].egz > 10);
    cout << "Iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
    int sk = 0; 
    do {
        cin >> Eil[i].paz[sk];
        if (Eil[i].paz[sk] != -1) { Eil[i].Galutinis = Eil[i].Galutinis + (float)Eil[i].paz[sk]; }
        sk++;
    } while (Eil[i].paz[sk - 1] != -1);
    sk--;
    Eil[i].Galutinis = Eil[i].Galutinis / sk;
    Eil[i].Galutinis = Eil[i].Galutinis * 0.4 + 0.6 * Eil[i].egz;
}


void vardo_ivedimas(duomenys Eil[], int i) 
{
    cout << "Iveskite studento nr. " << i + 1 << " duomenis:\n";
    do {
        cout << "Iveskite studento nr. " << i + 1 << " VARDA:\n";
        cin >> Eil[i].Vard;
    } while (Eil[i].Vard.length() < 0 || Eil[i].Vard.length() > 25);
 
    do {
        cout << "Iveskite studento nr. " << i + 1 << " PAVARDE:\n";
        cin >> Eil[i].Pav;
    } while (Eil[i].Pav.length() < 0 && Eil[i].Pav.length() > 25);
  
    cout << endl;
}

void spauskink(duomenys Eil[], int studentu_sk)
{
    cout << "\n\n";
    cout << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "----------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << setw(20) << left << Eil[i].Vard
            << setw(20) << left << Eil[i].Pav
            << setw(18) << left << Eil[i].Galutinis;
        Mediana(Eil[i].paz);
    }
    cout << "\n\n";
}



int main()
{
    int studentu_sk;
    int*nums;
    char temp;
    do
    {
        cout << "Iveskite studentu kieki:\n";
        cin >> studentu_sk;
    } while (int(studentu_sk) < 0 || int(studentu_sk) > 100);
    duomenys Eil[25];
    nums = new int[studentu_sk];
    do
    {
        cout << "Automatiskai - SPAUSKITE \"A\"\n Patys - RASYKITE \"P\"\n";
        cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'p' && temp != 'P') {
          cout << "pakartokite, netinkamas simbolis\n"; }
    } while (temp != 'a' && temp != 'A' && temp != 'p' && temp != 'P');
    for (int i = 0; i < studentu_sk; i++)
    {
        vardo_ivedimas(Eil, i);
        if (temp == 'p' || temp == 'P') { ivedimas_ranka(Eil, i); }
        else { automatiskai_ivedami_pazymiai(Eil, i, 5); }
    }
    spauskink(Eil, studentu_sk);
    delete[] nums;
		nums = 0;

    return 0;
}