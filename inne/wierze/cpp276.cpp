#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se socond

struct

int n;
vector<>coord;

void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        coord.push_back({{a, c}, {b, d}});
    }
}

int main(){
    wczytaj();
    sort(coord.begin(), coord.end(), cmp);
    policz();
    wypisz();
}