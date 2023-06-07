#include <bits/stdc++.h>
using namespace std;

int n,ans;
string S;
vector<int>znaki[555];

vector<int>conect(char x, char y)
{
    int ix=0,iy=0;
    vector<int>linked;
    while(ix<znaki[x].size()-1 || iy<znaki[y].size()-1)
    {
        if(znaki[x][ix]<znaki[y][iy])
        {
            linked.push_back(1);
            ix++;
        }
        else
        {
            linked.push_back(-1);
            iy++;
        }
    }
    return linked;
}

int solve(vector<int>linked)
{
    int subAns=0,part=0;
    bool minus=true;

    for(int i=0;i<linked.size();i++)
    {
        if(linked[i]==-1)
        {
            minus=false;
        }

        if(part+linked[i]<0)
        {
            part=0;
            minus=true;
        }

        else
        {
            part+=linked[i];
        }

        subAns=max(subAns,part-minus);
    }
    return subAns;
}

int main() 
{
    ios_base::sync_with_stdio(0);

    cin>>n;
    cin>>S;
    
    for(int i=0;i<S.size();i++)
    {
        znaki[S[i]].push_back(i);
    }
        
    for(char c='a';c<='z';c++)
    {
        znaki[c].push_back(n + 5);
    }
    
    for(char x='a';x<='z';x++)
    {
        for(char y='a';y<='z';y++)
        {
            if(x==y || znaki[x].size()==1 || znaki[y].size()==1) continue;

            ans=max(ans,solve(conect(x,y)));
        }
    }
    cout<<ans<<"\n";
}