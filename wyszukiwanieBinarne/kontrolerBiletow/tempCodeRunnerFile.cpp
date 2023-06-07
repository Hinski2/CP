#include <bits/stdc++.h>
using namespace std;

bool check(int ileWagonow, vector <int>v) 
{
	sort(v.begin(),v.end());
	int ileDone = 0;

	for(int i=0;i<v.size();i++) 
    {
		int proba=v[i];
        proba -= 2 * ileDone;
		ileDone += proba / 3;
	}

	return ileDone >= ileWagonow;
}


void wBinarne(int ileCzasow,int ileWagonow)
{
    vector<int>v(ileCzasow);
    for(int i=0;i<ileCzasow;i++)
    {
        cin>>v[i];
    }

    int l=0,r=ileCzasow;
    int Mid=(l+r)/2;

    while(l<r)
    {
        Mid=(l+r)/2;
        if(check(ileWagonow,vector<int>(v.begin(),v.begin()+Mid)))
        {
            r=Mid;      //true
        }
        else                       
        {
            l=Mid+1;    //false 
        }
    }
    //wypisywanie wyniku
    if(check(ileWagonow,vector<int>(v.begin(),v.begin()+(l+r)/2))==false)cout<<"NIE";
    else cout<<(l+r)/2;
}

int main()
{
    int ileTestow;
    ios_base::sync_with_stdio(0);

    scanf("%d",&ileTestow);
    while(ileTestow--)
    {
        int ileCzasow,ileWagonow;
        scanf("%d%d",&ileCzasow,&ileWagonow);
        wBinarne(ileCzasow,ileWagonow);
    }
}