#include "head.h"

int main()
{
    srand(time(0));
    vector <studentas> stud;
    char ar;
    cout << "Ar norite sugeneruoti naujus studento failus? (T/N)" << endl;
    cin >> ar;
    if (ar == 't' || ar == 'T')
    {
        cout << "Kiek studentas tures pazymiu" << endl;
        int kieknd;
        Skaicius(kieknd);
        Failugeneracija(kieknd);
    }
    else
    {
        cout << "Ar turite jau sugeneruotus studentu failus? (T/N)" << endl;
        cin >> ar;
        if (ar == 't' || ar == 'T')
        {
            cout << "Ar norite naudoti 1 strategija?" << endl;
            cin >> ar;
            if (ar == 't' || ar == 'T')
            {
                cout << "Ar norite analizuoti su vector konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        Greicioanalizevector(i);
                    }
                }
                cout << "Ar norite analizuoti su list konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        Greicioanalizelist(i);
                    }
                }
            }
            cout << "Ar norite naudoti 2 strategija?" << endl;
            cin >> ar;
            if (ar == 't' || ar == 'T')
            {
                cout << "Ar norite analizuoti su vector konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        Greicioanalizevector2(i);
                    }
                }
                cout << "Ar norite analizuoti su list konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        Greicioanalizelist2(i);
                    }
                }
            }

        }
        else
        {
            cout << "Ar norite duomenis ivesti ranka? (T/N)" << endl;
            cin >> ar;
            if (ar == 't' || ar == 'T')
            {
                Ivestisranka(stud);
                Isvestis(stud);
            }
            else
            {
                try {
                    Exists_test("kursiokai.txt");
                    Ivestis(stud);
                    Isvestis(stud);
                }
                catch (const char* msg) {
                    cout << msg << endl;
                }
            }
        }
    }
    return 0;
}