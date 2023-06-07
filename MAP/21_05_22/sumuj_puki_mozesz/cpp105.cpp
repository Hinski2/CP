#include <bits/stdc++.h>
using namespace std;

long long liczba, liczba2;

void liczenie()
{
    liczba2 = 0;

    while(liczba != 0)
    {
        liczba2 += liczba % 10;
        liczba /= 10;
    }

    liczba = liczba2;
}

int main()
{   
    scanf("%lld", &liczba);

    while(liczba >= 10)
    {
        liczenie();
    }
    
    printf("%lld", liczba);
}