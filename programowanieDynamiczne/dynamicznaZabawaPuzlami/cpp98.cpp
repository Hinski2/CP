#include<bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;
const int mak = 1e6 + 15;

int va[mak], vb[mak], vc[mak];

int a(int n);
int b(int n);
int c(int n);

void u()
{
    for(int i = 0; i < mak; i++)
    {
        va[i] = -1;
        vb[i] = -1;
        vc[i] = -1;
    }
}

int oblicz(int n)
{
    if(n == 1)
    {
        return 1;
    }

    if(n == 2)
    {
        return 3;
    }
    else
    {
        return (((a(n - 1) % m) + (b(n - 1) % m)) % m + (c(n - 1) % m)) % m;
    }
}

int a(int n)
{
    if(va[n] != -1)
    {
        return va[n];
    }
    else
    {
        return va[n] = (((a(n - 1) % m) + (b(n - 1) % m)) % m + (c(n - 1) % m)) % m;
    }
}

int b(int n)
{
    if(vb[n] != -1)
    {
        return vb[n];
    }
    else
    {
        return vb[n] = ((a(n - 1) % m) + ((c(n - 2) % m) * 2) % m) % m;
    }
}

int c(int n)
{
    if(vc[n] != -1)
    {
        return vc[n];
    }
    else
    {
        return vc[n] = ((a(n - 1) % m) + (b(n - 1) % m)) % m;
    }
}

int main()
{
    u();

    va[1] = 1;
    vb[1] = 1;
    vc[1] = 1;

    int n;
    scanf("%d", &n);

    cout<<oblicz(n)<<endl;
} 