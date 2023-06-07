#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, k;
int arr[mak];

vector<pair<int, int>>quest[350];

void dodanie(int co_ile)
{
    vector<int>v(mak, 0);

    for(auto u: quest[co_ile])
    {
        int od = u.first;
        int ile = u.second;

        v[od]++;
        v[od + co_ile * ile]--;
    }

    for(int i = 1; i <= n; i++)
    {
        arr[i] += v[i];
        v[i + co_ile] += v[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;

    const int sqr = sqrt(n);

    while(k--)
    {
        int od, ile, co_ile;
        cin>>od>>ile>>co_ile;

        if(co_ile > sqr)
        {
            int dod = od;
            for(int i = 1; i <= ile; i++)
            {
                arr[dod]++;
                dod += co_ile;
            }
        }
        else
        {
            quest[co_ile].push_back({od, ile});
        }
    }

    for(int i = 1; i <= 340; i++)
    {
        if(quest[i].size())
        {
            dodanie(i);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }

}