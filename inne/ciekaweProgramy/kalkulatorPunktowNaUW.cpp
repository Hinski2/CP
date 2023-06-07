#include <bits/stdc++.h>
using namespace std;
int w[5],i;
string p[5];

void sprawdzenie()
{
    string ans;
    {
        cout<<"czy zdajesz "<<p[i]<<"w poziome rozszeżonym T/N: ";
        cin>>ans;

        if(ans=="N"||ans=="n")
        {
            w[i]*=0.6;
        }
    }
}

int main()
{
    int wynik=0;

    p[0]="polski";
    p[1]="matematyka";
    p[2]="język obcy";
    p[3]="matematyka/informatyka";
    p[4]="przedmiot do wyboru";

    for(;i<5;i++)
    {
        cout<<"wynik z "<<p[i]<<" : ";
        cin>>w[i];
        if(i<3)sprawdzenie();
    }

    w[0]*=0.05;
    w[1]*=0.15;
    w[2]*=0.1;
    w[3]*=0.5;
    w[4]*=0.2;

    while(i--)
    {
        wynik+=w[i];
    }
    
    cout<<"twój wynik to "<<wynik<<" pkt"<<endl;

    // if(wynik>92)cout<<"dostałęś się"<<endl;
    // else cout<<"nie dostałęś się"<<endl;
}