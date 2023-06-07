#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n;
int arr[mak], p, d;

bool znaleziony_d, znaleziony_p;

int liczenie()
{
    if(!znaleziony_d)
    {
        return 1;
    }

    int ans = 0;
    int rosnie = (arr[p] < arr[d] ? 1 : 0);

    if(!rosnie) ans++;

    for(int i = 2; i <= n; i++)
    {
        if(rosnie)
        {
            if(arr[i - 1] > arr[i])
            {
                ans++;
                rosnie = false;
            }
        }
        else
        {
            if(arr[i - 1] < arr[i])
            {
                ans++;
                rosnie = true;
            }
        }
    }

    return ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if(!znaleziony_p)
        {
            znaleziony_p = true;
            p = i;
        }
        else if(arr[i] != arr[p] && !znaleziony_d)
        {
            znaleziony_d = true;
            d = i;
        }
    }

    //liczenie
    cout << liczenie() << "\n";
}