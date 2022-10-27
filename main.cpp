
#include "head.h"


int main()
{
    bool check = false, balas = false, arNulis = false, arVektorius = false, arMediana = false, arFailas = false, arAuto = false, arGeneruoti;
    int ndKiekis, stKiekis, duom = 0;
    string ndCheck = "";
    int ndCount = 0;

    Studentas studentas;

    vector<Studentas> stud;
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;

    list<Studentas> lStud;
    list<Studentas> lVargsiukai;
    list<Studentas> lGalvociai;


    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;

    cout << "Ar norite generuoti studento failus automatiskai ir is ju skaityti duomenis (1), ar duomenu negeneruoti(0)?: ";
    BoolCheck(arGeneruoti);
    chrono::duration<double> elapsed_seconds;

    if (arGeneruoti) {

        /* Testing of vector */
        cout << "Ar norite atlikti analize vektoriu (1) ar list(0)?: ";
        BoolCheck(arVektorius);
        if (arVektorius) {
            cout << "Test of Vector: \n\n";
            cout << "----------------------------------------------------------";
            cout << "Keliu duomenu faila norite testuoti? (1000, 10000, 100000, 10000000, 10000000: "; cin >> duom;
            if (duom == 1000) {
                /* 1000 irasu */
                stud.push_back(studentas);
                vargsiukai.push_back(studentas);
                galvociai.push_back(studentas);

                ContainerTesting_vector(vargsiukai, galvociai, stud, 1000);
            }
            else if (duom == 10000) {
                // 10 000 irasu
                stud = {}; vargsiukai = {}; galvociai = {}; // vektoriu isvalymas nuo praeitu irasu
                stud.clear(); vargsiukai.clear(); galvociai.clear();
                ContainerTesting_vector(vargsiukai, galvociai, stud, 10000);
            }
            else if (duom == 100000) {
                stud = {}; vargsiukai = {}; galvociai = {}; // vektoriu isvalymas nuo praeitu irasu
                stud.clear(); vargsiukai.clear(); galvociai.clear();
                ContainerTesting_vector(vargsiukai, galvociai, stud, 100000);
            }
            else if (duom == 1000000) {  // 1 000 000 irasu
                stud = {}; vargsiukai = {}; galvociai = {}; // vektoriu isvalymas nuo praeitu irasu
                stud.clear(); vargsiukai.clear(); galvociai.clear();
                ContainerTesting_vector(vargsiukai, galvociai, stud, 1000000);
            }
            else if (duom == 10000000) {
                // 10 000 000 irasu
                stud = {}; vargsiukai = {};galvociai = {}; // vektoriu isvalymas nuo praeitu irasu
                stud.clear(); vargsiukai.clear(); galvociai.clear();
                ContainerTesting_vector(vargsiukai, galvociai, stud, 10000000);
            }
            else {
                cout << "Klaida";
            }
        }
        else {
            /* Testing of list */
            cout << "Test of List: \n\n";
            cout << "---------------------------------------------------------------------------";
            cout << "Keliu duomenu faila norite testuoti? (1000, 10000, 100000, 10000000, 10000000: "; cin >> duom;
            if (duom == 1000) {
                lStud.push_back(studentas);
                lVargsiukai.push_back(studentas);
                lGalvociai.push_back(studentas);

                ContainerTesting_list(lVargsiukai, lGalvociai, lStud, 1000);
            }
            else if (duom == 10000) {
                // 10 000 irasu
                lStud = {}; lVargsiukai = {}; lGalvociai = {}; // listu isvalymas nuo praeitu irasu
                lStud.clear(); lVargsiukai.clear(); lGalvociai.clear();
                ContainerTesting_list(lVargsiukai, lGalvociai, lStud, 10000);
            }
            else if (duom == 100000) {
                // 100 000 irasu
                lStud = {};lVargsiukai = {}; lGalvociai = {};  // listu isvalymas nuo praeitu irasu
                lStud.clear(); lVargsiukai.clear(); lGalvociai.clear();
                ContainerTesting_list(lVargsiukai, lGalvociai, lStud, 100000);
            }
            else if (duom == 1000000) {
                // 1 000 000 irasu
                lStud = {};lVargsiukai = {}; lGalvociai = {};  // listu isvalymas nuo praeitu irasu
                lStud.clear(); lVargsiukai.clear(); lGalvociai.clear();
                ContainerTesting_list(lVargsiukai, lGalvociai, lStud, 1000000);
            }
            else if (duom == 10000000) {
                // 10 000 000 irasu
                lStud = {}; lVargsiukai = {}; lGalvociai = {};  // listu isvalymas nuo praeitu irasu
                lStud.clear(); lVargsiukai.clear(); lGalvociai.clear();
                ContainerTesting_list(lVargsiukai, lGalvociai, lStud, 10000000);
            }
            else {
                cout << "Klaida";
            }
        }
    }
    else {
        cout << "\nAr norite suvesti studento duomenis patys, ar nuskaityti juos is failo? Iveskite '0' jei norite ivesti patys, ir '1' jei norite vykdyti nuskaityma is failo: ";
        BoolCheck(arFailas);

        if (arFailas) { // skaitomi is failo
            //failoNuskaitymas(stud, ndCheck, ndCount, stKiekis);
            ifstream infile("kursiokai1000.txt");
            if (infile.is_open()) { // paprastuju failu nuskaitymas
                string line, ignore;
                try {
                    infile >> ignore >> ignore;
                    infile >> line;
                }
                catch (std::exception& e) {
                    cout << "Ivyko klaida failo pirmos eilutes nuskaityme. \n";
                }

                ndCheck = ndCheck + line[0] + line[1];
                if (line.substr(0, 1) != "E" || line.substr(0, 1) != "e") { // tikrina ar pirmasis skaicius po pavardes nera egzaminas
                    ndCount++;
                    infile >> line;
                    while (line.substr(0, 2) == ndCheck) { // skaiciuoja, kiek bus nd
                        infile >> line;
                        ndCount++;
                    }
                }
                int ndPazymys;
                while (!infile.eof()) {
                    try {
                        stud.push_back(Studentas());
                        infile >> stud[stKiekis].vardas;
                        infile >> stud[stKiekis].pavarde;

                        for (int i = 0; i < ndCount; i++) {
                            infile >> ndPazymys;
                            stud[stKiekis].ND.push_back(ndPazymys);
                        }
                        infile >> stud[stKiekis].egz;
                        stKiekis++;
                    }
                    catch (exception& e) {
                        cout << "Klaida nuskaitant failo duomenis\n";
                    }

                }
                infile.close();

                for (int i = 0; i < stKiekis; i++) {
                    if (ndCount == 0) {
                        stud[i].galMed = 0;
                        stud[i].galVid = stud[i].egz * 0.6;
                    }
                    else {
                        stud[i].galMed = Mediana(stud[i].ND);
                        stud[i].galVid = Vidurkis(stud[i].ND, stud[i].egz);
                    }
                }

                chrono::time_point<chrono::system_clock> start, end;
                start = chrono::system_clock::now();
                Isvedimas(stud);                         // isvedimas
                end = std::chrono::system_clock::now();
                chrono::duration<double> elapsed_seconds = end - start;
                cout << "Time elapsed: " << elapsed_seconds.count() << "s\n";
            }
            else {
                cout << "Problema su failu.\n";
            }
        }
        else { // ivedami ranka
            cout << "\nIveskite studento varda: ";
            cin >> studentas.vardas;
            DigitCheck(studentas.vardas, check);

            cout << "\nIveskite studento pavarde: ";
            cin >> studentas.pavarde;
            DigitCheck(studentas.pavarde, check);

            cout << "\nAr norite generuoti pazymius automatiskai? 0 - ne, 1- taip.";
            BoolCheck(arAuto);

            if (arAuto) { // generavimas automatiskai
                random_device rd;
                mt19937 mt(rd());
                uniform_int_distribution<int> kiekis(0, 5);
                uniform_real_distribution<double> balai(1.0, 10.0);
                ndKiekis = kiekis(mt);
                double balas;
                for (int i = 0; i < ndKiekis; i++) {
                    balas = balai(mt);
                    studentas.ND.push_back(balas);
                }
                balas = balai(mt);
                studentas.egz = balas;
                if (ndKiekis == 0) arNulis = true;
            }
            else { // vedimas ranka

                cout << "\nIveskite studento namu darbu kieki: ";
                SymbolCheck(studentas.n, check, balas);
                if (studentas.n == 0) arNulis = true;

                balas = true;
                if (!arNulis) {
                    for (int i = 0; i < studentas.n; i++) {
                        cout << "\nIveskite " << i + 1 << "-a studento namu darbu bala: ";
                        studentas.ND.push_back(VectorSymbolCheck());
                    }
                }

                cout << "\nIveskite studento egzamino bala: ";
                SymbolCheck(studentas.egz, check, balas);
            }
            cout << "\nAr galutini bala isvesti kaip aritmetini vidurki (iveskite 0), ar kaip mediana (iveskite 1): ";
            BoolCheck(arMediana);

            // Mediana/Vidurkis:
            if (arNulis) {
                cout << "nulis\n";
                studentas.galMed = studentas.egz;
                studentas.galVid = studentas.egz * 0.6;
            }
            else {
                studentas.galMed = Mediana(studentas.ND);
                studentas.galVid = Vidurkis(studentas.ND, studentas.egz);
            }

            sort(stud.begin(), stud.end(), CompareByLength); //sortas

            if (arMediana) {
                cout << "Pavarde:            Vardas:             Galutinis ivertinimas.:\n";
                cout << "---------------------------------------------------------\n";
                cout << left << setw(20) << studentas.pavarde << setw(20) << studentas.vardas << setw(20) << fixed << setprecision(2) << studentas.galMed << endl;
            }
            else {
                cout << "Pavarde:            Vardas:             Galutinis ivertinimas.:\n";
                cout << "---------------------------------------------------------\n";
                cout << left << setw(20) << studentas.pavarde << setw(20) << studentas.vardas << setw(20) << fixed << setprecision(2) << studentas.galVid << endl;
            }

        }

    }

    return 0;
}
