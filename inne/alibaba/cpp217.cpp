#include <bits/stdc++.h>
using namespace std;

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

bool sprawdzenie(vector<int> &m, vector<int> &cena)
{
    for(int i: {0, 1, 2})
    {
        if(m[i] < cena[i]) return 0;
    }

    return 1;
}

void liczenie()
{   
    int ilosc_przemian;
    unordered_map<vector<int>, bool, VectorHasher>mapa;

    vector<int> start(3), potrzebne(3);
    vector<pair<vector<int>, vector<int>>>przemiany;

    for(int i: {0, 1, 2})
    {
        cin >> start[i];
    }
    for(int i: {0, 1, 2})
    {
        cin >> potrzebne[i];
    }

    cin >> ilosc_przemian;
    for(int i = 1; i <= ilosc_przemian; i++)
    {
        vector<int> m1(3), m2(3);

        for(int i: {0, 1, 2})
        {
            cin >> m1[i];
        }
        for(int i: {0, 1, 2})
        {
            cin >> m2[i];
        }

        przemiany.push_back({m1, m2}); 
    }

    //liczenie
    queue<pair<vector<int>, int>>q;
    q.push({start, 0});

    while(!q.empty())
    {
        vector<int> m = q.front().first;
        int s = q.front().second;
        q.pop();

        auto it = mapa.find(m);
        if(it == mapa.end())
        {
            mapa[m] = true;
            //sprawdzenie czy udało sie wymienic 
            bool eureka = true;
            for(int i : {0, 1, 2})
            {
                if(m[i] < potrzebne[i]) eureka = false;
            }
            if(eureka)
            {
                cout << s << "\n";
                return;
            }

            //dalsze wymienianie
            for(auto u: przemiany)
            {
                if(sprawdzenie(m, u.first))
                {
                    vector<int> rezultat(3);
                    bool dalej = true;

                    for(int i: {0, 1, 2})
                    {
                        rezultat[i] = m[i] - u.first[i] + u.second[i];
                        if(rezultat[i] > 100) dalej = false;
                    }

                    if(dalej)
                    {
                        auto it2 = mapa.find(rezultat);
                        if(it2 == mapa.end())
                        {
                            q.push({rezultat, s + 1});
                        } 
                    }
                }
            }
        }
    }

    //nie udało się wychandlowac 
    cout << "NIE\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        liczenie();
    }
}