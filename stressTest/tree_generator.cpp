#include<bits/stdc++.h> //liczba=(rand()%x)+1
using namespace std;

const int mod_n = 50000;
const int mod_m = 200000;

long seed()
{
    auto t=chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t.time_since_epoch()).count();
}

int main()
{ 
    srand(seed());

    int n = (rand() % mod_n) + 1;
    int m = (rand() % mod_m) + 1;

    vector<int>dostepne;
    dostepne.push_back(0);

    printf("%d\n", n);
    for(int b = 1; b < n; b++)
    {
        int idx = (rand() % dostepne.size());
        int a = dostepne[idx];

        dostepne.push_back(b);

        printf("%d %d\n", a, b);
    }

    printf("%d\n", m);
    while(m--)
    {
        int a = rand() % n;
        int b = rand() % n;
        int c = rand() % n;
        printf("%d %d %d\n", a, b, c);
    }
}
