#include <bits/stdc++.h>
using namespace std;

int wysokosc_rurki, ilosc_krazkow;
vector<int>poziom_szerokosc;
vector<int>krazek_szerokosc;

void wczytanie(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> wysokosc_rurki >> ilosc_krazkow;
    for(int i = 1; i <= wysokosc_rurki; i++){
        int x;
        cin >> x;

        poziom_szerokosc.push_back(x);
    }
    for(int i = 1; i <= ilosc_krazkow; i++){
        int x;
        cin >> x;

        krazek_szerokosc.push_back(x);
    }
}

void ustawienie_zabawki(){
    for(int i = 1; i < wysokosc_rurki; i++)
        poziom_szerokosc[i] = min(poziom_szerokosc[i], poziom_szerokosc[i - 1]);
}

void dodawanie_krazkow(){
    int ans = wysokosc_rurki;
    int idx_krazek = 0;

    for(int obecna_wysokosc = wysokosc_rurki - 1; obecna_wysokosc >= 0; obecna_wysokosc--){
        if(poziom_szerokosc[obecna_wysokosc] >= krazek_szerokosc[idx_krazek]) idx_krazek++;

        if(idx_krazek == ilosc_krazkow){
            ans = obecna_wysokosc + 1;
            break;
        }
    }

    //wypisanie wyniku
    if(idx_krazek != ilosc_krazkow) cout << "0\n";
    else cout << ans << "\n";
}

int main(){
   wczytanie();
   ustawienie_zabawki();
   dodawanie_krazkow();
}