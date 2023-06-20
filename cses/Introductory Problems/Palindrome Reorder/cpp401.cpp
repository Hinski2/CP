#include<bits/stdc++.h>
using namespace std;

string str;
int letters[100];

int main(){
    //get string
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;

    //count occurance of letters
    for(auto u: str)
        letters[u]++;

    //chect how many letters occured odd number times
    int odd_leter, odd_numb = 0;
    for(int i = 'A'; i <= 'Z'; i++){
        if(letters[i] & 1){
            odd_numb++;
            odd_leter = i;
        }
    }

    //only one letter can occure odd number of times
    if(odd_numb > 1){
        cout << "NO SOLUTION\n";
        exit(0);
    }

    //printing palindrome
    for(int i = 'A'; i <= 'Z'; i++){
        if(i == odd_numb) continue;
        for(int j = 1; j <= letters[i] / 2; j++)
            cout << char(i);
    }

    if(odd_numb)
        cout << char(odd_leter);

    for(int i = 'Z'; i >= 'A'; i--){
        if(i == odd_numb) continue;
        for(int j = 1; j <= letters[i] / 2; j++)
            cout << char(i);
    }
}

