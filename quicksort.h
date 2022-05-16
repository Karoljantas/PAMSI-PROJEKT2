#pragma once
#include <algorithm>
#include "dane.h"
using namespace std;
class quicksort //klasa 
{
	dana* tab; //tab z danymi 
	int n; // ilosc rekordów 

public: //publiczna 
	int get_n() { return n; } 
	quicksort(int n) //konstruktor
	{
		this->n = n;  // przypisanie n z zewnatrz do n z klasy
		tab = new dana[n]; //wpisanie nowej danej do tablicy
	}





	void srednia()   //liczenie sredniej 
	{
		long double suma=0; //zmienna suma 
		for (int i = 0; i < n; i++) //przechodi po wszystkich ocenach 
		{
			suma += tab[i].ocena; //sumuje oceny 
		}
		cout <<"srednia"<< suma / n << endl; //wyswietla srednia 
	}





	void mediana()   //licznie mediany 
	{
		cout << "mediana " << tab[n / 2].ocena << endl; //wyswietla mediane 
	}

	



	void odczyt()
	{

		string dane;   //string  danych 
		fstream plik;   //przechowuje otwarty plik 
		std::stringstream ss; //string który jest uznawany jako strumien danych 
		int k = 0; // liczy filmy bez oceny
		plik.open("projekt2_dane.csv");  //otwieramy plik
		getline(plik, dane); //pobieramy linie (nag³ówek)



		for (int i = 0; i < n; i++) // pêtla wykonuje sie tyle ile mamy zczytac filmów 
		{
			getline(plik, dane); //pobiera linie z tytulem i ocena 
			tab[i].nazwa = dane; // zapisywanie ca³ej lini do danych 
			dane = dane.substr(dane.size()-5);  // przypisanie danych z wycietymi ostatnimi 5 symbolami (10.00)
			
				ss << dane; //przekazanie ca³ego stringa na strumien stringa 
				getline(ss, dane, ','); //zczytanie ze strumienia danych do , (usuwanie , jezeli mamy np ,9.00)
				
				getline(ss, dane); //zczytanie reszty wartosci oceny
				ss.ignore(1024, '\n'); //wyczyszczenie strumienia danych 
				ss.clear(); //wyczyszczenie strumienia danych cd


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
					cout <<"max danych : "<< i << endl; //wyswietlamy dane na których sortujemy 
					break; //koniec petli 
				}

		}


		cout <<"danebezoceny" << k << endl; //wyswietlamy ilosc danych które s¹ bez oceny 
		plik.close(); //zamykamy plik 

	}

	
	void sortowanie(int l, int p) //algorytm sortowania 
	{
		if (p <= l) return; //jezeli prawy jest mniejszy równy od lewego 

		int i = l - 1, j = p + 1,pivot = tab[(l + p) / 2].ocena; //wybieramy punkt odniesienia

		while (1)
		{
			
			while (pivot > tab[++i].ocena); //szukamy elemetu wiekszego niz pivot który jest po prawej stronie

			
			
			while (pivot < tab[--j].ocena); //szukamy elemetu mniejszego niz pivot który jest po lewej stronie

			
			if (i <= j) // jezeli liczniki siê nie mine³y to zmieniamy elemety ze soba stojace po zlej stronie pivot
				
				swap(tab[i], tab[j]); //funkcja swap zamienia wartosciami tab[i] z tab[j]
			else   // w innym przypadku 
				break; //wychodzimy z petli 
		}

		if (j > l) //jezeli j wieksze od lewego 
			sortowanie( l, j); //sortujemy 


		if (i < p) //jezeli i mniejsze od prawego 
			sortowanie( i, p); //sortujemy 

	}
};
