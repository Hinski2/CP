#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e6+15;

int n,home;
long long onLeft,onRight,ansCost;
pair<int,int>cost[maksimum];

list<int>ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//magiczna linijka

	cin>>n>>home;//wczytanie ilości gwiazd i tej z której zaczynamy;

	if(n==1)
	{
		cout<<"0\n";
		cout<<home;
		return 0;
	}

	for(int i=1;i<n;i++)
	{
		cin>>cost[i].first>>cost[i].second;//wczytanie i'tego kosztu telwportacji w leto i w prawo
	}

	onRight=n-home;		//ile ma gwiazd na lewo 
	onLeft=n-onRight-1;	//ile ma gwiazd na prawo

	int wlewo=home-1,wprawo=home+1;//idx gwiazdy na prowo od home i na lewo od home(przyda się) 

	ans.push_back(home);
	for(int i=1;i<n;i++)
	{
		//sprawdzenie czy da się iść w danym kierunku
		if(!onRight)	//nie da się iść w prawo
		{
			ansCost+=cost[i].first;
			ans.push_back(wlewo);
			wlewo--;
			onLeft--;
			continue;
		}
		else if(!onLeft)//nie da się iść w lewo
		{
			ansCost+=cost[i].second;
			ans.push_back(wprawo);
			wprawo++;
			onRight--;
			continue;
		}

		//normalne sprawdzenie co się bardziej opłaca 
		if(cost[i].first<cost[i].second)
		{
			ansCost+=cost[i].first;
			ans.push_back(wlewo);
			wlewo--;
			onLeft--;
		}
		else
		{
			ansCost+=cost[i].second;
			ans.push_back(wprawo);
			wprawo++;
			onRight--;
		}
	}


	//wypisanie wyników
	cout<<ansCost<<"\n";
	for(auto i:ans)
	{
		cout<<i<<" ";
	}

}