#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define x first
#define y second        
#define N 100005
typedef pair<int,int> pii;
 
struct node{
    pii M;
    pii l;
    pii r;
};
 
node t[4*N];
int a[N];

inline node combine(node a, node b){
    node res;
    if(a.l.x==b.r.x){                           
        res.M.x=res.l.x=res.r.x=a.l.x;
        res.M.y=res.l.y=res.r.y=a.l.y+b.r.y;
    }
    else{
        // Update res.l, res.r
        res.l=a.l;
        res.r=b.r;
        if(a.l.x==b.l.x){                       
            res.l.y=a.l.y+b.l.y;
        }
        if(a.r.x==b.r.x){                       
            res.r.y=a.r.y+b.r.y;
        }
 
        // Update res.M
        if(a.M.y>b.M.y) res.M=a.M;
        else res.M=b.M;
 
        if(a.r.x==b.l.x){                       
            int temp=a.r.y+b.l.y;
            if(temp>res.M.y){
                res.M.x=a.r.x;
                res.M.y=temp;
            }
        }
    }
 
    return res;
}

void Build(int v, int tl, int tr){
    if(tl==tr){
        t[v].M=mp(a[tl],1);
        t[v].l=mp(a[tl],1);
        t[v].r=mp(a[tl],1);
    }
    else{
        int tm=(tl+tr)/2;
 
        Build(v*2, tl, tm);
        Build(v*2+1, tm+1, tr);
 
        t[v]=combine(t[v*2], t[v*2+1]);
    }
}

inline node Query(int v, int tl, int tr, int l, int r){
    if(l==tl && (r==tr))  return t[v];
    int tm=(tl+tr)/2;
 
    if(r<=tm) return Query(v*2,tl,tm,l,r);
    if(l>tm) return Query(v*2+1,tm+1,tr,l,r);
 
    return combine(Query(v*2,tl,tm,l,tm),Query(v*2+1,tm+1,tr,tm+1,r));
}
 
int main(){
    int n,q,l,r;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        scanf(" %d",&q);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        Build(1,0,n-1);
        while(q--){
            scanf("%d %d",&l,&r);
            --l;
            --r;
            printf("%d\n",Query(1,0,n-1,l,r).M.y);
 
 
        }
    }
    
    return 0;
}