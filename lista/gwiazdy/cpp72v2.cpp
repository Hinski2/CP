#include <bits/stdc++.h>
using namespace std;

int n,s;						//ilość gwiazd, gwiazda początkowa
list<int> trip;					//wynik, w jakiej kolejnosci będzie odwiedzać te planety 
pair<int,int>tepy[1000015];		//wartoście ile kosztuje tepanie sie w lewo i prawo
bool jakTepy[1000015];			//sprawdza czy tepnąć się w lewo(0) czy w prawo(1)
long long cost;
list<int> planetki; 
list<pair<int,int>>compres;
int point=s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	//magiczna linijka

	cin>>n>>s;				//wczytanie ilości gwiazd, indeksu gwiazdy z której startujemy
	for(int i=1;i<n;i++)	//wczytywanie kosztu tepania się 
	{
		cin>>tepy[i].first>>tepy[i].second;
	}

	priority_queue<pair<int,int>>q;	//tworzenie "fake" priority queue 
	if(s<=(n/2))					//jeśli s znajduje się przed połową ciągu 
	{
		for(int i=1;i<=s;i++)	
		{
			int x=((tepy[i].first-tepy[i].second)<0?(tepy[i].first-tepy[i].second)*(-1):(tepy[i].first-tepy[i].second));
			q.push({x*(-1),i});
		}

		int wierzcholek=q.top().second;
		jakTepy[wierzcholek]=1;				//prawo

		for(int i=s+1;i<n;i++)
		{
			if(tepy[i].first<tepy[i].second)
			{
				jakTepy[i]=0;
			}
			else
			{
				jakTepy[i]=1;
			}
		}
	}
	else									//s znajduje się za połową ciągu 
	{
		for(int i=s;i<n;i++)	
		{
			int x=((tepy[i].first-tepy[i].second)<0?(tepy[i].first-tepy[i].second)*(-1):(tepy[i].first-tepy[i].second));
			q.push({x*(-1),i});
			jakTepy[i]=1;
		}

		int wierzcholek=q.top().second;
		jakTepy[wierzcholek]=0;

		for(int i=1;i<s;i++)
		{
			if(tepy[i].first<tepy[i].second)
			{
				jakTepy[i]=0;
			}
			else
			{
				jakTepy[i]=1;
			}
		}	
	}

	int c=0;
	while(c+1<n)
	{
		c++;
		int nr=1;

		while(jakTepy[c]==jakTepy[c+1]&&c+1<n)
		{
			nr++;
			c++;
		}
		compres.push_back({jakTepy[c],nr});
	}

	//liczenie kosztu
	for(int i=1;i<n;i++)
	{
		if(jakTepy[i])	//prawo
		{
			cost+=tepy[i].second;
		}
		else			//lewo
		{
			cost+=tepy[i].first;
		}
	}

	//od tąd 
	for(int i=1;i<=n;i++)planetki.push_back(i);
	planetki.remove(s);
	trip.push_back(s);

	int ileTrip=0;
	while(ileTrip<n-1)
	{
		int strona=compres.front().first;
		int ileIsc=compres.front().second;
		compres.pop_front();
		ileTrip+=ileIsc;

		if(strona)	//prawa  strona 
		{
			int x=planetki.back();
			for(int i=x-ileIsc+1;i<=x;i++)
			{
				trip.push_back(i);
				planetki.pop_back();
			}
		}
		else		//lewa strona 0	
		{
			int x=planetki.front();
			for(int i=x+ileIsc-1;i>=x;i--)
			{
				trip.push_back(i);
				planetki.pop_front();
			}
		}	
	}
	//wypisanie wyniku
	cout<<cost<<"\n";
	for(auto i:trip)
	{
		cout<<i<<" ";
	}
	cout<<"\n";
}