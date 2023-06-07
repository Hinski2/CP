#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, q;
int arr1[mak], arr2[mak];
int s[mak][3][3];

int quest(int l, int r)
{
    if(s[r][0][1] - s[l - 1][0][1] != s[r][1][0] - s[l - 1][1][0]) return -1;
    if(s[r][0][2] - s[l - 1][0][2] != s[r][2][0] - s[l - 1][2][0]) return -1;
    if(s[r][2][1] - s[l - 1][2][1] != s[r][1][2] - s[l - 1][1][2]) return -1;

    int ans = 0;
    ans +=  s[r][0][1] - s[l - 1][0][1];
    ans +=  s[r][0][2] - s[l - 1][0][2];
    ans +=  s[r][2][1] - s[l - 1][2][1];

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n>>q;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin>>c;
        if(c == 'T')
        {
            arr1[i] = 0;
        }
        else if(c == 'A')
        {
            arr1[i] = 1;
        }
        else
        {
            arr1[i] = 2;
        }
    }
    for(int i = 0; i < n; i++)
    {
        char c;
        cin>>c;
        if(c == 'T')
        {
            arr2[i] = 0;
        }
        else if(c == 'A')
        {
            arr2[i] = 1;
        }
        else
        {
            arr2[i] = 2;
        }
    }

    //*liczenie
    s[0][arr1[0]][arr2[0]]++;

    for(int i = 1; i < n; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                s[i][x][y] = s[i - 1][x][y];
            }
        }

        s[i][arr1[i]][arr2[i]]++;
    }

    //*odpowiadanie na zapytania
    while(q--)
    {
        int l, r;
        cin>>l>>r;

        cout<<quest(l, r)<<"\n";
    }
}
