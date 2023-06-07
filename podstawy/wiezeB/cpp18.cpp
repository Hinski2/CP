#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char i[1005][1005];
    bool xx[1005],yy[1005];
    //wczytywanie
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            cin>>i[x][y];
            if(i[x][y]=='W')
            {
                yy[y]=true;
                xx[x]=true;
            }
        }
    }
    //sprawdzanie
    for(int x=0;x<n;x++)
    {
        if(xx[x]==true)continue;
        for(int y=0;y<n;y++)
        {
            if(yy[y]==true)continue;
            if(yy[y]==false && xx[x]==false)
            {
                i[x][y]='W';
                yy[y]=true;
                xx[x]=true;
                y=0;
            }
        }
    }
    //wypisywanie
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            cout<<i[x][y];
        }
        cout<<endl;
    }
    return 0;
}
