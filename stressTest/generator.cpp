#include<bits/stdc++.h> //liczba=(rand()%x)+1
using namespace std;

long seed()
{
    auto t=chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t.time_since_epoch()).count();
}

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(seed());

    int n = rand() % 7 + 1, m = rand() % 3 + 1;
    cout << n << ' ' << m << endl;

    for(int i = 0; i < n; i++){
        int x = rand() % 20 * (rand() % 2 ? 1 : -1);
        cout << x << ' ';
    }
    cout << endl;

    for(int i = 0; i < m; i++){
        char op = (rand() % 2 ? 'Q' : 'U');
        cout << op << ' ';

        if(op == 'Q'){
            int a = rand() % n, b = rand() % n;
            while(a > b) a = rand() % n, b = rand() % n;
            cout << a << ' ' << b << endl;
        }
        else
            cout << rand() % n << ' ' << rand() % 20 * (rand() % 2 ? 1 : -1) << endl;
    }
}
