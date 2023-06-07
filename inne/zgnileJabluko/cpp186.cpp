#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
string slowo, liczba;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> slowo >> liczba;

    for(int i = 0; i < liczba.size(); i++)
    {
        n *= 10;
        n = (n + (liczba[i] - '0')) % slowo.size(); 
    }

    //wypisanie slowa
    for(int i = n; i < slowo.size(); i++) cout << slowo[i];
    for(int i = 0; i < n; i++) cout << slowo[i];
}