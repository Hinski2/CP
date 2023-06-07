//zadanie UKL Jakub iliński 3LA szkoły salezjańskie Szczecin 
#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long wynik,wynikNormal,maxRedIle;

void pierwszy()
{
	unsigned long long subWynik=0;
	unsigned long long focus=n-2,Max=n-1;
    unsigned long long brownSum=(Max*(Max-1))/2,redSum=n-1,x=n-1,maxBrown=n-2,Min=1;

	unsigned long long mod=(x%m)*m;
	if(mod!=0)
	{
		subWynik+=((brownSum%mod)*(redSum%mod))%mod/(x%m);
	}
	else
	{
		unsigned long long altMod=x*m;
		subWynik+=((brownSum%altMod)*(redSum%altMod))%altMod/x;
	}
    subWynik+=redSum%m;
	subWynik%=m;
	wynik+=subWynik;
	wynik%=m;
	subWynik=0;

    for(unsigned long long i=1;i<focus;i++)
    {
        x+=(n-2-i%m);
		mod=(x%m)*m;
		//*mod jest różne od zera 
		if(mod!=0)
		{
			maxBrown+=(n-2-i%m);
	        Min=(((i+1)%mod)*((i+2)%mod)/2)%mod;

        	brownSum=((((maxBrown+1)%m)*(maxBrown%m))/2)%mod;
        	redSum=((redSum%m)*((n-1-i)%m))%mod;

        	//wyniki        
			subWynik+=((brownSum)*(redSum))%mod/(x%m);
	        subWynik+=(redSum*Min)%m;
			x%=m;
		}

		//*mod jest równe zeru  
		else
		{
			long long altMod=x*m;
			maxBrown+=(n-2-i%m);
	        Min=(((i+1)%altMod)*((i+2)%altMod)/2)%altMod;

        	brownSum=((((maxBrown+1)%altMod)*(maxBrown%altMod))/2)%altMod;
        	redSum=((redSum%altMod)*((n-1-i)%altMod))%altMod;

        	//wyniki        
			subWynik+=(brownSum*redSum)%altMod/x;        
			subWynik+=(redSum*Min)%altMod;
			x%=m;
		}
	    subWynik%=m;
		wynik+=subWynik;
		wynik%=m;
		subWynik=0;
    }
}

void normal()
{
    unsigned long long brownSum,redSum=1,maxBrown,redIle=1,multi=1;
    unsigned long long Min=((n-1)*n)/2;
    //*1 cześć 

    maxBrown=((n-2)*(n-1))/2-1;

    brownSum=((maxBrown%(m*2))*(maxBrown+1%(m*2)))%(m*2);
	brownSum/=2;

    for(unsigned long long i=3;i<=n-1;i++)
    {
        redSum=(redSum*(multi%m))%m;
        if(redSum==0)
		{
			break;
		}
        multi++;
    }

    for(unsigned long long i=3;i<=n-1;i++)
    {
        redIle=(redIle*i)%m;
        if(redIle==0)break;
    }
	maxRedIle=(redIle*2)%m;
    wynikNormal+=(redSum*(brownSum%m))%m;

    //*2 część 
    wynikNormal+=((redSum*brownSum)%m+redIle)%m;

    //*końcowe modulo
    wynikNormal+=(Min*redIle*2)%m;
    wynikNormal%=m;
	wynik+=wynikNormal;
}

void unnormal()
{
	unsigned long long subWynik=0,subWynikNormal=(wynikNormal+(maxRedIle*(n-1%m)%m))%m;
	unsigned long long focus=n-2, Max=n-1, Min=1;
    unsigned long long brownSum=(Max*(Max-1))/2, redSum=n-1,x=n-1, maxBrown=n-2, greenSum=0;
	unsigned long long ban=n*(n-1);

	//*część pierwsza
	//odejmuje tylko bana od normala 
	long long czy=((long long)subWynikNormal%m)-((long long)ban%m)%m;

	if( czy>0 )
	{
		subWynik+=czy;
	}
	else if( czy<0 )
	{
		subWynik+=m+czy;
	}

	//*część druga
	unsigned long long mod=(x%m)*m,odejmowanko=0;

	//obliczenie greenSum
	if(mod!=0)
	{
		greenSum=((brownSum%mod)*(redSum%mod))%mod/(x%m);
	}
	else
	{
		unsigned long long altMod=x*m;
		greenSum=((brownSum%altMod)*(redSum%altMod))%altMod/x;
	}
	
	odejmowanko=(((redSum%m)*(ban+Min)%m)+(greenSum%m))%m;
	subWynikNormal+=(maxRedIle*(n-1))%m;
	subWynikNormal%=m;

	czy=((long long)subWynikNormal)-((long long)odejmowanko%m)%m;

	if( czy>0 )
	{
		subWynik+=czy;
	}
	else if( czy<0 )
	{
		subWynik+=m+czy;
	}

	//wynikowanie 
	subWynik%=m;
	wynik+=subWynik;
	subWynik=0;
	//*część trzecia
	for(unsigned long long i=1;i<focus-1;i++)//dla n >= 5
	{
		x+=(n-2-i%m);
		mod=(x%m)*m;
	    //podczesć 1 - obliczanie greenSum
		//*mod jest różne od zera 
		if(mod!=0)
		{
			maxBrown+=(n-2-i%m);
	        Min=(((i+1)%mod)*((i+2)%mod)/2)%mod;

        	brownSum=((((maxBrown+1)%m)*(maxBrown%m))/2)%mod;
        	redSum=((redSum%m)*((n-1-i)%m))%mod;

			greenSum=((brownSum)*(redSum))%mod/(x%m);
			x%=m;
		}

		//*mod jest równe zeru  
		else
		{
			long long altMod=x*m;
			maxBrown+=(n-2-i%m);
	        Min=(((i+1)%altMod)*((i+2)%altMod)/2)%altMod;

        	brownSum=((((maxBrown+1)%altMod)*(maxBrown%altMod))/2)%altMod;
        	redSum=((redSum%altMod)*((n-1-i)%altMod))%altMod;

			greenSum=(brownSum*redSum)%altMod/x;
			x%=m;        
		}

	    //pod czesć 2
		Min%=m;
		odejmowanko=(((redSum%m)*(ban+Min)%m)+(greenSum%m))%m;
		subWynikNormal+=(maxRedIle*(n-1))%m;
		subWynikNormal%=m;

		//podczęsć 3
		czy=((long long)subWynikNormal-(long long)odejmowanko)%m;

		if( czy>0 )
		{
			subWynik+=czy;
		}
		else if( czy<0 )
		{
			subWynik+=m+czy;
		}
		//wynikowanie 
		subWynik%=m;
		wynik+=subWynik;
		subWynik=0;
		wynik%=m;
	}
}

int main() 
{
	//wczytywanie
	cin>>n>>m;

	//*szybkie rozwiązanie dla n == 2 i n == 3
	//*poniewaz wzór na nie działa dla n <=3
	if(n==1)
	{
		cout<<1%m<<"\n";
		return 0;
	}
	if(n==2)
	{
		cout<<1%m<<"\n";
		return 0;
	}
	//*obliczanie sumy dla róznych plrzypadków
	pierwszy();	//sprawdzenie i wyznaczeni sumy dla 1 przypadku
	normal();	//normalne sprawdzenie 
	unnormal();	//nienormalne sprawdzenie

	//ostatnie obliczenia na sumie i wypisywanko
	wynik=wynik%m;
	cout<<wynik<<"\n"; 
}