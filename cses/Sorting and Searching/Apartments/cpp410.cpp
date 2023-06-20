#include<bits/stdc++.h>
using namespace std;

int no_people, no_flat, difference, ans;
vector<int> people;

map<int, int>flat;
map<int, int>::iterator itr;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //get data
    cin >> no_people >> no_flat >> difference;
    people.resize(no_people);

    for(int i = 0; i < no_people; i++)
        cin >> people[i];
    for(int i = 0; i < no_flat; i++){
        int x;
        cin >> x;
        flat[x]++;
    }

    //sort people in incraseing order
    sort(people.begin(), people.end());

    //assign value
    for(auto u: people){
        itr = flat.lower_bound(u - difference);
        if(itr == flat.end()) continue;

        if(itr -> first <= u + difference){
            ans++;
            if(--itr -> second == 0) flat.erase(itr);
        }
    }

    cout << ans << '\n';
}
