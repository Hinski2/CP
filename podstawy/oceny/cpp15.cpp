#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,int> map;
    map[1]=0;
    map[2]=0;
    map[3]=0;
    map[4]=0;
    map[5]=0;
    map[6]=0;
    int oceny,x;
    cin>>oceny;
    for(int i=0 ; i<oceny ; i++)
    {
        cin>>x;
        for(int z=1; z<=6;z++)
        {
            if(x==z)
            {
                map[z]+=1;
            }
        }
    }
    for(int o = 1;o<=6;o++)
    {
        cout<<map[o]<<" ";
    }
    return 0;
}
