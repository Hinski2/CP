#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll sum = 1LL * n * (n + 1); //sum of all numbers (1, 2... n) * 2
    if(sum % 4 != 0){
        printf("NO\n"); //only if sum is divisible by 4 we can find the answer
        exit(0);
    }
    sum /= 4;

    vector<int>set1, set2;
    for(int i = n; i > 0; i--){
        if(sum - i >= 0){
            set1.push_back(i);
            sum -= i;
        }
        else
            set2.push_back(i);
    }

    printf("YES\n");
    
    //print first set
    printf("%d\n", set1.size());
    for(auto u: set1)
        printf("%d ", u);

    //print second set
    printf("\n%d\n", set2.size());
    for(auto u: set2)
        printf("%d ", u);
}

    