#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 1005;

int n, m, ans;
pii start, finish;
int dist[mak][mak];
bool path[mak][mak];

struct transition{
    int fi;
    int se;
    char c;
};

struct pos{
    int i;
    int j;
    int odl;
};

vector<transition> movee{ //inverted
    {1, 0, 'U'},
    {0, 1, 'L'},
    {-1, 0, 'D'},
    {0, -1, 'R'}
};


void noumber(){
    queue<pos>kolejka;
    kolejka.push({start.fi, start.se, 1});

    while(!kolejka.empty()){
        int i = kolejka.front().i;
        int j = kolejka.front().j;
        int odl = kolejka.front().odl;
        kolejka.pop();

        if(dist[i][j] == 0){
            dist[i][j] = odl;

            for(auto u: movee)
                if(path[i + u.fi][j + u.se] && dist[i + u.fi][j + u.se] == 0)
                    kolejka.push({i + u.fi, j + u.se, odl + 1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;

            if(c != '#') path[i][j] = true;
            if(c == 'A') start = {i, j};
            if(c == 'B') finish = {i, j};
        }

    noumber();
    stack<char>ans;
    int i = finish.fi, j = finish.se;

    if(dist[i][j] == 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n" << dist[i][j] - 1 << '\n';
    while(!(i == start.fi && j == start.se)){
        for(auto u: movee){
            if(path[i + u.fi][j + u.se] && dist[i + u.fi][j + u.se] < dist[i][j]){
                ans.push(u.c);
                i = i + u.fi;
                j = j + u.se;

                break;
            }
        }
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
}
