#include <bits/stdc++.h>
using namespace std;

const int MAX= 2*1000*1000; 
long long arr[MAX+15];
bool barr[MAX+15];
int n,a,b;

void liczonko()//sito Eratostenesa
{
    for(int i=2;i<=MAX;i++)
    {
        if(barr[i]==false)// liczba pierwsza
        {
            arr[i]=arr[i-1]+i;

            for(int j=i;j<=MAX;j+=i)
            {
                barr[j]=true;
            }
        }
        else//nie liczba pierwsza
        {
            arr[i]=arr[i-1];
        }
    }
}

int main()
{
    liczonko(); //obliczanie sum prefiksowych dla liczb pierwszych od 2 do MAX
    scanf("%d",&n);//wczyrtwanie ilości zapytań
    for(int i=0;i<n;i++)//odpowiadania na każde pytanie 
    {
        scanf("%d%d",&a,&b);
        long long wynik=arr[b]-arr[a-1];//a-1 dlatego że a także należy do przediału
        printf("%lld\n",wynik);
    }
}