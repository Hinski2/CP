#include <bits/stdc++.h>
using namespace std;

int n;              //liczba osób 
char osoba[20][20]; //zmienna przetrzymująca ciąg zer i jedynek  
bool use[20];       //zmienna potrzebna do tworzenia podzbiorów 
vector<int>ans;     //wynik 

int main()
{
    ios_base::sync_with_stdio(0);//magiczna linijka 
    
    cin>>n;//ilosć osób
    for(int x=1;x<=n;x++)//wczytywanie ciągu zer i jedynek  
    {
        for(int y=1;y<=n;y++)
        {
            cin>>osoba[x][y];
        }
    }

    for(int x=1;x<=(1<<n);x++)//tworzenie wszystkich możliwych kombinacji-->1 ->x2 ->12 ->xx3 ->1x3 ->x23->123...
	{
        vector<int>check;//vector w którym przechowuje liczby które bede sprawdzał 

        //tworzenie kombinacji 
		if(use[1]==false)   //use[1]==false 
		{
			use[1]=true;
		}
		else                //use[1]==true 
		{
			int i=1;
			while(use[i]==true)
			{
				use[i]=false;
				i++;
			}
			use[i]=true;
		}

        for(int i=1;i<=n;i++)//dodaje liczby z kombinacji do vectora 
        {
            if(use[i]==true)check.push_back(i);
        }

        //sprawdzanie kombinacji
        if(ans.size()<check.size())//jeśli obecny wynik zawiera mniej liczb niż wynik do sprawdzenia 
        {
            bool zamiana=true;
            for(auto x: check)
            {
                if(zamiana==false)break;//sprawdzenie czy zamiana jest możliwa 

                for(auto y: check)
                {
                    if(osoba[x][y]!='0')//sprawdzenie czy osoby z kombinacji się nie lubią 
                    {   
                        zamiana=false;  //jesli się nie lubią to zamiana jest niemożliwa
                        break;          //więc dalsze sprawdzanie jest zbędne 
                    }
                }    
            }
            if(zamiana==true)ans=check;//podmiana wyniku 
        }
	}
    //wypisanie wyniku
    cout<<ans.size()<<"\n"; //wypisanie sumy możliwości 
    for(auto i:ans)
    {
        cout<<i<<" ";       //wypisanie itej możliwości 
    }
}