#include <bits/stdc++.h>
using namespace std;

const int mak = 60 * 1000 + 15;
const int mak_dist = 1e9;
const double eps = 1 / 1e8;

int n;
int speed[mak], pos[mak];

bool sprawdzenie(long double t)
{
    long double l = -mak_dist, r = mak_dist;

    for(int i = 1; i <= n; i++)
    {
        long double naL = pos[i] - t * speed[i];
        long double naR = pos[i] + t * speed[i];

        l = max(l, naL);
        r = min(r, naR);

        if(l > r) return 0;
    }

    return 1;
}

double wyznaczanie()
{
    long double ans;
    long double l = 0, r = mak_dist, t;

    while(r - l > eps)
    {
        t = (l + r) / 2;

        bool s = sprawdzenie(t);

        if(s)
        {
            ans = t;
            r = t;
        }
        else
        {
            l = t;
        }
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(10);
	//wczytywanie
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>pos[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>speed[i];
	}

	cout<<wyznaczanie()<<"\n";
} 