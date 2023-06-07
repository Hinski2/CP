#include <bits/stdc++.h>
using namespace std;

const int mak = 105; 

int n;
bool arr[mak];
int ans, pre[mak], suf[mak];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    for(int i = n; i > 0; i--)
    {
        suf[i] = suf[i + 1] + arr[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int zamiana = 0;
        for(int j = i; j > 0; j--)
        {
            if(arr[j] == 0) zamiana++;
            ans = max(ans, zamiana + pre[j - 1] + suf[i + 1]);
        }
    }

    cout << ans << "\n";
}