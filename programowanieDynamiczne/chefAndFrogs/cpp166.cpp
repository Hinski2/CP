#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, r, q;
int zasieg[mak];
int pos[mak];
int colour[mak], c = 1;

vector<pair<int, int>>para;

void kolorowanie(int i)
{
    int idx = para[i].second;
    int pos = para[i].first;
    colour[idx] = c;

    if(i + 1 < para.size())
    {
        int next_pos = para[i + 1].first;

        if(next_pos - pos <= r)
        {
            kolorowanie(i + 1);
        } 
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> r >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> pos[i];

        para.push_back({pos[i], i});
    }

    //liczenie
    sort(para.begin(), para.end());

    for(int i = 0; i < para.size(); i++)
    {
        if(!colour[para[i].second])
        {
            kolorowanie(i);
            c++;
        }
    }

    while(q--)
    {
        int a, b;
        cin >> a >> b;

        if(colour[a] == colour[b])cout << "YES\n";
        else cout << "NO\n";
    }
}