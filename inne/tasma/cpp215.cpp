#include <bits/stdc++.h>
using namespace std;

void liczenie()
{
    int n, ans = 0;
    cin >> n;

    int a = 0, b = 0, a_pos = 0, b_pos = 0;

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if(b == 0)
        {
            if(a == x) continue;
            if(a == 0)
            {
                a = x;
                a_pos = i;
            }
            else
            {
                b = x;
                b_pos = i;
                ans = b_pos - a_pos;
            }
        }
        else
        {
            if(x != a)
            {
                ans = i - a_pos;
            }
            else
            {
                ans = max(ans, i - b_pos);
            }
        }
    }

    if(b_pos == 0) cout << "BRAK\n";
    else cout << ans << "\n";
}

int main()
{   
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    int q;
    cin >> q;

    // liczenie
    while(q--)
    {
        liczenie();
    }
}