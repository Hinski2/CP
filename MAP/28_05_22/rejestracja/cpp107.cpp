#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin>>s;
	char ans = 'z';
	for(int i = 0; i < s.length(); i++)
	{
		ans = min(ans, s[i]);
	}
	cout<<ans<<endl;
}