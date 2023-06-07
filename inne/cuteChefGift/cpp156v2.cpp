#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int q;
int dzielnik[mak];

int naL[mak], naR[mak];
int arr[mak];

void sito()
{
    for(int i = 2; i * i <= mak; i++)
    {
        if(!dzielnik[i])
        {
            for(int j = i * i; j < mak; j += i)
            {
                dzielnik[j] = i;
            }
        }
    }
    for(int i = 2; i < mak; i++)
    {
        if(!dzielnik[i])
        {
            dzielnik[i] = i;
        }
    }
}

void wyznaczenie()
{
    for(int i = 0; i < mak; i++)
    {
        naL[i] = mak - 1;
        naR[i] = 0;
        arr[i] = 0;
    }

    int n; 
    cin>>n;
    
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin>>v;

        while(v > 1)
        {
            int p = dzielnik[v];

            naL[p] = min(naL[p], i);
            naR[p] = max(naR[p], i);
            
            v /= p;
        }
    }

    for(int i = 2; i < mak; i++)
    {
        int l = naL[i];
        int r = naR[i];

        if(l <= r)
        {
            arr[l]++;
            arr[r]--;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }

    for(int i = 1; i <= n; i++)
    {
        if(arr[i] == 0)
        {
            cout<<i<<"\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //preprocesing
    sito();

    //wczytywanie
    cin>>q;
    while(q--)
    {
        wyznaczenie();
    }
}