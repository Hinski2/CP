#include <bits/stdc++.h>
#include "dna.h"

using namespace std;

const int mak = 1e5 + 15;

int n, q;
int arr1[mak], arr2[mak];
int s[mak][3][3];

int get_distance(int x, int y)
{
    x++;
    y++;

    int v01 = s[y][0][1] - s[x - 1][0][1];
    int v10 = s[y][1][0] - s[x - 1][1][0];

    int v02 = s[y][0][2] - s[x - 1][0][2];
    int v20 = s[y][2][0] - s[x - 1][2][0];

    int v21 = s[y][2][1] - s[x - 1][2][1];
    int v12 = s[y][1][2] - s[x - 1][1][2];

    if(v01 + v02 != v10 + v20) return -1;
    if(v10 + v12 != v01 + v21) return -1;
    if(v21 + v20 != v12 + v02) return -1;

    int ans = 0;

    ans += min(v01, v10);
    ans += min(v02, v20);
    ans += min(v12, v21);

    //jeśli jest cykl 0 -> 1 -> 2 -> 0
    ans += 2 * abs(v01 - v10);

    return ans;
}


void init(string a, string b)
{
    //*wczytywanie
    n = a.size();

    for(int i = 0; i < n; i++)
    {
        char c = a[i];

        if(c == 'T')
        {
            arr1[i + 1] = 0;
        }
        else if(c == 'A')
        {
            arr1[i + 1] = 1;
        }
        else
        {
            arr1[i + 1] = 2;
        }
    }
    for(int i = 0; i < n; i++)
    {
        char c = b[i];

        if(c == 'T')
        {
            arr2[i + 1] = 0;
        }
        else if(c == 'A')
        {
            arr2[i + 1] = 1;
        }
        else
        {
            arr2[i + 1] = 2;
        }
    }

    //*liczenie
    for(int i = 1; i <= n; i++)
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
}

// int main()
// {
//     cin>>n>>q;

//     string a, b;
//     cin>>a>>b;

//     init(a, b);

//     while(q--)
//     {
//         int x, y;
//         cin>>x>>y;

//         cout<<get_distance(x, y)<<"\n";
//     }
// }