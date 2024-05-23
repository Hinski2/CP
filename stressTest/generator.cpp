#include<bits/stdc++.h> //liczba=(rand()%x)+1
using namespace std;

long seed()
{
    auto t=chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t.time_since_epoch()).count();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(seed());
    int t = 10000; cout << t << endl;
    for(int i = 0; i < t; i++){
        int n = 3; cout << n << endl;
        for(int i = 0; i < n; i++)
            cout << rand() % 10000 << ' ';
        cout << endl;
    }
}
