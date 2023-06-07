#include "arc.h"//kompiluje się: g++ -O2 -std=c++11 cpp73v3.cpp arczaw.c -o cpp73v3
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 15;					//nieskończoność

int k, poprzedni = inf, lSize;				//ile propozycji dać krulowi,, rozmiar listy "l"

list<int>l;								//głowna lista, to ją otrzymać ma krór 
list<list<int>::iterator>srednie;		//takie średnie elementy listy l bym powiedział

void usun()//usuwa zły projekt
{
	if(srednie.empty())	//jeśli na horyzoncie nie wydać żadnych średnich elementów 
	{
		l.pop_back();	//usuń ostatni element z listy l
	}
	else				//jeśli są jakieś średnie elementy 
	{
		l.erase(prev(srednie.front()));	//usuwa pierwszy element z listy średnie
		if(srednie.front()==l.begin() || *(prev(srednie.front()))>=*(srednie.front()))
		{//jeśli jredni element  jest taki sam jak pierwszy element l lub można usunać gorszy element 
			srednie.pop_front();		//usuń pierwszy średni element 
		}
	}
	lSize--;			//zmniejsza rozmiar listy do k
}

void make(int nowy)					//dodaje nowy element
{	//jeśli nie ma średnich elementów do  usunięcia, poprzedni element jest mniejszy od nowego albo nie ma wystarczajacej liczby projektów
	if(!srednie.empty() || poprzedni<nowy || lSize<k)	
	{
		l.push_back(nowy);			//dodanie nowego elementu do listy
		lSize++;			

		if(poprzedni<nowy)			//jeśli poprzednia wartość jest mniejsza od nowej
		{
			auto it=l.end();		
			it--;
			srednie.push_back(it);	//dodanie nowej średniej wartości (warto ją usunąć, dodajemy wartość poprzedni)	
		}

		poprzedni=l.back();			//aktualizacja nowego ostatniego elementu

		if(lSize>k)	//jeśli lista jej za długa trzeba usunąć najgorszy element 
		{
			usun();	//usuwanko
		}
	}
}

int main()
{
	k = inicjuj();				//wczytanie ile projektów chce król

	while(int nowy = wczytaj()) 	//wczytywanie projektów
	{
		make(nowy);				//rozważanie projektów
	}

	for(auto i: l)				//wypisanie wyniku
	{
		wypisz(i);
	}
}