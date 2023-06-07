#include<bits/stdc++.h>
using namespace std;

const int mak = 10;

int arr[mak];
int n, m, k;
int ans[mak];

bool odwiedzny[mak];

vector<int>cykl;

void zamiana(int l, int r)
{
    int ile = r - l + 1;
    int mid = ile / 2;

    for(int i = 0; i < mid; i++)
    {
        swap(arr[l + i], arr[r - i]);
    }
}

void sprawdzenie(int v)
{
    odwiedzny[v] = true;

    cykl.push_back(v);

    if(!odwiedzny[arr[v]])
    {
        sprawdzenie(arr[v]);
    }
}

void znajdownie()
{
    for(int i = 1; i <= n; i++)
    {
        if(!odwiedzny[i])
        {
            sprawdzenie(i);

            for(int j = 0; j < cykl.size(); j++)
            {
                ans[cykl[j]] = cykl[(j + k % cykl.size()) % cykl.size()];
            }

            cykl.clear();
        }
    }
}

int main()
{
    cin>>n>>m>>k;

    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        int l, r;
        cin>>l>>r;

        zamiana(l, r);
    }

    //znajdownie cykli
    znajdownie();

    //wypisanie
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    cout<<endl;
} 