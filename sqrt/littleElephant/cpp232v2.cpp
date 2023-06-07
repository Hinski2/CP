//https://codeforces.com/contest/220/my link do rozwiazanego zadania 
//https://codeforces.com/profile/Hinski2 link do profilu

#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m;
int sqr;
int freq[mak], arr[mak];

void wczytanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	sqr = sqrt(n);

	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;

        if(x > mak)continue;
		freq[x]++;
	}
}

void liczenie()
{
    vector<int>l(m + 1, 0);
    vector<int>r(m + 1, 0);
    vector<int>ans(m + 1, 0);

    for(int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
    }

    for(int i = 1; i < mak; i++)
    {
        if(freq[i] >= i)
        {
            vector<int>f(n + 1, 0);
            for(int j = 1; j <= n; j++)
            {
                f[j] = f[j - 1] + (arr[j] == i);
            }

            for(int j = 1; j <= m; j++)
            {
                ans[j] += (f[r[j]] - f[l[j] - 1] == i);
            }
        }
    }

    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
	wczytanie();
    liczenie();
}