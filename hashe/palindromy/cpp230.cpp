#include <bits/stdc++.h>
using namespace std;

const int mak = 205;
const int mod = 1e9 + 7;
const int p = 37;

int n;
string str;

int arr[mak];

int power[mak];
int hshL[mak], hshR[mak];

int Min[mak], Max[mak];

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> str;

    n = str.size();
    for(int i = 1; i <= n; i++)
    {
        char c = str[i - 1];
        arr[i] = c - 'a' + 1;
    }
}

void powerowanie()
{
    power[0] = 1;
    for(int i = 1; i < mak; i++)
    {
        power[i] = ( 1LL * power[i - 1] * p) % mod;
    }
}

void haszowanie()
{
    hshL[0] = 0;
    hshR[n + 1] = 0;
    
    for(int i = 1; i <= n; i++)
    {
        hshL[i] = (1LL * hshL[i - 1] * p + arr[i]) % mod;
    }

    for(int i = n; i >= 1; i--)
    {
        hshR[i] = (1LL * hshR[i + 1] * p + arr[i]) % mod;
    }
}

void wyznaczanie(int s)
{
    for(int i = s + 1; i <= n; i++)
    {
        int haszl = (hshL[i] - ((1LL * hshL[s - 1] * power[i - s + 1]) % mod)) % mod;
        int haszr = (hshR[s] - ((1LL * hshR[i + 1] * power[i - s + 1]) % mod)) % mod;

        if(haszl < 0) haszl += mod;
        if(haszr < 0) haszl += mod;
        
        if((i - s + 1) % 2 == 0 && haszl == haszr)
        {
            if(!Min[s]) Min[s] = i;
            Max[s] = i;
        }
    }
}

void wypisanieMin()
{
    int i = 1, space;
    while(i < n)
    {
        space = Min[i];
        for(int j = i - 1; j < space; j++)
        {
            cout << str[j];
        }
        cout << " ";
        i = space + 1;
    }
}

void wypisanieMax()
{
    int i = 1, space;
    while(i < n)
    {
        space = Max[i];
        for(int j = i - 1; j < space; j++)
        {
            cout << str[j];
        }
        cout << " ";
        i = space + 1;
    }
}
int main()
{
    wczytanie();
    powerowanie();
    haszowanie();
    for(int i = 1; i <= n; i++)
    { 
        wyznaczanie(i);
    }
    wypisanieMax();
    wypisanieMin();
}