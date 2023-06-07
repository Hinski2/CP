//nie działa 
#include <bits/stdc++.h>
using namespace std;

bool dokument[1005][1005];


int sprawdzenie(int x,int y,int n,int m,int pierwszy,int drugi)
{
    if(x+pierwszy<0&&x+pierwszy>=n&&y+drugi>=m)
    {
        return 0;
    }
    return 1;
}

int check(int x,int y,int pierwszy,int drugi)
{
    if(dokument[x+pierwszy][y+drugi]==true)
    {
        dokument[x+pierwszy][y+drugi]=false;
    }
    else
    {
        return 0;
    }
    return 1;
}

int main()
{
    int n,m,a,b;
    int q;
    vector<pair<int,int>>pieczec;
    char pierwszy;

//skanowanie danych
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {

//wczytywanie danych 
        scanf("%d %d %d %d",&n,&m,&a,&b);

//tworzenie dokumentu
        for(int x=0;x<n;x++)
        {
        
            scanf("%c",&pierwszy);
            for(int y=0;y<m;y++)
            {
                //skanowanie znaku
                char znak;
                scanf("%c",&znak);
                //przypoisywanie znaku
                if(znak=='x')dokument[x][y]=true;  //true jest tusz / jest "x"
                else dokument[x][y]=false;         //false nie ma tuszu / jest "."
            }
        }

//tworeznie pieczeci
        for(int x=0;x<a;x++)
        {
        scanf("%c",&pierwszy);
            for(int y=0;y<b;y++)
            {
            //skanowanie znaku
                char znakk;
                scanf("%c",&znakk);         //wczytuje znak
                //przypoisywanie znaku
                if(znakk=='x')              //jeśli to jest x to zapiuje to miejsce w vektorze
                {
                    if(x==0||y==0)pieczec.push_back(make_pair(x,y));
                    else pieczec.push_back(make_pair(x-pieczec[0].first,y-pieczec[0].second));
                }
            }
        }

//sprawdzanie   
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                if(dokument[x][y]==true)   // jest x
                {
                    bool czy=true;
                    for(int i=0;i<pieczec.size();i++)
                    {
                        if(czy==false)break;
                        if(sprawdzenie(x,y,n,m,pieczec[i].first,pieczec[i].second)==0)
                        {
                            cout<<"NIE"<<endl;
                            czy=false;
                        }
                        if(czy==false)break;
                        else if(check(x,y,pieczec[i].first,pieczec[i].second==0))
                        {
                            cout<<"NIE"<<endl;
                            czy=false;
                        }
                    }
                }
                else continue;             // jest .
            }
        }
        cout<<"TAK"<<endl;
    }
}