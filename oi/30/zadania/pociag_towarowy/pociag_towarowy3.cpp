//jakub iliński zadanie pociag towarowy (przypuszczalna wzorcówka)
#include <bits/stdc++.h>
using namespace std;

const int mak = 3e5 + 15;

int n, m, k;
int younger[mak], najdalej[mak], ans[mak];

vector<int>v[mak];

void wczytaj(){
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    najdalej[m + 1] = n + 1;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        v[x].push_back(i);
    }

    for(int i = 1; i <= m; i++)
        cin >> younger[i];
    
}

int znajdz(int idx, int from, int to){
    int l = 0, r = v[younger[idx]].size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(v[younger[idx]][mid] >= from)
            r = mid;
        else
            l = mid + 1;
    }
    
    if(v[younger[idx]][l] >= to || v[younger[idx]][l] < from) return n + 1;
    return l;
}

void ustaw(){
    int idx = 1;
    for(int i = 1; i <= m; i++){
        if(v[younger[i]].size() == 0){ //! potem usuń tego ifa
            najdalej[m + 1] = 0;
            return;
        }

        int pozycja = znajdz(i, idx, n + 1);
        if(pozycja == n + 1) najdalej[m + 1] = 0;

        najdalej[i] = v[younger[i]][pozycja];
        idx = v[younger[i]][pozycja] + 1;
    }

}

void wypisz(){
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

void sprawdz(){
    for(int idx = m; idx > 0; idx--){
        int i = znajdz(idx, najdalej[idx], najdalej[idx + 1]);
        if(i == n + 1) ans[najdalej[idx]] = true;
        else{
            while(i < v[younger[idx]].size() && v[younger[idx]][i] < najdalej[idx + 1]){
                ans[v[younger[idx]][i]] = true;
                najdalej[idx] = v[younger[idx]][i];

                i++;
            }
        }
    }
}

int main(){
    wczytaj();
    ustaw();
    if(najdalej[m + 1]) // jeśli znaleziono ciąg bitka w ciągu bajtka
        sprawdz();
    wypisz();
}