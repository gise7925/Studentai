# Studentai
Pirmojoje užduoties versijoje (v0.1) yra:

Pagal aprašytus užduoties reikalavimus realizuota programą, kuri nuskaito vartotojų įvedamus reikiamus duomenis: 
     studento vardą ir pavardę, namų darbų ir egzamino rezultatą.
     
Suskaičiuoja galutinį balą ir pateikia į ekraną, dviejų skaičių po kablelio tikslumu.
Programa skaičiuoja pažymių medianą.
Ji veikia ir tokiu atveju, kai namų darbų skaičius (n) yra nežinomas iš anksto, naudojant tradicinį dinaminį C masyvą (failo vardas pavadinimas „masyvas“) bei vektorius (failo pavadinimas „vektoriai“).
Yra galimybė, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai.

Dar vis veikia bug'ovai.
Neišpildytas atsakymas į klausimą, kas nutiktų, jeigu ten kur reikia "rankomis" suvesti duomenis aš vietoj balo įvedu kažkokį kitą simbolį, pvz. "s" raidę?

v0.2
Papildyta programos versija (v0.1 su vector) taip, kad būtų galima duomenis ne tik įvesti bet ir nuskaityti iš failo. Todėl sukurtas failas kursiokai.txt.
Reikalavimai output’ui: studentai turi būti surūšiuoti pagal vardus (ar pavardes) ir visi stulpeliai būtų gražiai "išlygiuoti".
Atliktas kodo reorganizavimą (refactoring'ą).
Kur tikslinga, bent minimaliai panaudotas išimčių valdymas (angl. [Exception Handling].
