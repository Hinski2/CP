#include<bits/stdc++.h>
using namespace std;

const int maks = 10 + 5;
const int capacity = 1024;

int kubek[maks][maks];
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    int h, t;
    cin>>h>>t;

    //liczenie
    kubek[1][1] = t * capacity;

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(kubek[i][j] >= capacity)
            {
                ans++;

                kubek[i][j] -= capacity;
                kubek[i][j] /= 2;

                kubek[i + 1][j] += kubek[i][j];
                kubek[i + 1][j + 1] += kubek[i][j];
            }
        }
    }

    //wypianie wyniku
    cout<<ans<<"\n"; 
}