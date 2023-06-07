#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 19;

int tree[base << 1];
int lazyTree[base << 1];

void add(int v, int a, int b, int p, int k, int s)
{
    if(b < p || k < a) return;
    else if(p <= a && b <= k)
    {
        tree[v] += (b - a + 1) * s;
        lazyTree[s] += (b - a + 1) * s;
    }
    else
    {
        int l = v << 1, r = (v << 1) + 1, mid = (a + b) >> 1;

        tree[l] += lazyTree[v] / 2;
        tree[r] += lazyTree[v] / 2;

        lazyTree[l] += lazyTree[v] / 2;
        lazyTree[r] += lazyTree[v] / 2;

        lazyTree[v] = 0;

        add(l, a, mid, p, k, s);
        add(r, mid + 1, b, p, k, s);

        tree[v] = tree[l] + tree[r];
    }
}

int querry(int v, int a, int b, int p, int k)
{
    if(b < p || k < a) return 0;
    else if(p <= a && b <= k) return tree[v];
    else
    {
        int l = v << 1, r = (v << 1) + 1, mid = (a + b) >> 1;

        tree[l] += lazyTree[v] / 2;
        tree[r] += lazyTree[v] / 2;

        lazyTree[l] += lazyTree[v] / 2;
        lazyTree[r] += lazyTree[v] / 2;

        lazyTree[v] = 0;

        return querry(l, a, mid, p, k) + querry(r, mid + 1, b, p, k);
    }
}

int main()
{
    int stefan = 1;
    add(stefan, 0, base - 1, 1, 2, 1);
    add(stefan, 0, base - 1, 3, 4, 1);
    add(stefan, 0, base - 1, 5, 8, 1);
    add(stefan, 0, base - 1, 6, 7, 1);

    while(1)
    {
        int x, y;
        cin>>x>>y;

        cout<<querry(stefan, 0, base - 1, x, y) / 2<<endl;
    }


    // cout<<querry(stefan, 0, base - 1, 1, 2) / 2<<endl;
    // cout<<querry(stefan, 0, base - 1, 3, 4) / 2<<endl;
    // cout<<querry(stefan, 0, base - 1, 5, 8) / 2<<endl;
    // cout<<querry(stefan, 0, base - 1, 6, 7) / 2<<endl;
    // cout<<querry(stefan, 0, base - 1, 0, 9) / 2<<endl;
}