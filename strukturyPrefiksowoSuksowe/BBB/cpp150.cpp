#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n;
int p, q;
int x, y;

int wyciag[mak];
int m[mak], s;

int pre[mak], pre_min[mak], suf[mak] ;

void sufikso_prefiksy()
{
    pre[0] = p;
    pre_min[0] = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + wyciag[i];
        pre_min[i] = min(pre_min[i - 1], pre[i]);
    }

    suf[n + 1] = p;
    for(int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + wyciag[i];
    }

    int idx = 1;
    for(int i = n; i >= 1; i--)
    {
        m[idx] = pre_min[i] + suf[i + 1] - p;
        idx++;
    }

}

int liczenie()
{
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        int wynik;
        int presuniecia = (i - 1) * y;
        int w = 0;

        if(m[i] < 0 )
        {
            w = ceil(-m[i] / 2);
        }

        if(q - p < s + 2 * w)
        {
            wynik = w + (s + 2 * w - q + p) / 2; 
        }
        else
        {
            wynik = w + (q - p - s - 2 * w) / 2;
        }

        wynik = wynik * x + presuniecia;
        ans = min(ans, wynik);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //* wczytywanie
    cin>>n>>p>>q>>x>>y;

    for(int i = 1; i <= n; i++)
    {
        char c;
        cin>>c;

        if(c == '+')
        {
            wyciag[i] = 1;
            s++;
        }
        else
        {
            wyciag[i] = -1;
            s--;
        }
    }

    //*liczenie
    sufikso_prefiksy();
    cout<<liczenie()<<"\n";
}