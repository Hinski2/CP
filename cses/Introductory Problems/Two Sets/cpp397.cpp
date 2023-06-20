#include<bits/stdc++.h>
using namespace std;

bool check(int mask, int n){
    int sum1 = 0, sum2 = 0, numb = 1;
    for(int i = 0; i < n; i++){
        if(mask & (1 << i)) sum1 += i + 1;
        else sum2 += i + 1;
    }

    return sum1 == sum2;
}

void print(int mask, int n){
    vector<int>vec1, vec2;

    for(int i = 0; i < n; i++){
        if(mask & (1 << i)) vec1.push_back(i + 1);
        else vec2.push_back(i + 1);
    }

    printf("YES\n");
    printf("%d\n", vec1.size());
    for(auto u: vec1)
        printf("%d ", u);
    printf("\n%d\n", vec2.size());
    for(auto u: vec2)
        printf("%d ", u);
}

int main(){
    //get the input
    int n;
    scanf("%d", &n);

    for(int mask = 0; mask < (1 << n); mask++){
        if(check(mask, n)){
            print(mask, n);
            exit(0);
        }
    }

    printf("NO\n");
}

