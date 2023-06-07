//liczenie dla funkcju normal()
#include <bits/stdc++.h>
using namespace std;

long long wynik,subWynik;

int main()
{
    long long n,m;
    cin>>n>>m;
    long long brownSum,redSum=1,maxBrown,redIle=1;
    long long Min=((n-1)*n/2)%m;
    //*1 cześć 
    maxBrown=((n-2)*(n-1))/2-1;

    brownSum=(maxBrown*(maxBrown+1)/2);

    int multi=1;
    for(int i=3;i<=n-1;i++)
    {
        redSum=(redSum*multi)%m;
        if(redSum==0)break;
        multi++;
    }

    for(int i=3;i<=n-1;i++)//TODO polepsz 
    {
        redIle=(redIle*i)%m;
        if(redIle==0)break;
    }
    wynik+=(redSum*(brownSum%m))%m;

    //*2 część 
    wynik+=((redSum*brownSum)%m+redIle)%m;

    //*końcowe modulo
    wynik+=(Min*redIle*2)%m;
    wynik%=m;
    cout<<wynik<<endl;//TODO usuń
}
