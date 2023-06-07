#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;
const int mod = 1e9 + 7;

int n;
int arr[mak], par_l; //par_l to licznik par
vector<int>pos[mak];
vector<int>pod[2];

int sprawdzenie()
{
    for(int i = 1; i <= n; i++)
    {
        if(pos[i].size() == 1 || pos[i].size() == 0) continue;
        if(pos[i].size() == 2)
        {
            par_l++;    //licznik par
            if(abs(pos[i][0] - pos[i][1]) != 2) return 0;
            pod[(pos[i][0] + 1) % 2].push_back(pos[i][0] + 1);
        }
        if(pos[i].size() > 2) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        arr[i] = x;                 //zwykły ciąg
        pos[x].push_back(i);        //indeksowanie pozycji
    }

    if(!sprawdzenie()) // sprawdza czy zeznania krasnali są prawidłowe
    {
        cout<<"0\n";
        return 0;
    }

    //jeśli nie ma pewniaków 
    if(!par_l)
    {
        if(n%2) //nieparzysty
        {
            cout<<"0\n";
        }
        else    //parzysty - ponieważ istanieje tylko jeden możliwy ciag
        {
            cout<<"1\n";
        }
        return 0;
    }

    //kolejny warunek
    if(pod[0].size() == 0 && pod[1].size() > 0)
    {
        if(n%2) //nieparzysty
        {
            cout<<"0\n";
        }
        else    //parzysty - ponieważ istanieje tylko jeden możliwy ciag
        {
            cout<<"1\n";
        }
        return 0;
    }

    for(auto u: pod[0])
    {
        cout<<u<<" ";
    }
    cout<<endl;
    for(auto u: pod[1])
    {
        cout<<u<<" ";
    }
    cout<<endl;

}