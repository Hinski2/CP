#include <bits/stdc++.h>
using namespace std;

const int mak = 250005;

int n, arr[mak];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    stack<int>stos;
    stos.push(0);
    int wynik = 0;

    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, nowy;
        cin >> x >> nowy;

        while(nowy < stos.top())
        {
            stos.pop();
        }

        if(nowy > stos.top())
        {
            wynik++;
            stos.push(nowy);
        } 
    }

    cout << wynik << "\n";
}