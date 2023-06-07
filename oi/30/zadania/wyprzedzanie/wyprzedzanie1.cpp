//Jakub Iliński zadanie wyprzedzanie przypuszczalna wzorcówka
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<pair<ld, ld>, pair<int, int>> para;

const ld eps = 1e-4;
const ld nigdy = 1e16;

//dane bajtazara
int n, baj_len;
ld V;

//dane cieżarówek 
vector<int>start_pos, truck_len;
vector<ld>v;

int ans;
vector<para>stos;
vector<ld>wyprzedzenie;


void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << setprecision(22);

    int s, t;
    cin >> n >> baj_len >> s >> t;

    V = (ld) s / t;

    truck_len.resize(n + 1);
    start_pos.resize(n + 1);
    wyprzedzenie.resize(n + 1);
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

ld wyznacz_przeciecie(int a, ld b1, int c, ld b2){

    if(v[c] - v[a] > eps) return nigdy;

    ld l = 0, r = nigdy;
    ld czas = (ld) (l + r) / 2;

    while(abs(r - l) > eps){
        czas = (ld) (l + r) / 2;

        if(v[c] * czas + b2 - (v[a] * czas + b1) < eps)
            r = czas - eps;
        else
            l = czas + eps;
    }

    return czas; 
}

void przeciecie(int a){
    while(!stos.empty()){
        ld czas1 = stos.back().first.first;
        ld czas2 = stos.back().first.second;
        int c = stos.back().second.first;
        int h = stos.back().second.second;

        //sprawdzenie czy w tym miejscu zmieści sie bajtazar
        if(abs(wyprzedzenie[a] - czas1) < eps || wyprzedzenie[a] - czas1 > eps)
            if(abs(wyprzedzenie[a] - czas2) < eps || wyprzedzenie[a] - czas2 < eps){
                ld odl = v[c] * wyprzedzenie[a] + start_pos[c] - (truck_len[c] + h) - (v[a] * wyprzedzenie[a] + start_pos[a]) - baj_len;
                if(abs(odl) < eps || odl > eps) ans++; //bajtazar sie mieści 
            }
        //sprawdzenie czy w tym miejscu a przecina sie z b
        ld odl = v[c] * wyprzedzenie[a] + start_pos[c] - (truck_len[c] + h) - (v[a] * wyprzedzenie[a] + start_pos[a]);
        ld inter = wyznacz_przeciecie(a, start_pos[a], c, start_pos[c] - truck_len[c] - h);

        if((abs(inter - czas1) < eps || inter - czas1 > eps) && (abs(inter - czas2) < eps || inter - czas2 < eps) && (abs(odl) < eps || odl < eps)){
            stos.pop_back();
            stos.push_back({{inter, czas2}, {c, h}});
            stos.push_back({{0, inter}, {a, 0}});

            break;
        }
        else{
            stos.pop_back();
            if(!stos.empty())
            stos.back().second.second += truck_len[c] + h;
        }
    }

    if(stos.empty()){
        stos.push_back({{0, nigdy}, {a, 0}});
    }
}

int main(){
    //wczytanie
    wczytaj();

    //liczenie
    for(int i = 1; i <= n; i++)
        wyznacz_wyprzedzenie(i);

    stos.push_back({{0, nigdy}, {n, 0}});
    for(int i = n - 1; i > 0; i--)
        przeciecie(i);

    //wypisanie
    cout << ans + 1 << '\n';
}