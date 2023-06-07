#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m;
int S;

vector<bool>inside;
vector<vector<int>>G;
vector<int>operacje, p, sajz;

vector<int>ans;

void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    G.resize(n + 1);
    p.resize(n + 1);
    inside.resize(n + 1);
    sajz.resize(n + 1, 1);
    operacje.resize(n);

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = n - 1; i >= 0; i--)
        cin >> operacje[i];

    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int znajdz(int v){
    if(p[v] == v) return v;
    return p[v] = znajdz(p[v]);
}

void polacz(int a, int b){
    a = znajdz(a);
    b = znajdz(b);

    if(a == b) return;

    S--;
    if(sajz[a] < sajz[b]) swap(a, b);
    sajz[a] += sajz[b];
    p[b] = p[a];
}

void dodaj(int v){
    S++;
    inside[v] = true;

    for(auto u: G[v])
        if(inside[u])
            polacz(v, u);
}

int main(){
    freopen("closing.in","r", stdin);
    freopen("closing.out","w", stdout);

    //wczytaywanie
    wczytaj();

    //liczenie
    for(auto u: operacje){
        dodaj(u);

        if(S == 1) ans.push_back(1);
        else ans.push_back(0);
    }

    //wypiszanie wyniku
    for(int i = n - 1; i >= 0; i--){
        if(ans[i] == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}