//liczenie dla funkcju pierwszy()
#include <bits/stdc++.h>
using namespace std;

long long  n,m,Max,focus;
long long wynik;

int main()
{
    cin>>n>>m;

	Max=n-1;//maxymalna liczba     
	focus=n-2;//ile liczb jest w rzędzie
    //poniżęj będzie inaczej trochę przez pętle 
    long long brownSum=(Max*(Max-1))/2,redSum=n-1,greenSum,x=n-1,maxBrown=n-2,redIle=n-1,Min=1;

    greenSum=(brownSum*redSum/x)%m;
    wynik+=greenSum;
    wynik+=redSum%m;
    
    for(int i=1;i<focus;i++)
    {
        x+=n-2-i;
        Min=((i+1)*(i+2)/2)%m;

        maxBrown+=n-2-i;
        brownSum=((maxBrown+1)*maxBrown)/2;

        redSum=(redIle*(n-1-i));

        if(redSum%x==0)
        {
            greenSum=((redSum/x)*brownSum)%m;
        }
        else if(greenSum%x==0)
        {
            greenSum=(redSum*(brownSum/x))%m;
        }
        else
        {
            double long a=redSum,mood=x;
            a/=mood;
            a=fmod(a,m);
            greenSum=a*brownSum+0.5;
            greenSum%=m;
        }

        if(redIle!=0)redIle=redIle*(redIle-1)%m;
        else break;

        //wyniki        
        wynik+=greenSum;
        wynik+=(redSum*Min)%m;
    }
    wynik%=m;
    cout<<wynik<<endl;
}
