#include <bits/stdc++.h>
using namespace std;

const int maks=10000;
int n,m;
string s[1015];
bitset<maks>liczba;
vector<int>pin[10];

bitset<maks> sprawdzenie(const string &s)
{
	for(int i=0;i<10;i++)
	{
		pin[i].assign(s.size()+1,-1);//podniemia s.size()+1 pierwszych elementów pinu na nowe komórki
		
	}
	
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=0;j<10;j++)
		{
			pin[j][i]=(j==s[i]-'0' ? i : pin[j][i+1]);
		}
	}
	
	bitset<maks>Find;
		
	for(int maska=0;maska<maks;maska++)
	{
		int mask=maska;
		int lastPosition=0;
		bool succed=true;
		
		for(int i=0;i<4;i++)
		{
			int digit=mask%10;
			int candidate=pin[digit][lastPosition];
			
			if(candidate==-1)
			{
				succed=false;
				break;
			}
			
			lastPosition=candidate;
			mask/=10;
		}
		
		if(succed)
		{
			Find[maska]=true;
		}
	}
	return Find;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
    cin>>n;
	liczba.set();
	
	for(int i=1;i<=n;i++)
	{
		cin>>m>>s[i];
		liczba&=sprawdzenie(s[i]);	
	}
	cout<<liczba.count()<<"\n";
}
