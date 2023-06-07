#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll wynik, last_sum;

vector<int>liczby;
stack<pair<ll, ll>>stos;

void stosowanie(int l)
{
    if(stos.size() == 0)
    {
        stos.push({l, 1});
        last_sum = l;
        wynik += l;
    }

    else
    {
        ll ile_dodac = 0;
        int s = stos.top().first;
        
        if(l > s)
        {
            while(l > s)
            {
                ll ile = stos.top().second;
                last_sum -= s * ile;
                ile_dodac += ile;

                stos.pop();

                if(stos.size() == 0) break;
                s = stos.top().first;
            }
        }

        last_sum += l * (ile_dodac + 1);
        wynik += last_sum;

        stos.push({l, (ile_dodac + 1)});
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x; 
        cin >> x;
        liczby.push_back(x);
    }

    //liczenie
    for(auto u: liczby)
    {
        stosowanie(u);
    }

    //wypisanie wyniku
    cout << wynik << "\n";
}