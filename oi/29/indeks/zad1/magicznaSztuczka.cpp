//zadanie magiczna sztuczka Jakub Iliński
#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e5+15;
int n;
int arr[maksimum],liczba[maksimum];

bool podSprawdzenie(int a)
{
	vector<int>vr;
	vector<int>vm;
	int rosnacy=0, malejacy=1000000;

	for(int i=1;i<=a;i++)
	{
		vr.push_back(arr[i]);
	}
	for(int i=a+1;i<=n;i++)
	{
		vm.push_back(arr[i]);
	}

	sort(vr.begin(),vr.end());
	sort(vm.begin(),vm.end());

	for(auto i:vr)	//rosnący
	{
		if(vr.size()==1)continue;

		if(rosnacy<liczba[i])
		{
			rosnacy=liczba[i];
		}
		else
		{
			return false;
		}
	}
	for(auto i:vm)	//malejący
	{
		if(vm.size()==1)continue;

		if(liczba[i]<malejacy)
		{
			malejacy=liczba[i];
		}
		else
		{
			return false;
		}
	}

	//udało się 
	cout<<"TAK\n";							//tak
	cout<<vr.size()<<" "<<vm.size()<<"\n";	//razmiar rosnacy, rozmiar malejacy
	for(auto i:vr)							//rosnący
	{
		cout<<liczba[i]<<" ";
	}
	cout<<"\n";
	for(auto i:vm)							//malejący
	{
		cout<<liczba[i]<<" ";
	}
	cout<<"\n";
	return true;
}

bool sprawdzenie()
{
	for(int i=1;i<=n;i++)
	{
		if(podSprawdzenie(i))
		{
			return true;		//znalazło wynik
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	//magiczna linijka
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		arr[i]=i;

		int x;
		cin>>x;
		liczba[i]=x;
	}

	do
	{
		if(sprawdzenie())return 0;
	}
	while(next_permutation(arr+1, arr+n+1));

	cout<<"NIE\n";
}

