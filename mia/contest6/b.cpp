#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;
const int maks = 1e6 + 15;
int q;

bool pierwsze[maks];
bool odwiedzone[maks];

void sito()
{
    for(long long i = 2; i < maks; i++)
    {
        if(!odwiedzone[i])
        {
            pierwsze[i] = true;
            for(long long j = i * i; j < maks; j += i)
            {
                odwiedzone[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //pre procesing, wyznaczanie liczb pierwszych
    sito();

    //wczytywanie
    cin>>q;
    while(q--)
    {
        long long numb, s;
        cin>>numb;

        s = sqrt(numb);

        if(s * s == numb && pierwsze[s])
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
} 