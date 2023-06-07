#include <bits/stdc++.h>
using namespace std;

int n;
int m[1005][1005];

bool visited[1005][1005];

int nin;
int nax;
int value;

int x[] = {0, 1, 1, 1, 0, -1, -1, -1};
int y[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool ok(int _x, int _y) {
    if(m[_y][_x] == value) return true;
    else {
        nin = min(nin, m[_y][_x]);
        nax = max(nax, m[_y][_x]);
        return false;
    }
}

bool inside(int _x, int _y) {
    return 1 <= _x && _x <= n && 1 <= _y && _y <= n;
}

void bfs(int &_x, int &_y) {
    visited[_y][_x] = true;
    
    queue <pair <int, int>> Q;
    Q.push({_y, _x});
    
    while(!Q.empty()) {
        int nx = Q.front().second;
        int ny = Q.front().first;
        Q.pop();
        visited[ny][nx] = true;
        
        for(int i = 0; i < 8; i++) {
            if(inside(nx + x[i], ny + y[i])) {
                if(ok(nx + x[i], ny + y[i])) {
                    if(!visited[ny + y[i]][nx + x[i]]) {
                        visited[ny + y[i]][nx + x[i]] = true;
                        Q.push({ny + y[i], nx + x[i]});
                    }
                }
            }
        }

    }
}

void read() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &m[i][j]);
}

void solve() {
    int low = 0;
    int high = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visited[i][j]) continue;
            
            value = nin = nax = m[i][j];
            
            bfs(j, i);
            
            if(nin == value) low++;
            if(nax == value) high++;
            
        }
    }
    
    printf("%d %d\n", high, low);
}

int main() {
    read();
    solve();
}