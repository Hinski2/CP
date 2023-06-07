#include <bits/stdc++.h>
using namespace std;

int ile;
int budynek[500010];

bool sprawdzenie(int Max)
{
    int i=1;
    for(int row=1;row<=Max;row++)       //przechodzi po każdym rzędzie
    {
        int sumInRow=0;                 //suma żołnierzy w rzędzie
        while(sumInRow<Max)             //jeśli jest możliwe dostawienie nawet jednego żołnierza
        {
            if(sumInRow+budynek[i]<=Max) //jeśli da się dostawić następną osobę 
            {
                if(i==ile)return true;      //jeśli wszyscy żołnierze już są dostawieni
                sumInRow+=budynek[i];   //dostawienie do rzędu
                i++;                    
            }
            else
            {
                break;                  //jeśli nie da się dostawić idzie do następnego rzędu
            }
        }
    }
    return false;
}



int main()
{
    scanf("%d",&ile);
    for(int i=1;i<=ile;i++)
    {
        cin>>budynek[i];
    }
    //*liczenie
    int l=0,r=1e9;
    int Mid=(l+r)/2;

    while(l<r)
    {
        if(sprawdzenie(Mid)==true)  //możliwe
        {
            r=Mid;
        }
        else                        //nieMożliwe
        {
            l=Mid+1;
        }
        Mid=(l+r)/2;
    }
    printf("%d",Mid);
}