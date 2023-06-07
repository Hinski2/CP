// drzewo przedział punkt (zmiana na przedziale, odczytanie z punktu)
#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 20;
int tree[base << 1];

void add(int a, int b, int x)
{
    a += base;
    b += base;

    tree[a] += x;
    if(a != b) tree[b] += x;

    while(a >> 1 != b >> 1)
    {
        if(a % 2 == 0) tree[a + 1] += x;
        if(b % 2 == 1) tree[b - 1] += x;

        a >>= 1;
        b >>= 1;
    }
}

int querry(int v)
{
    v += base;

    int ans = 0;
    while(v)
    {
        ans += tree[v];
        v >>= 1;
    }

    return ans;
}

int main()
{
    while(true)
    {
        char c;  //a - add, q - querry
        cin>>c;

        if(c == 'a')    //dodanie na przedziale domkniętym [a, b] wartości x
        {
            int a, b, x; 
            cin>>a>>b>>x;

            add(a, b, x);
        }
        else            //zapytanie w wierzchołku q
        {
            int v;
            cin>>v;
            cout<<querry(v)<<"\n";
        }
    }
}
