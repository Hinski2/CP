#!/usr/bin/env python3

import sys 
import re 
from pathlib import Path
from typing import List, Tuple

########
# data
########
TEMPLATE_CPP = """#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

template<typename T> long long sum(const vector<T> &v){
    long long s = 0;
    for(auto u: v) s += u;
    return s;
}

template<typename T> T max(const vector<T> &v){
    T maxi = v[0];
    for(auto u: v) maxi = max(maxi, u);
    return maxi;
}

template<typename T> T min(const vector<T> &v){
    T mini = v[0];
    for(auto u: v) mini = min(mini, u);
    return mini;
}

template<typename T> unsigned arg_max(const vector<T> &v){
    T maxi = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] > maxi){
            maxi = v[i];
            pos = i;
        }
    return pos;
}

template<typename T> unsigned arg_min(const vector<T> &v){
    T mini = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] < mini){
            mini = v[i];
            pos = i;
        }
    return pos;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl \'\\n\'
#define alf 'z' + 1
#define yn (solve() ? \"YES\" : \"NO\")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
}
"""

TEMPLATE_PY = """t = int(input())
for _ in range(t):
    pass
"""

########
# utils
########
def ok(p: Path) -> Tuple[bool, int | None]:
    filename = str(p).split('/')[-1]
    parts: List[str] = filename.split('.')
    if len(parts) != 2:
        return (False, None)
    
    if not parts[0].startswith(parts[1]):
        return (False, None)
    
    n = parts[0][len(parts[1]):]
    if not n.isdigit():
        return (False, None)
    
    return (True, int(n))

def get_next_numb(root: Path) -> int:
    '''
        get the next number in the root directory
    '''
    max_n = 0
    for p in root.rglob('*.*'):
        (ok_n, n) = ok(p)
        if ok_n and n is not None:
            max_n = max(max_n, n)
    return max_n + 1
    
########
# main
########
if __name__ == '__main__':
    root = Path('/home/hinski2/Programowanie/competitive/codeforces/problems') # we start looking for files in this directory
    arg = sys.argv[1] if len(sys.argv) > 1 else None 
    
    filename, content = '', '' 
    if arg == 'cpp':
        filename = f'cpp{get_next_numb(root)}.cpp'
        content = TEMPLATE_CPP
    elif 'cpp' in str(arg):
        filename = f'{str(arg)}.cpp'
        content = TEMPLATE_CPP
    elif arg == 'py':
        filename = f'py{get_next_numb(root)}.py'
        content = TEMPLATE_PY
    elif 'py' in str(arg):
        filename = f'{str(arg)}.py'
        content = TEMPLATE_PY
    else:
        filename = 'a'
        content = TEMPLATE_CPP
        
        while f'{filename}.cpp' in [p.name for p in Path.cwd().rglob('*.*')]:
            # get next letter
            filename = chr(ord(filename) + 1)
            if ord(filename) > ord('z'):
                raise Exception('too many files, prlease provide your own name')
            
        filename = f'{filename}.cpp'
        
    # create the file 
    print(filename)
    file_path = Path.joinpath(Path.cwd(), filename)
    with open(file_path, 'w') as f:
        f.write(content)
        
    print(f"File created: {file_path}")
    