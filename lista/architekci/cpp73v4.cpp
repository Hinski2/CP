#include "arc.h"//kompiluje się: g++ -O2 -std=c++11 cpp73v3.cpp arczaw.c -o cpp73v3
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 15;           //nieskończoność

int k, poprzedni = inf;      //ile propozycji dać krulowi,, rozmiar listy "l"

list<int>l;                         //głowna lista, to ją otrzymać ma krór 
list<list<int>::iterator>d;         //do usunięcia

void usun()                         //usuwa zły projekt
{
    l.erase(prev(d.front()));
    if(d.front() == l.begin() || *(prev(d.front())) >= *(d.front()))
    {
        d.pop_front();
    }
}

void make(int nowy)                 //dodaje nowy element
{
    // jeśle l < k || nie ma co usunąć || ostatni element jet < niz nowy 
    if(l.size() < k || !d.empty() || poprzedni < nowy) 
    {
        l.push_back(nowy);

        if(poprzedni < nowy)
        {
            auto it = l.end();
            d.push_back(--it); //it-- ponieważ it wstazuje na end => (element za ostatnim elementem w liscie) 
        }

        poprzedni = l.back();

        if(l.size() > k)
        {
            if(d.empty()) l.pop_back();
            else usun();
        }
    }
}

int main()
{
    //* wczytywanie 
    k = inicjuj();                  //wczytanie ile projektów chce król

    while(int nowy = wczytaj())     //wczytywanie projektów
    {
        make(nowy);                 //rozważanie projektów
    }

    //* wypisywanie wyniku
    for(auto i: l)                  //wypisanie wyniku
    {
        wypisz(i);
    }
}