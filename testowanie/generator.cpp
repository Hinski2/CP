#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ziarno;
    cin >> ziarno;
    srand(ziarno);

    int a = 0, b = 1000;
    printf("%d\n",a + rand() % (b - a + 1));
}

