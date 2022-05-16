#pragma once
#include "dane.h"
using namespace std;
class przezscalanie //klasa 
{
    dana* tab; //tab z danymi 
    dana* pomocniczy;  //pomocnicza 
    int n; //  ilosc rekordów 
	 
public: //publiczna 
    int get_n() { return n; } 
    przezscalanie(int n) // konstruktor
    {
        this->n = n;  // przypisanie n z zewnatrz do n z klasy
        tab = new dana[n]; //wpisanie nowej danej do tablicy
        pomocniczy = new dana[n]; //przypisanie do pomocniczego 
    }



	void srednia() //licznie sredniej 
	{
		long double suma = 0; //zmienna suma 
		for (int i = 0; i < n; i++) // przechodzimy po wszystkich ocenach 
		{
			suma += tab[i].ocena; // sumowanie
		}
		cout << "srednia" << suma / n << endl; // wyswietlamy srednia 
	}




	void mediana() //liczymy mediane 
	{
		cout << "mediana " << tab[n / 2].ocena << endl; // wyswietlamy mediane 
	}




	void odczyt()
	{
		string dane;  //string  danych
		fstream plik;  //przechowuje otwarty plik
		std::stringstream ss; //string który jest uznawany jako strumien danych
		int k = 0; // liczy filmy bez oceny
		plik.open("projekt2_dane.csv");  //otwieramy plik
		getline(plik, dane);  //pobieramy linie (nag³ówek)


		for (int i = 0; i < n; i++) // pêtla wykonuje sie tyle ile mamy zczytac filmów
		{
			getline(plik, dane); //pobiera linie z tytulem i ocena
			tab[i].nazwa = dane; // zapisywanie ca³ej lini do danych
			dane = dane.substr(dane.size() - 5); // przypisanie danych z wycietymi ostatnimi 5 symbolami (10.00)

			
			ss << dane; //przekazanie ca³ego stringa na strumien stringa
			getline(ss, dane, ','); //zczytanie ze strumienia danych do , (usuwanie , jezeli mamy np ,9.00)
			
			getline(ss, dane); //zczytanie reszty wartosci oceny
			ss.ignore(1024, '\n'); //wyczyszczenie strumienia danych 
			ss.clear();  //wyczyszczenie strumienia danych cd


			if (dane.size() > 0) //jezeli danych jest wiecej niz 0 
			{
				
				tab[i].ocena = stod(dane); //konwersja string na double
			} 
			else  // w innym przypadku
			{ 
				k++; //zwiekszamy ilosc danych bez oceny
				i--; //cofamy ilosc danych o 1
			}

			if (k + i == 1010000) // sprawdzamy czy suma pobranych danych i suma danych bez oceny jest równa max ilosci danych z pliku
			{ 
				n = i; //jezeli tak to n zmieniamy na i bo nie doszlismy do n 
				cout << "max danych : " << i << endl; //wyswietlamy dane na których sortujemy 
				break; //koniec petli 
			} 

		}


		cout <<"danebezoceny"<< k << endl;  //wyswietlamy ilosc danych które s¹ bez oceny
		plik.close();  //zamykamy plik

	}


    void sortowanie(int pierwszym, int ostatnis) //alg sortowania
    {
        int srodek, i_n=0, i_s=0, i; // srodek, elemet nowego i starego zbioru, zmienna sterujaca
		srodek = (pierwszym + ostatnis + 1) / 2; // liczenie srodka 



        if (srodek - pierwszym > 1) // jezeli srodek- pierwszy z mlodego zbioru jest wiekszy od 1 
        {
            sortowanie(pierwszym, srodek - 1); // sortujemy 
        }



        if (ostatnis - srodek > 0) //jezeli ostatni starego zbioru - srodek wiekszy od 0 
        {
            sortowanie(srodek, ostatnis); //sortujemy 
           
        }


 i_n = pierwszym; //przypisujemy elemetowi z mlodego zbioru pierwszy elemet z mlodego zbioru 
            i_s = srodek; //przypisanie elemetowi starego zbioru srodka



        for (i = pierwszym; i <= ostatnis; i++) // przechodzimy po elemetach od pierwszego do ostatniego w danym zbiorze  
        {
            pomocniczy[i] = ((i_n == srodek) || ((i_s <= ostatnis) && (tab[i_n].ocena > tab[i_s].ocena))) ? tab[i_s++] : tab[i_n++]; // zaleznie od strumienia przypisujemy i_s lub i_n
        }




        for (i = pierwszym; i <= ostatnis; i++) // przechodzimy po elemetach od pierwszego do ostatniego w danym zbiorze 
        {
            tab[i] = pomocniczy[i]; // przypisujemy zbiór pomocniczy do tablicy 
        }
    }
};