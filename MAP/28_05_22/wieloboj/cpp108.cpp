#include <bits/stdc++.h>
using namespace std;

long long need;
int n;

void rozw()
{
	int multi, michal, najlepszy;
	cin>>multi>>michal>>najlepszy;

	if(michal <= najlepszy)
	{
		need += (long long)multi * (najlepszy + 1 - michal);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--)
	{
		rozw();
	}
	cout<<need<<endl;
}