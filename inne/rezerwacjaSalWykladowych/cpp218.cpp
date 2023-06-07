#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>>przedzialy;

void wczytanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	przedzialy.push_back({0, 0}); //dodanie fałszywego wykładwce

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		przedzialy.push_back({b, a});	//przedziały{koniec, początek}
	} 
}

int wBin(int granica)
{
	int l = 0, r = przedzialy.size() - 1, mid;

	while(l < r)
	{
		mid = (l + r + 1) / 2;

		if(przedzialy[mid].first > granica)
		{
			r = mid - 1;
		}
		else
		{	
			l = mid;
		}
	}

	return l;
}

int obliczanie()
{	
	sort(przedzialy.begin(), przedzialy.end()); //sortowanie przedziałów
	vector<int>czas(przedzialy.size());
	

	for(int i = 1; i < przedzialy.size(); i++)
	{
		int t1 = czas[i - 1];	//nie bierzemy tego wykładowcy

		int granica = wBin(przedzialy[i].second);
		int t2 = czas[granica] + przedzialy[i].first - przedzialy[i].second;

		czas[i] = max(t1, t2);
	}

	return czas.back();
}

int main()
{

	wczytanie();
	cout << obliczanie() << "\n";
}