#include <bits/stdc++.h>
using namespace std;

const int maksimum=500005;					//maksymalna liczba
const long long inf=1e18;					//zmienna pomocnicza

int n,s;									//ilość wgiazd, gwaizda z której zaczynamy
list<int>gwiazdy;							//lista gwiazd jaki trzeba odwiedzić 
int costL[maksimum+15],costR[maksimum+15];	//koszt lotu w lewo, koszt lotu w prawo
long long prefiksL[maksimum+15],prefiksR[maksimum+15];
long long sufiks[maksimum+15],optimalL[maksimum+15];

int main()
{	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	//magiczna linijka

	cin>>n>>s;									//wczytanie ilości gwiazd oraz nr gwiazdy z której startujemy

	for(int i=1;i<n;i++)
	{
		cin>>costL[i]>>costR[i];				//koszt teleportacji w lewo i prawo
		gwiazdy.push_back(i);					//stworzenie listy gwiazd które mamy odwiedzić 
	}
	gwiazdy.push_back(n);						//dodatkowe dodanie n ponieważ pętla ⇧ nie przyjmuje wartości n

	list<int>::iterator gwiazda=gwiazdy.begin();//iterator do chodzenia po gwiazdach 
	for(int i=1;i<s;i++)gwiazda++;				//sprawdzenie ile gwiazd trzeba przejżeć "oddzielnie" 

	for(int i=1;i<n;i++)			
	{
		prefiksL[i]=costL[i]+prefiksL[i-1];//przechodzenie po wszystkich kosztach teleportu w lewę i zapizywanie kosztu	
		prefiksR[i]=costR[i]+prefiksR[i-1];//przechodzenie po wszystkich kosztach teleportu w prawo i zapizywanie
	}

	for(int i=n-1;i>=1;i--)
	{
		sufiks[i]=sufiks[i+1]+min(costR[i],costL[i]);	//obliczasnie sufiksu dla znaleźlenia najlepszej kolejności odwiedzin 
		optimalL[i]=optimalL[i+1]+(costL[i]<=costR[i]);	//najlepsza ilość skoków w lewo 
	}

	long long bestCost=inf;			//najlepszy możliwy koszt wędrówki po planetach 
	int Length=-1;					//długość specjalnego sprawdzania 
	char lr=0;						//przyjmuje wortości 'l'||'r' mówi czy ciąg wygląda lllrl czy rrrlr				

	for(int i=1;i<s;i++)			//dodatkowe sprawdzenie jak się powinno iść
	{
		if(bestCost>prefiksL[i]+costR[i+1]+sufiks[i+2])	//sprawdzeni czy opłaca się iść w lewo
		{
			bestCost=prefiksL[i]+costR[i+1]+sufiks[i+2];
			Length=i;									//długość specjalnego sprawdzenia
			lr='l';
		}
	}
	for(int i=1;i<n-s+1;i++)
	{
		if(bestCost>prefiksR[i]+costL[i+1]+sufiks[i+2])	//sprawdzneie czy opłaca się iść w prawo
		{
			bestCost=prefiksR[i]+costL[i+1]+sufiks[i+2];
			Length=i;									//długość specjalnego sprawdzenia
			lr='r';
		}
	}

	cout<<bestCost<<"\n";			//wypisanie najlepszego kosztu
	for(int i=0;i<Length;i++)		//wypisanie specjalnego sprawdzenia
	{
		cout<<(*gwiazda)<<" ";		//na samym początku jest ustawiona na s
		if(lr=='r') 
		{
            auto del = gwiazda;
            gwiazda++;
            gwiazdy.erase(del);
        } 
		else 
		{
            auto del = gwiazda;
            gwiazda--;
            gwiazdy.erase(del);
        }
	}

	gwiazda=(lr=='r' ? --gwiazdy.end() : gwiazdy.begin());	//sprawdznie czy usuówać od tyłu
	cout<<(*gwiazda)<<" ";
	gwiazdy.erase(gwiazda);

	gwiazda=gwiazdy.begin();
	for(int i=0;i<optimalL[Length+2];i++)
	{
		gwiazda++;
	}

	for(int i=Length+2;i<n;i++)	//normalne wypisanie na podstawi tego co jest tańsze
	{
		cout<<(*gwiazda)<<" ";
		cout.flush();

		if(costL[i]<=costR[i])
		{
			auto del=gwiazda;
			gwiazda--;
			gwiazdy.erase(del);
		}
		else
		{
			auto del=gwiazda;
			gwiazda++;
			gwiazdy.erase(del);
		}
	}

	if(!gwiazdy.empty())
	{
		cout<<(*gwiazda)<<"\n";
	}
}