//zadanie DOM Jakub iliński 3LA szkoły salezjańskie Szczecin 
#include <bits/stdc++.h>
using namespace std;

vector<long long> ciag(90,-1);
tuple<long long,int,int>drzewo[75];
vector<long long>ban;

long long sprawdzenie(long long n)// fibonaci
{
    if(n==1)return 1;
    if(n==2)return 2;

    if(ciag[n]!=-1) return ciag[n];
    else return ciag[n]=sprawdzenie(n-1)+sprawdzenie(n-2);
}

bool inside(long long liczba,int sumka,int MAX)//sprawdzaenie czy liczba == liczbie z ciągu 
{
    for(int i=1;i<=MAX;i++)
    {
        if(liczba==ciag[i])
        {
            sumka+=i+1;
            cout<<sumka<<"\n";
            return true;
        }
    }
    return false;
}
int obliczanie(long long liczba,int Max,int MaxS)
{
    int iDrzewo=0;

    while(iDrzewo>=0)
    {
        int i=get<1>(drzewo[iDrzewo]);

        if(liczba%ciag[i]==0&&i>1)//jest podzielny 
        {   
            if (find(ban.begin(), ban.end(), liczba) != ban.end() )//jeśłi znajdzie
            {
                iDrzewo--;
                liczba=get<0>(drzewo[iDrzewo]);
                get<1>(drzewo[iDrzewo])--;//zmniejszanie i o 1
                continue;
            }                                    
            //TODO moze MaxS-iDzrewo
            if(inside(liczba,get<2>(drzewo[iDrzewo]),MaxS)==true)return 0;//if tak to koniec(inside() wypisze wynik)
            //kreacja nizszej gałęzi
            liczba/=ciag[i];
            iDrzewo++;
            if(get<0>(drzewo[iDrzewo])==liczba)//jeśłi taki odłam istniał,zastąpienie
            {
                drzewo[iDrzewo]={liczba,i,(get<2>(drzewo[iDrzewo-1])+i+1)};
            }
            else// nie istniał 
            {                                //suma
                drzewo[iDrzewo]={liczba,Max,(get<2>(drzewo[iDrzewo-1])+i+1)};
            }
            
        }
        else //nie jest podzielny 
        {
            get<1>(drzewo[iDrzewo])--;
            if(i<=2)
            {
                ban.push_back(liczba);
                iDrzewo--;
                liczba=get<0>(drzewo[iDrzewo]);
                get<1>(drzewo[iDrzewo])--;//zmniejszanie i o 1
            }
        }

    }
    cout<<"NIE\n"; 
    return 0;
}

int main() 
{
//*liczby ciągu-obliczanie
	ciag[1]=1;
    ciag[2]=2;
    sprawdzenie(88);
//*poczatek wczytywania
	long long liczba;
	scanf("%lld",&liczba);
    if(liczba==1)
    {
        cout<<"1\n";
        return 0;
    }

//*oblicznie możliwości 
    int mozliwosci=0,Max,MaxS;
    bool pierwszy=false,pierwszyS=false;
    for(int z=88;z>1;z--) //sprawdznie czy warto zaczynać
    {
        if(pierwszyS==false&&ciag[z]<=liczba)
        {
            MaxS=z;
            pierwszyS=true;
        }
        if(liczba%ciag[z]==0)
        {
            if(pierwszy==false)
            {
                Max=z;
                drzewo[0]={liczba,Max,-1};
                pierwszy=true;
            }
        }
        if(z==2)//slprawdzenie czy już 1 liczba nie dzieli się przez nic i nie należy do ciągu 
        {
            if(get<1>(drzewo[0])==0)
            {
                cout<<"NIE\n";
                return 0;
            }
        }
    }
//*początek tworzenia i obliczania drzewa
    obliczanie(liczba,Max,MaxS);
}