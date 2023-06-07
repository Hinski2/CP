#include <bits/stdc++.h>
using namespace std;

const int mak = 5e5 + 15;

int n, q;
int r[mak], r_size[mak];

void ustawnienie()
{
    for(int i = 1; i <= n; i++)
    {
        r[i] = i;
    }
}

int find(int v)
{
    if(v == r[v]) return v;
    return r[v] = find(r[v]);
}

void join(int a, int b)
{
    if(r[a] == r[b]) return;
    if(r_size[a] < r_size[b]) swap(a, b);

    r_size[a] += r_size[b];
    r[find(b)] = r[find(a)];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> q;

    ustawnienie();

    while(q--)
    {
        int operacja;
        cin >> operacja;

        if(operacja == 1)
        {
            int a, b;
            cin >> a >> b;
            join(a, b);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if(r[find(a)] == r[find(b)]) cout << "TAK\n";
            else cout << "NIE\n";
        }
    }
}