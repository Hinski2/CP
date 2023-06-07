#include <bits/stdc++.h>
using namespace std;

const int maksimum = 5015;
int liczbaPortow, liczbaKrawedzi, liczbaOpowiesci;
int nPrzejscie[maksimum][maksimum], pPrzejscie[maksimum][maksimum]; //minimalna odległość między punktami dla nieparzystego przejścia i parzystego przejścia 

vector<int> v[maksimum];  

void obliczanie(int start)
{
    queue<tuple<int, int, int>>k;   //z kąd, do kąd, dystans

    k.push({start, start, 0});

    while(!k.empty())
    {
        int from = get<0>(k.front()); 
        int to = get<1>(k.front());
        int distance = get<2>(k.front());

        k.pop();

        if(distance  % 2 == 0) //parzyste
        {
            pPrzejscie[from][to] = distance ;
        }
        else            //nieparzyste
        {
            nPrzejscie[from][to] = distance ;
        }

        for(auto i: v[to])
        {
            if(distance  % 2 == 0)     //parzysta odległość 
            {
                if(nPrzejscie[start][i] == -1)  //nie sprawdznona odległość dla parzystej odległości
                {
                    k.push({start, i, distance +1});
                    nPrzejscie[start][i] = -2; //dzięki temu port zostanie sprawdzonre raz dla wartości parzystych i nieparzystych
                }
            }   
            else                //nieparzysta odległość 
            {
               if(pPrzejscie[start][i] == -1)   //nie sprawdzona odległość dla nieparzystej odległości
                {
                    k.push({start, i, distance +1});
                    pPrzejscie[start][i] = -2; //dzięki temu port zostanie sprawdzone raz dla wartości parzystych i nieparzystych
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &liczbaPortow, &liczbaKrawedzi, &liczbaOpowiesci);

    //wczytywanie krawędzi
    for(int i = 1; i <= liczbaKrawedzi; i++)
    {
        int x, y;
        scanf("%d%d",&x, &y);
        
        v[x].push_back(y);
        v[y].push_back(x);
    }

    //podmienianie odległości minimialnych między portami
    for(int i = 1; i <= liczbaPortow; i++)
    {
        for(int j = 1; j <= liczbaPortow; j++)
        {
            nPrzejscie[i][j] = -1;
            pPrzejscie[i][j] = -1;
        }
    }

    //obliczanie odległości dla każdego wierzchołka 
    for(int i = 1; i <= liczbaPortow; i++)
    {
        obliczanie(i);
    }

    while(liczbaOpowiesci--)
    {
        int from, to, odleglosc;
        scanf("%d%d%d", &from, &to, &odleglosc);

        if(odleglosc % 2 == 0)
        {
            if(pPrzejscie[from][to] <= odleglosc && pPrzejscie[from][to] != -1 && pPrzejscie[from][to] != -2)
            {
                printf("TAK\n");
            }
            else
            {
                printf("NIE\n");
            }
        }
        else 
        {
            if(nPrzejscie[from][to] <= odleglosc && nPrzejscie[from][to] != -1 && nPrzejscie[from][to] != -2)
            {
                printf("TAK\n");
            }
            else
            {
                printf("NIE\n");
            }
        }
    }
}