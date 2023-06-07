#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int b, q;
int a[mak];

long long S;
long long suma[mak];

void sumowanie()
{
    suma[0] = a[0];

    for(int i = 1; i < b; i++)
    {
        suma[i] = suma[i - 1] + a[i];
    }
}

void wyrzucanie()
{
    int r = S % (b - 1);

    if(r > 0)
    {
        a[r]--;
    }
}

void zapytanie()
{
    long long k;
    cin>>k;
    k++;

    int l = 0, r = b;
    while(l < r)
    {
        int mid = (l + r) / 2;

        if(suma[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    
    int mid = (l + r) / 2;
    
    cout<<(mid == b ? -1 : mid)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>b>>q;
    for(int i = 0; i < b; i++)
    {
        cin>>a[i];
        S += 1LL * a[i] * i;
    }

    //*liczenie
    //pre procesing 
    wyrzucanie(); //tworzenie najwiekszej liczby
    sumowanie();

    //odpowiadanie na zapytania
    while(q--)
    {
        zapytanie();
    }
}