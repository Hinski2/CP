#include <bits/stdc++.h>
using namespace std;

int length;
char znak[1000010];
int Distance;

int primeSubMax=0,primeSubMin=1e6+2;
int primeMaxStart=0,primeMinStart=0;
int primeMinFinish=0,primeMaxFinish=0;

void sprawdzenie(char litera)
{
    int sub=1,localPrimeSubMax=0,localPrimeSubMin=1e6+2;
    int Start=0,localPrimeMaxStart=0,localPrimeMinStart=0;
    int Finish=0,localPrimeMinFinish=0,localPrimeMaxFinish=0;

    bool find=false;

    for(int i=0;i<length;i++)
    {
        if(find)    //find == true
        {
            if(znak[i]==litera)
            {
                sub++;
            }
            else
            {
                find=false;
                Finish=i-1;
                if(sub>localPrimeSubMax)
                {
                    localPrimeSubMax=sub;
                    localPrimeMaxStart=Start;
                    localPrimeMaxFinish=Finish;
                }
                if(sub<primeSubMin)
                {
                    localPrimeSubMin=sub;
                    localPrimeMinStart=Start;
                    localPrimeMinFinish=Finish;
                }
            }
        }
        else        //find == false
        {
            if(znak[i]==litera)
            {
                find=true;
                sub=1;
                Start=i;
            }
        }
    }
    //ostatnie sprawdzenie 
    sub=length-1-Start;

    if(sub>localPrimeSubMax)
    {
        localPrimeSubMax=sub;
        localPrimeMaxStart=Start;
        localPrimeMaxFinish=Finish;
    }
    if(sub<primeSubMin)
    {
        localPrimeSubMin=sub;
        localPrimeMinStart=Start;
        localPrimeMinFinish=Finish;
    }
    //przyrównanie do maksymalnych 
    if(localPrimeSubMax>=primeSubMax)
    {
        //obliczanie
        int subDistance=0;

        if(localPrimeMinStart<localPrimeMaxStart)subDistance=localPrimeMaxFinish-localPrimeMinStart-1;
        else subDistance=localPrimeMinFinish-localPrimeMaxStart-1;
        
        if(subDistance>Distance)
        {
            Distance=subDistance;
            primeSubMax=localPrimeSubMax;
            primeSubMin=localPrimeSubMin;
            primeMaxStart=localPrimeMaxStart;
            primeMaxFinish=localPrimeMaxFinish;
            primeMinStart=localPrimeMinStart;
            primeMinFinish=localPrimeMinFinish;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);//magiczna linijka 

    //wczytywanie
    cin>>length;
    for(int i=0;i<length;i++)
    {
        cin>>znak[i];
    }

    //liczenie
    for(char c='a';c<'z';c++)
    {
        sprawdzenie(c);
    }

    cout<<Distance<<"\n";

}