#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n;
int p, q;
int x, y;

string S;

int bilans[mak], s;
int preMin[mak], sufMin[mak];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //* wczytywanie
    cin>>n>>p>>q>>x>>y;
    cin>>S;
    
    bilans[0] = s;
    for(int i = 0; i < n; i++)
    {
        char &c = S[i];
        if(c == '+')
        {
            s++;
        }
        else
        {
            s--;
        }

        bilans[i + 1] = s;
    }

    preMin[0] = bilans[0];
    for(int i = 1; i <= n; i++)
    {
        preMin[i] = min(preMin[i - 1], bilans[i]);
    }
    
    sufMin[n] = bilans[n];
    for(int i = n - 1; i >= 0; i--)
    {
        sufMin[i] = min(sufMin[i + 1], bilans[i]);
    }

    int toAdd = q - (s + p);
    int ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        int cMin = (i == 0 ? p + preMin[n] : min(p + bilans[n] - bilans[i] + preMin[i - 1], p + sufMin[i] - bilans[i]));
        int rezultat = (n - i) % n * y;

        if(cMin >= 0)
        {
            rezultat += abs(toAdd / 2) * x;
        }
        else
        {
            if(toAdd >= 0)
            {
                rezultat += toAdd / 2 * x;
                rezultat += max(0, (-(cMin + toAdd) + 1) / 2 * 2) * x;
            }
            else
            {
                rezultat += -toAdd / 2 * x;
                rezultat += (-cMin + 1) / 2 * 2 * x;
            }
        }

        ans = min(ans, rezultat);
    }

    cout<<ans<<"\n";
}