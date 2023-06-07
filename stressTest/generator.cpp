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

    int n = 400;
    cout << n << '\n';
    for(int i = 1; i <= n; i++){
        int numb = rand() % 10;
        if(numb % 2) numb *= -1;

        cout << numb << ' ';
    }
    cout << '\n';

    vector<int>dostepne;
    dostepne.push_back(1);

    for(int b = 2; b <= n; b++)
    {
        int idx = (rand() % dostepne.size());
        int a = dostepne[idx];

        dostepne.push_back(b);

        cout << a << ' ' << b << '\n';
    }
}
