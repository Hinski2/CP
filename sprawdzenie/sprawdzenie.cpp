#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<vector<int>> bit(N, vector<int>(N, 0));

void add(int x, int y, int val) {
    for (int i = x; i < N; i += i & -i)
        for (int j = y; j < N; j += j & -j)
            bit[i][j] += val;
}

int sum(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            res += bit[i][j];
    return res;
}

int interval_sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

int main() {
    // Example usage:
    add(1, 1, 5);
    cout << interval_sum(1, 1, 2, 2) << endl;
    return 0;
}