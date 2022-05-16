

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "quicksort.h"
#include "scalanie.h"
#include "kubelkowe.h"

using namespace std;

int main()
{
	clock_t start, stop;   //zmienna przechowujaca czas 
    double czas; //zmienna czas 
    int nr; // zmienna ilosc elemetów 
    fstream plik; // przechowuje otwarty plik 
    plik.open("wyniki.txt"); // otwieramy plik z wynikami 
    cout << "podaj ilosc elementow " << endl; //prosi o podanie ilosci elemetow do sortowania 
    cin >> nr; // pobiera te ilosc elemetów 



    quicksort a(nr); // odpala sortowanie szybkie
    a.odczyt(); //odpala funkcje odczyt 
    start = clock(); //zczytujemy czas i zapisujemy do zmiennej czas 
    a.sortowanie(0,a.get_n()-1); //odpalamy sortowanie 
    stop = clock(); //zczytujemy czas  i zapisujemy do zmiennej czas 
    czas = (double)(stop - start) ; //obliczenie czasu sortowania 
    a.srednia(); //odpalamy funkcje srednia 
    a.mediana(); //odpalamy funkcje mediana 
    plik << "szybkie " << czas << endl; // zapisujemy fraze szybkie do pliku razem z czasem 



   przezscalanie b(nr); //odpala sortowanie przez scalanie
    b.odczyt(); //odpala funkcje odczyt 
    start = clock(); //zczytujemy czas i zapisujemy do zmiennej czas 
    b.sortowanie(0, b.get_n() - 1); //odpalamy sortowanie
    stop = clock(); //zczytujemy czas i zapisujemy do zmiennej czas 
    czas = (double)(stop - start) ; //liczymy czs sortowania 
    b.srednia(); //odpalamy f srednia
    b.mediana(); //odpalamy f mediana 
    plik << "przezscalanie " << czas << endl; // zapisujemy fraze przezscalanie do pliku razem z czasem



   
    kubelkowe c(nr); //odpala sortowanie kubelkowe
    c.odczyt();// odpalamy f odczyt 
    start = clock();//zczytujemy czas i zapisujemy do zmiennej czas 
    c.sortowanie(); //odpalamy sortowanie 
    stop = clock(); //zczytujemy czas i zapisujemy do zmiennej czas 
    czas = (double)(stop - start) ; //liczymy czas
    c.srednia(); //odpalamy f srednia
    c.mediana(); //odpalamy f mediana
    plik << "kubelkowe " << czas << endl; // zapisujemy fraze kubelkowe do pliku razem z czasem
    
}

