#include<bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 5;

int n, m, k;
int arr[mak];
int colour[mak], c;
int idx, idx_w_cyklu[mak];

vector<int>cykl[mak];


void zamiana(int l, int r)
{
    while(l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void kolorowanie(int v)
{
    colour[v] = c;
    idx_w_cyklu[v] = idx++;
    cykl[c].push_back(v);

    if(!colour[arr[v]])
    {
        kolorowanie(arr[v]);
    }
}

void obliczanie(int v)
{
    int i = (idx_w_cyklu[v] + (k % cykl[colour[v]].size())) % cykl[colour[v]].size();
    cout<<cykl[colour[v]][i]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    cin>>n>>m>>k;

    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    while(m--)
    {
        int l, r;
        cin>>l>>r;
        
        zamiana(l, r);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!colour[i])
        {
            idx = 0;
            c++;
            kolorowanie(i);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        obliczanie(i);
    }
}