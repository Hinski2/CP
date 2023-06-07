#include <bits/stdc++.h>
using namespace std;

const int mak = 40;

int n, s;
int arr[mak];
int ans1, ans2;
int ans[mak];


map<int, int> sum;

void sprawdzenie(int suma, int i)
{
    if(sum.find(s - suma) != sum.end())
    {
        //ans nie będzie binarny
        ans1 = sum[s - suma]; 
        ans2 = i;
    }
}
int main()
{
    //wczytywanie
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &s);

    //liczenie 
    //licznie 1 części 
    for(int i = 0; i < 1 << (n / 2); i++) //od 0 do połowy 
    {
        int mask = i;
        int suma = 0;
        int idx = 0;

        while(mask)
        {
            if(mask % 2)
            {
                suma += arr[idx];
            }
            idx++;
            mask /= 2;
        }
        sum[suma] = i;
    }

    //liczenie 2 części
    for(int i = 0; i < 1 << ((n + 1) / 2); i++) //od połowy + 1 do końca 
    {
        int mask = i;
        int suma = 0;
        int idx = n / 2;

        while(mask)
        {
            if(mask % 2)
            {
                suma += arr[idx];
            }
            idx++;
            mask /= 2;
        }
        sprawdzenie(suma, i); 
    }

    //konwertowanie ans1 i ans2 na sys dwujkowy 
    int idx = 0;

    while(ans1)
    {   
        if(ans1 % 2)
        {
            ans[idx] = 1;
        }
        idx++;
        ans1 /= 2;
    }
    idx = (n / 2); // by działało dla ans1 i ans2 o rózńych długościach 
    while(ans2)
    {
        if(ans2 % 2)
        {
            ans[idx] = 1;
        }
        idx++;
        ans2 /= 2;
    }
    
    //wypisanie wyniku
    for(int i = 0; i < n; i++)
    {
        printf("%d", ans[i]);
    }
}