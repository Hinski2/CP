#include <bits/stdc++.h>
using namespace std;

const int mak = 105;

int x, y, k, m;
int ans = INT_MAX;

bool odwiedzony[205][205];

void oblicz()
{
    queue<pair<pair<int, int>, int>>q;

    q.push({{0, 0}, 0});

    while(!q.empty())
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int step = q.front().second;

        q.pop();

        if(!odwiedzony[a][b])
        {
            odwiedzony[a][b] = true;
            ans = min(ans, abs(m - (a + b)));

            if(step < k) //dodawanie kolejnego poziomu
            {
                //wypelnienie
                if(!odwiedzony[x][b]) q.push({{x, b}, step + 1});
                if(!odwiedzony[a][y]) q.push({{a, y}, step + 1});
                
                //wylanie
                if(!odwiedzony[0][b]) q.push({{0, b}, step + 1});
                if(!odwiedzony[a][0]) q.push({{a, 0}, step + 1});

                //przelanie
                int przelanie_do_a = min(b, x - a);
                int przelanie_do_b = min(a, y - b);

                if(!odwiedzony[a + przelanie_do_a][b - przelanie_do_a]) q.push({{a + przelanie_do_a, b - przelanie_do_a}, step + 1});
                if(!odwiedzony[a - przelanie_do_b][b + przelanie_do_b]) q.push({{a - przelanie_do_b, b + przelanie_do_b}, step + 1});
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    //wczytywanie
    cin >> x >> y >> k >> m;

    //liczenie
    oblicz();

    cout << ans << "\n";
}