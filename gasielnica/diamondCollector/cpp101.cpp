#include<bits/stdc++.h>
using namespace std; 

const int mak = 50015;

int ans;
int n, k;
int arr[mak];
int max_ogon[mak], max_glowa[mak];

int sumowanie()
{
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, max_glowa[i] + max_ogon[i + 1]);
	}
	return ans;
}

void maksowanie()
{
	int maks = 0;
	for(int i = n; i > 0; i--)
	{
		maks = max(maks, max_ogon[i]);
		max_ogon[i] = maks; 
	}
}
void gasielnica()
{
	int l = 1, r = 0;
	int wynik = 0;

	while(l <= n)
	{
		if(arr[r + 1] - arr[l] <= k && r < n)
		{
			r++;
			wynik++;
			max_glowa[r] = wynik;
		}
		else
		{
			max_ogon[l] = wynik;
			l++;
			wynik--;
		}
	}
}

int main()
{
	freopen("diamond.in","r", stdin);
	freopen("diamond.out","w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie danych 
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
	{
		cin>>arr[i];
	}

	//sortowanko
	sort(arr + 1, arr + n + 1);

	gasielnica();
	maksowanie();
	cout<<sumowanie()<<"\n";
}