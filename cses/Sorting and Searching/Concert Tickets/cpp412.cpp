#include<bits/stdc++.h>
using namespace std;

int no_tickets, no_customers;
map<int, int>ticket;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> no_tickets >> no_customers;
    for(int i = 0; i < no_tickets; i++){
        int x;
        cin >> x;
        ticket[x]++;
    }

    while(no_customers--){
        int c;
        cin >> c;
        map<int, int>::iterator itr = ticket.lower_bound(c);

        while(itr -> first > c && itr != ticket.begin() || (itr == ticket.end() && ticket.size()))
            itr--;
        if(itr -> first > c || ticket.size() == 0)
            cout << "-1\n";
        else{
            cout << itr -> first << '\n';
            if(--itr -> second == 0) ticket.erase(itr);
        }
    }
}




