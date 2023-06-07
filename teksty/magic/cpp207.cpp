#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;
const int nak = 123;
const int mod = 1e9 + 7;

int n, ans;
char c[mak];

unordered_set<char>set_letter;
unordered_map<char, int>przemapowanie;
map<vector<int>, int>mapa;

void przemapowanie_seta()
{
    int idx = 0;
    for(auto u: set_letter)
    {
        przemapowanie[u] = idx++;
    }
}

void dodac_takie_same(vector<int> &dif)
{
    mapa[dif]++;
    ans = (ans + mapa[dif]) % mod;
}

void dodac_inne(vector<int> &dif)
{
    auto znajdz = mapa.find(dif);
    if(znajdz != mapa.end())
    {
        ans = (ans + mapa[dif]) % mod;
    }

    mapa[dif]++;
}

void liczenie(vector<int>& pre, int idx)
{
    vector<int>dif(set_letter.size());
    int character = przemapowanie[c[0]];

    pre[przemapowanie[c[idx]]]++;
    for(int i = 0; i < set_letter.size(); i++)
    {
        dif[i] = pre[i] - pre[character];
    }

    //sprawdzenie czy wartosci sa takie same 
    bool takie_same = true;
    for(int i = 0; i < dif.size() && takie_same; i++)
    {
        if(dif[i] != dif[0]) takie_same = false;
    }

    if(takie_same)
    {
        dodac_takie_same(dif);
    }
    else
    {
        dodac_inne(dif);
    }

    //debug
    // for(auto u: mapa)
    // {
    //     for(auto i : u.first) cout << i << " ";
    //     cout << "\t" << u.second << endl;
    // }
    // cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        set_letter.insert(c[i]);
    }

    //liczenie
    przemapowanie_seta();

    vector<int>pre(set_letter.size(), 0);

    for(int i = 0; i < n; i++)
    {
        liczenie(pre, i);
    }

    //wypisanie wyniku
    cout << ans << "\n";
}