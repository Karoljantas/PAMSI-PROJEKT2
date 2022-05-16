#pragma once
#include "dane.h"
using namespace std;

class kubelkowe  //klasa sortowania kubelkowego 
{
    dana* tab;  //tablica z danymi 

    int* tablicz; // tab przechowuj�ca ilosc rekord�w z ta sama ocena

    int n; // ilosc rekord�w 

public: // publiczna 
  
    kubelkowe(int n) //konstruktor
    {
        this->n = n; // przypisanie n z zewnatrz do n z klasy
        tab = new dana[n]; //wpisanie nowej danej do tablicy 
        tablicz = new int[11]; //tworzenie tablicy ilosci danych rekord�w 
    }



	void srednia()  //liczenie sredniej 
	{
		long double suma = 0; //zmienna suma 
		for (int i = 0; i < n; i++) //przechodzi po wszystkich ocenach 
		{
			suma += tab[i].ocena; // sumuje 
		}
		cout << "srednia" << suma / n << endl; //wyswietla srednia 
	}



	void mediana()   //liczenie mediany
	{
		cout << "mediana " << tab[n / 2].ocena << endl;
	}




	void odczyt()
	{
		string dane; //string  danych 
		fstream plik; //przechowuje otwarty plik 
		std::stringstream ss; //string kt�ry jest uznawany jako strumien danych 
		int k = 0; // liczy filmy bez oceny
		plik.open("projekt2_dane.csv"); //otwiera plik 
		getline(plik, dane); // pobiera linie (nag��wek)



		for (int i = 0; i < n; i++)  // p�tla wykonuje sie tyle ile mamy zczytac film�w
		{
			getline(plik, dane);  //pobiera linie z tytulem i ocena 
			tab[i].nazwa = dane;  // zapisywanie ca�ej lini do danych
			dane = dane.substr(dane.size() - 5); // przypisanie danych z wycietymi ostatnimi 5 symbolami (10.00)

			
			ss << dane; //przekazanie ca�ego stringa na strumien stringa
			getline(ss, dane, ','); //zczytanie ze strumienia danych do , (usuwanie , jezeli mamy np ,9.00)
			
			getline(ss, dane); //zczytanie reszty wartosci oceny
			ss.ignore(1024, '\n');  //wyczyszczenie strumienia danych
			ss.clear(); //wyczyszczenie strumienia danych cd


			if (dane.size() > 0) //jezeli danych jest wiecej niz 0 
			{
				
				tab[i].ocena = stod(dane);  //konwersja string na double
			}


			else  // w innym przypadku
			{
				k++; //zwiekszamy ilosc danych bez oceny
				i--; //cofamy ilosc danych o 1 
			}


			if (k + i == 1010000)  // sprawdzamy czy suma pobranych danych i suma danych bez oceny jest r�wna max ilosci danych z pliku
			{
				n = i;  //jezeli tak to n zmieniamy na i bo nie doszlismy do n 
				cout << "max danych : " << i << endl;  //wyswietlamy dane na kt�rych sortujemy
				break;  //koniec petli
			}

		}
		cout <<"danebezoceny"<< k << endl;  //wyswietlamy ilosc danych kt�re s� bez oceny
		plik.close(); //zamyka plik 

	}

    void sortowanie() //funkcja sortujaca 

    {
        int i, j; // zmienne sterujace 


        for (i = 0; i < 11; i++) // dla i nalezacego od 0 do 11 
        {
            tablicz[i] = 0; // przypisujemy o do tablicy ilosic rekord�w danej oceny 
        }


        int k=0; // nr indeksu tablicy ilosci rekord�w danej oceny 


        for (double j = 0; j <= 10.0; j = j + 1.0) //przechodzimy po kolejnych ocenach 
        {
            for (i = 0; i < n; i++) // przechodzimy po wszystkich elemetach tablicy 
            {
                if (tab[i].ocena == j) // jezeli dana ocena jest r�wna z ocena sprawdzana 
                    tablicz[k]++; //zwiekszamy  ilosc rekord�w
            }
            k++;// zwiekszamy indeks tablicy 
        }


        int b = 0; // zmienna kolejne indeksy tablicy 
        double w = 0; // ocena


        for (i = 0; i < k; i++) // przechodimy po ilosci danej oceny 
        {
            for (j = 0; j < tablicz[i]; j++)  // przechodzenie po ilosci rekord�w danej oceny
            {
                tab[b++].ocena = w; //zwiekszamy ilosc ocen
            }
            w += 1.0; // zwiekszenie oceny o 1 

        }
          


    }
};