#include "arc.h"		//kompiluje się: g++ -O2 -std=c++11 cpp73.cpp arczaw.c -o cpp73
#include <bits/stdc++.h>
using namespace std;

int k=inicjuj();
list<pair<int,int>>lista;
priority_queue<pair<int,int>>kolejka;

int mian()
{
	int x=1;
	while(true)
	{
		kolejka.push({wczytaj,x});
		x++;
	}

	for(int i=1;i<=k;i++)
	{
		lista.push_back({kolejka.top().first, kolejka.top().second});
		lista.pop();
	}

	lista.sort([](auto const& a, auto const& b) {return a.second < b.second;});

	for(auto i:lista)
	{
		wypisz(i.first);
	}
}