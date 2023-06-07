//Jakub Iliński zadanie wyprzedzanie, rozwiązanie poprawne, ale nie optymalne;
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld eps = 1e-4;
const ld nigdy = 1e16;

//dane bajtazara
int n, baj_len;
ld V;

//dane cieżarówek 
vector<int>start_pos, truck_len;
vector<ld>v;

int ans;
vector<ld>wyprzedzenie;
vector<ld>poczatek;

void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << setprecision(22);

    int s, t;
    cin >> n >> baj_len >> s >> t;

    V = (ld) s / t;

    truck_len.resize(n + 1);
    start_pos.resize(n + 1);
    wyprzedzenie.resize(n + 1);
    poczatek.resize(n + 1);
    v.resize(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> start_pos[i] >> truck_len[i] >> s >> t;
        v[i] = (ld)s / t;
    }
}

void wyznacz_wyprzedzenie(int i){
    ld l = 0, r = nigdy;
    ld czas = (ld) (l + r) / 2;

    while(abs(r - l) > eps){
        czas = (ld) (l + r) / 2;

        if(V * czas - baj_len - (v[i] * czas + start_pos[i]) < eps)
           l = czas + eps;
        else
            r = czas - eps;
    } 
    
    wyprzedzenie[i] = czas;
} 

void wyznacz_poczatek(int i){
    for(int j = 1; j <= n; j++)
        poczatek[j] = v[j] * wyprzedzenie[i] + start_pos[j];

    for(int j = n - 1; j > 0; j--)
        if(abs(poczatek[j + 1] - truck_len[j + 1] - poczatek[j]) > eps && poczatek[j + 1] - truck_len[j + 1] - poczatek[j] < eps)
            poczatek[j] = poczatek[j + 1] - truck_len[j + 1];
}

void sprawdzenie(int a, int b){
    if(abs(poczatek[b] - truck_len[b] - poczatek[a] - baj_len) < eps || poczatek[b] - truck_len[b] - poczatek[a] - baj_len > eps)
        ans++;
}

int main(){
    //wczytanie
    wczytaj();

    //liczenie
    for(int i = 1; i <= n; i++)
        wyznacz_wyprzedzenie(i);

    for(int i = 1; i < n; i++){
        wyznacz_poczatek(i);
        sprawdzenie(i, i + 1);
    }

    //wypisanie
    cout << ans + 1 << '\n';
}