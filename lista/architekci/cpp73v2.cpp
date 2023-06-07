#include "arc.h"					//kompiluje się: g++ -O2 -std=c++11 cpp73v2.cpp arczaw.c -o cpp73v2
#include <bits/stdc++.h>
using namespace std;

int k,qSize=0;						//ile projektów oddać królowi, obecny rozmiar kolejki "q"
priority_queue<pair<int,int>>q;		//kolejka
priority_queue<pair<int,int>>sq;	//posortowana kolejka

void make(int i,int idx)            //tworzenie kolejki
{
    if(!q.empty() && i*(-1)==(int)q.top().first && qSize==k)
    {
        q.pop();
        q.push({i*(-1),idx});
    }

    else
    {
        q.push({i*(-1),idx});           //dodawanie wartości do kolejki, -i ponieważ chcemy mieć na szczycie najmniejszą wartość
        qSize++;
        if(qSize>k)//jeśli ilość elementów kolejki > k --> usuń najmniejszą wartosć
        {
            q.pop();
            qSize--;
        } 
    }             
}

void sortowanie() //sortowanie kolejki q i przenoszenie danych do kolejke sq
{
    while(!q.empty())
    {           //dodanie -idx liczby oraz dodanie liczby 
        sq.push({q.top().second*(-1),q.top().first*(-1)});
        q.pop();
    }   
}

int main()
{
    k=inicjuj();            //wczytanie ile projektów bedziemy oddawali królowi

    int idx=1;              //indeks liczby, by było jak je potem posortować 
    while(int i=wczytaj())  //wczytuje aż nie napotka 0
    {
        make(i,idx);        //tworzy kolejkę
        idx++; 
    }

    sortowanie();

    while(!sq.empty())      //wypisanie wyniku
    {
        wypisz(sq.top().second);
        sq.pop();
    }
}