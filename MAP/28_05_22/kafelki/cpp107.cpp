#include<bits/stdc++.h>
using namespace std;

long long a, b, c, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b>>c>>k;

	long long basen = 0;

	basen += 2 * a * c;
	basen += 2 * b * c;

	k *= k;

	long double w = (long double)basen / k;
	cout<<ceil(w)<<endl;
}