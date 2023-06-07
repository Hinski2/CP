#include <bits/stdc++.h>
using namespace std; 

const int mak = 2020;

int n, k;
int wynik = mak;
int suma[mak][mak];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++){

            //liczenie sumy butelek potrzebnych do zdjęcia by sie dostać do butelki
            if(i == 0 || j == i) 
                suma[i][j] = i + 1;
            else
                suma[i][j] = suma[i - 1][j] + j + 1;

            //nadpisywanie wyniku
            int wino;
            cin >> wino;

            if(suma[i][j] <= k) wynik = min(wynik, wino);
        }

    cout << wynik << "\n";
}
