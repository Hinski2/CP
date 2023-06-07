#include <bits/stdc++.h>
using namespace std;

int x, y;
void oblicz(int a, int b){
	if(b != 0){
		oblicz(b, a % b);
		int c = y;
		y = x - a / b * y;
		x = c;
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int a, b, c, d;
	while(cin >> a && a != -100){
		cin >> b >> c >> d;
		x = 1; y = 0;	

		oblicz(a, b);
		int g = __gcd(a, b);
        int l = d - c;
		
        int opt1 = l / g, opt2 = opt1 + 1, opt3 = opt1 - 1, ile;
        int ans1 = abs(d - (c + opt1 * g));
        int ans2 = abs(d - (c + opt2 * g));
        int ans3 = abs(d - (c + opt3 * g));

        int ans = min(ans1, min(ans2, ans3));

        if(ans1 == ans) ile = opt1;
        else if(ans2 == ans) ile = opt2;
        else ile = opt3;

		cout << x * ile << ' ' << y * ile << '\n';	
	}
}
