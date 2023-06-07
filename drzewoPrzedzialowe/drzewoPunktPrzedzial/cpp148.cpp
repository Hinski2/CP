//drzewo punkt - przedział (zmiana na punkcie, odczytanie z przedziału)
#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 20; 
int tree[base << 1];

void add(int v, int x)
{
    v += base;
    while(v)
    {
        tree[v] += x;
        v >>= 1;
    }
}

int querry(int a, int b)
{
    a += base;
    b += base;

    int ans = 0;
    ans += tree[a];
    if(a != b) ans += tree[b];
    
    while(a >> 1 != b >> 1)
    {
        if(a % 2 == 0) ans += tree[a + 1];
        if(b % 2 == 1) ans += tree[b - 1];

        a >>= 1;
        b >>= 1;
    }

    return ans;
}

int main()
{
    while(true)
    {
        char c;  //a - add, q - querry
        cin>>c;

        if(c == 'a')    //dodanie wartości "x" w punkcie v
        {
            int v, x;
            cin>>v>>x;
            add(v, x);  //wierzchołek, ile
        }
        else            //zapytanie na przedziale domkniętym [a, b]
        {
            int a, b;
            cin>>a>>b;

            cout<<querry(a, b)<<"\n";
        }
    }
}