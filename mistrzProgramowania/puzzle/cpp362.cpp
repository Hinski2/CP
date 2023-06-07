#include <bits/stdc++.h>                                                        
using namespace std;                                                            
                                                                                
inline int oblicz(int x){                                                       
    int a = x, b = 1;                                                           
    for(int i = sqrt(x); i > 1; i--){                                           

        if(x % i == 0){                                                         
            a = i;                                                              
            b = x / i;                                                          
            break;                                                              
        }                                                                       
    }                                                                           
                                                                                
    a += 2; b += 2;                                                             
    return a * b - x;                                                           
}                                                                               
                                                                                
int main(){                                                                     
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                      
    int q, x;                                                                   
    cin >> q;                                                                   
    while(q--){                                                                 
        cin >> x;                                                               
        cout << oblicz(x) << '\n';                                              
    }                                                                           
}     