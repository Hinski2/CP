#include <bits/stdc++.h>
using namespace std;

int n;
string S;

vector<int>znaki[555];

vector<int>getVec(char c1, char c2) 
{
    int i=0, j=0;
    vector<int>res;
    while(i<znaki[c1].size()-1 || j<znaki[c2].size()-1) 
    {
        if(znaki[c1][i]<znaki[c2][j]) 
        {
            res.push_back(1);
            i++;
        }
         
        else
        {
            res.push_back(-1);
            j++;
        }
    }
    return res;
}

int solve(vector<int>arr) 
{
    int cur=0;
    int ans=0;
    bool nok=true;
    for(int i=0;i<arr.size();i++) 
    {
        if(arr[i]==-1) nok=false;
        if(cur+arr[i]<0) 
        {
            cur=0;
            nok=true;
        } 

        else 
        {
            cur+=arr[i];
        }
        
        ans=max(ans,cur-nok);
    }
    return ans;
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
        
    for(char c = 'a'; c <= 'z'; c++)
    {
        znaki[c].push_back(n + 5);
    }
    int ans = 0;
    
    for(char i='a';i<='z';i++) 
    {
        for(char j='a';j<='z';j++) 
        {
            if(i==j || znaki[i].size()==1 || znaki[j].size()==1) continue;
            ans = max(ans, solve(getVec(i, j)));
        }
    }
    cout<<ans<<endl;   
}