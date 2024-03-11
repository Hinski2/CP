#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
ll base = 1;

ll n, q;
ll *tree;

void update(int v, int x)
{
    v += base;
    tree[v] = x;
    v >>= 1;

    while(v)
    {
        tree[v] += tree[v * 2] + tree[v * 2 + 1];
        v >>= 1;
    }
}

ll query(int a, int b)
{
    a += base;
    b += base;

    ll ans = 0;
    ans += tree[a];
    if(a != b) ans += tree[b];
    
    while(a >> 1 != b >> 1)
    {
        if(a % 2 == 0) ans += tree[a + 1];
        if(b % 2 == 1) ans += tree[b - 1];

        a >>= 1;
        b >>= 1;
    }

    return ans;
}

int main(){
    scanf("%lld %lld", &n, &q);
    while(base < n) base *= 2;
    tree = (ll*) malloc((base << 1) * sizeof(long long));
    
    for(int i = 0; i < n; i++)
        scanf("%lld", &tree[i + base]);

    for(int i = base - 1; i > 0; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
        
    while(q--){
        char opt; scanf(" %c", &opt);
        
        if(opt == 'U'){
            ll n, x; scanf("%lld %lld", &n, &x);
            update(n, x);
        }
        else{
            ll a, b; scanf("%lld %lld", &a, &b);
            printf("%lld\n", query(a, b));
        }
    }
    return 0;
}