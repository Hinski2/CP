#include <bits/stdc++.h>
using namespace std;

int n, m;
string tekst, wzorzec;
vector<int>lps;
vector<int>ans;

inline void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> n;
    cin >> wzorzec >> tekst;

    lps.resize(m + 1);
    wzorzec = '#' + wzorzec;
    tekst = '#' + tekst;
}

inline void make_lps(){
    int l = 0;
    for(int i = 2; i <= m; i++){
        while(wzorzec[i] != wzorzec[l + 1] && l > 0) l = lps[l];
        if(wzorzec[i] == wzorzec[l + 1]) l++;
        lps[i] = l;
    }
}

inline void kmp(){
    int l = 0;
    for(int i = 1; i <= n; i++){
        while(wzorzec[l + 1] != tekst[i] && l > 0) l = lps[l];
        if(wzorzec[l + 1] == tekst[i]) l++;
        if(l == m){
            ans.push_back(i - m + 1);
            l = lps[l];
        }
    }
}

inline void wypisz(){
    for(auto u: ans)
        cout << u << '\n';
}

int main(){
    wczytaj();
    make_lps();
    kmp();
    wypisz();
}